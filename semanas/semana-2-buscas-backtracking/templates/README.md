# Semana 2 · templates C++17

[Semana 2](../README.md) · [Todos os templates](../../../consulta/templates.md) · [Consulta de C++](../../../consulta/README.md)

Cada programa lê entrada padrão e imprime a resposta. São exemplos didáticos adicionais, não versões editadas dos originais.

| Programa | Entrada / resultado | Hipótese ou cuidado |
|---|---|---|
| [bounds.cpp](bounds.cpp) | n x, valores → limites e ocorrências | Índices 0-based; ordena antes de buscar |
| [sort_indices.cpp](sort_indices.cpp) | n, valores → valor e posição original | Índices 1-based; comparação de pair |
| [next_permutation.cpp](next_permutation.cpp) | palavra → permutações distintas | Ordena antes; quantidade pode ser fatorial |
| [two_pointers.cpp](two_pointers.cpp) | n alvo, valores → dois índices ou IMPOSSIBLE | Elementos distintos; O(n log n) com sort |
| [soma_tres_valores.cpp](soma_tres_valores.cpp) | n alvo, valores → três índices ou IMPOSSIBLE | Aplicação extra; índices distintos; O(n²) |
| [sliding_window.cpp](sliding_window.cpp) | n S, valores → maior trecho com soma<=S | Valores não negativos; S>=0 |
| [sweep_line.cpp](sweep_line.cpp) | n q, pares l r, pontos → coberturas | Intervalos fechados; cuidar dos empates |
| [binary_search_resposta.cpp](binary_search_resposta.cpp) | n k, valores → menor maior soma dos grupos | Valores não negativos; n>=1 e k>=1 |
| [bitmask.cpp](bitmask.cpp) | n, pesos → menor diferença entre grupos | Pesos não negativos; n pequeno; O(n·2ⁿ) |
| [backtracking.cpp](backtracking.cpp) | n, tabuleiro ./* → arranjos de rainhas | 1<=n<=12; escolher, validar e desfazer |
| [recursao_subset.cpp](recursao_subset.cpp) | n alvo, valores → quantidade de subconjuntos | Inclui vazio; aceita negativos; O(2ⁿ) |

Compile um programa por vez. Exemplo, a partir da raiz do repositório:

```sh
g++ -std=c++17 -O2 -Wall -Wextra semanas/semana-2-buscas-backtracking/templates/two_pointers.cpp -o programa
```

Confira as hipóteses e custos nos comentários. O sweep usa intervalos **fechados**; veja a [nota sobre os limites nos slides](../aula/roteiro.md#sweep-line). Bitmask é oficial da aula 2 (página 47). A recursão de subconjuntos conta conjuntos de índices: valores repetidos podem gerar escolhas distintas.

Os códigos originais ficam em [Homework 2](../homework-2/README.md) e [Contest 3](../contest-3/README.md). Para revisar a pilha monotônica da aula anterior, consulte o [template da semana 1](../../semana-1-stl-prefix-sum/templates/pilha_monotonica.cpp).
