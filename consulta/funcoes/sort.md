# sort / stable_sort — ordenar e comparar

[Início](../../README.md) · [Consulta de contest](../README.md) · [Todas as funções](README.md)

**Palavras-chave:** sort, stable_sort, ordenar, crescente, decrescente, comparador, comparator, lambda, pair, empate, índice original.

> `sort` modifica a faixa em ordem crescente e **retorna void**. O comparador responde: “a deve vir antes de b?”.

## Sintaxe principal

`<algorithm>`. Fragmentos em `main`, com cabeçalhos e `using namespace std;`.

```cpp
vector<int> v = {3, 1, 2};
sort(v.begin(), v.end());   // [1,2,3].
sort(v.rbegin(), v.rend()); // [3,2,1].
// Alternativa: sort(v.begin(),v.end(),greater<int>()); <functional>
```

## Dois critérios e posições originais

```cpp
vector<pair<int,int>> itens = {{7,1}, {3,2}, {7,3}};
sort(itens.begin(), itens.end()); // first crescente, depois second crescente.
sort(itens.begin(), itens.end(), [](const auto& a, const auto& b) {
    if (a.first != b.first) return a.first > b.first; // Valor decrescente.
    return a.second < b.second; // Índice crescente em empate.
});
```

O segundo campo pode guardar o índice original antes de ordenar. Para tuple, a comparação também é lexicográfica.

## sort ou stable_sort?

| Função | Empates | Custo de comparações |
|---|---|---|
| sort | Não preserva a ordem relativa | O(n log n), pior caso |
| stable_sort | Preserva equivalentes pelo comparador | O(n log n) com memória disponível; O(n log² n) caso contrário |

Para um critério próprio: `stable_sort(v.begin(),v.end(),comp)`. Comparadores que constroem strings ou estruturas grandes custam mais do que uma comparação de int.

## Pegadinhas

- Use ordem estrita: `cmp(a,a)` false; nunca `<=`. A relação deve ser consistente e transitiva, inclusive para equivalência.
- Não ordene se o problema precisa da contiguidade ou da ordem original.
- Não existe `v.sort()` para vector. `std::sort` precisa de iteradores de acesso aleatório; set já mantém ordem, list tem seu método sort.
- Para tirar todas as duplicatas: [sort + unique + erase](unique_erase.md).

[Template: ordenar com índices](../../semanas/semana-2-buscas-backtracking/templates/sort_indices.cpp) · [Comparador de concatenação](../../semanas/semana-1-stl-prefix-sum/templates/sort_comparador.cpp)

**Referência C++17:** [N4659: ordenação](https://timsong-cpp.github.io/cppwp/n4659/alg.sort).
