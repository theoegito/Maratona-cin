# Consulta de contest · funções, sintaxe e significado

[Catálogo de funções](funcoes/README.md) · [Início](../README.md) · [Semanas](../semanas/README.md) · [Escolher uma solução](como-escolher.md) · [Algoritmos por semana](algoritmos.md) · [Templates completos](templates.md)

Use `Ctrl+F` (`Cmd+F` no Mac) nesta página para procurar o **nome em C++**, uma **palavra em português** ou uma **pista do problema**. Siga o link para a sintaxe, o retorno e um exemplo. A busca do navegador cobre somente a página aberta.

> **Entenda a chamada antes de usar:** confira os parâmetros, o que muda nos dados e o tipo do retorno.<br>
> `find` pode retornar iterador ou índice; `pop` retorna `void`; `substr` cria outra string.<br>
> O [catálogo de funções](funcoes/README.md) compara as chamadas e aponta os exemplos completos.

## Funções por categoria

[Entrada, tipos e parâmetros](funcoes/entrada_tipos_funcoes.md) · [Vector/string](funcoes/vector_string.md) · [Map/set](funcoes/map_set.md) · [Pilha/fila/heap](funcoes/pilha_fila_heap.md) · [Algoritmos STL e numéricos](funcoes/README.md)

[Pair/tuple e índices](funcoes/pair_tuple.md) · [Iteradores e retornos](funcoes/iteradores.md) · [Escolher pela restrição e pelo objetivo](como-escolher.md)

## O que preciso fazer? · índice por palavras-chave

