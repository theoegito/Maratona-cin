# Contest 3 · semana 2

[Semana 2 · Buscas e Backtracking](../README.md) · [Homework 2](../homework-2/README.md) · [Consulta de C++](../../../consulta/README.md)

## H · Sum of Three Values

**Palavras-chave:** soma de três, three sum, trios, índices distintos, pair, posição original, sort, two pointers, O(n²), time limit.

Encontrar três posições distintas cujos valores somam x. No enunciado fornecido, n<=5000 e os valores são positivos até 10⁹.

| Material | O que contém |
|---|---|
| [H.cpp](H.cpp) | Rascunho da pasta local Contest_3, preservado byte a byte. Está incompleto no laço `for (int j = 0; j )` e não compila |
| [Exemplo completo C++17](../templates/soma_tres_valores.cpp) | Ordena pares {valor,índice original}, fixa um valor e busca os outros dois com dois ponteiros |
| [Pair/tuple e posições originais](../../../consulta/funcoes/pair_tuple.md#indices-originais) | Como agrupar dados, acessar first/second e preservar associações ao ordenar |
| [Escolher pela restrição](../../../consulta/como-escolher.md#soma-tres-valores) | Por que três laços dão TLE e como reconhecer a busca O(n²) |
| [Two pointers da aula](../aula/roteiro.md) | Base oficial; trios são uma aplicação adicional |

### Ideia da solução

1. Guarde cada valor junto da posição original; sort move os dois juntos.
2. Fixe j. Comece l=j+1 e r=n-1, exigindo l<r.
3. Se a soma for pequena, avance l; se grande, recue r; se igual, imprima os índices originais.

Cada busca move as pontas em uma única direção. Custo O(n²) após ordenar, contra O(n³) de enumerar os três índices. Use long long: a soma pode passar do limite de int. Valores repetidos são permitidos; as posições continuam distintas.

### Erro observado no código enviado na conversa

Além do custo cúbico, o bool compartilhado `estourou` encerrava todas as buscas. Em `1 2 2 2 5`, alvo 6, a dupla `1+5` ativava a parada antes de testar `2+2+2`. Uma poda para o primeiro elemento atual não descarta automaticamente todos os primeiros elementos seguintes.

O rascunho local e o exemplo completo ficam separados. [Compilação e testes registrados](../../../consulta/verificacao/organizacao-semanas.md).
