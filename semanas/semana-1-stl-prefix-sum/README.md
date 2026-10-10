# Semana 1 · STL e Prefix Sum

[Início](../../README.md) · [Semanas](../README.md) · [Consulta de C++](../../consulta/README.md) · [Semana 2](../semana-2-buscas-backtracking/README.md)

**Base oficial:** aula 1, Introdução. Esta semana cobre a linguagem necessária para os exercícios, containers e funções da STL, complexidade, somas de prefixos e pilha monotônica.

## Material da aula

| Quero… | Abra |
|---|---|
| Seguir os assuntos na ordem dos slides | [Roteiro da aula, com páginas e atalhos](aula/roteiro.md) |
| Ver o material original | [Slides · Introdução](aula/slides.pdf) |
| Estudar C++ com explicações e exemplos | [Guia completo](aula/guia.md) |
| Relembrar a sintaxe rapidamente | [Consulta da semana](aula/consulta-rapida.md) · [PDF imprimível](aula/consulta-rapida.pdf) |
| Rever detalhes e simplificações dos slides | [Complemento](aula/complemento.md) |

## Tema → função → aplicação

| Tema oficial | Funções / sintaxe para lembrar | Aplicação nesta semana |
|---|---|---|
| Entrada, tipos e funções | [cin, getline, const, referência, return, lambda](../../consulta/funcoes/entrada_tipos_funcoes.md) | Ler corretamente; evitar cópias e overflow |
| Vector, string e dados agrupados | [push_back, erase, reserve, substr](../../consulta/funcoes/vector_string.md) · [pair/tuple](../../consulta/funcoes/pair_tuple.md) | [Homework 1: B, K e N](homework-1/README.md) |
| Map, set e multiset | [find, count, [], erase](../../consulta/funcoes/map_set.md) | [Homework 1: B, E e M](homework-1/README.md) |
| Stack, queue, deque e heap | [top, front, push, pop, greater](../../consulta/funcoes/pilha_fila_heap.md) | [Homework 1: A, C e D](homework-1/README.md) |
| Algoritmos STL e iteradores | [Catálogo de funções](../../consulta/funcoes/README.md) · [begin/end e retornos](../../consulta/funcoes/iteradores.md) | Ordenar, procurar, somar, inverter, contar e remover |
| Prefix sum | [Montagem e consulta de intervalos](aula/algoritmos.md#prefix-sum) | [Homework 1: I](homework-1/I.cpp) · [template](templates/prefix_sum.cpp) |
| Prefixos + set, existência | [Roteiro oficial](aula/roteiro.md#prefixos) | A contagem com map é extensão: [Homework 1: M](homework-1/M.cpp) |
| Pilha monotônica | [Menor anterior estrito](aula/algoritmos.md#pilha-monotonica) | [Template](templates/pilha_monotonica.cpp) |

Janela fixa, prefixos com frequências e greedy com heap são aplicações das soluções; o [roteiro](aula/roteiro.md) distingue essas extensões do conteúdo oficial.

## Atividades e programas

| Material | Conteúdo |
|---|---|
| [Homework 1](homework-1/README.md) | 9 originais: A, B, C, D, E, I, K, M, N; assuntos e instruções por arquivo |
| [Contest 2](contest-2/README.md) | F: contagem por dígitos; H: blocos consecutivos, min/max |
| [7 templates](templates/README.md) | Base, prefixos, janela fixa, prefixos + map, ordenação, heap e pilha monotônica |
| [Verificação](verificacao/validacao.md) | Registro anterior da semana; [conferência atual](../../consulta/verificacao/organizacao-semanas.md) |

**Para uma dúvida durante a questão:** consulte o [catálogo](../../consulta/funcoes/README.md) pelo nome ou [como escolher](../../consulta/como-escolher.md) pelo objetivo. A próxima semana aplica essas ferramentas às [buscas](../semana-2-buscas-backtracking/README.md).
