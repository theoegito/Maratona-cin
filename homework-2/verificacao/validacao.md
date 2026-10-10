# Verificação do Homework 2

Data: 10/10/2026. Base remota conferida por Git: `5b2436c19d1cdadfce45eb78212cd34b779d2d18`.

## Integridade e completude

- 10 anexos recuperados (E,F,G,I,J,K,L,M,N,O) copiados e comparados byte a byte com os arquivos disponibilizados pela conversa anterior; todos idênticos. SHA-256 e tamanhos em [originais.json](originais.json) e [originais-sha256.txt](originais-sha256.txt).
- **Pendentes A.cpp, B.cpp, C.cpp e D.cpp do Homework 2.** A ferramenta disponibilizou somente os dez últimos anexos. Não foram reconstruídos nem substituídos por arquivos da primeira semana. A solicitação de 14 originais ainda não foi integralmente atendida.
- Todos os arquivos preexistentes da semana 1 preservados: originais/templates/PDFs idênticos aos blobs anteriores; guias e registros sem alteração; README e .gitattributes têm somente acréscimos ao final. Registro: [semana-1-preservada.json](semana-1-preservada.json).
- Fontes sincronizadas em sources/ foram apenas lidas, sem alteração.
- `.gitattributes` desativa conversão de quebras de linha para os novos originais.

## Compilação e execução

| Material | Resultado |
|---|---|
| 10 originais Homework 2 | Todos compilaram individualmente com GCC C++17, -O2 -Wall -Wextra |
| 11 templates Homework 2 e revisão | Todos compilaram com os mesmos flags e -pedantic, sem avisos |
| 9 originais primeira semana | Recompilados; todos compilaram |
| 6 templates primeira semana | Recompilados; todos compilaram |
| Templates Homework 2 e revisão | 765 casos passaram, incluindo comparações com força bruta |
| Originais Homework 2 | Um teste pequeno por arquivo, 10 passaram |
| PDF Homework 2 | 2 páginas renderizadas; revisão visual registrada nesta preparação |

Resultados completos e mensagens do compilador: [resultados.json](resultados.json).

Os testes de templates incluem bounds com ausências/duplicatas/vetor vazio; sort com índices; pares e índices distintos; janelas com zeros e impossível; intervalos fechados degenerados e empates; partições com k=1, k>=n e zeros; máscaras e recursão comparadas a enumeração; permutações com duplicatas; rainhas com obstáculos comparadas a permutações; somas acima de int. Seed fixa 20261010. O script [verificar.py](verificar.py) permite reproduzir compilação, integridade e testes com Python 3 e g++ no PATH. O diretório de executáveis pode ser definido por MARATONA_BUILD_DIR; por padrão usa um diretório temporário. Não altera os originais.

Recompilar a primeira semana não substitui sua validação anterior: os testes desta execução concentram-se no Homework 2. Testes pequenos dos originais não comprovam correção geral ou aceitação no juiz.

## Avisos e hipóteses dos originais, sem edição

- I.cpp: variável distancia_atual não usada. O predicado usa lower_bound desde begin; com distância zero pode reutilizar o mesmo estábulo. Para estudo, prefira percorrer índices crescentes. Sem restrições oficiais completas, não afirmamos que isso muda a resposta final da questão.
- J.cpp: comparação de contador com size() mistura inteiros com/sem sinal. Pressupõe n>=1, k>=1, valores não negativos e somas dentro de long long.
- E.cpp: há uma barra invertida no fim de uma linha; o compilador trata como continuação de linha. Foi preservada. Bounds implementam intervalos fechados e paridade.
- K.cpp: depende de valores não negativos e limite >=0; fora dessas hipóteses a janela pode falhar ou acessar fora do vetor.
- G/M/O: `1 << n` ou `1 << m` opera em int; exige limite de deslocamento válido e dimensões pequenas para viabilidade exponencial. G requer valores entre 1 e n. M/O requerem somas que caibam em long long.
- F.cpp: espera exatamente 8 linhas válidas, com ao menos 8 caracteres cada.
- L.cpp: soma do par deve caber em long long; índices impressos são 1-based.
- N.cpp: guarda todas as permutações; memória cresce com o tamanho da saída.
- Semana 1: avisos de sinal em C e possível inicialização em K continuam documentados no registro anterior; nenhuma correção foi aplicada aos originais.

## Fontes e publicação

Consultados os dois PDFs oficiais fornecidos: aula 1 (Introdução) e aula 2 (Buscas, rev.1.1). Bitmask foi confirmado visualmente no slide 47 da aula 2 e marcado como oficial. Compressão também foi confirmada nos slides 39-41. Pilha monotônica foi confirmada nos slides 59-67 da aula 1. Provas, fronteiras e esclarecimentos de precisão complementam as simplificações dos slides.

O conector GitHub retornou 403 `Resource not accessible by integration` ao tentar criar um blob, mesmo com metadados push=true. Publicação depende de confirmação do Git remoto, registrada separadamente em PUBLICACAO.md. Não inferir publicação a partir de arquivos locais ou permissões declaradas.
