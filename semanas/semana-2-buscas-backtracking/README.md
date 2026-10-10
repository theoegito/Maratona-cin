# Semana 2 · Buscas e Backtracking

[Início](../../README.md) · [Semanas](../README.md) · [Consulta de C++](../../consulta/README.md) · [Semana 1](../semana-1-stl-prefix-sum/README.md)

**Base oficial:** aula 2, Buscas. Esta semana trata de busca binária, predicados monótonos, two pointers, janela, sweep line, compressão, busca exaustiva e backtracking.

## Material da aula

| Quero… | Abra |
|---|---|
| Seguir os temas, exemplos e páginas dos slides | [Roteiro da aula](aula/roteiro.md) |
| Ver o material original | [Slides · Buscas](aula/slides.pdf) |
| Entender as ideias e suas pré-condições | [Guia explicado](aula/guia.md) |
| Consultar funções, custos e cuidados rapidamente | [Consulta da semana](aula/consulta-rapida.md) · [PDF imprimível](aula/consulta-rapida.pdf) |
| Implementar a técnica com uma receita | [Algoritmos desta semana](aula/algoritmos.md) |

## Tema → função → aplicação

| Tema oficial | Funções / ideias para lembrar | Exercícios e templates |
|---|---|---|
| Busca binária e busca na resposta | [binary_search](../../consulta/funcoes/binary_search.md), [bounds](../../consulta/funcoes/lower_bound.md), predicado ok(mid) | [Homework 2: A, I e J](homework-2/README.md) · [receitas mínimo/máximo](aula/algoritmos.md#busca-binaria) |
| Two pointers e janela | [sort](../../consulta/funcoes/sort.md), [pair e índices](../../consulta/funcoes/pair_tuple.md), expandir/encolher | [Homework 2: C, K e L](homework-2/README.md) · [pares](aula/algoritmos.md#two-pointers) · [janela](aula/algoritmos.md#janela-variavel) |
| Sweep line e compressão | Eventos, ordem dos empates, [sort/unique](../../consulta/funcoes/unique_erase.md), [bounds](../../consulta/funcoes/upper_bound.md) | [Homework 2: D e E](homework-2/README.md) · [sweep](aula/algoritmos.md#sweep-line) · [compressão](aula/algoritmos.md#compressao) |
| Permutações | [next_permutation](../../consulta/funcoes/next_permutation.md), ordenar antes, bool | [Homework 2: N](homework-2/N.cpp) · [template](templates/next_permutation.cpp) |
| Bitmask e subconjuntos | Testar bits, long long, custo 2ⁿ | [Homework 2: G, M e O](homework-2/README.md) · [receita](aula/algoritmos.md#bitmask) |
| Recursão/backtracking | [Funções e lambda](../../consulta/funcoes/entrada_tipos_funcoes.md#funcoes), escolher/validar/desfazer | [Homework 2: B e F](homework-2/README.md) · [receita](aula/algoritmos.md#backtracking) |

**Aplicação extra:** a soma de três valores do Contest 3 combina o agrupamento de valor/índice da semana 1 com a busca por dois ponteiros desta semana. [Entender a questão e o erro do rascunho](contest-3/README.md).

## Atividades e programas

| Material | Conteúdo |
|---|---|
| [Homework 2](homework-2/README.md) | 14 originais: A, B, C, D, E, F, G, I, J, K, L, M, N, O |
| [Contest 3](contest-3/README.md) | H: Sum of Three Values; rascunho original separado de exemplo completo |
| [11 templates](templates/README.md) | Buscas, pares/trios, janela, eventos, permutações, máscaras e recursão |
| [Verificação](verificacao/validacao.md) | Histórico e [script reproduzível](verificacao/verificar.py); [conferência atual](../../consulta/verificacao/organizacao-semanas.md) |

Para escolher uma técnica, confira n, negativos, contiguidade, índices originais e monotonicidade. [Checklist explicado](../../consulta/como-escolher.md).
