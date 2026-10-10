# Templates C++17 · copiar, compilar e adaptar

[Início](../README.md) · [Consulta de contest](README.md) · [Funções](funcoes/README.md) · [Algoritmos](algoritmos.md)

Cada arquivo tem **main próprio**, cabeçalhos explícitos, entrada e hipóteses nos comentários. Compile um por vez, a partir da raiz do repositório:

```sh
g++ -std=c++17 -O2 -Wall -Wextra homework-2/templates/bounds.cpp -o programa
```

Execute `./programa` no Linux/macOS ou `.\programa.exe` no PowerShell. Leia os formatos completos do [Homework 2](../homework-2/templates/README.md) ou da [semana 1](../semana-1/README.md).

## Encontrar o programa pelo objetivo

| Template completo | O que faz / palavras-chave | Antes de copiar |
|---|---|---|
| [Base](../templates/base.cpp) | Estrutura mínima, cin, cout, main | Preencher com a lógica do problema |
| [Bounds](../homework-2/templates/bounds.cpp) | lower_bound, upper_bound, índices, contar duplicatas | Ordena os valores; consulta crescente |
| [Sort com índices](../homework-2/templates/sort_indices.cpp) | pair, valor + posição original | Guardar índice antes de ordenar |
| [Comparador de strings](../templates/sort_comparador.cpp) | Menor concatenação, comparator, lambda | Comparação tem custo do comprimento das strings |
| [Permutações](../homework-2/templates/next_permutation.cpp) | next_permutation, anagramas distintos | Número de respostas pode ser fatorial |
| [Prefix sum](../templates/prefix_sum.cpp) | Soma de intervalo, range sum | Consultas 1-based, fechadas |
| [Prefixos + map](../templates/subarray_sum_map.cpp) | Contar subarrays de soma alvo, negativos | freq[0]=1; consultar antes de inserir |
| [Janela fixa](../templates/sliding_window.cpp) | Distintos em todo bloco de tamanho k | 1<=k<=n; apagar frequência zero |
| [Janela variável](../homework-2/templates/sliding_window.cpp) | Maior trecho de soma limitada | Valores não negativos |
| [Two pointers](../homework-2/templates/two_pointers.cpp) | Par com soma alvo, índices originais | Dois elementos distintos; par não é subarray |
| [Sweep line](../homework-2/templates/sweep_line.cpp) | Cobertura por ponto, eventos, intervalos | Este template usa intervalos fechados |
| [Busca na resposta](../homework-2/templates/binary_search_resposta.cpp) | Minimizar maior soma dos grupos | Valores não negativos; predicado monótono |
| [Bitmask](../homework-2/templates/bitmask.cpp) | Partição de pesos, menor diferença | n pequeno; O(n·2ⁿ); pesos não negativos |
| [Recursão de subconjuntos](../homework-2/templates/recursao_subset.cpp) | Contar subconjuntos com soma alvo | Inclui vazio; aceita negativos; veja limites de soma |
| [Backtracking](../homework-2/templates/backtracking.cpp) | n rainhas com obstáculos | 1<=n<=12; escolher, validar, recursar, desfazer |
| [Pilha monotônica](../homework-2/templates/pilha_monotonica.cpp) | Menor anterior estrito, nearest smaller | Saída 1-based; zero quando não existe |
| [Greedy + heap](../templates/greedy_priority_queue.cpp) | Selecionar máximo, vida não negativa | Regra de troca específica deste objetivo |

**Para a sintaxe isolada**, prefira as [páginas de funções](funcoes/README.md). **Para entender a prova e os gatilhos**, prefira as [receitas](algoritmos.md). Os originais das questões ficam separados em [semana 1](../solucoes/) e [Homework 2](../homework-2/solucoes/).
