# lower_bound — primeiro maior ou igual (>=)

[Início](../../README.md) · [Consulta de contest](../README.md) · [Todas as funções](README.md)

**Palavras-chave:** lower_bound, lower bound, limite inferior, busca binária, binary search, primeiro >=, maior ou igual, inserir ordenado, posição, índice, duplicatas, predecessor.

> **O que lembrar:** em ordem crescente, retorna o **iterador do primeiro elemento `>= x`**. Se todos forem menores, retorna `end()`. Não retorna o valor nem um bool.

## Sintaxe e semântica

Cabeçalho: `<algorithm>`. Cada bloco é um exemplo independente: presuma os cabeçalhos e `using namespace std;`, e coloque as instruções dentro de `main`.

```cpp
vector<int> v = {1, 3, 3, 3, 7}; // Ordenado em ordem crescente.
auto it = lower_bound(v.begin(), v.end(), 3);
auto indice = it - v.begin();    // 1: índice 0-based.
if (it != v.end()) cout << *it;  // 3: valor encontrado.
```

| Busca em `[1,3,3,3,7]` | Índice retornado | Valor, se existir |
|---|---|---|
| `lower_bound(..., 0)` | 0 | 1 |
| `lower_bound(..., 3)` | 1 | 3, primeira ocorrência |
| `lower_bound(..., 4)` | 4 | 7, mesmo sem existir 4 |
| `lower_bound(..., 8)` | 5, igual a `v.size()` | Nenhum: `end()` |

Faixa pesquisada é `[begin,end)`: início incluído e fim excluído. O vector ordenado satisfaz a pré-condição; formalmente, a faixa precisa estar particionada pelo teste `elemento < x`. Na prova, ordenar antes é a receita segura para várias buscas.

## Existe exatamente x? Primeiro <x ou <=x?

```cpp
vector<int> v = {1, 3, 3, 3, 7};
int x = 4;
auto it = lower_bound(v.begin(), v.end(), x);
bool existe = it != v.end() && *it == x; // false; *it seria 7.
if (it != v.begin()) {
    auto anterior = prev(it); // <iterator>; maior elemento estritamente <x.
    cout << *anterior;
}
// Para maior elemento <=x, parta de upper_bound(x), confira begin e use prev.
```

## Contar duplicatas e valores num intervalo

```cpp
vector<int> v = {1, 3, 3, 3, 7};
int x = 3;
auto lo = lower_bound(v.begin(), v.end(), x);
auto hi = upper_bound(v.begin(), v.end(), x);
auto quantidade = hi - lo; // 3 ocorrências de 3.
int L = 3, R = 7;          // L <= R.
auto no_intervalo = upper_bound(v.begin(), v.end(), R)
                  - lower_bound(v.begin(), v.end(), L); // 4 em [L,R].
```

## Set/map e ordem decrescente

```cpp
set<int> s = {1, 3, 7}; // <set>
auto it = s.lower_bound(4); // Use o MÉTODO: O(log n), resultado 7.
vector<int> dec = {7, 3, 3, 1};
auto jt = lower_bound(dec.begin(), dec.end(), 4, greater<int>());
// Com esse comparador: primeiro <=4, portanto valor 3. <functional>
```

Use o mesmo comparador da ordenação. Em `set/map`, não subtraia iteradores: `it - s.begin()` não compila. `distance` funciona, mas pode percorrer O(n).

## Custos e pegadinhas

- Vector: O(log n) por busca após ordenar; preparo O(n log n).
- `std::lower_bound` em iteradores de set faz poucas comparações, mas pode avançar O(n) vezes. Prefira `s.lower_bound`/`m.lower_bound`.
- Não use `*end()`. Não use `prev(begin())`. Vetor vazio devolve `end()`.
- Encontrar um elemento `>=x` não significa que encontrou `x`.
- Ordenar muda a sequência. Preserve índices com pair se o problema pede posições originais.

[Comparar com upper_bound](upper_bound.md) · [Somente presença: binary_search](binary_search.md) · [Programa completo](../../semanas/semana-2-buscas-backtracking/templates/bounds.cpp)

**Referência C++17:** [N4659: lower.bound](https://timsong-cpp.github.io/cppwp/n4659/lower.bound).
