"""Execute com Python 3 e GCC no PATH, a partir de qualquer diretório.
Executáveis e logs ficam no diretório temporário do sistema; originais nunca são editados.
"""
from pathlib import Path
import hashlib,itertools,json,random,subprocess,tempfile,bisect,contextlib,os
base=Path(__file__).resolve().parents[1]
result={'integridade':[], 'compilacao':[], 'testes_templates':{}, 'testes_originais':{}}
manifest=json.loads((base/'verificacao/originais.json').read_text())
for item in manifest:
 p=base/item['arquivo']; ok=hashlib.sha256(p.read_bytes()).hexdigest()==item['sha256']
 result['integridade'].append({'arquivo':item['arquivo'],'ok':ok});assert ok,p
rng=random.Random(20261010)
build=Path(os.environ.get('MARATONA_BUILD_DIR',str(Path(tempfile.gettempdir())/'maratona-hw2-build')))
build.mkdir(parents=True,exist_ok=True)
with contextlib.nullcontext(str(build)) as folder:
 executables={}
 for group,path in [('hw2-original',base/'solucoes'),('hw2-template',base/'templates'),('semana1-original',base.parent/'solucoes'),('semana1-template',base.parent/'templates')]:
  for src in sorted(path.glob('*.cpp')):
   exe=Path(folder)/(group+'-'+src.stem+'.exe')
   cmd=['g++','-std=c++17','-O2','-Wall','-Wextra']
   if 'template' in group:cmd+=['-pedantic']
   proc=subprocess.run(cmd+[str(src),'-o',str(exe)],capture_output=True,text=True)
   result['compilacao'].append({'grupo':group,'arquivo':src.name,'codigo':proc.returncode,'avisos':proc.stderr})
   assert proc.returncode==0,(src,proc.stderr)
   executables[(group,src.stem)]=exe
 def run(name,data,group='hw2-template'):
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
 # Saída estruturada permite reproduzir contagens e avisos.
 print(json.dumps(result,ensure_ascii=False,indent=2))
