# Aula da semana 2 · Buscas e backtracking

[Semana 2](../README.md) · [Guia completo](guia.md) · [Consulta rápida](consulta-rapida.md) · [Funções por nome](../../../consulta/funcoes/README.md) · [Algoritmos](../../../consulta/algoritmos.md)

**Base oficial:** [slides da aula 2](slides.pdf). A numeração abaixo é a página do PDF, contando a capa como página 1. Esta aula reutiliza STL e prefixos da [semana 1](../../semana-1-stl-prefix-sum/README.md).

## O que entra nesta aula

| Bloco oficial | Slides | O que revisar |
|---|---|---|
| Busca linear, busca binária e funções STL | [2–8](slides.pdf#page=2) | Faixa ordenada, existência, fronteiras e iteradores |
| Monotonicidade e busca binária na resposta | [9–12](slides.pdf#page=9) | Transformar uma resposta candidata em teste de viabilidade |
| Two pointers / janela de soma | [14–29](slides.pdf#page=14) | Maior segmento com soma ≤ S; manter e corrigir o estado |
| Sweep line e prefixos de eventos | [31–38](slides.pdf#page=31) | Cobertura de pontos por intervalos |
| Compressão de coordenadas | [39–41](slides.pdf#page=39) | Ordenar, tirar duplicatas e mapear valores grandes |
| Busca exaustiva | [43–48](slides.pdf#page=43) | Permutações, subconjuntos por bitmask e laços aninhados |
| Backtracking | [49–64](slides.pdf#page=49) | Estado, transição, desfazer, caso base, poda e complexidade |
| Aplicação em Sudoku | [65–78](slides.pdf#page=65) | Evitar escolhas incompatíveis e restaurar o tabuleiro |

## 1. Funções necessárias: chamada, retorno e hipótese

| Recurso | Sintaxe | Semântica / dúvida que resolve |
|---|---|---|
| [sort](../../../consulta/funcoes/sort.md) | `sort(v.begin(),v.end());` | Ordena a própria faixa; retorna `void`; prepare a ordem da busca |
| [binary_search](../../../consulta/funcoes/binary_search.md) | `binary_search(v.begin(),v.end(),x)` | `bool`: existe na faixa ordenada? [slide 7](slides.pdf#page=7) |
| [lower_bound](../../../consulta/funcoes/lower_bound.md) | `lower_bound(v.begin(),v.end(),x)` | Iterador do primeiro `>= x`, em ordem crescente; [slides 7–8](slides.pdf#page=7) |
| [upper_bound](../../../consulta/funcoes/upper_bound.md) | `upper_bound(v.begin(),v.end(),x)` | Iterador do primeiro `> x`, em ordem crescente; [slides 7–8](slides.pdf#page=7) |
| [unique + erase](../../../consulta/funcoes/unique_erase.md) | `v.erase(unique(v.begin(),v.end()),v.end());` | Após sort, deixa uma cópia de cada coordenada; [slide 39](slides.pdf#page=39) |
| [next_permutation](../../../consulta/funcoes/next_permutation.md) | `next_permutation(v.begin(),v.end())` | Muda a sequência; retorna se havia próxima; [slide 46](slides.pdf#page=46) |
| [Vector](../../../consulta/funcoes/vector_string.md) / [iteradores](../../../consulta/funcoes/iteradores.md) | `push_back(x); pop_back(); begin(); end();` | Montar/desfazer escolhas; `end` é fim excluído, nunca elemento |
| [Pair / tuple](../../../consulta/funcoes/pair_tuple.md) | `pair<long long,int>{valor,indice}` | Manter dados juntos após ordenar; relembre [aula 1, slides 33–34](../../semana-1-stl-prefix-sum/aula/slides.pdf#page=33) |
| [Funções e referências](../../../consulta/funcoes/entrada_tipos_funcoes.md#funcoes) | `bool pode(long long x)`; `vector<int>& estado` | Teste de viabilidade e estado recursivo sem cópias desnecessárias |

Não confunda **índice**, **valor**, **iterador** e **bool**. Em vector, `it-v.begin()` converte um iterador em posição; só faça `*it` após conferir `it != v.end()`. As funções de busca dos slides retornam iteradores, embora o texto use a palavra “ponteiro”.

## 2. Busca binária: dois usos diferentes

**Busca em dados ordenados** ([slides 3–8](slides.pdf#page=3)): elimine metade da faixa por comparação. Custo O(log n) por busca em vector; ordenar antes custa O(n log n). Para saber apenas se existe, `binary_search`; para localizar uma fronteira, bounds.

**Busca na resposta** ([slides 9–12](slides.pdf#page=9)): não exige um array de respostas. Exige um predicado monótono: antes de uma fronteira a resposta é falsa, depois verdadeira, ou o inverso.

No **Factory Machines**, `pode(t)` testa se as máquinas produzem a quantidade pedida em t unidades de tempo. Se funciona em t, funciona em qualquer tempo maior. Procure o **menor t viável**, com custo O(n log limite) quando o teste custa O(n).

```cpp
vector<long long> tempos = {3, 5}; // Tempos de produção positivos.
long long meta = 6;
auto pode = [&](long long tempo) {
    long long produzidos = 0;
    for (long long t : tempos) {
        long long quantidade = tempo / t;
        if (quantidade >= meta - produzidos) return true;
        produzidos += quantidade;
    }
    return false;
};
// Só a máquina mais rápida já produz a meta neste limite.
long long l = 0, r = meta * *min_element(tempos.begin(), tempos.end());
while (l < r) {
    long long mid = l + (r - l) / 2;
    if (pode(mid)) r = mid;
    else l = mid + 1;
}
// l = 12: a primeira máquina faz 4 e a segunda faz 2.
```

**Gatilhos:** “menor tempo suficiente”, “menor capacidade”, “maior distância possível”. **Pegadinhas:** provar monotonicidade, escolher limites válidos, garantir progresso e evitar overflow no teste. O produto que define o limite também deve caber em `long long`. Para somar produção, pare ao atingir a meta. [Modelos de mínimo e máximo](algoritmos.md#busca-binaria).

## 3. Two pointers / sliding window

Nos [slides 15–29](slides.pdf#page=15), a pergunta é o **maior segmento contínuo com soma ≤ S**. Expanda a direita, some o novo elemento e, enquanto a soma superar S, remova elementos pela esquerda. Só então atualize o maior comprimento válido.

**Invariante:** a soma corresponde exatamente ao intervalo atual. **Hipótese da estratégia:** valores não negativos; com negativos, aumentar a janela pode diminuir a soma e a decisão de descartar a esquerda deixa de ser segura.

Cada ponteiro avança no máximo n vezes: **O(n)** no total, mesmo com `while` dentro de `for`. [Janela variável](algoritmos.md#janela-variavel).

Outro uso de two pointers é buscar **dois valores de soma X em array ordenado**: esquerda no início e direita no fim; soma pequena → avance a esquerda; soma grande → recue a direita. Essa é uma aplicação complementar da técnica, distinta da janela contínua dos slides. [Pares em ordem](algoritmos.md#two-pointers).

<a id="sweep-line"></a>

## 4. Sweep line: intervalo e desempate importam

Os [slides 31–38](slides.pdf#page=31) transformam intervalos em eventos: começa → +1, termina → −1. Ordenar eventos e acumular a cobertura evita verificar todos os intervalos em cada consulta. A tabela assume `L < R`; descarte intervalos vazios antes de criar eventos para intervalos abertos ou semiabertos.

| Intervalo do enunciado | Condição para um ponto q pertencer | Eventos no mesmo ponto |
|---|---|---|
| Fechado `[L,R]` | `L <= q && q <= R` | Início → consulta → fim |
| Semiaberto `[L,R)` | `L <= q && q < R` | Fim → início → consulta |
| Aberto `(L,R)` | `L < q && q < R` | Fim → consulta → início |

**Atenção aos slides:** a página 32 usa “intervalos abertos”; o vetor de diferenças mostrado na página 37, com +1 em L e −1 em R, inclui L e exclui R. Na sua solução, a condição do enunciado decide a inclusão dos extremos e o desempate. Não copie uma convenção para outra.

Em coordenadas inteiras pequenas, um vetor de diferenças + prefixos pode bastar. Em coordenadas grandes, ordene eventos ou comprima coordenadas. Ordenação de n intervalos e q consultas custa O((n+q) log(n+q)). [Consulta de sweep line](algoritmos.md#sweep-line).

## 5. Compressão de coordenadas

[Slides 39–41](slides.pdf#page=39): valores até 10⁹ não obrigam criar um vetor de tamanho 10⁹. Guarde só coordenadas usadas, ordene e remova duplicatas; depois localize cada coordenada pelo índice de sua busca.

```cpp
vector<long long> coords = {100, 5, 100, 900000000};
sort(coords.begin(), coords.end());
coords.erase(unique(coords.begin(), coords.end()), coords.end());
int indice_de_100 = lower_bound(coords.begin(), coords.end(), 100) - coords.begin();
// coords = {5,100,900000000}; índice de 100 = 1.
```

**Pegadinha:** a compressão preserva ordem e igualdade, não distância nem comprimento. Uma consulta pode cair entre coordenadas ou antes da primeira; `upper_bound(...) - 1` precisa de verificação antes de acessar. [Explicação e condições](algoritmos.md#compressao).

## 6. Busca exaustiva: conte possibilidades antes

| Forma oficial | Como gerar | Custo / risco |
|---|---|---|
| Permutações, [slide 46](slides.pdf#page=46) | Ordene a sequência; processe-a em `do {...} while(next_permutation(...));` | Até n! ordens; se examinar n elementos por ordem, O(n·n!) |
| Subconjuntos, [slide 47](slides.pdf#page=47) | `mask & (1ULL << i)` indica se item i foi escolhido | O(n·2ⁿ) examinando todos os bits; limite de deslocamento e memória |
| Pares/trios, [slide 48](slides.pdf#page=48) | Índices distintos com `i < j < k` | C(n,k) combinações; para k=3, O(n³) |

“Escolher ou não escolher” sugere subconjuntos; “ordenar todos” sugere permutações. Valores iguais não tornam posições iguais. Estimativas de n viável dos [slides 45 e 58–64](slides.pdf#page=45) dependem do trabalho por estado e do tempo limite. [Bitmask](algoritmos.md#bitmask) e [permutações](../../../consulta/funcoes/next_permutation.md).

## 7. Backtracking: escolher, explorar, desfazer

[Slides 50–57](slides.pdf#page=50): descreva o estado mínimo, as escolhas, os casos de parada e as podas. Em cada ramo, **faça a escolha → chame recursivamente → desfaça a escolha**.

- **Estado:** informações para continuar, como `(indice,soma)` ou linha atual e posições já ocupadas.
- **Transição:** incluir/excluir um item ou tentar uma posição disponível.
- **Caso base:** solução completa ou fim sem solução; precisa impedir a recursão infinita.
- **Poda:** descarte apenas ramos que comprovadamente não podem funcionar. `soma > alvo` só permite parar se os valores restantes não puderem reduzir a soma.
- **Restaurar:** remova da solução parcial e limpe as marcações antes do próximo ramo.

Nos [slides 58–64](slides.pdf#page=58), duas escolhas por nível geram O(2ⁿ) estados; permutações têm O(n!) estados. Copiar/imprimir vetores adiciona custo. A poda melhora a prática, mas pode não reduzir o pior caso. [Receita e exemplo](algoritmos.md#backtracking).

O Sudoku dos [slides 65–78](slides.pdf#page=65) aplica essa receita: tente um número permitido pela linha, coluna e bloco, avance e restaure a célula quando a tentativa falhar.

## Aplicação extra: soma de três valores

O problema enviado na conversa combina **preservar índices com pair + sort + two pointers**. Fixe um índice i e procure os outros dois com `l=i+1`, `r=n-1`; mantenha `i < l < r`. A soma deve ser recalculada para esse trio em `long long`. São O(n²) verificações, em vez de O(n³) com três laços.

Essa aplicação complementa a aula; não é o exemplo de janela de soma apresentado nos slides. Uma tentativa que ultrapassou a meta não autoriza encerrar todas as escolhas do primeiro índice. Consulte o [índice da semana](../README.md) para o exemplo explicado e o Homework 2; use o [catálogo de funções](../../../consulta/funcoes/README.md) quando a dúvida for de sintaxe ou retorno.
