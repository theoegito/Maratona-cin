# Guia explicado - Homework 2

[Início](../../README.md) · [Homework 2](../README.md) · [Consulta de contest](../../consulta/README.md) · [Funções A–Z](../../consulta/funcoes/README.md)

Os exemplos completos estão em ../templates/. Custos e hipóteses fazem parte de cada receita.

## Índice

1. [sort e comparadores](#tema-1)
2. [lower_bound e upper_bound](#tema-2)
3. [next_permutation](#tema-3)
4. [two pointers](#tema-4)
5. [sliding window](#tema-5)
6. [sweep line](#tema-6)
7. [binary search na resposta](#tema-7)
8. [bitmask](#tema-8)
9. [recursão e backtracking](#tema-9)

<a id="tema-1"></a>
## 1. sort e comparadores

**Fonte e escopo:** Oficial: aula 1.

**Gatilho:** A ordem atual atrapalha parear, agrupar, achar vizinhos ou buscar? Ordenar costuma revelar a estrutura.

`sort(v.begin(),v.end())` ordena em O(n log n) no pior caso em C++17. `sort(v.rbegin(),v.rend())` inverte a ordem. Para manter índices, use `pair<valor,indice>`. Pair e tuple comparam lexicograficamente: primeiro campo, depois os seguintes. `stable_sort` mantém a ordem relativa dos elementos equivalentes; pode custar O(n log² n) sem memória auxiliar.

Um comparador precisa estabelecer ordem estrita: `a < b`, nunca `a <= b`. Deve ser consistente e transitivo; `cmp(a,a)` é false. Ordenar por concatenação `a+b < b+a` é uma estratégia específica, não uma regra para qualquer problema. Para deduplicar: sort e depois `v.erase(unique(v.begin(),v.end()),v.end())`. Unique compacta repetições consecutivas e retorna o novo fim lógico; não reduz sozinho o tamanho e não exige ordenação se só se deseja remover duplicatas consecutivas.

**Salva na prova:** ordene dados associados juntos; ordenar só os valores perde os índices. **Pegadinha:** ordenar uma sequência pode destruir a contiguidade original exigida pelo problema.

<a id="tema-2"></a>
## 2. lower_bound e upper_bound

**Fonte e escopo:** Oficial: aulas 1 e 2.

**Gatilho:** Muitas consultas de quantidade, posição, primeiro >= ou primeiro > em uma lista estática.

Em vetor ordenado, lower_bound(x) aponta para o primeiro valor >= x; upper_bound(x), para o primeiro > x. O intervalo [lower,upper) contém exatamente as ocorrências de x. `auto i = lower_bound(v.begin(),v.end(),x)-v.begin();` devolve um índice, inclusive n se não existe resposta. Confira `it != v.end()` antes de desreferenciar.

Para [L,R] fechado, quantidade = upper_bound(R)-lower_bound(L). Para (L,R), use lower_bound(R)-upper_bound(L), com L<R. Para existência, `binary_search` devolve bool. Custo: ordenação O(n log n), depois O(log n) por busca no vector. As funções retornam **iteradores**, não necessariamente ponteiros.

**Salva na prova:** bounds contam valores com duplicatas sem percorrer todos. **Pegadinha:** use `s.lower_bound(x)` em set/map. O algoritmo genérico faz O(log n) comparações, mas pode avançar iteradores em O(n). Ordem e comparador precisam ser os mesmos da busca.

<a id="tema-3"></a>
## 3. next_permutation

**Fonte e escopo:** Oficial: aula 1; aplicado no original N.

**Gatilho:** Gerar todas as ordens distintas; n pequeno ou tamanho da saída inevitavelmente grande.

Comece ordenando. Use `do { processar(); } while(next_permutation(v.begin(),v.end()));` para incluir a primeira configuração. A função muda a sequência para a próxima ordem lexicográfica e retorna true. Ao retornar false, rearranja para a menor ordem. Partindo da ordenação, valores iguais produzem permutações distintas sem duplicação.

Uma chamada custa O(n); enumerar e imprimir P permutações custa O(nP), com P<=n!. Para multiplicidades c_i, P=n!/produto(c_i!). Guardar todas custa O(nP) em memória; imprimir diretamente usa O(n) de estado, quando o formato permite.

**Salva na prova:** enumere para construir uma referência de testes pequenos. **Pegadinha:** começar desordenado deixa de visitar ordens anteriores; usar while sem do ignora a configuração inicial.

<a id="tema-4"></a>
## 4. two pointers

**Fonte e escopo:** Oficial: aula 2; pares como extra de aplicação no original L.

**Gatilho:** Pares em lista ordenada ou intervalo cuja validade muda de forma previsível ao mover as pontas.

Para soma de dois valores em ordem crescente: l=0, r=n-1. Se a soma for pequena, aumente l; se grande, reduza r; se igual, achou. Essa escolha elimina uma linha/coluna de possibilidades porque os valores estão ordenados. Exija l<r para usar elementos distintos. Guarde índices antes de ordenar.

Ordenar custa O(n log n); a varredura custa O(n), pois cada ponteiro percorre no máximo n posições. Valores negativos não impedem esse algoritmo de pares em lista ordenada. Isso é diferente da janela por soma da próxima seção.

**Salva na prova:** definir o que cada ponteiro elimina é uma prova curta de correção. **Pegadinha:** índice na lista ordenada não é índice original; não confunda par com segmento contíguo.

<a id="tema-5"></a>
## 5. sliding window

**Fonte e escopo:** Oficial: two pointers da aula 2; janela fixa e frequências retomam a primeira semana.

**Gatilho:** Maior segmento contínuo válido; retirar pela esquerda nunca piora a propriedade.

Para valores não negativos e limite S>=0: adicione a[r]; enquanto soma>S, retire a[l++] ; atualize o tamanho r-l+1. Invariante: depois de encolher, [l,r] é válido e l é a menor fronteira válida para esse r. Cada elemento entra e sai uma vez: O(n), além da memória dos dados.

Com negativos, soma pode diminuir ao expandir. Exemplo [4,-3], S=2: descartar 4 prematuramente perde o segmento inteiro válido. Para soma exatamente K com negativos, use prefixos e frequências da semana 1; não assuma que essa receita resolve maior segmento com soma <=K. Para janela fixa de k itens, remova a[r-k]; com mapa de frequências, erase só quando a contagem zera. Custo O(n log d) com map e d valores distintos.

**Salva na prova:** quando todos os comprimentos menores são válidos, adicionar r-l+1 pode contar segmentos terminando em r; prove essa propriedade antes. **Pegadinha:** limite negativo pode esvaziar a janela e ainda violar a condição; use pré-condições explícitas ou um algoritmo adequado.

<a id="tema-6"></a>
## 6. sweep line

**Fonte e escopo:** Oficial: aula 2; cuidado de fronteiras esclarecido.

**Gatilho:** Muitos intervalos e consultas: quantos estão ativos em cada coordenada?

Transforme cada intervalo em eventos de entrada +1 e saída -1. Ordene os eventos e consultas e mantenha ativos. A ordem em coordenadas iguais depende da definição do intervalo. Para [l,r): saída, entrada, consulta (intervalos vazios devem ser descartados). Para [l,r]: entrada, consulta, saída. Para (l,r): saída, consulta, entrada; se l=r, descarte o intervalo vazio. Custo O((n+q) log(n+q)), memória O(n+q).

Alternativa para intervalos fechados: ordene inícios e fins separadamente. Em x: `upper_bound(inicios,x)-lower_bound(fins,x)` = entradas <=x menos saídas <x. Para abertos, entradas <x menos saídas <=x, após descartar vazios. Para semiabertos [l,r), entradas <=x menos saídas <=x. O original E usa intervalos fechados e paridade da cobertura.

Em coordenadas inteiras pequenas, vetor de diferenças pode ser mais simples; em coordenadas grandes, eventos são uma alternativa adicional; compressão também aparece oficialmente na aula 2. Evite r+1 sem verificar overflow.

**Salva na prova:** empates de coordenadas são parte do algoritmo. **Pegadinha oficial:** a aula enuncia intervalos abertos; não copie uma implementação de fechados sem adaptar as fronteiras.

<a id="tema-7"></a>
## 7. binary search na resposta

**Fonte e escopo:** Oficial: aula 2 (Factory Machines).

**Gatilho:** Menor capacidade/tempo que funciona, ou maior distância que ainda funciona; decisão mais fácil que otimização.

Defina `ok(x)` e prove monotonicidade. Para mínimo: false false true true; se ok(mid), hi=mid, senão lo=mid+1. Comece com lo<=resposta<=hi e hi viável. Use `mid=lo+(hi-lo)/2` para limites não negativos cuja diferença cabe no tipo. O número de passos é O(log amplitude); multiplique pelo custo do predicado.

Factory Machines: ok(t) verifica soma floor(t/a_i)>=alvo. Pare ao atingir o alvo e sature a soma para evitar overflow. Todos os tempos de máquina devem ser positivos. Um limite superior conhecido viável pode ser min(a)*alvo, mas só calcule se couber no tipo; dobrar também exige checar overflow.

Dividir vetor não negativo em até k grupos (J): lo=max(a), hi=sum(a). Percorra e abra grupo ao ultrapassar capacidade. O greedy usa o mínimo de grupos para aquela capacidade. Funciona para k>=1, n>=1; para exatamente k grupos, a equivalência exige k<=n e possibilidade de subdividir. Negativos invalidam essa prova.

Para maximizar distância (I), ok(d) é true true false false. Um greedy coloca a primeira vaca e as seguintes no primeiro local a distância >=d. Percorra índices crescentes, sem reutilizar posição quando d=0. Uma busca com limites inclusivos e resposta guardada funciona; não misture suas atualizações com a variante hi=mid.

**Salva na prova:** escreva na margem a sequência F...F T...T ou T...T F...F. **Pegadinha:** monotonicidade precisa ser demonstrada; uma função qualquer não pode ser resolvida por busca binária.

<a id="tema-8"></a>
## 8. bitmask

**Fonte e escopo:** Oficial: aula 2, slide 47 (Subconjuntos); aplicado em G, M e O.

**Gatilho:** Cada item entra ou não entra, n pequeno; explorar todos os subconjuntos.

O bit j representa a presença do item j. Teste `(mask & (1ULL<<j)) != 0`; ligue com OR, desligue com AND do complemento, alterne com XOR. Para enumerar, `for(uint64_t mask=0; mask<(1ULL<<n); ++mask)`. Use n<64 para evitar deslocamento inválido, mas a viabilidade de O(n 2^n) normalmente exige n muito menor, por exemplo perto de 20 conforme o custo. A máscara vazia faz parte do conjunto de subconjuntos; exclua-a apenas se o problema exigir.

M: diferença dos dois grupos = abs(total-2*somaEscolhida), com contas que caibam em long long. G: união dos conjuntos selecionados; a quantidade de bits é o número de conjuntos, não o universo coberto. O: controle quantidade, soma, mínimo e máximo; só use min/max quando o subconjunto não estiver vazio.

**Salva na prova:** máscaras são uma referência simples contra soluções mais rápidas em casos pequenos. **Pegadinha:** `1<<n` desloca int mesmo se a variável destino for long long. `__builtin_popcountll` é extensão GNU, não função ISO C++17.

<a id="tema-9"></a>
## 9. recursão e backtracking

**Fonte e escopo:** Oficial: aula 2.

**Gatilho:** Gerar todas as soluções, verificar possibilidades sob restrições; espaço de busca pequeno ou podável.

Defina estado (informações para continuar), transições (escolhas), caso base e poda. Receita: validar escolha → fazer → chamar recursivamente → desfazer. Restaurar o estado exatamente permite explorar a próxima escolha sem contaminar os outros ramos. Passar o mesmo vetor por referência evita cópias, mas exige desfazer; parâmetros escalares por valor já isolam o ramo.

Oito rainhas (F): linha atual, colunas e diagonais ocupadas; diagonais linha+coluna e linha-coluna+7. Cada linha recebe uma rainha; podar coluna/diagonal usada e obstáculo. O template generaliza para n pequeno e tabuleiro com . e *. Não use recursão profunda em entrada enorme sem considerar limite da pilha.

Subset sum tem 2^n folhas e 2^(n+1)-1 nós na árvore completa, O(2^n) com transições O(1); imprimir cada subconjunto acrescenta custo proporcional ao tamanho. Poda soma>alvo só é segura quando nenhum valor restante pode reduzir a soma. O template de subset sum permite negativos e por isso não usa essa poda.

**Salva na prova:** pré-calcule restrições para validar em O(1); pare cedo se só precisa de existência. **Pegadinha:** ao retornar cedo depois de marcar estado compartilhado, restaure-o antes se outros ramos ainda serão explorados.

## Plano para uma questão travada

1. Leia limites e formato. Estime tempo e memória; 10^8 operações/s é só heurística da aula, não garantia.
2. Faça exemplos mínimos, repetidos e extremos. Escreva o que a resposta representa.
3. Procure ordenação, monotonicidade, contiguidade ou escolhas binárias.
4. Escreva invariante/pré-condição antes de adaptar um template.
5. Compare com força bruta em entradas pequenas. Confira overflow, fronteiras e formato.

## Precisões em relação aos slides

O guia esclarece simplificações: bounds retornam iteradores; sort C++17 tem O(n log n) no pior caso; unique só exige duplicatas consecutivas para compactar, e não move necessariamente todas as duplicatas para o fim; next_permutation custa O(n) por chamada e enumerar pode custar O(n*n!); a árvore binária completa tem 2^(n+1)-1 nós. O uso de '\n' não garante que toda a saída só apareça no fim: apenas não solicita flush como endl. Esses esclarecimentos complementam a aula sem alterar os PDFs.

## Compressão de coordenadas - oficial, aula 2

Quando as coordenadas são grandes, ordene e deduplique os valores relevantes; um índice de lower_bound representa a posição comprimida. A técnica conserva ordem e igualdade, não distância. Para consultas offline, inclua as coordenadas das consultas ou procure a posição correta com bounds. Há ligação com sweep: representar eventos em uma estrutura pequena, mas o comprimento entre dois índices depende da diferença das coordenadas originais.

## Revisão da primeira semana

A pilha monotônica e as demais lacunas oficiais estão no [complemento](../../guias/complemento-semana-1.md), com template adicional validado junto a este homework.
