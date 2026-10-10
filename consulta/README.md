# Consulta de contest · encontre pela função ou pela ideia

[Início](../README.md) · [Funções A–Z](funcoes/README.md) · [Algoritmos](algoritmos.md) · [Templates completos](templates.md)

Use `Ctrl+F` (`Cmd+F` no Mac) nesta página para procurar o **nome em C++**, uma **palavra em português** ou uma **pista do problema**. Siga o link para a sintaxe, o retorno e um exemplo. A busca do navegador cobre somente a página aberta.

> **Bounds em 10 segundos:** ordene com o mesmo comparador.<br>
> [`lower_bound(begin,end,x)`](funcoes/lower_bound.md) → iterador do primeiro **>=x**.<br>
> [`upper_bound(begin,end,x)`](funcoes/upper_bound.md) → iterador do primeiro **>x**.<br>
> No vector, `it-begin` dá o índice; `upper-lower` conta iguais. Confira `it!=end()` antes de ler `*it`.

## O que preciso fazer? · índice por palavras-chave

| Objetivo / palavras-chave para buscar | Consulta |
|---|---|
| lower_bound, lower bound, limite inferior, primeiro maior ou igual, >=, posição, índice, inserir ordenado, predecessor <x | [lower_bound](funcoes/lower_bound.md) |
| upper_bound, upper bound, limite superior, primeiro maior que, >, último menor ou igual, predecessor <=x | [upper_bound](funcoes/upper_bound.md) |
| duplicatas, ocorrências, frequência em vetor ordenado, quantidade igual a x, intervalo [L,R], limites abertos/fechados | [Contagem com bounds](funcoes/upper_bound.md) |
| binary_search, binary search, busca binária em vetor, existe, presença, bool | [binary_search](funcoes/binary_search.md) |
| sort, stable_sort, ordenar, crescente, decrescente, empate, comparador, comparator, lambda, pair, índice original | [Ordenação](funcoes/sort.md) |
| unique, erase, remove, remove_if, deduplicar, apagar repetidos, fim lógico, filtrar valor, erase remove idiom | [unique / remove + erase](funcoes/unique_erase.md) |
| next_permutation, prev_permutation, permutation, permutação, anagrama, lexicográfica, todas as ordens, fatorial | [Permutações](funcoes/next_permutation.md) |
| accumulate, total, somatório, somar vetor, numeric, 0LL, long long, overflow | [accumulate](funcoes/accumulate.md) |
| min, max, min_element, max_element, minmax_element, extremos, menor/maior valor ou posição | [Mínimo e máximo](funcoes/min_max.md) |
| find, count, count_if, busca linear, contar ocorrências, reverse, inverter, palíndromo | [Busca, contagem e inversão](funcoes/find_count_reverse.md) |
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
| cin, cout, getline, linha inteira, espaços, ws, ignore, EOF, entrada, saída | [Leitura e escrita](funcoes/entrada_tipos_funcoes.md#cin-cout) |
| int, long long, 1LL, 0LL, overflow, double, cast, divisão inteira, resto % | [Tipos e contas](funcoes/entrada_tipos_funcoes.md#tipos-overflow) |
| função, function, parâmetros, assinatura, return, void, referência, const, auto, lambda, captura | [Funções e parâmetros](funcoes/entrada_tipos_funcoes.md#funcoes) |
| gcd, lcm, MDC, MMC, abs, swap, sqrt, pow, floor, ceil, potência, arredondar | [Funções numéricas](funcoes/entrada_tipos_funcoes.md#funcoes-uteis) |
| prefix sum, prefixos, soma acumulada, range sum, soma de intervalo [l,r] | [Prefix sum](algoritmos.md#prefix-sum) |
| subarray sum, contar segmentos, soma exata, negativos, prefix sum map, frequência de prefixos | [Prefixos + map](algoritmos.md#prefixos-map) |
| sliding window, janela fixa, tamanho k, fixed window, distintos | [Janela fixa](algoritmos.md#janela-fixa) |
| sliding window, janela variável, maior segmento, longest subarray, soma limitada, expandir/encolher | [Janela variável](algoritmos.md#janela-variavel) |
| two pointers, dois ponteiros, duas pontas, two sum, pair sum, soma alvo, índices originais | [Two pointers: par](algoritmos.md#two-pointers) |
| sweep line, varredura, eventos, intervalos ativos, cobertura, sobreposição, entrada/saída, aberto/fechado | [Sweep line](algoritmos.md#sweep-line) |
| binary search on answer, busca binária na resposta, first true, menor tempo/capacidade, minimizar maior soma | [Busca do mínimo viável](algoritmos.md#busca-minimo) |
| last true, maior distância, maximizar mínimo, aggressive cows, espaçamento | [Busca do máximo viável](algoritmos.md#busca-maximo) |
| bitmask, máscara de bits, subset, subconjunto, 2^n, força bruta, todas as escolhas, entra/não entra | [Bitmask](algoritmos.md#bitmask) |
| recursion, recursão, backtracking, DFS, poda, escolher/desfazer, Sudoku, rainhas | [Backtracking](algoritmos.md#backtracking) |
| monotonic stack, pilha monotônica, menor anterior, nearest smaller, próximo maior | [Pilha monotônica](algoritmos.md#pilha-monotonica) |
| coordinate compression, compressão, discretização, rank, coordenadas grandes, sort unique lower_bound | [Compressão](algoritmos.md#compressao) |
| greedy, guloso, min-heap, Potions, vida não negativa, aceitar/descartar pior, selecionar máximo | [Greedy + heap](algoritmos.md#greedy-heap) |

## Pegadinhas que mais custam tempo

| Lembrete | Onde conferir |
|---|---|
| Iterador não é valor; `end()` não pode ser lido | [lower_bound](funcoes/lower_bound.md) |
| `pop()` remove e retorna void; copie o topo antes | [Stack, queue e heap](funcoes/pilha_fila_heap.md) |
| `map[x]` insere; `.find(x)` só consulta | [Map](funcoes/map_set.md#map) |
| `erase(valor)` no multiset apaga todas as cópias | [Erase](funcoes/map_set.md#erase) |
| `reserve` não cria elementos; `resize` cria | [Vector](funcoes/vector_string.md#reserve-resize) |
| `unique` não reduz size; falta erase | [Duplicatas](funcoes/unique_erase.md) |
| `0LL`/`1LL` precisam estar no início da conta | [Overflow](funcoes/entrada_tipos_funcoes.md#tipos-overflow) |
| Janela variável por soma exige não negativos nesta receita | [Janela](algoritmos.md#janela-variavel) |
| Pontas abertas/fechadas mudam os empates dos eventos | [Sweep](algoritmos.md#sweep-line) |
| Busca na resposta exige prova de monotonicidade | [Busca mínimo/máximo](algoritmos.md#busca-binaria) |

## Para estudar, executar e imprimir

[17 templates C++17](templates.md) · [Semana 1 completa](../semana-1/README.md) · [Homework 2 completo](../homework-2/README.md)

PDFs por semana: [primeira semana](../guias/consulta-rapida.pdf) · [segunda semana](../homework-2/guias/consulta-rapida.pdf). São as consultas das respectivas semanas; as páginas acima reúnem a navegação e os exemplos detalhados mais recentes.
