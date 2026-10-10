# Funções C++17 · catálogo A–Z

[Início](../../README.md) · [Consulta por palavras-chave](../README.md) · [Algoritmos](../algoritmos.md) · [Templates](../templates.md)

Procure o nome com `Ctrl+F`/`Cmd+F`. O mesmo nome pode ter semântica diferente conforme o tipo: `std::find` retorna iterador, `string::find` retorna índice; `vector::erase` recebe iterador, `multiset::erase(valor)` apaga todas as cópias.

> **Mais procuradas:** [lower_bound: primeiro >=](lower_bound.md) · [upper_bound: primeiro >](upper_bound.md) · [sort](sort.md) · [map.find](map_set.md#map-find) · [min-heap](pilha_fila_heap.md#min-heap)

## Função, retorno e significado

| Nome / sintaxe abreviada | Significado / retorno | Referência |
|---|---|---|
| `abs(x)` | Valor absoluto; precisa caber no tipo | [Numéricas](entrada_tipos_funcoes.md#funcoes-uteis) |
| `accumulate(first,last,0LL)` | Soma; tipo do inicial define acumulador | [accumulate](accumulate.md) |
| `at(i)` / `map.at(chave)` | Referência com verificação; pode lançar exceção | [Vector](vector_string.md#vector) / [map](map_set.md#map) |
| `auto`, `auto&`, `const auto&` | Deduz tipo; cópia / referência / leitura | [Referências](entrada_tipos_funcoes.md#referencias-auto) |
| `back()` | Referência ao último, exige não vazio | [Vector/string](vector_string.md) / [fila/deque](pilha_fila_heap.md#queue) |
| `begin()` / `end()` | Iteradores; end é após o último | [Vector](vector_string.md#vector) |
| `binary_search(first,last,x)` | bool: existe em faixa ordenada | [binary_search](binary_search.md) |
| `capacity()` | Espaço reservado; não é quantidade de elementos | [reserve/resize](vector_string.md#reserve-resize) |
| `ceil(x)` / `floor(x)` | Arredondamento; resultado flutuante | [Numéricas](entrada_tipos_funcoes.md#funcoes-uteis) |
| `cin >> x` / `cout << x` | Leitura de token / escrita; stream | [Entrada/saída](entrada_tipos_funcoes.md#cin-cout) |
| `clear()` | Apaga todos os elementos; void | [Vector](vector_string.md#vector-erase) |
| `const`, parâmetros `&` | Referência para leitura / alteração | [Funções](entrada_tipos_funcoes.md#referencias-auto) |
| `count(first,last,x)` / `count_if(...,pred)` | Quantidade; percorre a faixa | [Contagem](find_count_reverse.md) |
| `map.count(x)` / `set.count(x)` / `multiset.count(x)` | Presença ou multiplicidade da chave | [Map/set](map_set.md) |
| `empty()` / `size()` | bool: vazio? / quantidade sem sinal | [Vector](vector_string.md#vector) / [estruturas](pilha_fila_heap.md) |
| `vector.erase(it)` / `erase(first,last)` | Remove posições; iterador seguinte | [Vector](vector_string.md#vector-erase) |
| `map.erase(x)` / `set.erase(x)` | Remove chave; quantidade apagada | [Map/set](map_set.md#erase) |
| `multiset.erase(x)` / `erase(it)` | Todas as cópias / uma ocorrência | [Multiset](map_set.md#multiset-erase) |
| `string.erase(pos,k)` | Apaga até k caracteres; referência à string | [String](vector_string.md#string) |
| `find(first,last,x)` | Busca linear; iterador ou end | [std::find](find_count_reverse.md) |
| `map.find(x)` / `set.find(x)` | Busca chave; iterador ou end | [Map/set](map_set.md#map-find) |
| `string.find(texto)` / `string::npos` | Índice ou marcador de ausência | [String](vector_string.md#string-find) |
| `front()` | Referência ao primeiro, exige não vazio | [Vector](vector_string.md#vector) / [queue](pilha_fila_heap.md#queue) |
| `gcd(a,b)` / `lcm(a,b)` | MDC / MMC; inteiros | [Numéricas](entrada_tipos_funcoes.md#gcd-lcm) |
| `getline(cin,s)` | Linha inteira; stream | [getline](entrada_tipos_funcoes.md#getline) |
| `greater<T>` | Comparador >; gera min-heap | [Heap mínimo](pilha_fila_heap.md#min-heap) / [sort](sort.md) |
| `ignore(...,'\n')` | Descarta até quebra de linha | [getline/ignore](entrada_tipos_funcoes.md#ignore) |
| `vector.insert(it,x)` | Insere antes da posição; iterador | [Vector](vector_string.md#vector-insert) |
| `map.insert({k,v})` / `set.insert(x)` | Insere se ausente; pair<iterador,bool> | [Map/set](map_set.md) |
| `multiset.insert(x)` | Insere outra ocorrência; iterador | [Multiset](map_set.md#set-insert) |
| `lambda: [captura](parâmetros){...}` | Função curta; pode capturar estado | [Lambda](entrada_tipos_funcoes.md#lambda) |
| `lower_bound(first,last,x)` | Iterador do primeiro >=x, crescente | [lower_bound](lower_bound.md) |
| `set.lower_bound(x)` / `map.lower_bound(x)` | Método O(log n), primeiro valor/chave >=x | [Bounds em árvore](map_set.md#bounds) |
| `min(a,b)` / `max(a,b)` | Menor/maior valor; copie o resultado | [min/max](min_max.md) |
| `min_element` / `max_element` / `minmax_element` | Iterador(es) dos extremos | [Extremos](min_max.md) |
| `next_permutation` / `prev_permutation` | Modifica ordem; bool: existe próxima/anterior? | [Permutações](next_permutation.md) |
| `operator[]`: `v[i]`, `s[i]`, `m[chave]` | Vector/string: referência; map insere se ausente | [Vector/string](vector_string.md) / [map](map_set.md#map-operator) |
| `pop()` | Remove topo de stack/heap ou início de queue; void | [Pilha/fila/heap](pilha_fila_heap.md) |
| `pop_back()` / `pop_front()` | Remove numa ponta; void; exige não vazio | [Vector](vector_string.md#vector-pop-back) / [deque](pilha_fila_heap.md#deque) |
| `pow(a,b)` / `sqrt(x)` | Potência / raiz aproximadas | [Numéricas](entrada_tipos_funcoes.md#sqrt-pow) |
| `push(x)` | Insere em stack/queue/heap; void | [Estruturas](pilha_fila_heap.md) |
| `push_back(x)` / `push_front(x)` | Insere numa ponta; void | [Vector](vector_string.md#vector-push-back) / [deque](pilha_fila_heap.md#deque) |
| `remove` / `remove_if` | Compacta valores que ficam; novo fim lógico | [remove + erase](unique_erase.md) |
| `reserve(n)` / `resize(n)` | Capacidade / quantidade de elementos; void | [Vector](vector_string.md#reserve-resize) |
| `return valor` / `void` | Entrega resultado / função sem valor de retorno | [Definição de função](entrada_tipos_funcoes.md#funcoes) |
| `reverse(first,last)` | Inverte a ordem; void | [reverse](find_count_reverse.md) |
| `sort` / `stable_sort` | Ordena faixa; void; estabilidade em empate | [sort](sort.md) |
| `substr(pos,k)` | Nova string com até k caracteres | [substr](vector_string.md#string-substr) |
| `swap(a,b)` | Troca valores; void | [Numéricas](entrada_tipos_funcoes.md#funcoes-uteis) |
| `top()` | Referência ao último da stack ou prioridade do heap | [Stack](pilha_fila_heap.md#stack) / [heap](pilha_fila_heap.md#priority-queue) |
| `unique(first,last)` | Compacta iguais consecutivos; novo fim lógico | [unique + erase](unique_erase.md) |
| `upper_bound(first,last,x)` | Iterador do primeiro >x, crescente | [upper_bound](upper_bound.md) |
| `set.upper_bound(x)` / `map.upper_bound(x)` | Método O(log n), primeiro valor/chave >x | [Bounds em árvore](map_set.md#bounds) |
| `ws` | Consome todos os espaços iniciais, inclusive linhas vazias | [getline/ws](entrada_tipos_funcoes.md#ws) |

## Por assunto

[Ordenação](sort.md) · [Bounds](lower_bound.md) · [Duplicatas e remoção](unique_erase.md) · [Vector/string](vector_string.md) · [Map/set](map_set.md) · [Pilha/fila/heap](pilha_fila_heap.md) · [Entrada, tipos e funções](entrada_tipos_funcoes.md)

**Convenção:** `first,last` formam [first,last), com fim excluído. Exemplos usam C++17; as páginas informam cabeçalhos, hipóteses e custos. Não use `.contains()`, `std::erase` ou `std::popcount` como se fossem C++17.
