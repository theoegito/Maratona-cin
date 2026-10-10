# Semana 1 · receitas de algoritmos

[Semana 1](../README.md) · [Roteiro oficial](roteiro.md) · [Consulta de C++](../../../consulta/README.md)

- [Prefix Sum](#prefix-sum)
- [Prefixos + map](#prefixos-map)
- [Janela fixa](#janela-fixa)
- [Pilha monotônica](#pilha-monotonica)
- [Greedy + heap](#greedy-heap)

## Como copiar os fragmentos

Todos os blocos são **independentes** e ficam dentro de `main`; não junte receitas com nomes repetidos. Considere estes cabeçalhos e `using namespace std;` antes de `main`:

```cpp
#include <algorithm>
#include <cstdint>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
```

Quando uma seção usa `a` e `n`, pressupõe `vector<long long> a` já preenchido e `int n = static_cast<int>(a.size());`, com tamanho que caiba em `int`. Os demais dados de entrada são declarados em **Entradas**. As somas, diferenças e contagens precisam caber em `long long`. A resposta fica na variável indicada; imprima-a no formato exigido pelo juiz.
<a id="prefix-sum"></a>

## Prefix sum — soma de intervalo em O(1)

**Busca:** prefix sum, prefixos, soma acumulada, range sum, somatório, consulta [l,r]. **Gatilho:** muitas consultas de soma no mesmo vetor, sem atualizações.

**Semântica:** `pref[i]` soma os primeiros i elementos. Logo, `pref[r] - pref[l]` soma **[l,r)**. O prefixo vazio vale zero.

**Entradas:** `a`, `n`; índices `int l, r`, com `0 <= l <= r <= n`. **Resultado:** `soma`.

```cpp
vector<long long> pref(n + 1, 0);
for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
long long soma = pref[r] - pref[l]; // [l,r), r não entra
```

**Custo:** montagem O(n), consulta O(1), memória O(n). Negativos funcionam.

**Salva na prova:** para [l,r] fechado e 0-based, use `pref[r+1]-pref[l]`; para entrada 1-based fechada, `pref[r]-pref[l-1]`.

**Pegadinha:** alterar `a` depois da montagem deixa os prefixos desatualizados. `pref[r]-pref[l]` não inclui `a[r]`. Uma diferença entre prefixos também precisa caber no tipo.

**Escopo:** base da semana 1. [Template completo](../templates/prefix_sum.cpp).
<a id="prefixos-map"></a>

## Prefixos + map — contar subarrays de soma K

**Busca:** subarray sum, soma exata, prefix sum map, frequência de prefixos, negativos, count subarrays. **Gatilho:** contar trechos contíguos não vazios de soma K, incluindo negativos e zeros.

**Semântica/invariante:** antes de registrar o prefixo atual `s`, `freq` guarda somente prefixos **anteriores**. Cada prefixo de valor `s-K` forma um trecho de soma K.

**Entradas:** `a`; `long long K`. **Resultado:** `resposta`.

```cpp
map<long long, long long> freq;
freq[0] = 1; // prefixo antes do primeiro elemento
long long s = 0, resposta = 0;
for (long long x : a) {
    s += x;
    auto it = freq.find(s - K); // consulta sem criar chave
    if (it != freq.end()) resposta += it->second;
    ++freq[s]; // registrar DEPOIS de consultar
}
```

**Custo:** O(n log(n+1)) com map, memória O(n). `s`, `s-K` e a resposta devem caber no tipo.

**Salva na prova:** `a={0,0}`, K=0 → 3 trechos. Frequência conta posições distintas de prefixos iguais.

**Pegadinhas:** esquecer `freq[0]=1` perde trechos começando no índice 0; registrar primeiro conta trecho vazio quando K=0; set resolve existência, mas perde multiplicidade. Esta receita não resolve automaticamente o maior trecho com soma ≤ K.

**Escopo:** contagem da semana 1; extensão do exemplo oficial com set. [Template completo](../templates/subarray_sum_map.cpp).
<a id="janela-fixa"></a>

## Janela fixa — distintos em cada bloco de k

**Busca:** fixed sliding window, janela fixa, tamanho k, valores distintos, frequência, quem entra/quem sai. **Gatilho:** a mesma pergunta para todos os blocos de comprimento k.

**Semântica/invariante:** depois da remoção, o map representa exatamente os elementos da janela atual. Chaves com frequência zero são apagadas; `freq.size()` é a quantidade de distintos.

**Entradas:** `a`, `n`; `int k`, com `1 <= k <= n`. **Resultado:** vetor `distintos`, um valor por janela.

```cpp
map<long long, int> freq;
vector<int> distintos;
for (int r = 0; r < n; ++r) {
    ++freq[a[r]];
    if (r >= k && --freq[a[r - k]] == 0) freq.erase(a[r - k]);
    if (r >= k - 1) distintos.push_back(static_cast<int>(freq.size()));
}
```

**Custo:** O(n log(k+1)); map O(k), além do vetor de respostas. Valores negativos são permitidos.

**Salva na prova:** para soma de janela fixa, troque o map por uma soma: adicione `a[r]` e, se r≥k, subtraia `a[r-k]`.

**Pegadinhas:** só há resposta depois de k elementos; frequência zero que fica no map não é valor ativo. Não confunda janela fixa com a janela variável por soma.

**Escopo:** aplicação da semana 1. [Template completo](../templates/sliding_window.cpp).
<a id="pilha-monotonica"></a>

## Pilha monotônica — menor estrito mais próximo à esquerda

**Busca:** monotonic stack, nearest smaller, menor anterior, vizinho menor, próximo maior/menor, histogramas. **Gatilho:** procurar vizinho por valor mantendo a ordem original.

**Semântica/invariante:** a pilha guarda índices crescentes cujos valores são estritamente crescentes. Remova valores ≥ atual; o topo restante é o menor estrito mais próximo à esquerda.

**Entradas:** `a`, `n`. **Resultado:** `anterior[i]` é índice 0-based ou -1 quando não existe.

```cpp
vector<int> pilha, anterior(n, -1);
for (int i = 0; i < n; ++i) {
    while (!pilha.empty() && a[pilha.back()] >= a[i]) pilha.pop_back();
    if (!pilha.empty()) anterior[i] = pilha.back();
    pilha.push_back(i);
}
```

**Custo:** O(n), memória O(n); cada índice entra uma vez e sai no máximo uma vez.

**Salva na prova:** `[3,5,2,7,8]` → `[-1,0,-1,2,3]`. Para procurar à direita, percorra i em ordem inversa.

**Pegadinhas:** menor **estrito** remove ≥; menor **ou igual** remove somente >. `back()` exige pilha não vazia. Ordenar a entrada destrói os vizinhos originais.

**Escopo:** oficial da aula 1, slides 59–67; histogramas são aplicação extra. [Template completo, saída 1-based/0](../templates/pilha_monotonica.cpp).
<a id="greedy-heap"></a>

## Greedy + min-heap — aceitar e retirar o pior

**Busca:** greedy, guloso, priority_queue, min-heap, Potions, vida não negativa, selecionar máximo, troca, descartar menor. **Gatilho:** escolher o máximo de itens em ordem, mantendo soma de cada prefixo da subsequência ≥0.

**Semântica/invariante:** tente incluir o novo item; se a vida ficar negativa, retire o menor escolhido. Excluir um negativo melhora todos os prefixos posteriores à posição dele. Uma remoção basta: antes da inclusão a vida era ≥0 e o menor valor é ≤ ao novo.

**Entradas:** `a`; vida inicial 0; cada escolha vale uma unidade. Somas e subtrações cabem em long long. **Resultado:** `quantidade`.

```cpp
priority_queue<long long, vector<long long>, greater<long long>> heap;
long long vida = 0;
for (long long x : a) {
    vida += x;
    heap.push(x);
    if (vida < 0) {
        vida -= heap.top(); // top consulta antes da remoção
        heap.pop();        // pop retorna void
    }
}
auto quantidade = heap.size();
```

**Custo:** O(n log(n+1)), memória O(n). `greater` coloca o **menor** no topo; a priority_queue padrão colocaria o maior.

**Salva na prova:** `[4,-3,-2]` descarta -3, mantém `[4,-2]` e responde 2. A regra de troca conserva mais vida com a mesma quantidade de itens, favorecendo futuras escolhas.

**Pegadinhas:** o heap não representa a ordem da subsequência; ele decide qual valor descartar. Esta regra não serve automaticamente se itens têm recompensas diferentes, outras restrições ou outro objetivo. Não atribua `heap.pop()` a uma variável.

**Escopo:** aplicação das soluções da semana 1; não apresentada aqui como algoritmo novo da aula 2. [Template completo](../templates/greedy_priority_queue.cpp).

**Antes de adaptar qualquer receita:** confira negativos, limites, duplicatas, pontas do intervalo, convenção dos índices e monotonicidade. Compare contra força bruta em entradas pequenas quando a adaptação mudar a lógica.
