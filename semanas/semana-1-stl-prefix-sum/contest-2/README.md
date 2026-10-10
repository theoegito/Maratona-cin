# Contest 2 · semana 1

[Semana 1 · STL e Prefix Sum](../README.md) · [Homework 1](../homework-1/README.md) · [Consulta de C++](../../../consulta/README.md)

Os arquivos abaixo vieram da pasta local `Contest_2`, copiados sem edição. As associações explicam o código; sem os enunciados completos ou resultados do juiz, não indicam submissão aceita.

| Questão | Código original | Ideia e funções para revisar |
|---|---|---|
| F | [F.cpp](F.cpp) | Contagem por faixas de dígitos decimais; divisão inteira, potências de 10 e [long long](../../../consulta/funcoes/entrada_tipos_funcoes.md#tipos-overflow) |
| H | [H.cpp](H.cpp) | Comprimentos de blocos consecutivos, `2*min(bloco_anterior,bloco_atual)`; [min/max](../../../consulta/funcoes/min_max.md), manter estado e ordem original |

**F:** pela leitura, calcula quantos positivos até cada número têm quantidade ímpar de dígitos. O laço trabalha com potências inteiras; não substitua por pow sem considerar arredondamento.

**H:** guarda o tamanho de dois blocos vizinhos e atualiza o melhor comprimento. Ordenar destruiria os blocos originais. É uma aplicação de leitura, estado e comparação; não é uma consulta de prefix sum.

Os dois originais compilaram e foram testados com referências simples sob essas hipóteses. [Registro atual](../../../consulta/verificacao/organizacao-semanas.md).
