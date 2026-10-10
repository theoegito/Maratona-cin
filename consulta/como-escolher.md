# Como escolher funções, estruturas e algoritmos no contest

[Início](../README.md) · [Consulta](README.md) · [Funções](funcoes/README.md) · [Algoritmos](algoritmos.md) · [Templates](templates.md)

**Palavras-chave:** reconhecer problema, qual função, qual estrutura, STL, complexidade, limites, TLE, time limit, soma, intervalo, contíguo, índices, negativos, ordenação, pair, two pointers, três valores.

Comece por **o que a resposta pede**, depois escolha como guardar os dados e quais operações executar. O catálogo lembra a sintaxe; a abordagem precisa aproveitar alguma propriedade do problema. As bases vêm das aulas [1: STL e Prefix Sum](../semanas/semana-1-stl-prefix-sum/README.md) e [2: Buscas e Backtracking](../semanas/semana-2-buscas-backtracking/README.md); as aplicações abaixo são explicações complementares.

<a id="tipo"></a>
## 1. O que cada dado representa?

| Preciso guardar… | Estrutura inicial | O que lembrar |
|---|---|---|
| Uma sequência com acesso por índice | [`vector<T>`](funcoes/vector_string.md#vector) | `v[i]` é o elemento; respeitar `0 <= i < size()` |
| Valor e posição, prazo e duração, dois campos associados | [`pair<T,U>`](funcoes/pair_tuple.md#pair) | Escolher significado de `first` e `second`; ordenar move os dois juntos |
| Três ou mais campos associados | [`tuple<T...>`](funcoes/pair_tuple.md#tuple) | `get<0>` ou decomposição; não tem `.first` |
| Frequência ou informação por chave | [`map<K,V>`](funcoes/map_set.md#map) | `m[chave]` pode criar entrada; `find` só consulta |
| Valores distintos ou vizinho na ordem | [`set<T>`](funcoes/map_set.md#set) | Não guarda multiplicidade; use `multiset` para repetições |
| Sempre consultar maior/menor candidato | [`priority_queue`](funcoes/pilha_fila_heap.md#priority-queue) | `top()` consulta; `pop()` remove e retorna `void` |
| Texto e posições dentro do texto | [`string`](funcoes/vector_string.md#string) | `find` retorna índice ou `npos`; `substr(pos,k)` recebe comprimento |

**Tipos:** a soma de três valores até 10⁹ pode chegar a 3×10⁹ e ultrapassar `int`. Guarde valores/somas em `long long`; para multiplicar dois `int`, `1LL*a*b` amplia o cálculo antes de multiplicar. [Tipos, referências e funções](funcoes/entrada_tipos_funcoes.md#tipos-overflow).

<a id="funcoes"></a>
## 2. Qual operação preciso executar?

| Objetivo / palavras-chave | Função ou sintaxe | Semântica indispensável |
|---|---|---|
| Ordenar, crescente, desempate | [`sort`](funcoes/sort.md) | Altera a sequência; `pair` compara campos em ordem |
| Primeiro ≥ x / primeiro > x | [`lower_bound`](funcoes/lower_bound.md) / [`upper_bound`](funcoes/upper_bound.md) | Em sequência crescente; retorna **posição**, possivelmente `end()` |
| Saber se existe em sequência ordenada | [`binary_search`](funcoes/binary_search.md) | Retorna `bool`, não posição |
| Buscar em sequência sem ordenar | [`find`](funcoes/find_count_reverse.md) | Busca linear; retorna iterador |
| Consultar chave em map/set | [`m.find(x)`](funcoes/map_set.md#map-find) | Não cria chave; ausência é `m.end()` |
| Maior/menor valor de uma sequência | [`max_element` / `min_element`](funcoes/min_max.md) | Retorna iterador; vazio exige cuidado |
| Somar todos os valores | [`accumulate`](funcoes/accumulate.md) | Tipo do resultado depende do valor inicial: `0LL` para `long long` |
| Remover repetições | [`sort` + `unique` + `erase`](funcoes/unique_erase.md) | `unique` só agrupa repetidos consecutivos e não diminui o vector sozinho |
| Próxima ordem dos elementos, permutação | [`next_permutation`](funcoes/next_permutation.md) | Retorna se conseguiu avançar; ao terminar, volta à ordem mínima |
| Consultar/remover último ou topo | [`back` / `pop_back`](funcoes/vector_string.md#vector-pop-back), [`top` / `pop`](funcoes/pilha_fila_heap.md) | Salvar o valor antes de remover; exigir estrutura não vazia |
| Percorrer resultado de busca | [`*it`, `it->campo`, `it-begin`](funcoes/iteradores.md) | Valor, campo e posição têm sintaxes diferentes |

Antes de escrever `auto resposta = funcao(...)`, confira **o retorno**. Antes de chamar a função, confira **a pré-condição**: ordenação, intervalo válido, contêiner não vazio ou tamanho do tipo.

<a id="algoritmo"></a>
## 3. Quais propriedades tornam a solução rápida?

| Pista do enunciado | Abordagem | Cuidado que muda a escolha |
|---|---|---|
| Muitas somas de intervalos em vetor estático | [Prefix sum](../semanas/semana-1-stl-prefix-sum/aula/algoritmos.md#prefix-sum) | Preserva a ordem original; prefixo vazio vale zero |
| Contar trechos de soma exata, incluindo negativos | [Prefixos + frequências](../semanas/semana-1-stl-prefix-sum/aula/algoritmos.md#prefixos-map) | Guardar frequência dos prefixos anteriores, não só presença |
| Todos os blocos de comprimento k | [Janela fixa](../semanas/semana-1-stl-prefix-sum/aula/algoritmos.md#janela-fixa) | Retirar quem saiu e incluir quem entrou |
| Segmento de soma limitada, valores não negativos | [Janela variável](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#janela-variavel) | Com negativos, aumentar janela pode diminuir soma; esta receita perde a justificativa |
| Dois elementos de posições distintas somam x | [Sort + two pointers](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#two-pointers) | Se pedir posições originais, guardar `{valor,indice}` |
| Três elementos somam x; n até 5.000 | [Fixar um + two pointers](#soma-tres-valores) | Três laços são O(n³); duas pontas reduzem para O(n²) |
| Menor tempo/capacidade que permite atingir meta | [Busca na resposta](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#busca-minimo) | Provar que a viabilidade muda uma vez: false → true |
| Quantos intervalos simultâneos, entradas/saídas | [Sweep line](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#sweep-line) | Definir a ordem de eventos empatados conforme pontas abertas/fechadas |
| Todas as escolhas sim/não, n pequeno | [Bitmask](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#bitmask) | 2ⁿ cresce rapidamente; percorrer n bits por máscara custa O(n·2ⁿ) |
| Construir escolhas e podar opções impossíveis | [Backtracking](../semanas/semana-2-buscas-backtracking/aula/algoritmos.md#backtracking) | Desfazer estado e justificar cada poda |

**Ordenar muda o problema?** Para escolher quaisquer dois/três itens, ordenar pode ajudar. Para achar um **trecho contíguo na ordem de entrada**, ordenar altera quais itens são vizinhos e geralmente destrói o significado da resposta. Guardar índices não restaura automaticamente a propriedade de contiguidade.

<a id="soma-tres-valores"></a>
## Exemplo de raciocínio: Sum of Three Values

**Pedido:** três posições diferentes com soma x; os valores podem se repetir. **Limite:** n ≤ 5.000. **Saída:** índices da entrada, não valores nem posições depois de ordenar.

1. Guarde cada item como `{valor,indice_original}` em `vector<pair<long long,int>>`.
2. Ordene com `sort`; `.first` dá o valor e `.second` mantém o índice original.
3. Fixe `j`. Procure os outros dois com `l=j+1` e `r=n-1`, mantendo `j<l<r`.
4. Se a soma for menor que x, avance `l`; se for maior, recue `r`. Se for igual, imprima os três `.second`.

**Por que pode mover?** Com j fixo e soma pequena, nenhum r menor resolve com o mesmo l: só reduziria a soma. Portanto descarte l. Com soma grande, nenhum l maior resolve com o mesmo r: só aumentaria a soma. Portanto descarte r. Cada ponteiro anda apenas em uma direção.

**Custo:** ordenar O(n log n), busca O(n²), armazenamento O(n). Para n=5.000, três laços podem examinar aproximadamente **20,8 bilhões de trios**, enquanto esta busca faz no máximo aproximadamente **12,5 milhões de verificações**. Essas contagens explicam a escolha; o tempo real depende do ambiente.

**Poda:** um sinalizador que encerra todos os laços porque uma dupla passou de x pode descartar soluções com outro primeiro elemento. Cada descarte precisa excluir somente candidatos cuja impossibilidade foi demonstrada. Esse raciocínio também vale para podas em backtracking.

Veja [o problema e a explicação do Contest 3](../semanas/semana-2-buscas-backtracking/contest-3/README.md) e o [template completo C++17](../semanas/semana-2-buscas-backtracking/templates/soma_tres_valores.cpp).

<a id="antes-de-enviar"></a>
## 4. Revisão curta antes de enviar

| Pergunta | Exemplo de erro que evita |
|---|---|
| Meu custo cabe no maior n? | O(n³) para n=5.000; permutações para n grande |
| A função retorna valor, iterador, bool ou void? | Imprimir iterador; atribuir resultado de `sort`; esperar valor de `pop` |
| Os tipos aguentam os cálculos intermediários? | Soma de três `int` estoura antes de ser atribuída a `long long` |
| A resposta usa valores ou posições originais? | Imprimir `j` depois de ordenar, em vez de `.second` |
| As posições escolhidas são distintas? | Usar o mesmo elemento duas vezes quando há repetidos |
| Minha condição depende de positivos ou de ordenação? | Aplicar janela de soma com negativos; bounds sem ordenar |
| Tratei ausência, repetidos e menor tamanho permitido? | Acessar `end()`; esquecer zeros; tentar três itens com n<3 |

**Para consultar durante a prova:** abra [Funções](funcoes/README.md) para sintaxe e retorno, [Algoritmos](algoritmos.md) para condições e invariantes, e a página da **semana** para a sequência oficial da aula, homework e contest.
