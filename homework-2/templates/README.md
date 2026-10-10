# Templates C++17

[Início](../../README.md) · [Todos os templates](../../consulta/templates.md) · [Consulta de contest](../../consulta/README.md)

Cada programa lê entrada padrão e imprime a resposta. São exemplos didáticos adicionais, não versões editadas dos originais.

| Arquivo | Entrada | Saída |
|---|---|---|
| bounds.cpp | n x; n valores | lower upper ocorrências, índices 0-based |
| sort_indices.cpp | n; n valores | valor índice original 1-based por linha |
| next_permutation.cpp | palavra | permutações distintas por linha |
| two_pointers.cpp | n alvo; n valores | dois índices 1-based ou IMPOSSIBLE |
| sliding_window.cpp | n S; n valores >=0 | maior comprimento com soma<=S |
| sweep_line.cpp | n q; n pares l r; q valores | coberturas de intervalos fechados |
| binary_search_resposta.cpp | n k; n valores >=0 | menor maior soma de até k grupos |
| bitmask.cpp | n; pesos >=0 | diferença mínima de grupos |
| backtracking.cpp | n; tabuleiro ./* | número de arranjos de rainhas |
| recursao_subset.cpp | n alvo; n valores | número de subconjuntos com soma alvo |

Confira as hipóteses e custos nos comentários. O sweep usa intervalos **fechados**, explicitamente diferente do enunciado de intervalos abertos da aula. Bitmask é oficial da aula 2 (slide 47). Recursão de subconjuntos conta conjuntos de índices, portanto valores repetidos podem gerar escolhas distintas.

Revisão oficial da semana 1: `pilha_monotonica.cpp` lê n e n valores, imprime índices 1-based do menor estrito mais próximo à esquerda, ou 0 se não existe; O(n).
