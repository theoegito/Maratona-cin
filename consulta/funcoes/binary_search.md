# binary_search — verificar se existe

[Início](../../README.md) · [Consulta de contest](../README.md) · [Todas as funções](README.md)

**Palavras-chave:** binary_search, binary search, busca binária, existe, presença, membership, vetor ordenado, bool.

> Retorna **bool**: true se encontra um elemento equivalente a x. Não devolve índice.

## Sintaxe

`<algorithm>`. Fragmento em `main`, com cabeçalhos e `using namespace std;`.

```cpp
vector<int> v = {1, 3, 3, 7};
bool achou = binary_search(v.begin(), v.end(), 3); // true.
bool faltou = binary_search(v.begin(), v.end(), 4); // false.
```

Faixa ordenada com o comparador da busca. O(log n) em vector, após o preparo com sort. Retorna false em faixa vazia. Comparador opcional: `binary_search(v.begin(),v.end(),x,comp)`.

## Qual função escolher?

| Preciso... | Função |
|---|---|
| Só saber se existe | binary_search |
| Índice do primeiro >=x | [lower_bound](lower_bound.md) |
| Primeiro >x | [upper_bound](upper_bound.md) |
| Chave em map/set | `.find(x) != .end()` |
| Mínimo tempo/capacidade que funciona | [Busca binária NA RESPOSTA](../../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#busca-binaria) |

`binary_search` e busca binária na resposta têm objetivos diferentes: a segunda chama um predicado `ok(mid)` e precisa de monotonicidade. Em set/map, métodos como find têm O(log n) sem os avanços lineares de iteradores da versão genérica.

**Referência C++17:** [N4659: binary.search](https://timsong-cpp.github.io/cppwp/n4659/binary.search).
