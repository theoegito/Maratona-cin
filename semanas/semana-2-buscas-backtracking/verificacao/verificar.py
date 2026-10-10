"""Execute com Python 3 e GCC no PATH, a partir de qualquer diretório.
Executáveis ficam no diretório temporário do sistema; originais nunca são editados.
Resultados JSON são impressos na saída padrão. CXX pode escolher o compilador.
O rascunho Contest 3/H.cpp é preservado: sua falha de compilação é esperada.
"""
from pathlib import Path
import hashlib,itertools,json,random,subprocess,tempfile,bisect,contextlib,os
base=Path(__file__).resolve().parents[1]
semana1=base.parent/'semana-1-stl-prefix-sum'
repo=base.parent.parent
result={'integridade':[], 'compilacao':[], 'testes_templates':{}, 'testes_originais':{},
        'observacoes':['Contest 3/H.cpp é um rascunho original incompleto: sua falha de compilação é esperada e registrada; ele não é executado.']}
def integrity(path,expected):
 actual=hashlib.sha256(path.read_bytes()).hexdigest()
 ok=actual==expected
 result['integridade'].append({'arquivo':path.relative_to(repo).as_posix(),'sha256':actual,'ok':ok})
 assert ok,path
manifest=json.loads((base/'verificacao/originais.json').read_text(encoding='utf-8'))
for item in manifest:
 # O manifesto histórico usava solucoes/; a organização atual usa homework-2/.
 p=base/item['arquivo']
 if not p.is_file():p=base/'homework-2'/Path(item['arquivo']).name
 integrity(p,item['sha256'])
for line in (semana1/'verificacao/originais-sha256.txt').read_text(encoding='utf-8').splitlines():
 if not line.strip():continue
 expected,previous=line.split(maxsplit=1)
 p=semana1/previous.strip()
 if not p.is_file():p=semana1/'homework-1'/Path(previous.strip()).name
 integrity(p,expected)
contest_hashes={
 semana1/'contest-2/F.cpp':'42a9cfae2633a7c05552ef15791920b737d31054e25a0ea48b8f5666252978f3',
 semana1/'contest-2/H.cpp':'629f9ed7cbd175147e2d4ded2edd8d2454a033d774f5bd5562edee6b04b73738',
 base/'contest-3/H.cpp':'d9b8d9ba472944f945ac55dde9bf045d60a269491f24266acd3d05e3e9cae1be'}