| Objetivo / palavras-chave para buscar | Consulta |
|---|---|
| cin, cout, getline, linha inteira, espaços, ws, ignore, EOF, entrada, saída | [Leitura e escrita](funcoes/entrada_tipos_funcoes.md#cin-cout) |
| int, long long, 1LL, 0LL, overflow, double, cast, divisão inteira, resto % | [Tipos e contas](funcoes/entrada_tipos_funcoes.md#tipos-overflow) |
| função, function, parâmetros, assinatura, return, void, referência, const, auto, lambda, captura | [Funções e parâmetros](funcoes/entrada_tipos_funcoes.md#funcoes) |
| pair, tuple, first, second, make_pair, get, tie, dados agrupados, índices originais, ordem lexicográfica | [Pair e tuple](funcoes/pair_tuple.md) |
| iterator, iterador, begin, end, rbegin, rend, distance, prev, next, desreferenciar, invalidação, valor ou posição | [Iteradores](funcoes/iteradores.md) |
| vector, vetor, push_back, pop_back, insert, erase, begin, end, size, empty, acesso por índice | [Vector](funcoes/vector_string.md#vector) |
| reserve, resize, capacity, reservar espaço, criar elementos, tamanho, realocação | [reserve × resize](funcoes/vector_string.md#reserve-resize) |
| string, texto, caractere, find, npos, substr, substring, recortar, comprimento | [String](funcoes/vector_string.md#string) |
| map, mapa, dictionary, dicionário, chave, frequência, find, count, operator[], inserir sem querer | [Map](funcoes/map_set.md#map) |
| set, conjunto, distintos, multiset, repetidos, erase uma ocorrência, vizinho menor/maior, bounds | [Set / multiset](funcoes/map_set.md#set) |
| unordered_map, hash, O(1) médio, busca exata, rehash | [Hash map](funcoes/map_set.md#unordered-map) |
| stack, pilha, LIFO, último entra/primeiro sai, top, push, pop | [Stack](funcoes/pilha_fila_heap.md#stack) |
| queue, fila, FIFO, primeiro entra/primeiro sai, front, back, push, pop, BFS | [Queue](funcoes/pilha_fila_heap.md#queue) |
| deque, duas pontas, push_front, push_back, pop_front, pop_back | [Deque](funcoes/pilha_fila_heap.md#deque) |
| priority_queue, heap, prioridade, top, min heap, max heap, menor/maior, greater | [Heap](funcoes/pilha_fila_heap.md#priority-queue) |
| sort, stable_sort, ordenar, crescente, decrescente, empate, comparador, comparator, lambda, pair, índice original | [Ordenação](funcoes/sort.md) |
| find, count, count_if, busca linear, contar ocorrências, reverse, inverter, palíndromo | [Busca, contagem e inversão](funcoes/find_count_reverse.md) |
| unique, erase, remove, remove_if, deduplicar, apagar repetidos, fim lógico, filtrar valor, erase remove idiom | [unique / remove + erase](funcoes/unique_erase.md) |
| next_permutation, prev_permutation, permutation, permutação, anagrama, lexicográfica, todas as ordens, fatorial | [Permutações](funcoes/next_permutation.md) |
| lower_bound, lower bound, limite inferior, primeiro maior ou igual, >=, posição, índice, inserir ordenado, predecessor <x | [lower_bound](funcoes/lower_bound.md) |
| upper_bound, upper bound, limite superior, primeiro maior que, >, último menor ou igual, predecessor <=x | [upper_bound](funcoes/upper_bound.md) |
| duplicatas, ocorrências, frequência em vetor ordenado, quantidade igual a x, intervalo [L,R], limites abertos/fechados | [Contagem com bounds](funcoes/upper_bound.md) |
| binary_search, binary search, busca binária em vetor, existe, presença, bool | [binary_search](funcoes/binary_search.md) |
| accumulate, total, somatório, somar vetor, numeric, 0LL, long long, overflow | [accumulate](funcoes/accumulate.md) |
| min, max, min_element, max_element, minmax_element, extremos, menor/maior valor ou posição | [Mínimo e máximo](funcoes/min_max.md) |
| gcd, lcm, MDC, MMC, abs, swap, sqrt, pow, floor, ceil, potência, arredondar | [Funções numéricas](funcoes/entrada_tipos_funcoes.md#funcoes-uteis) |
| prefix sum, prefixos, soma acumulada, range sum, soma de intervalo [l,r] | [Prefix sum](../semanas/semana-1-stl-prefix-sum/aula/algoritmos.md#prefix-sum) |
| subarray sum, contar segmentos, soma exata, negativos, prefix sum map, frequência de prefixos | [Prefixos + map](../semanas/semana-1-stl-prefix-sum/aula/algoritmos.md#prefixos-map) |
| sliding window, janela fixa, tamanho k, fixed window, distintos | [Janela fixa](../semanas/semana-1-stl-prefix-sum/aula/algoritmos.md#janela-fixa) |
| sliding window, janela variável, maior segmento, longest subarray, soma limitada, expandir/encolher | [Janela variável](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#janela-variavel) |
| two pointers, dois ponteiros, duas pontas, two sum, pair sum, soma alvo, índices originais | [Two pointers: par](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#two-pointers) |
| sweep line, varredura, eventos, intervalos ativos, cobertura, sobreposição, entrada/saída, aberto/fechado | [Sweep line](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#sweep-line) |
| binary search on answer, busca binária na resposta, first true, menor tempo/capacidade, minimizar maior soma | [Busca do mínimo viável](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#busca-minimo) |
| last true, maior distância, maximizar mínimo, aggressive cows, espaçamento | [Busca do máximo viável](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#busca-maximo) |
| bitmask, máscara de bits, subset, subconjunto, 2^n, força bruta, todas as escolhas, entra/não entra | [Bitmask](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#bitmask) |
| recursion, recursão, backtracking, DFS, poda, escolher/desfazer, Sudoku, rainhas | [Backtracking](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#backtracking) |
| monotonic stack, pilha monotônica, menor anterior, nearest smaller, próximo maior | [Pilha monotônica](../semanas/semana-1-stl-prefix-sum/aula/algoritmos.md#pilha-monotonica) |
| coordinate compression, compressão, discretização, rank, coordenadas grandes, sort unique lower_bound | [Compressão](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#compressao) |
| greedy, guloso, min-heap, Potions, vida não negativa, aceitar/descartar pior, selecionar máximo | [Greedy + heap](../semanas/semana-1-stl-prefix-sum/aula/algoritmos.md#greedy-heap) |

## Pegadinhas que mais custam tempo

| Lembrete | Onde conferir |
|---|---|
| Iterador não é valor; `end()` não pode ser lido | [Busca com iterador](funcoes/find_count_reverse.md) |
| `pop()` remove e retorna void; copie o topo antes | [Stack, queue e heap](funcoes/pilha_fila_heap.md) |
| `map[x]` insere; `.find(x)` só consulta | [Map](funcoes/map_set.md#map) |
| `erase(valor)` no multiset apaga todas as cópias | [Erase](funcoes/map_set.md#erase) |
| `reserve` não cria elementos; `resize` cria | [Vector](funcoes/vector_string.md#reserve-resize) |
| `unique` não reduz size; falta erase | [Duplicatas](funcoes/unique_erase.md) |
| `0LL`/`1LL` precisam estar no início da conta | [Overflow](funcoes/entrada_tipos_funcoes.md#tipos-overflow) |
| Janela variável por soma exige não negativos nesta receita | [Janela](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#janela-variavel) |
| Pontas abertas/fechadas mudam os empates dos eventos | [Sweep](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#sweep-line) |
| Busca na resposta exige prova de monotonicidade | [Busca mínimo/máximo](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#busca-binaria) |

## Para estudar, executar e imprimir

[18 templates C++17](templates.md) · [Semana 1 completa](../semanas/semana-1-stl-prefix-sum/README.md) · [Semana 2 completa](../semanas/semana-2-buscas-backtracking/README.md)

PDFs por semana: [primeira semana](../semanas/semana-1-stl-prefix-sum/aula/consulta-rapida.pdf) · [segunda semana](../semanas/semana-2-buscas-backtracking/aula/consulta-rapida.pdf). São as consultas das respectivas semanas; as páginas acima reúnem a navegação e os exemplos detalhados mais recentes.
