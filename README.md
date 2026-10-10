# Maratona CIn · C++17

**Caderno de contest:** sintaxe, significado das funções, algoritmos e soluções organizados para encontrar a informação durante a prova.

[Consulta de contest](consulta/README.md) · [Funções A–Z](consulta/funcoes/README.md) · [Algoritmos](consulta/algoritmos.md) · [Templates](consulta/templates.md)

> **Procurando `lower_bound`? [Abra a página direta →](consulta/funcoes/lower_bound.md)**<br>
> Primeiro **maior ou igual (>=)**, índice, iterador, duplicatas, predecessor, busca binária.<br>
> `upper_bound` é o primeiro **estritamente maior (>)**: [veja a comparação e os intervalos](consulta/funcoes/upper_bound.md).

## Acesso rápido durante o contest

| Preciso lembrar… | Abra direto | Palavras para pesquisar |
|---|---|---|
| Primeiro >=x; posição; contar iguais | [lower_bound](consulta/funcoes/lower_bound.md) | limite inferior, maior ou igual, duplicatas |
| Primeiro >x; último <=x; contar em [L,R] | [upper_bound](consulta/funcoes/upper_bound.md) | limite superior, intervalo, predecessor |
| Saber se x existe numa lista ordenada | [binary_search](consulta/funcoes/binary_search.md) | presença, busca binária, bool |
| Ordenar e desempatar | [sort / stable_sort](consulta/funcoes/sort.md) | comparador, lambda, pair, índice original |
| Apagar repetidos ou filtrar valores | [unique + erase / remove_if](consulta/funcoes/unique_erase.md) | duplicatas, fim lógico, deduplicar |
| Gerar todas as ordens | [next_permutation](consulta/funcoes/next_permutation.md) | permutação, anagrama, lexicográfica |
| Somar sem estourar int | [accumulate](consulta/funcoes/accumulate.md) | 0LL, long long, overflow |
| Buscar chave, contar frequências, apagar uma cópia | [map / set / multiset](consulta/funcoes/map_set.md) | find, count, erase, dicionário |
| Inserir, apagar, buscar ou recortar texto | [vector / string](consulta/funcoes/vector_string.md) | push_back, reserve, resize, find, substr |
| Retirar topo, primeiro, menor ou maior | [stack / queue / deque / heap](consulta/funcoes/pilha_fila_heap.md) | top, front, pop, priority_queue, greater |
| Ler linha; declarar função; passar referência | [Entrada, tipos e funções](consulta/funcoes/entrada_tipos_funcoes.md) | getline, const, auto, return, lambda |

Cada referência mostra **sintaxe C++17 → o que faz → o que retorna → custo → exemplo → pegadinhas**. Para lembrar uma função pelo nome, use o [catálogo completo](consulta/funcoes/README.md).

## Reconhecer o algoritmo

| Pista do enunciado | Receita |
|---|---|
| Muitas somas de intervalos | [Prefix sum](consulta/algoritmos.md#prefix-sum) |
| Contar subarrays de soma exata, inclusive negativos | [Prefixos + map](consulta/algoritmos.md#prefixos-map) |
| Blocos de tamanho k / maior segmento válido | [Janela fixa](consulta/algoritmos.md#janela-fixa) / [sliding window](consulta/algoritmos.md#janela-variavel) |
| Dois números com soma alvo | [Two pointers](consulta/algoritmos.md#two-pointers) |
| Intervalos ativos, eventos, sobreposição | [Sweep line](consulta/algoritmos.md#sweep-line) |
| Menor tempo/capacidade ou maior distância viável | [Busca binária na resposta](consulta/algoritmos.md#busca-binaria) |
| Enumerar subconjuntos ou escolhas com restrições | [Bitmask](consulta/algoritmos.md#bitmask) / [recursão e backtracking](consulta/algoritmos.md#backtracking) |
| Menor anterior / coordenadas enormes / descartar o pior | [Pilha monotônica](consulta/algoritmos.md#pilha-monotonica) / [compressão](consulta/algoritmos.md#compressao) / [greedy + heap](consulta/algoritmos.md#greedy-heap) |

## Estudo e prática por semana

| Material | Semana 1 · fundamentos e STL | Homework 2 · buscas e backtracking |
|---|---|---|
| Índice, soluções e instruções | [Semana 1](semana-1/README.md) | [Homework 2](homework-2/README.md) |
| Explicação para estudar com calma | [Guia C++](guias/guia-cpp.md) + [complemento](guias/complemento-semana-1.md) | [Guia da aula 2](homework-2/guias/guia.md) |
| Consulta por semana | [Markdown](guias/consulta-rapida.md) · [PDF imprimível](guias/consulta-rapida.pdf) | [Markdown](homework-2/guias/consulta-rapida.md) · [PDF imprimível](homework-2/guias/consulta-rapida.pdf) |
| Programas para adaptar | [6 templates](templates/) | [11 templates e suas entradas](homework-2/templates/README.md) |
| Códigos originais preservados | [9 soluções](solucoes/) | [14 soluções](homework-2/solucoes/) |
| Compilação e integridade | [Registro da semana 1](verificacao/validacao.md) | [Registro do Homework 2](homework-2/verificacao/validacao.md) |

As receitas indicam o que vem das aulas **#1 Introdução** e **-2 Buscas** e o que é aplicação ou complemento. O material da primeira semana continua disponível no seu [índice completo](semana-1/README.md); os arquivos de soluções mantêm os bytes originais.

## Encontrar em segundos

1. **Se lembra do nome:** clique no atalho acima ou abra [Funções A–Z](consulta/funcoes/README.md).
2. **Só lembra o objetivo:** abra a [consulta de contest](consulta/README.md) e use `Ctrl+F` com “maior ou igual”, “soma alvo”, “duplicatas”, “linha inteira” etc. No Mac: `Cmd+F`. Isso busca na página atual.
3. **Quer um arquivo:** no GitHub, use **Go to file** (atalho `t`) e digite, por exemplo, `lower_bound.md` ou `binary_search_resposta.cpp`. [Atalhos oficiais](https://docs.github.com/en/get-started/accessibility/keyboard-shortcuts).
4. **Quer ocorrências no repositório:** na busca de código do GitHub, use `repo:theoegito/Maratona-cin lower_bound`.

## Organização e verificação

```text
consulta/       → entrada de contest, funções, receitas e índice de templates
semana-1/       → índice completo da primeira semana
guias/          → guias e PDF da primeira semana
solucoes/       → originais da primeira semana
templates/      → exemplos da primeira semana
homework-2/     → guia, consulta, PDF, templates e 14 originais da segunda semana
verificacao/    → integridade, compilação e conferência da navegação
```

Os templates são programas independentes: compile **um `.cpp` por vez** com C++17. [Formatos de entrada e atalhos para os 17 templates](consulta/templates.md). A [verificação desta organização](verificacao/consulta-contest.md) registra links, exemplos e preservação dos códigos.

Ao adicionar uma questão, use a pasta da semana correspondente, anote seus assuntos no índice e acrescente uma pegadinha ou palavra-chave à consulta relevante.