for p,expected in contest_hashes.items():integrity(p,expected)
rng=random.Random(20261010)
build=Path(os.environ.get('MARATONA_BUILD_DIR',str(Path(tempfile.gettempdir())/'maratona-hw2-build')))
build.mkdir(parents=True,exist_ok=True)
with contextlib.nullcontext(str(build)) as folder:
 executables={}
 for group,path in [('hw2-original',base/'homework-2'),('hw2-template',base/'templates'),('semana1-original',semana1/'homework-1'),('semana1-template',semana1/'templates'),('contest2-original',semana1/'contest-2'),('contest3-original',base/'contest-3')]:
  for src in sorted(path.glob('*.cpp')):
   exe=Path(folder)/(group+'-'+src.stem+'.exe')
   cmd=[os.environ.get('CXX','g++'),'-std=c++17','-O2','-Wall','-Wextra']
   if 'template' in group:cmd+=['-pedantic']
   proc=subprocess.run(cmd+[str(src),'-o',str(exe)],capture_output=True,text=True)
   expected_failure=group=='contest3-original' and src.name=='H.cpp'
   result['compilacao'].append({'grupo':group,'arquivo':src.relative_to(repo).as_posix(),'codigo':proc.returncode,'falha_esperada':expected_failure,'avisos':proc.stderr})
   if expected_failure:
    assert proc.returncode!=0,'O rascunho original foi alterado ou passou a compilar; reveja o registro.'
    continue
   assert proc.returncode==0,(src,proc.stderr)
   executables[(group,src.stem)]=exe
 def run(name,data,group='hw2-template'):
  if name=='pilha_monotonica' and group=='hw2-template':group='semana1-template'
  proc=subprocess.run([str(executables[(group,name)])],input=data,capture_output=True,text=True,timeout=5)
  assert proc.returncode==0,(name,proc.stderr)
  return proc.stdout.strip()
 def check(name,data,expected):
  actual=run(name,data);assert actual==str(expected).strip(),(name,data,expected,actual)
  result['testes_templates'][name]=result['testes_templates'].get(name,0)+1
 for _ in range(80):
  n=rng.randrange(0,13);a=[rng.randrange(-8,9) for _ in range(n)];x=rng.randrange(-10,11);s=sorted(a)
  lb=bisect.bisect_left(s,x);ub=bisect.bisect_right(s,x)
  check('bounds',f'{n} {x}\n'+ ' '.join(map(str,a)),f'{lb} {ub} {ub-lb}')
  check('sort_indices',str(n)+'\n'+' '.join(map(str,a)), '\n'.join(f'{v} {i+1}' for v,i in sorted((v,i) for i,v in enumerate(a))))
  previous=[max([0]+[j+1 for j in range(i) if a[j]<a[i]]) for i in range(n)]
  check('pilha_monotonica',str(n)+'\n'+' '.join(map(str,a)), ' '.join(map(str,previous)))
  actual=run('two_pointers',f'{n} {x}\n'+' '.join(map(str,a)))
  possible=any(a[i]+a[j]==x for i in range(n) for j in range(i+1,n))
  if actual=='IMPOSSIBLE':assert not possible
  else:
   i,j=map(int,actual.split());assert 1<=i<=n and 1<=j<=n and i!=j and a[i-1]+a[j-1]==x
  result['testes_templates']['two_pointers']=result['testes_templates'].get('two_pointers',0)+1
  b=[rng.randrange(0,10) for _ in range(n)];lim=rng.randrange(0,30)
  brute=max([0]+[j-i for i in range(n) for j in range(i+1,n+1) if sum(b[i:j])<=lim])
  check('sliding_window',f'{n} {lim}\n'+' '.join(map(str,b)),brute)
  subsets=[sum(a[j] for j in range(n) if mask>>j&1) for mask in range(1<<n)]
  check('recursao_subset',f'{n} {x}\n'+' '.join(map(str,a)),subsets.count(x))
  sums=[sum(b[j] for j in range(n) if mask>>j&1) for mask in range(1<<n)]
  check('bitmask',str(n)+'\n'+' '.join(map(str,b)),min(abs(sum(b)-2*t) for t in sums))
  m=rng.randrange(0,9);intervals=[sorted([rng.randrange(-5,6),rng.randrange(-5,6)]) for _ in range(m)]
  queries=[rng.randrange(-6,7) for _ in range(10)]
  check('sweep_line',f'{m} 10\n'+'\n'.join(f'{l} {r}' for l,r in intervals)+'\n'+' '.join(map(str,queries)), '\n'.join(str(sum(l<=q<=r for l,r in intervals)) for q in queries))
 for _ in range(80):
  n=rng.randrange(1,9);a=[rng.randrange(0,12) for _ in range(n)];k=rng.randrange(1,n+3)
  answer=sum(a)
  for mask in range(1<<(n-1)):
   if mask.bit_count()+1>k:continue
   groups=[];current=a[0]
   for i in range(n-1):
    if mask>>i&1:groups.append(current);current=0
    current+=a[i+1]
   groups.append(current);answer=min(answer,max(groups))
  check('binary_search_resposta',f'{n} {k}\n'+' '.join(map(str,a)),answer)
 for word in ['a','aa','ab','aab','abc','baba','cba','aabbcc']:
  check('next_permutation',word, '\n'.join(sorted({''.join(p) for p in itertools.permutations(word)})))
 for n in range(1,8):
  for _ in range(5):
   board=[''.join('.' if rng.random()>.2 else '*' for _ in range(n)) for _ in range(n)]
   expected=0
   for perm in itertools.permutations(range(n)):
    if all(board[r][c]=='.' for r,c in enumerate(perm)) and len({r+c for r,c in enumerate(perm)})==n and len({r-c for r,c in enumerate(perm)})==n:expected+=1
   check('backtracking',str(n)+'\n'+'\n'.join(board),expected)
 # overflow de int, duplicatas e fronteiras em long long.
 check('binary_search_resposta','3 2\n3000000000 3000000000 3000000000','6000000000')
 check('sliding_window','3 6000000000\n3000000000 3000000000 1','2')
 sudoku_solved='''5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9'''
 sudoku_impossible='0 1 2 3 4 5 6 7 8\n9 0 0 0 0 0 0 0 0\n'+('0 0 0 0 0 0 0 0 0\n'*7)
 original_tests={
 'A':[('3 7\n3 2 5\n','8'),('1 1000000000\n1000000000\n','1000000000000000000')],
 'B':[('1\n'+sudoku_solved.replace('5 3 4','0 3 4',1)+'\n',sudoku_solved),('1\n'+sudoku_impossible,'No solution')],
 'C':[('1\n7\n','1'),('6\n1 1 6 6 7 12\n','4'),('5\n-3 2 3 7 8\n','3')],
 'D':[('0\n','0'),('2\n1 2\n2 3\n','1'),('3\n1 5\n2 4\n4 6\n','2')],
 'E':('10 4 2\n1 3 5 7\n1 5\n3 7\n','2'),
 'F':(('........\n'*8),'92'),
 'G':('3 2\n2 1 2\n2 2 3\n','1'),
 'I':('1\n5 3\n1 2 8 4 9\n','3'),
 'J':('5 3\n2 4 7 3 5\n','8'),
 'K':('7 20\n2 6 4 3 6 8 9\n','4'),
 'L':('4 8\n2 7 5 1\n','4 2'),
 'M':('5\n3 2 7 4 1\n','1'),
 'N':('aab\n','3\naab\naba\nbaa'),
 'O':('3 5 6 1\n1 2 3\n','2')}
 for name,cases in original_tests.items():
  if isinstance(cases,tuple):cases=[cases]
  for data,expected in cases:
   actual=run(name,data,'hw2-original');assert actual==expected,(name,expected,actual)
  result['testes_originais'][name]={'casos':len(cases),'resultado':'todos passaram; testes de execução sob hipóteses documentadas'}
 # Sum of Three Values: aceita qualquer trio válido de índices distintos.
 triples=[([1,2,2,2,5],6),([2,7,5,1],8),([1],3),([1,2],3),([2,2,2],6),
          ([1000000000,1000000000,1000000000],1000000000)]
 triple_rng=random.Random(1641)
 for _ in range(70):
  triples.append(([triple_rng.randrange(1,21) for _ in range(triple_rng.randrange(1,11))],triple_rng.randrange(1,61)))
 for a,x in triples:
  possible=any(sum(a[i] for i in ids)==x for ids in itertools.combinations(range(len(a)),3))
  output=run('soma_tres_valores',f'{len(a)} {x}\n'+' '.join(map(str,a))+'\n')
  if output=='IMPOSSIBLE':assert not possible,(a,x,output)
  else:
   ids=[int(s)-1 for s in output.split()]
   assert len(ids)==3 and len(set(ids))==3 and all(0<=i<len(a) for i in ids),(a,x,output)
   assert sum(a[i] for i in ids)==x,(a,x,output)
 maximum='5000 1000000000\n'+' '.join(['1']*5000)+'\n'
 assert run('soma_tres_valores',maximum)=='IMPOSSIBLE'
 result['testes_templates']['soma_tres_valores']=len(triples)+1

 # Contest 2/F: hipótese inferida do código, sem enunciado oficial disponível.
 # Conta positivos até N cuja quantidade de dígitos decimais é ímpar.
 def odd_digit_count(n):
  return sum(max(0,min(n,10**digits-1)-10**(digits-1)+1) for digits in range(1,20,2))
 numbers={0,1,8,9,10,11,99,100,101,999,1000,9999,10000,2**63-1}
 for power in range(1,19):numbers.update([10**power-1,10**power,10**power+1])
 numbers=sorted(numbers)
 data=str(len(numbers))+'\n'+'\n'.join(map(str,numbers))+'\n'
 actual=run('F',data,'contest2-original')
 assert actual=='\n'.join(str(odd_digit_count(n)) for n in numbers),actual
 result['testes_originais']['contest2/F']={'casos':len(numbers),'resultado':'passaram sob hipótese: contagem de números positivos com quantidade ímpar de dígitos, 0<=N<=LLONG_MAX'}

 # Contest 2/H: hipótese de valores 1/2; dois blocos adjacentes de mesmo tamanho.
 arrays=[[1],[1,1,1],[1,2],[1,1,2,2],[1,2,1,2,1]]
 contest_rng=random.Random(1138)
 for _ in range(80):arrays.append([contest_rng.randrange(1,3) for _ in range(contest_rng.randrange(1,20))])
 for a in arrays:
  expected=0
  for start in range(len(a)):
   for k in range(1,(len(a)-start)//2+1):
    first=a[start:start+k];second=a[start+k:start+2*k]
    if len(set(first))==len(set(second))==1 and first[0]!=second[0]:expected=max(expected,2*k)
  actual=run('H',str(len(a))+'\n'+' '.join(map(str,a))+'\n','contest2-original')
  assert actual==str(expected),(a,expected,actual)
 result['testes_originais']['contest2/H']={'casos':len(arrays),'resultado':'passaram sob hipótese: n>=1 e valores 1/2; dois blocos consecutivos de igual tamanho'}
 result['testes_originais']['contest3/H']={'casos':0,'resultado':'não executado: rascunho original incompleto, falha de compilação esperada'}
 # Saída estruturada permite reproduzir contagens e avisos.
 # Escapes Unicode mantêm o JSON válido ao redirecionar consoles Windows.
 print(json.dumps(result,ensure_ascii=True,indent=2))
