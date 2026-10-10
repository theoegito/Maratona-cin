# Conferência da organização por semanas

[Início](../../README.md) · [Semanas](../../semanas/README.md) · [Consulta de C++](../README.md) · [Resultados completos](organizacao-resultados.json)

Verificação em 10/10/2026, a partir do commit `856c4e73d314920bb40c04beca8388ff90e8b98b`. A raiz passou a reunir o conteúdo em **semanas/** e **consulta/**.

## Divisão do material

| Semana | Base oficial | Atividades |
|---|---|---|
| 1 · STL e Prefix Sum | [Slides da aula 1](../../semanas/semana-1-stl-prefix-sum/aula/slides.pdf), funções e containers, complexidade, prefixos e pilha monotônica | Homework 1: 9 originais; Contest 2: F e H |
| 2 · Buscas e Backtracking | [Slides da aula 2](../../semanas/semana-2-buscas-backtracking/aula/slides.pdf), buscas, janela, sweep, compressão, permutações, bitmask e recursão | Homework 2: 14 originais; Contest 3: rascunho H |

Os nove arquivos antes em `solucoes/` são do **Homework 1**, conforme confirmação do autor. Os roteiros indicam as páginas dos slides e distinguem aplicações complementares. Os PDFs de consulta existentes foram preservados; as referências Markdown contêm a navegação mais recente.

## Preservação e compilação

| Conferência | Resultado |
|---|---|
| 42 arquivos C++/PDF já existentes | Bytes, tamanho e SHA-256 preservados após a mudança de pasta |
| 26 códigos originais | 9 do Homework 1 + 14 do Homework 2 + 3 dos contests; SHA-256 conferido |
| Slides das duas aulas | Cópias idênticas aos PDFs fornecidos; fontes locais intactas |
| Exemplos C++ anteriores | Texto dos blocos preservado; receitas distribuídas pelas semanas |
| 44 programas, incluindo 18 templates | 43 compilaram; 1 falha esperada no rascunho original do Contest 3 |
| 14 novos exemplos de funções/iteradores | Compilação C++17 e verificações semânticas passaram |
| 4 novos exemplos dos roteiros | Compilação C++17 passou |

**Falha esperada:** [Contest 3/H.cpp](../../semanas/semana-2-buscas-backtracking/contest-3/H.cpp) está incompleto, com `for (int j = 0; j )` na linha 27. Foi preservado como rascunho; ele não é executado. A [explicação](../../semanas/semana-2-buscas-backtracking/contest-3/README.md) aponta o [programa completo separado](../../semanas/semana-2-buscas-backtracking/templates/soma_tres_valores.cpp).

## Execuções verificadas

- **842 casos de templates:** bounds, ordenação com índices, pilha monotônica, pares, janela, subconjuntos, bitmask, sweep, busca na resposta, permutações, rainhas e soma de três valores.
- **163 casos dos originais:** 20 do Homework 2, 58 de Contest 2/F e 85 de Contest 2/H. Os casos dos contests usam hipóteses inferidas do código; não comprovam aceitação no juiz.
- **Soma de três valores:** 76 casos pequenos confrontados com força bruta e um caso com 5.000 elementos; os índices retornados são distintos e a soma é conferida.

Todos esses testes passaram. Os exemplos novos de funções também verificam tipos de retorno, cópia/referência, comparação, índices e iteradores. Avisos de compilação estão no JSON; os originais não foram corrigidos nem reformatados.

## Reproduzir a verificação

Com Python 3.10+ e GCC no PATH, execute a partir da raiz:

```sh
python semanas/semana-2-buscas-backtracking/verificacao/verificar.py > resultados-locais.json
```

O script resolve a estrutura atual, confere os 26 hashes, compila os 44 programas e executa os 1.005 casos acima. `CXX` permite escolher o compilador. Executáveis são gravados na pasta temporária do sistema.

Os registros antigos de cada semana mantêm os caminhos usados à época. O script trata os nomes anteriores de `solucoes/`; este relatório e seu JSON descrevem a organização atual.

## Navegação

Foram conferidas **44 páginas Markdown, 865 links locais e 311 links com âncora**, além das páginas referenciadas dos dois PDFs. Nenhum link ou âncora inválido foi encontrado. O resultado está em `navegacao` no [JSON completo](organizacao-resultados.json).
