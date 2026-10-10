# min / max / min_element / max_element — extremos

[Início](../../README.md) · [Consulta de contest](../README.md) · [Todas as funções](README.md)

**Palavras-chave:** min, max, min_element, max_element, minmax_element, menor, maior, mínimo, máximo, posição, iterator.

> `min/max` escolhem entre **valores**. `min_element/max_element` localizam **iteradores** na faixa.

## Sintaxe e retornos

`<algorithm>`. Fragmentos em `main`, com cabeçalhos e `using namespace std;`.

```cpp
int a = 7, b = 3;
int menor = min(a, b); // 3.
int maior = max({a, b, 9}); // 9; lista não vazia, tipos compatíveis.
vector<int> v = {5, 2, 2, 8};
auto it = min_element(v.begin(), v.end());
if (it != v.end()) {
    cout << *it;           // 2, menor valor.
    cout << it-v.begin();  // 1, índice da primeira ocorrência.
}
auto jt = max_element(v.begin(), v.end()); // Índice 3, valor 8.
```

min/max de dois valores: uma comparação, O(1) para números. min/max_element: O(n) comparações, sem precisar ordenar. Em faixa vazia, retornam end(). Nos empates, min_element e max_element devolvem a primeira ocorrência.

## Dois extremos de uma vez

```cpp
vector<int> v = {5, 2, 8};
auto [lo, hi] = minmax_element(v.begin(), v.end());
if (lo != v.end()) cout << *hi - *lo; // 6; tipos devem comportar diferença.
```

minmax_element tem O(n); em empate, mínimo é a primeira ocorrência e máximo é a última. Ambos são end() se a faixa é vazia.

## Pegadinhas

- Não faça `*min_element(...)` sem garantir faixa não vazia.
- Para iterador de vector, subtrair begin devolve índice; não faça isso em set/map.
- `max(int, long long)` não deduz um tipo único: ajuste os tipos ou use `max<long long>(a,b)`.
- Valores retornados por min/max de duas referências podem se tornar referências pendentes se você guardar referência a um argumento temporário; na consulta usual, atribua por valor.

[Uso em limites da busca na resposta](../algoritmos.md#busca-binaria)

**Referência C++17:** [N4659: mínimo e máximo](https://timsong-cpp.github.io/cppwp/n4659/alg.min.max).
