# Aula da semana 1 · STL, complexidade e Prefix Sum

[Semana 1](../README.md) · [Guia completo](guia.md) · [Consulta rápida](consulta-rapida.md) · [Complemento](complemento.md) · [Funções por nome](../../../consulta/funcoes/README.md)

**Base oficial:** [slides da aula 1](slides.pdf). A numeração abaixo é a página do PDF, contando a capa como página 1. Use este roteiro para escolher o assunto; abra a página da função quando a dúvida for de sintaxe, parâmetros ou retorno.

## O que entra nesta aula

| Bloco oficial | Slides | O que revisar |
|---|---|---|
| Introdução a C++, tipos, escopo, referências e entrada/saída | [3–18](slides.pdf#page=3) | `main`, `cin`, `cout`, `getline`, `long long`, `auto`, cópia e referência |
| Complexidade temporal e espacial | [19–23](slides.pdf#page=19) | Estimar tempo/memória antes de escrever os laços |
| Containers STL | [24–34](slides.pdf#page=24) | Vector, string, map, set, multiset, stack, queue, deque, heap, pair e tuple |
| Algoritmos STL e percorrimento | [35–44](slides.pdf#page=35) | Iteradores, sort, erase, unique, buscas, accumulate, reverse, extremos e permutações |
| Soma de prefixos | [45–52](slides.pdf#page=45) | Pré-processar uma vez e responder intervalos em O(1) |
| Existência de subarray com soma K | [54–58](slides.pdf#page=54) | Prefixos anteriores em um set, inclusive com negativos |
| Pilha monotônica | [59–67](slides.pdf#page=59) | Menor elemento mais próximo à esquerda, em O(n) |

## 1. Sintaxe e semântica de funções

Uma chamada precisa de três perguntas: **o que recebe, o que modifica e o que retorna?** Não trate um iterador como índice, `bool` ou valor; não espere que uma função `void` entregue o elemento removido.

| Preciso lembrar… | Sintaxe de referência | Significado e acesso |
|---|---|---|
| Ler números / imprimir | `cin >> x; cout << x << '\n';` | Token / saída; [entrada e saída](../../../consulta/funcoes/entrada_tipos_funcoes.md#cin-cout), [slides 15–16](slides.pdf#page=15) |
| Ler uma linha inteira | `getline(cin, s);` | Inclui espaços; confira a quebra de linha pendente; [getline](../../../consulta/funcoes/entrada_tipos_funcoes.md#getline) |
| Evitar overflow | `long long s = 1LL * a * b;` | A promoção precisa ocorrer antes da operação; [tipos](../../../consulta/funcoes/entrada_tipos_funcoes.md#tipos-overflow), [slides 7–8](slides.pdf#page=7) |
| Passar dados sem copiar | `const vector<int>& v` | Referência só para leitura; [funções e parâmetros](../../../consulta/funcoes/entrada_tipos_funcoes.md#funcoes), [slide 12](slides.pdf#page=12) |
| Percorrer e alterar | `for (auto& x : v) ++x;` | Referência modifica o original; `auto x` copia; [auto/referência](../../../consulta/funcoes/entrada_tipos_funcoes.md#referencias-auto), [slide 44](slides.pdf#page=44) |
| Usar uma faixa | `v.begin(), v.end()` | `[begin,end)`: o fim fica excluído e não pode ser dereferenciado; [iteradores e faixas](../../../consulta/funcoes/iteradores.md), [slide 36](slides.pdf#page=36) |

## 2. Estruturas e seus métodos

| Estrutura | Sintaxe / operações principais | Quando escolher |
|---|---|---|
| [Vector](../../../consulta/funcoes/vector_string.md#vector) | `vector<int> v; v.push_back(x); v[i]; v.size();` | Sequência com acesso por índice; [slide 25](slides.pdf#page=25) |
| [String](../../../consulta/funcoes/vector_string.md#string) | `string s; s.find(t); s.substr(pos,quantidade);` | Texto, caracteres e trechos; `find` retorna índice ou `npos`; [slides 26–27](slides.pdf#page=26) |
| [Map](../../../consulta/funcoes/map_set.md#map) | `map<int,int> freq; ++freq[x]; freq.find(x);` | Chave → valor / frequência; `operator[]` pode inserir; [slide 28](slides.pdf#page=28) |
| [Set / multiset](../../../consulta/funcoes/map_set.md#set) | `s.insert(x); s.find(x); s.erase(it);` | Valores ordenados sem/com repetição; [slide 29](slides.pdf#page=29) |
| [Stack / queue](../../../consulta/funcoes/pilha_fila_heap.md#stack) | `push(x); top()/front(); pop(); empty();` | Último a entrar / primeiro a entrar; `pop` retorna `void`; [slide 30](slides.pdf#page=30) |
| [Deque](../../../consulta/funcoes/pilha_fila_heap.md#deque) | `push_front(x); push_back(x); pop_front(); pop_back();` | Inserir/remover nas duas pontas; [slide 31](slides.pdf#page=31) |
| [Priority queue](../../../consulta/funcoes/pilha_fila_heap.md#priority-queue) | `priority_queue<int> pq; pq.push(x); pq.top(); pq.pop();` | Retirar sempre o maior; comparador muda para menor; [slide 32](slides.pdf#page=32) |
| [Pair](../../../consulta/funcoes/pair_tuple.md) | `pair<long long,int> p = {valor,indice}; p.first; p.second;` | Associar dois dados e manter a relação após ordenar; [slide 33](slides.pdf#page=33) |
| [Tuple](../../../consulta/funcoes/pair_tuple.md) | `tuple<int,int,int> t = {a,b,c}; get<0>(t);` | Associar três ou mais campos; `get<I>` usa índice constante; [slide 34](slides.pdf#page=34) |

**Pair/tuple:** os campos podem ter tipos diferentes. A comparação padrão é lexicográfica: primeiro campo, depois segundo em caso de empate, e assim por diante. `.first` e `.second` são membros de dados, não chamadas de função. Em C++17, `auto [a,b] = p;` copia os campos; `auto& [a,b] = p;` permite alterá-los no original. Veja também o [complemento](complemento.md).

```cpp
vector<pair<long long, int>> dados = {{20, 1}, {10, 2}, {20, 3}};
sort(dados.begin(), dados.end());
// Agora: {10,2}, {20,1}, {20,3}.
// .first é valor; .second continua sendo a posição original.
```

## 3. Algoritmos STL: o retorno faz diferença

| Função | Sintaxe mais usada | Retorna / modifica | Slides |
|---|---|---|---|
| [sort / stable_sort](../../../consulta/funcoes/sort.md) | `sort(v.begin(), v.end());` | `void`; ordena a própria faixa | [37](slides.pdf#page=37) |
| [erase](../../../consulta/funcoes/vector_string.md#vector-erase) | `v.erase(it);` | No vector, iterador do próximo elemento; apaga e desloca | [38](slides.pdf#page=38) |
| [unique + erase](../../../consulta/funcoes/unique_erase.md) | `v.erase(unique(v.begin(),v.end()),v.end());` | `unique` retorna fim lógico; `erase` reduz tamanho | [39](slides.pdf#page=39) |
| [binary_search](../../../consulta/funcoes/binary_search.md) | `binary_search(v.begin(),v.end(),x);` | `bool`: existe na faixa ordenada? | [40](slides.pdf#page=40) |
| [lower_bound](../../../consulta/funcoes/lower_bound.md) / [upper_bound](../../../consulta/funcoes/upper_bound.md) | `lower_bound(v.begin(),v.end(),x);` | Iterador: primeiro `>= x` / primeiro `> x`, em ordem crescente | [40](slides.pdf#page=40) |
| [accumulate](../../../consulta/funcoes/accumulate.md) | `accumulate(v.begin(),v.end(),0LL);` | Soma em `long long`; não altera a faixa | [41](slides.pdf#page=41) |
| [reverse](../../../consulta/funcoes/find_count_reverse.md) | `reverse(v.begin(),v.end());` | `void`; inverte a própria faixa | [41](slides.pdf#page=41) |
| [min_element / max_element](../../../consulta/funcoes/min_max.md) | `min_element(v.begin(),v.end());` | Iterador do extremo; `end()` se vazia | [42](slides.pdf#page=42) |
| [next_permutation](../../../consulta/funcoes/next_permutation.md) | `next_permutation(v.begin(),v.end());` | `bool`; muda a sequência para a próxima ordem | [43](slides.pdf#page=43) |

**Pegadinhas de precisão:** `unique` remove iguais consecutivos; ordenar antes serve para juntar todas as duplicatas. Bounds genéricos em set/map podem fazer muitos avanços: prefira `s.lower_bound(x)`. `std::string` é uma classe própria, não literalmente `vector<char>`. Confira custos e pré-condições nas páginas de cada função.

## 4. Prefix Sum: muitas consultas de soma

**Gatilho:** array que não muda + muitas perguntas sobre soma de um intervalo contínuo.

Para índices 0-based, defina `pref[i]` como a soma dos **primeiros i elementos**. Assim, `pref[0] = 0` e a soma inclusiva `[l,r]` é `pref[r+1] - pref[l]` ([slides 49–51](slides.pdf#page=49)).

```cpp
vector<long long> a = {2, 8, 3, 5};
vector<long long> pref(a.size() + 1, 0);
for (size_t i = 0; i < a.size(); ++i)
    pref[i + 1] = pref[i] + a[i];
long long soma_1_a_3 = pref[4] - pref[1]; // 8 + 3 + 5 = 16
```

Construção O(n), consulta O(1), memória O(n). Não confunda o índice do array com o índice do prefixo. Prefixos aceitam números negativos; uma janela que depende de a soma crescer não necessariamente aceita. [Explicação e gatilhos](algoritmos.md#prefix-sum).

<a id="prefixos"></a>

## 5. Aplicações oficiais de prefixos e pilha

| Problema | Invariante / ideia | Custo e acesso |
|---|---|---|
| Existe subarray com soma K? | Para prefixo atual `s`, procure prefixo anterior `s-K`; comece com 0 no set; procure antes de inserir `s` | O(n log n) com set; [slides 54–58](slides.pdf#page=54) |
| Menor estrito mais próximo à esquerda | Retire da pilha valores `>= a[i]`; o topo restante é a resposta; depois empilhe `i` | O(n), cada índice entra/sai uma vez; [slides 59–67](slides.pdf#page=59), [explicação](algoritmos.md#pilha-monotonica) |

Guardar **índices** na pilha permite devolver posições e ainda acessar valores. Para menor ou igual, mude a remoção para `>`; para consultar à direita, percorra no sentido inverso.

## 6. Antes de escolher o algoritmo

[Slides 19–23](slides.pdf#page=19): conte quantas vezes cada operação acontece. Um `while` dentro de um `for` pode ser O(n) no total se cada elemento entrar e sair só uma vez. Três laços independentes sobre n normalmente custam O(n³).

- Se ordenar, preserve índices originais quando o enunciado pede posições; pair é uma opção.
- Faça somas/produtos no tipo correto desde o início; não basta converter o resultado depois.
- Teste sequência vazia quando permitida, repetidos, extremos, resposta ausente e índices 0/1-based.
- As estimativas de operações por segundo dos slides são heurísticas; custo de cada operação e limite de tempo importam.

## Extras e conexões com a próxima semana

**Extras de apoio:** contar *todos* os subarrays de soma K com mapa de frequências amplia a pergunta de existência dos slides; [prefixos + map](algoritmos.md#prefixos-map). Janela fixa e guloso com heap aparecem nas aplicações dos exercícios e na consulta, mas não formam blocos próprios desta aula.

**Oficial da aula 2:** compressão de coordenadas, busca binária na resposta, two pointers e backtracking. A [semana 2](../../semana-2-buscas-backtracking/README.md) reúne essas ideias e o Homework 2. Não confunda subconjunto (pode pular elementos) com subarray (segmento contínuo).

Para praticar esta aula: volte ao [índice da semana 1](../README.md), que separa **Homework 1** e **Contest 2**. Para uma dúvida pontual, abra o [catálogo de funções](../../../consulta/funcoes/README.md); para decidir a estratégia, use a [consulta de algoritmos](../../../consulta/algoritmos.md).
