# Semana 1 · templates C++17

[Semana 1](../README.md) · [Consulta de C++](../../../consulta/README.md) · [Todos os templates](../../../consulta/templates.md)

| Programa | Entrada / resultado | Hipótese ou cuidado |
|---|---|---|
| [base.cpp](base.cpp) | Estrutura de main, cin/cout e cabeçalhos | Preencha com sua lógica |
| [prefix_sum.cpp](prefix_sum.cpp) | n q, valores, consultas l r → somas | Consultas 1-based, fechadas |
| [sliding_window.cpp](sliding_window.cpp) | n k, valores → distintos em cada janela | 1<=k<=n; apagar frequência zero |
| [subarray_sum_map.cpp](subarray_sum_map.cpp) | n alvo, valores → quantidade de subarrays | Aceita negativos; consultar antes de registrar |
| [greedy_priority_queue.cpp](greedy_priority_queue.cpp) | n, valores → máximo escolhido com prefixos não negativos | Regra específica de troca; min-heap |
| [sort_comparador.cpp](sort_comparador.cpp) | n, palavras → menor concatenação | Comparador estrito; custo das strings |
| [pilha_monotonica.cpp](pilha_monotonica.cpp) | n, valores → menor anterior estrito | Índices 1-based, zero se inexistente |

Compile um programa por vez. Exemplo, a partir da raiz do repositório:

```sh
g++ -std=c++17 -O2 -Wall -Wextra semanas/semana-1-stl-prefix-sum/templates/prefix_sum.cpp -o programa
```

Todos os arquivos têm comentários com formato, custo e hipóteses. Os códigos originais das atividades ficam em [Homework 1](../homework-1/README.md) e [Contest 2](../contest-2/README.md).
