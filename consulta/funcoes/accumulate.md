# accumulate — somar com o tipo certo

[Início](../../README.md) · [Consulta de contest](../README.md) · [Todas as funções](README.md)

**Palavras-chave:** accumulate, soma, sum, total, somatório, 0LL, long long, overflow, numeric.

> Retorna o acumulador final. **O tipo do valor inicial determina o tipo do acumulador.** Cabeçalho `<numeric>`.

## Sintaxe

Fragmento em `main`, com `<numeric>`, `<vector>` e `using namespace std;`.

```cpp
vector<int> v = {2000000000, 2000000000};
long long total = accumulate(v.begin(), v.end(), 0LL); // 4000000000.
// accumulate(...,0) acumularia em int, mesmo atribuindo a long long depois.
```

Percorre `[first,last)` e começa em init. Faixa vazia retorna init. O(n) aplicações da operação; `0.0` escolhe double, `0LL` escolhe long long. O total ainda deve caber no tipo escolhido.

## Operação própria

```cpp
vector<int> v = {2, 3, 4};
long long produto = accumulate(v.begin(), v.end(), 1LL,
                              [](long long a, int b) { return a * b; }); // 24.
```

O valor inicial faz parte da conta. Produto inicia em 1, soma em 0. No C++17, accumulate percorre na ordem; não altere os elementos/faixa dentro da operação. Não use produto se pode ultrapassar long long.

## Pegadinha que salva

Uma variável long long recebe o resultado **depois** da expressão. Em multiplicação de ints, use `1LL*a*b` desde o início; na soma da faixa, use `0LL`.

[Prefixos: várias consultas de soma](../../semanas/semana-1-stl-prefix-sum/aula/algoritmos.md#prefix-sum) · [Tipos e overflow](entrada_tipos_funcoes.md#tipos-overflow)

**Referência C++17:** [N4659: accumulate](https://timsong-cpp.github.io/cppwp/n4659/accumulate).
