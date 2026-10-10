# find / count / reverse — procurar, contar e inverter

[Início](../../README.md) · [Consulta de contest](../README.md) · [Todas as funções](README.md)

**Palavras-chave:** find, count, count_if, reverse, busca linear, ocorrências, inverter, palindrome, palíndromo, iterator, string find.

## Sintaxe, semântica e retorno

`<algorithm>`. Fragmentos em `main`, com cabeçalhos e `using namespace std;`.

```cpp
vector<int> v = {3, 1, 3, 2};
auto it = find(v.begin(), v.end(), 3); // Primeiro 3, ou end() se ausente.
auto qtd = count(v.begin(), v.end(), 3); // 2 ocorrências.
auto pares = count_if(v.begin(), v.end(), [](int x){ return x%2 == 0; }); // 1.
reverse(v.begin(), v.end()); // [2,3,1,3]; modifica a faixa, retorna void.
```

find/count/count_if percorrem O(n) no pior caso. Reverse faz O(n) trocas. Não exigem ordenação. Faixa é `[begin,end)`; vazia é aceita.

| Quero... | Use |
|---|---|
| Procurar em vetor não ordenado | `find(v.begin(),v.end(),x)` |
| Procurar chave em map/set | `.find(x)` — O(log n) |
| Procurar posição de texto em string | `s.find(texto)` — retorna índice ou string::npos |
| Contar duplicatas em vetor ordenado | [upper_bound-lower_bound](upper_bound.md) — O(log n) |
| Inverter ordem existente | reverse — não é ordenar decrescente |

## Palíndromo: exemplo

```cpp
string s = "arara";
string invertida = s;
reverse(invertida.begin(), invertida.end());
bool palindromo = s == invertida; // true; considera todos os caracteres.
```

find devolve iterador; `string::find` devolve índice. Não use `*it` quando it==end e não use string::npos como índice válido. [Strings e substr](vector_string.md#string)

**Referência C++17:** [N4659: algoritmos de busca linear](https://timsong-cpp.github.io/cppwp/n4659/alg.find).
