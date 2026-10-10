# upper_bound — primeiro estritamente maior (>)

[Início](../../README.md) · [Consulta de contest](../README.md) · [Todas as funções](README.md)

**Palavras-chave:** upper_bound, upper bound, limite superior, busca binária, primeiro >, maior que, último <=, duplicatas, quantidade, intervalo.

> **O que lembrar:** em ordem crescente, retorna o **iterador do primeiro elemento `> x`**. Pula todas as ocorrências iguais a x.

## Sintaxe e resultado

Cabeçalho `<algorithm>`. Fragmento para `main`, com cabeçalhos e `using namespace std;`.

```cpp
vector<int> v = {1, 3, 3, 3, 7};
auto it = upper_bound(v.begin(), v.end(), 3);
auto indice = it - v.begin();   // 4, índice do 7.
if (it != v.end()) cout << *it; // 7.
```

| Em `[1,3,3,3,7]` | lower_bound | upper_bound |
|---|---|---|
| Alvo 3 | índice 1: primeiro >=3 | índice 4: primeiro >3 |
| Alvo 4 | índice 4: valor 7 | índice 4: valor 7 |
| Alvo 7 | índice 4: valor 7 | índice 5: end() |

Retorna iterador, não valor nem bool. Faixa `[first,last)` ordenada com o comparador usado na busca; formalmente, particionada pelo teste `!(x < elemento)`.

## Quantos são <=x? Qual o maior <=x?

```cpp
vector<int> v = {1, 3, 3, 3, 7};
int x = 3;
auto it = upper_bound(v.begin(), v.end(), x);
auto quantidade_menores_ou_iguais = it - v.begin(); // 4.
if (it != v.begin()) cout << *prev(it); // 3. <iterator>
```

Com lower_bound, o prefixo contém valores `<x`; com upper_bound, contém valores `<=x`.

## Duplicatas e intervalos: limites prontos

Para `L<R` nas linhas de intervalo aberto e `L<=R` nas demais:

| O que contar em vector ordenado | Receita |
|---|---|
| Igual a x | `upper_bound(x) - lower_bound(x)` |
| Fechado [L,R] | `upper_bound(R) - lower_bound(L)` |
| Aberto (L,R) | `lower_bound(R) - upper_bound(L)` |
| Semiaberto [L,R) | `lower_bound(R) - lower_bound(L)` |

Na tabela, `lower_bound(x)` abrevia `lower_bound(v.begin(),v.end(),x)`. Se o intervalo for vazio/invalidamente invertido, trate como zero antes de subtrair.

## Custos e pegadinhas

- O(log n) no vector; `s.upper_bound(x)` e `m.upper_bound(x)` para set/map.
- Confira `it != end()` antes de ler; `it != begin()` antes de `prev(it)`.
- Em vector decrescente com `greater<T>`, upper_bound procura o primeiro **<x** segundo a ordem numérica; não aplique a tabela crescente.
- Contar em set/map com `distance(lo,hi)` pode ser O(quantidade). Iteradores não aceitam subtração.

[lower_bound](lower_bound.md) · [Programa completo de bounds](../../semanas/semana-2-buscas-backtracking/templates/bounds.cpp) · [Sweep e fronteiras](../../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#sweep-line)

**Referência C++17:** [N4659: upper.bound](https://timsong-cpp.github.io/cppwp/n4659/upper.bound).
