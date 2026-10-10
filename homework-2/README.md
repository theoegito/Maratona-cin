# Homework 2 - buscas e backtracking

## Por onde começar

| Quero... | Abra |
|---|---|
| Entender as ideias e reconhecer problemas | [Guia explicado](guias/guia.md) |
| Consultar funções, custos e pegadinhas | [Consulta rápida](guias/consulta-rapida.md) |
| Imprimir os lembretes | [PDF](guias/consulta-rapida.pdf) |
| Executar exemplos C++17 | [Templates](templates/) |
| Conferir compilação e integridade | [Verificação](verificacao/validacao.md) |
| Rever lacunas da primeira semana | [Complemento](../guias/complemento-semana-1.md) |

**Roteiro:** sort e bounds → two pointers e janela → sweep line → busca na resposta → permutações → máscaras → backtracking.

## Originais

Os **14 originais solicitados** estão completos: A,B,C,D,E,F,G,I,J,K,L,M,N,O. A-D foram fornecidos diretamente pelo usuário em 10/10/2026; os outros dez vieram da conversa anterior. Todos foram copiados sem edição e preservados byte a byte. Não há arquivo H solicitado.

| Arquivo | Ideia identificada pela leitura do código |
|---|---|
| [A](solucoes/A.cpp) | Busca binária na resposta: mínimo tempo de produção das máquinas |
| [B](solucoes/B.cpp) | Sudoku por recursão/backtracking; escolher, validar e desfazer |
| [C](solucoes/C.cpp) | Sort e two pointers: maior grupo com amplitude até 5 |
| [D](solucoes/D.cpp) | Sweep line: máximo de clientes simultâneos, saídas antes de entradas nos empates |
| [E](solucoes/E.cpp) | Intervalos fechados, bounds e paridade de mudanças |
| [F](solucoes/F.cpp) | Oito rainhas com obstáculos; fazer e desfazer |
| [G](solucoes/G.cpp) | Máscaras de conjuntos e cobertura da união |
| [I](solucoes/I.cpp) | Maximizar distância mínima com busca na resposta |
| [J](solucoes/J.cpp) | Minimizar maior soma de grupos contíguos |
| [K](solucoes/K.cpp) | Maior janela com soma limitada |
| [L](solucoes/L.cpp) | Par com soma alvo; índices originais |
| [M](solucoes/M.cpp) | Partição por máscaras, menor diferença |
| [N](solucoes/N.cpp) | Permutações distintas de uma palavra |
| [O](solucoes/O.cpp) | Enumerar subconjuntos com soma e amplitude limitadas |

Sem os enunciados completos, essas associações explicam o código e não comprovam aceitação pelo juiz. Os avisos e pré-condições estão na verificação.

## Como compilar e executar

Cada arquivo é independente e tem seu próprio main:

```sh
g++ -std=c++17 -O2 -Wall -Wextra templates/bounds.cpp -o programa
```

No Linux: `./programa`. No PowerShell: `.\programa.exe`.
Exemplo de bounds: entrada `5 3` e `1 3 3 3 5`; saída `1 4 3` (índices do lower/upper e quantidade).

Os templates têm cabeçalhos explícitos, comentários de entrada e hipóteses. Os originais usam o ambiente GNU com bits/stdc++.h.

## Conteúdo oficial e extras

Base oficial: `#1 Introdução.pdf` (STL, complexidade, prefixos, sort, bounds, next_permutation) e `-2 Buscas.pdf` (busca binária, resposta monótona, two pointers, sweep line, recursão/backtracking). Os PDFs foram consultados integralmente; o material de referência sincronizado foi preservado. Bitmask é **conteúdo oficial da aula 2**, no slide 47 (Subconjuntos). Compressão de coordenadas também é oficial, nos slides 39-41. O guia identifica também os demais extras e esclarecimentos de precisão.
