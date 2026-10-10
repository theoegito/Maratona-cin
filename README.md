# Maratona CIn · meu caderno de C++

Soluções e material de estudo da preparação para a Maratona CIn, com explicações para quem está começando em C++ e programação competitiva.

## Por onde começar

| Quero… | Abra |
|---|---|
| Entender os comandos com calma | [Guia de C++](guias/guia-cpp.md) |
| Consultar sintaxe enquanto resolvo | [Consulta rápida](guias/consulta-rapida.md) |
| Ler ou imprimir a consulta rápida | [PDF complementar](guias/consulta-rapida.pdf) |
| Ver meus códigos enviados | [Soluções](solucoes/) |
| Testar exemplos pequenos e comentados | [Templates](templates/) |

**Sugestão de estudo:** template e entrada/saída → `vector` e `string` → STL → complexidade → prefix sum → janela deslizante → prefix sum com `map` → greedy com heap → comparadores.

## Organização

```text
maratona-cin/
├── README.md
├── solucoes/                  # Os nove .cpp originais
├── guias/
│   ├── guia-cpp.md             # Explicações e exemplos
│   ├── consulta-rapida.md      # Tabelas e lembretes
│   └── consulta-rapida.pdf     # Complemento para leitura offline
├── templates/                 # Programas didáticos independentes
└── verificacao/
    ├── originais-sha256.txt    # Registro de integridade
    └── validacao.md            # O que foi conferido
```

## Minhas soluções

Os arquivos abaixo foram copiados **sem alterar seu conteúdo, formatação ou quebras de linha**. Os assuntos foram identificados pela leitura do código; os enunciados completos e o histórico de submissões não vieram com os anexos. Por isso, esta tabela não afirma que as soluções foram aceitas pelo juiz.

| Arquivo | O que o código pratica |
|---|---|
| [A.cpp](solucoes/A.cpp) | `deque`, inserção/remoção nas duas pontas e atualização da contagem de pares |
| [B.cpp](solucoes/B.cpp) | `map` de nomes e pontos, `find`, acumulação e ordem original em `vector` |
| [C.cpp](solucoes/C.cpp) | Simulação com três `stack`, `top`, `pop` e registro de operações |
| [D.cpp](solucoes/D.cpp) | Greedy com `priority_queue` mínima e manutenção de uma soma não negativa |
| [E.cpp](solucoes/E.cpp) | Janela de tamanho fixo, frequências com `map` e números distintos |
| [I.cpp](solucoes/I.cpp) | Prefix sum e consultas de soma em intervalos |
| [K.cpp](solucoes/K.cpp) | `string`, caracteres `'0'`/`'1'` e contagem de blocos consecutivos |
| [M.cpp](solucoes/M.cpp) | Prefix sum + `map` para contar subarrays com soma alvo |
| [N.cpp](solucoes/N.cpp) | `sort` com comparador de concatenações de strings |

Se encontrar um erro, registre a correção em uma nova versão com uma explicação. O registro dos anexos em [originais-sha256.txt](verificacao/originais-sha256.txt) permite conferir a preservação desta primeira versão.

## Como compilar e executar

Cada `.cpp` tem seu próprio `main`. Compile **um arquivo por vez**; não junte todos em um único executável.

Com um compilador GCC instalado, por exemplo:

```sh
g++ -std=c++17 -O2 -Wall -Wextra solucoes/I.cpp -o programa
```

| Parte do comando | Significado |
|---|---|
| `g++` | Compilador de C++ |
| `-std=c++17` | Usa a versão C++17 da linguagem |
| `-O2` | Ativa otimizações usuais |
| `-Wall -Wextra` | Mostra avisos úteis; um aviso não é necessariamente erro |
| `solucoes/I.cpp` | Arquivo que será compilado |
| `-o programa` | Nome do executável gerado |

No Linux/macOS, execute `./programa`. No PowerShell do Windows, execute `.\programa.exe`. Digite a entrada esperada pelo problema e pressione Enter. Para encerrar entrada até EOF, use Ctrl+D em um terminal Unix ou Ctrl+Z seguido de Enter no Windows.

Exemplo pequeno para `I.cpp`:

```text
Entrada:
5 3
2 4 1 3 5
1 3
2 5
4 4

Saída:
7
13
3
```

Os originais usam `<bits/stdc++.h>`, um atalho do GCC/libstdc++ comum em maratonas. Ele não faz parte do padrão C++; para maior portabilidade, veja os cabeçalhos explícitos nos templates. Em `C.cpp`, a função livre `size(...)` requer C++17 ou posterior.

## Exemplos para experimentar

| Programa | Entrada resumida | Ideia |
|---|---|---|
| [base.cpp](templates/base.cpp) | Template para preencher | Entrada/saída e estrutura mínima |
| [prefix_sum.cpp](templates/prefix_sum.cpp) | `n q`, valores, consultas `l r` | Soma inclusiva de `l` até `r` |
| [sliding_window.cpp](templates/sliding_window.cpp) | `n k`, valores | Distintos em cada janela de tamanho `k` |
| [subarray_sum_map.cpp](templates/subarray_sum_map.cpp) | `n alvo`, valores | Conta intervalos com soma alvo, inclusive com negativos |
| [greedy_priority_queue.cpp](templates/greedy_priority_queue.cpp) | `n`, valores | Escolhe o máximo de valores mantendo os prefixos da subsequência não negativos |
| [sort_comparador.cpp](templates/sort_comparador.cpp) | `n`, palavras | Menor concatenação em ordem lexicográfica |

Os templates são exemplos adicionais de estudo. As hipóteses, formatos e custos estão nos comentários de cada arquivo e no guia. Antes de adaptar um deles, confira as restrições do enunciado.

## Como adicionar a próxima questão

1. Salve o novo arquivo em `solucoes/`, com um nome que identifique a questão.
2. Compile e teste exemplos, casos mínimos e limites.
3. Acrescente uma linha à tabela acima, com o assunto que praticou.
4. Anote uma pegadinha nova no guia ou na consulta rápida.
5. Faça um commit explicando a mudança, como `Adiciona questão F e anotação sobre set`.

Este repositório é um caderno de aprendizado. As regras da competição determinam quais materiais podem ser consultados durante a prova.


## Contest: índice da segunda semana

- [Homework 2: guia, consulta, templates e originais](homework-2/README.md)
- [Complemento da primeira semana](guias/complemento-semana-1.md)
- [Consulta rápida da segunda semana](homework-2/guias/consulta-rapida.md)
- [PDF imprimível da segunda semana](homework-2/guias/consulta-rapida.pdf)
- [Verificação e pendências do Homework 2](homework-2/verificacao/validacao.md)

Todo o conteúdo anterior permanece preservado. A pasta solucoes/ continua sendo a primeira semana.
