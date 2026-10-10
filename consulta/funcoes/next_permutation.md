# next_permutation — próxima permutação

[Início](../../README.md) · [Consulta de contest](../README.md) · [Todas as funções](README.md)

**Palavras-chave:** next_permutation, permutation, permutação, anagrama, todas as ordens, lexicográfica, duplicatas, fatorial.

> Modifica a sequência para a próxima ordem lexicográfica e retorna **bool**. Ao retornar false, rearranja para a menor ordem.

## Enumerar todas as ordens distintas

`<algorithm>` + `<string>` + `<iostream>`. Fragmento em `main`, com `using namespace std;`.

```cpp
string s = "aab";
sort(s.begin(), s.end()); // Começa pela primeira ordem.
do {
    cout << s << '\n';   // aab, aba, baa.
} while (next_permutation(s.begin(), s.end()));
```

Valores iguais não geram cópias extras da mesma permutação ao partir de uma sequência ordenada. `prev_permutation` percorre no sentido contrário; para enumerar todas com ela, comece pela maior ordem.

## Custos e pegadinhas

- O(n) no pior caso por chamada; visitar/imprimir P ordens custa O(nP), com P<=n!.
- Guardar todas pode gastar O(nP) de memória; imprimir diretamente usa O(n) de estado, se o formato permitir.
- `while(next_permutation(...))` sem o do ignora a configuração inicial.
- Começar desordenado visita somente as ordens posteriores à atual até voltar à primeira.
- Permutar modifica os dados. N pequeno não dispensa verificar o tamanho da saída.

[Programa completo](../../homework-2/templates/next_permutation.cpp) · [Escolhas com poda: backtracking](../algoritmos.md#backtracking)

**Referência C++17:** [N4659: geradores de permutações](https://timsong-cpp.github.io/cppwp/n4659/alg.permutation.generators).
