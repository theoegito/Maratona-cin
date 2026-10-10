# unique + erase — remover duplicatas

[Início](../../README.md) · [Consulta de contest](../README.md) · [Todas as funções](README.md)

**Palavras-chave:** unique, erase, remove, remove_if, deduplicar, duplicatas, repetidos, fim lógico, erase remove idiom.

> `unique` compacta **iguais consecutivos** e retorna o novo fim lógico. `erase` reduz o tamanho do container.

## Deduplicar toda a sequência

`<algorithm>` + `<vector>`. Fragmentos em `main`, com `using namespace std;`.

```cpp
vector<int> v = {3, 1, 3, 2, 1};
sort(v.begin(), v.end()); // [1,1,2,3,3].
auto novo_fim = unique(v.begin(), v.end());
v.erase(novo_fim, v.end()); // [1,2,3], size=3.
// Forma curta: v.erase(unique(v.begin(),v.end()),v.end());
```

Se deseja compactar somente blocos consecutivos, não precisa ordenar: `[1,1,2,1]` vira `[1,2,1]`. Após unique, o conteúdo do trecho depois do novo fim não deve ser usado como lista de “duplicatas removidas”.

## Remover um valor ou condição

```cpp
vector<int> v = {1, 2, 1, 3};
v.erase(remove(v.begin(), v.end(), 1), v.end()); // [2,3].
v.erase(remove_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }),
        v.end()); // [3].
```

`remove/remove_if` também retornam fim lógico; não reduzem size sozinhos. `std::erase(v,x)` pertence ao C++20; use a receita acima em C++17.

## Semântica, custo e containers

- unique/remove: O(n); vector.erase pode deslocar O(n). Sort+unique+erase: O(n log n).
- `v.erase(it)` remove uma posição e retorna iterador para a próxima; `v.erase(first,last)` remove `[first,last)`.
- `v.erase(x)` não aceita um valor inteiro como busca por conteúdo.
- No multiset, `erase(valor)` remove todas as cópias, `erase(it)` só uma. [Veja exemplos e invalidação](map_set.md#erase).
- No vector, apagar invalida iteradores/referências na posição removida e nas seguintes. Use o iterador retornado ao apagar em um loop.

**Referência C++17:** [N4659: unique](https://timsong-cpp.github.io/cppwp/n4659/alg.unique).
