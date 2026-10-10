# Maratona CIn · C++17

**Caderno de contest:** consulta de funções C++17 por sintaxe, significado e retorno, com algoritmos e soluções organizados por assunto.

[Catálogo de funções](consulta/funcoes/README.md) · [Busca por palavras-chave](consulta/README.md) · [Algoritmos](consulta/algoritmos.md) · [Templates](consulta/templates.md)

> **Lembre a chamada e entenda o resultado:** [abra o catálogo de funções →](consulta/funcoes/README.md)<br>
> O que passa nos parâmetros? O que a função faz? Ela modifica os dados? O que retorna?<br>
> Cada referência reúne a sintaxe, um exemplo, as condições de uso e as pegadinhas.

## Funções: sintaxe → significado → retorno

| Chamada / sintaxe C++17 | O que faz | O que retorna | Referência / palavras-chave |
|---|---|---|---|
| `getline(cin,s)` | Lê uma linha, incluindo espaços | Stream; pode testar o sucesso da leitura | [Entrada](consulta/funcoes/entrada_tipos_funcoes.md#getline) · linha inteira, quebra de linha |
| `long long f(const vector<int>& v);` | Declara função que recebe vetor por referência para leitura | `long long` ao chamar `f(v)` | [Funções e parâmetros](consulta/funcoes/entrada_tipos_funcoes.md#funcoes) · assinatura, const, referência, return |
| `v.push_back(x)` / `v.resize(n)` | Acrescenta um elemento / ajusta a quantidade | `void` | [Vector](consulta/funcoes/vector_string.md#vector) · tamanho, reserve, resize |
| `s.substr(pos,k)` | Copia até k caracteres a partir de pos | Nova `string` | [String](consulta/funcoes/vector_string.md#string-substr) · substring, recortar texto |
| `s.find(texto)` | Busca uma sequência de caracteres | Índice ou `string::npos` | [Busca em string](consulta/funcoes/vector_string.md#string-find) · posição, ausência |
| `m.find(chave)` / `m[chave]` | Consulta a chave / acessa ou insere o valor | Iterador ou `end()` / referência ao valor | [Map](consulta/funcoes/map_set.md#map) · dicionário, frequência, inserção |
| `ms.erase(x)` / `ms.erase(it)` | Apaga todas as cópias / uma ocorrência | Quantidade apagada / iterador seguinte | [Set e multiset](consulta/funcoes/map_set.md#erase) · remover, duplicatas |
| `pilha.top()` / `fila.front()` / `heap.top()` | Consulta último / primeiro / maior prioridade | Referência ao elemento; exige não vazio | [Pilha, fila e heap](consulta/funcoes/pilha_fila_heap.md) · LIFO, FIFO, min-heap |
| `estrutura.pop()` | Remove o elemento acessado no topo ou início | `void`; copie o valor antes | [Remoção nas estruturas](consulta/funcoes/pilha_fila_heap.md) · retirar, pop, empty |
| `sort(v.begin(),v.end())` | Ordena o vetor no próprio lugar | `void` | [Ordenação](consulta/funcoes/sort.md) · crescente, comparador, desempate |
| `unique(v.begin(),v.end())` | Compacta iguais consecutivos; ainda falta `erase` | Iterador do novo fim lógico | [Duplicatas e filtros](consulta/funcoes/unique_erase.md) · unique, remove_if |
| `accumulate(v.begin(),v.end(),0LL)` | Soma usando acumulador `long long` | Soma no tipo do valor inicial | [Soma](consulta/funcoes/accumulate.md) · total, 0LL, overflow |
| `min_element(v.begin(),v.end())` | Procura o menor elemento | Iterador; `end()` se a faixa estiver vazia | [Mínimo e máximo](consulta/funcoes/min_max.md) · extremo, valor, posição |
| `next_permutation(v.begin(),v.end())` | Avança para a próxima ordem lexicográfica | `bool`; no fim, volta à primeira ordem | [Permutações](consulta/funcoes/next_permutation.md) · todas as ordens, anagrama |
| `gcd(a,b)` / `lcm(a,b)` | Calcula MDC / MMC | Resultado inteiro | [Funções numéricas](consulta/funcoes/entrada_tipos_funcoes.md#gcd-lcm) · divisor, múltiplo |
| `lower_bound(b,e,x)` / `upper_bound(b,e,x)` | Busca primeiro >=x / >x em faixa ordenada crescente | Iterador ou `e` | [Limites e busca](consulta/funcoes/lower_bound.md) · posição, intervalo, binary_search |

Nos algoritmos acima, `b,e` representam os iteradores de início e fim; o fim é excluído. Para consultar pelo nome, use [Funções A–Z](consulta/funcoes/README.md). Para lembrar pelo objetivo, use o [índice por palavras-chave](consulta/README.md).

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
2. **Só lembra o objetivo:** abra a [consulta de contest](consulta/README.md) e use `Ctrl+F` com “recortar”, “frequência”, “retirar”, “soma alvo” etc. No Mac: `Cmd+F`. Isso busca na página atual.
3. **Quer um arquivo:** no GitHub, use **Go to file** (atalho `t`) e digite, por exemplo, `vector_string.md` ou `next_permutation.cpp`. [Atalhos oficiais](https://docs.github.com/en/get-started/accessibility/keyboard-shortcuts).
4. **Quer ocorrências no repositório:** na busca de código do GitHub, use, por exemplo, `repo:theoegito/Maratona-cin substr`.

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
