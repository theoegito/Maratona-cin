# Algoritmos: reconhecer, lembrar e copiar

[Início](../README.md) · [Consulta de contest](README.md) · [Funções](funcoes/README.md) · [Templates](templates.md)

Procure pelo **nome, palavra-chave ou sintoma** com `Ctrl+F`. Para a sintaxe das funções da STL, abra a [consulta de funções](funcoes/README.md); para os programas completos, siga o link de cada receita.

## Escolha pela pista do enunciado

| Preciso de… / palavras-chave | Receita | Condição que decide |
|---|---|---|
| Somar muitos intervalos, range sum, soma acumulada | [Prefix sum](#prefix-sum) | Vetor estático; consulta contígua |
| Contar segmentos de soma exata, subarray sum, negativos | [Prefixos + map](#prefixos-map) | Contar prefixos anteriores, não só distintos |
| Todos os blocos de tamanho k, fixed window, distintos | [Janela fixa](#janela-fixa) | Comprimento fixo; negativos permitidos |
| Maior segmento válido, sliding window, soma limitada | [Janela variável](#janela-variavel) | Para esta receita, valores não negativos |
| Dois valores somam alvo, pair sum, duas pontas | [Two pointers: pares](#two-pointers) | Valores ordenados; índices distintos |
| Intervalos ativos, eventos, cobertura, sweep line | [Sweep line](#sweep-line) | Definir se cada ponta é aberta ou fechada |
| Menor tempo/capacidade que funciona, first true | [Busca binária: mínimo](#busca-minimo) | Predicado false → true |
| Maior distância viável, last true, maximizar mínimo | [Busca binária: máximo](#busca-maximo) | Predicado true → false |
| Todas as escolhas sim/não, subset, máscara | [Bitmask](#bitmask) | n pequeno; 2ⁿ possibilidades |
| Gerar soluções com restrições, desfazer, DFS | [Backtracking](#backtracking) | Estado restaurável; árvore pequena ou podável |
| Menor anterior, nearest smaller, próximo maior | [Pilha monotônica](#pilha-monotonica) | Ordem original precisa ser preservada |
| Coordenadas enormes, rank, discretização | [Compressão](#compressao) | Preserva ordem/igualdade, não distância |
| Selecionar máximo de itens, descartar pior, heap | [Greedy + heap](#greedy-heap) | Provar a regra de troca para o problema |

**Escopo das aulas:** two pointers, sweep, busca na resposta, bitmask, recursão/backtracking e compressão são oficiais da aula 2; pilha monotônica é oficial da aula 1. Prefixos, janela fixa e greedy + heap retomam as soluções e os guias da semana 1. A contagem por prefixos + map amplia o exemplo oficial de existência com prefixos + set. As aplicações concretas e os cuidados de fronteiras abaixo complementam as aulas; não são novos enunciados oficiais. Veja [Homework 2](../homework-2/guias/guia.md) e [complemento da semana 1](../guias/complemento-semana-1.md).

### Como copiar os fragmentos

Todos os blocos são **independentes** e ficam dentro de `main`; não junte receitas com nomes repetidos. Considere estes cabeçalhos e `using namespace std;` antes de `main`:

```cpp
#include <algorithm>
#include <cstdint>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
```

Quando uma seção usa `a` e `n`, pressupõe `vector<long long> a` já preenchido e `int n = static_cast<int>(a.size());`, com tamanho que caiba em `int`. Os demais dados de entrada são declarados em **Entradas**. As somas, diferenças e contagens precisam caber em `long long`. A resposta fica na variável indicada; imprima-a no formato exigido pelo juiz.

<a id="prefix-sum"></a>
## Prefix sum — soma de intervalo em O(1)

**Busca:** prefix sum, prefixos, soma acumulada, range sum, somatório, consulta [l,r]. **Gatilho:** muitas consultas de soma no mesmo vetor, sem atualizações.

**Semântica:** `pref[i]` soma os primeiros i elementos. Logo, `pref[r] - pref[l]` soma **[l,r)**. O prefixo vazio vale zero.

**Entradas:** `a`, `n`; índices `int l, r`, com `0 <= l <= r <= n`. **Resultado:** `soma`.

```cpp
vector<long long> pref(n + 1, 0);
for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
long long soma = pref[r] - pref[l]; // [l,r), r não entra
```

**Custo:** montagem O(n), consulta O(1), memória O(n). Negativos funcionam.

**Salva na prova:** para [l,r] fechado e 0-based, use `pref[r+1]-pref[l]`; para entrada 1-based fechada, `pref[r]-pref[l-1]`.

**Pegadinha:** alterar `a` depois da montagem deixa os prefixos desatualizados. `pref[r]-pref[l]` não inclui `a[r]`. Uma diferença entre prefixos também precisa caber no tipo.

**Escopo:** base da semana 1. [Template completo](../templates/prefix_sum.cpp).

<a id="prefixos-map"></a>
## Prefixos + map — contar subarrays de soma K

**Busca:** subarray sum, soma exata, prefix sum map, frequência de prefixos, negativos, count subarrays. **Gatilho:** contar trechos contíguos não vazios de soma K, incluindo negativos e zeros.

**Semântica/invariante:** antes de registrar o prefixo atual `s`, `freq` guarda somente prefixos **anteriores**. Cada prefixo de valor `s-K` forma um trecho de soma K.

**Entradas:** `a`; `long long K`. **Resultado:** `resposta`.

```cpp
map<long long, long long> freq;
freq[0] = 1; // prefixo antes do primeiro elemento
long long s = 0, resposta = 0;
for (long long x : a) {
    s += x;
    auto it = freq.find(s - K); // consulta sem criar chave
    if (it != freq.end()) resposta += it->second;
    ++freq[s]; // registrar DEPOIS de consultar
}
```

**Custo:** O(n log(n+1)) com map, memória O(n). `s`, `s-K` e a resposta devem caber no tipo.

**Salva na prova:** `a={0,0}`, K=0 → 3 trechos. Frequência conta posições distintas de prefixos iguais.

**Pegadinhas:** esquecer `freq[0]=1` perde trechos começando no índice 0; registrar primeiro conta trecho vazio quando K=0; set resolve existência, mas perde multiplicidade. Esta receita não resolve automaticamente o maior trecho com soma ≤ K.

**Escopo:** contagem da semana 1; extensão do exemplo oficial com set. [Template completo](../templates/subarray_sum_map.cpp).

<a id="janela-fixa"></a>
## Janela fixa — distintos em cada bloco de k

**Busca:** fixed sliding window, janela fixa, tamanho k, valores distintos, frequência, quem entra/quem sai. **Gatilho:** a mesma pergunta para todos os blocos de comprimento k.

**Semântica/invariante:** depois da remoção, o map representa exatamente os elementos da janela atual. Chaves com frequência zero são apagadas; `freq.size()` é a quantidade de distintos.

**Entradas:** `a`, `n`; `int k`, com `1 <= k <= n`. **Resultado:** vetor `distintos`, um valor por janela.

```cpp
map<long long, int> freq;
vector<int> distintos;
for (int r = 0; r < n; ++r) {
    ++freq[a[r]];
    if (r >= k && --freq[a[r - k]] == 0) freq.erase(a[r - k]);
    if (r >= k - 1) distintos.push_back(static_cast<int>(freq.size()));
}
```

**Custo:** O(n log(k+1)); map O(k), além do vetor de respostas. Valores negativos são permitidos.

**Salva na prova:** para soma de janela fixa, troque o map por uma soma: adicione `a[r]` e, se r≥k, subtraia `a[r-k]`.

**Pegadinhas:** só há resposta depois de k elementos; frequência zero que fica no map não é valor ativo. Não confunda janela fixa com a janela variável por soma.

**Escopo:** aplicação da semana 1. [Template completo](../templates/sliding_window.cpp).

<a id="janela-variavel"></a>
## Janela variável — maior trecho com soma ≤ S

**Busca:** sliding window, two pointers, segmento contíguo, longest subarray, expandir/encolher, soma limitada. **Gatilho:** expandir pode invalidar; retirar à esquerda nunca piora a validade.

**Semântica/invariante:** após o while, [l,r] tem soma ≤ S; l é a menor fronteira válida para esse r. Cada elemento entra e sai no máximo uma vez.

**Entradas:** `a`, `n`; `long long S >= 0`; **todos os `a[i] >= 0`**. **Resultado:** `melhor`.

```cpp
int l = 0, melhor = 0;
long long soma = 0;
for (int r = 0; r < n; ++r) {
    soma += a[r];
    while (l <= r && soma > S) soma -= a[l++];
    melhor = max(melhor, r - l + 1);
}
```

**Custo:** O(n), memória extra O(1). A soma temporária antes de encolher também deve caber.

**Salva na prova:** para contar todos os trechos com soma ≤ S sob estas mesmas hipóteses, acumule `r-l+1` em long long após encolher; todos esses sufixos são válidos.

**Pegadinha:** negativos quebram a prova: `[4,-3]`, S=2, tem soma total 1, mas a janela descartaria 4 cedo demais. O while dentro do for continua O(n), pois l nunca recua.

**Escopo:** aplicação de two pointers oficial da aula 2. [Template completo](../homework-2/templates/sliding_window.cpp).

<a id="two-pointers"></a>
## Two pointers — dois elementos com soma alvo

**Busca:** two sum, pair sum, duas pontas, dois ponteiros, par, soma alvo, índices originais. **Gatilho:** buscar um par em O(n) depois de ordenar.

**Semântica/invariante:** se a menor+maior soma é pequena, a menor não serve com nenhum candidato atual; elimine-a. Se é grande, elimine a maior. `l < r` exige elementos distintos.

**Entradas:** `a`, `n`; `long long alvo`. **Resultado:** `resposta` contém índices originais 0-based ou {-1,-1}.

```cpp
vector<pair<long long, int>> v;
for (int i = 0; i < n; ++i) v.push_back({a[i], i});
sort(v.begin(), v.end());
int l = 0, r = n - 1;
pair<int, int> resposta = {-1, -1};
while (l < r) {
    long long s = v[l].first + v[r].first;
    if (s == alvo) { resposta = {v[l].second, v[r].second}; break; }
    if (s < alvo) ++l;
    else --r;
}
```

**Custo:** O(n log n) incluindo sort, varredura O(n), memória O(n). Negativos funcionam; a soma do par deve caber.

**Salva na prova:** guarde `{valor,indice}` antes de ordenar; converta para 1-based somente na saída se o enunciado pedir.

**Pegadinha:** ordenar destrói a contiguidade; esta receita busca **par**, não subarray. Contar todos os pares exige tratar duplicatas e suas multiplicidades.

**Escopo:** two pointers oficial da aula 2; pares são aplicação adicional. [Template completo](../homework-2/templates/two_pointers.cpp).

<a id="sweep-line"></a>
## Sweep line — cobertura de intervalos em pontos

**Busca:** varredura, eventos, sweep line, intervalos ativos, cobertura, sobreposição, entrada/saída. **Gatilho:** muitos intervalos e consultas offline em coordenadas grandes.

**Semântica/invariante:** ao processar uma consulta, `ativos` é o número de intervalos que contêm aquele ponto. O desempate na mesma coordenada faz parte dessa definição.

**Entradas:** `vector<pair<long long,long long>> intervalos`, com l≤r; `vector<long long> consultas`. Este código usa **[l,r] fechado**. **Resultado:** `cobertura`, na ordem das consultas; quantidades/tamanhos cabem em int.

```cpp
vector<tuple<long long, int, int>> eventos; // coordenada, tipo, id
for (auto [l, r] : intervalos) {
    eventos.emplace_back(l, 0, -1); // entrada antes da consulta
    eventos.emplace_back(r, 2, -1); // saída depois da consulta
}
for (int i = 0; i < static_cast<int>(consultas.size()); ++i)
    eventos.emplace_back(consultas[i], 1, i);
sort(eventos.begin(), eventos.end());
vector<int> cobertura(consultas.size());
int ativos = 0;
for (auto [x, tipo, id] : eventos) {
    if (tipo == 0) ++ativos;
    else if (tipo == 2) --ativos;
    else cobertura[id] = ativos;
}
```

| Intervalo | Desempate em x: primeiro → último | Quando l=r |
|---|---|---|
| [l,r] | entrada → consulta → saída | Conta naquele ponto |
| [l,r) | saída → entrada → consulta | Descartar: vazio |
| (l,r) | saída → consulta → entrada | Descartar: vazio |
| (l,r] | consulta → saída → entrada | Descartar: vazio |

**Custo:** O((n+q) log(n+q)), memória O(n+q), para n intervalos e q consultas.

**Salva na prova:** alternativa para fechados: ordene `inicios` e `fins`; em x, conte entradas ≤x com `upper_bound(inicios.begin(),inicios.end(),x)-inicios.begin()` e saídas <x com `lower_bound(fins.begin(),fins.end(),x)-fins.begin()`. Cobertura = entradas−saídas; subtraia **índices**, nunca iteradores de vetores diferentes.

**Pegadinhas:** a aula enuncia intervalos **abertos**; adapte os tipos dos eventos em vez de copiar os fechados. Não faça r+1 sem conferir domínio inteiro e overflow. Contar pontos ativos não calcula comprimento da união.

**Escopo:** oficial da aula 2; tabela explicita os cuidados de fronteiras. [Template de intervalos fechados](../homework-2/templates/sweep_line.cpp).

<a id="busca-binaria"></a>
<a id="busca-minimo"></a>
## Busca binária na resposta — menor capacidade viável

**Busca:** binary search on answer, busca na resposta, first true, mínimo viável, dividir vetor, capacidade, minimizar maior soma. **Gatilho:** verificar `ok(x)` é mais fácil que obter a melhor resposta diretamente.

**Semântica/invariante:** `ok(cap)` é false…false,true…true. A resposta está em [lo,hi], e hi é viável. Se mid funciona, reduza hi; senão, elimine mid e tudo à esquerda.

**Entradas:** `a` não negativo, `n >= 1`; `int k >= 1`. Dividir em **até k grupos contíguos não vazios**; soma total cabe em long long. **Resultado:** `lo`.

```cpp
long long lo = *max_element(a.begin(), a.end());
long long hi = accumulate(a.begin(), a.end(), 0LL);
auto ok = [&](long long cap) {
    int grupos = 1;
    long long soma = 0;
    for (long long x : a) {
        if (x > cap - soma) { // evita overflow de soma+x
            if (grupos == k) return false;
            ++grupos; soma = x;
        } else soma += x;
    }
    return true;
};
while (lo < hi) {
    long long mid = lo + (hi - lo) / 2; // arredonda para baixo
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
}
```

**Custo:** O(n log(hi inicial−lo inicial+2)), memória extra O(1). O greedy do predicado abre grupo só quando precisa e usa o mínimo de grupos para aquela capacidade.

**Salva na prova:** escreva `F F F T T T` antes de escolher atualizações. Em Factory Machines, o predicado conta produção até o tempo; pare ao atingir a meta para evitar overflow.

**Pegadinhas:** hi precisa ser viável; negativos invalidam esta divisão gulosa. Para **exatamente k** grupos, a equivalência exige k≤n e poder subdividir os grupos. `0LL` faz accumulate somar em long long.

**Escopo:** busca na resposta oficial da aula 2; divisão em grupos é aplicação. [Template completo](../homework-2/templates/binary_search_resposta.cpp).

<a id="busca-maximo"></a>
## Busca binária na resposta — maior distância viável

**Busca:** last true, maximizar mínimo, aggressive cows, distância mínima, espaçamento, maior viável. **Gatilho:** aumentar a resposta torna o problema mais difícil.

**Semântica/invariante:** `ok(d)` é true…true,false…false. lo é viável; a resposta está em [lo,hi]. O greedy coloca cada item no primeiro local disponível suficientemente distante do anterior.

**Entradas:** `vector<long long> p` com posições; `int c`, com `2 <= c <= p.size()`; diferenças entre posições cabem em long long. Cada posição do vetor pode ser usada uma vez. **Resultado:** `lo`.

```cpp
sort(p.begin(), p.end());
auto ok = [&](long long d) {
    int usados = 1;
    long long ultimo = p[0];
    for (int i = 1; i < static_cast<int>(p.size()); ++i) {
        if (p[i] - ultimo >= d) {
            ultimo = p[i];
            if (++usados >= c) return true;
        }
    }
    return false;
};
long long lo = 0, hi = p.back() - p.front();
while (lo < hi) {
    long long delta = hi - lo;
    long long mid = lo + delta / 2 + delta % 2; // arredonda para cima
    if (ok(mid)) lo = mid;
    else hi = mid - 1;
}
```

**Custo:** sort O(n log n), busca O(n log(amplitude+2)), memória extra O(1) além da ordenação.

**Salva na prova:** `T T T F F F`; mid para cima garante progresso quando `lo+1==hi`.

**Pegadinhas:** usar mid para baixo com `lo=mid` pode travar. Não reutilize posição para d=0. c=1 exige outra definição para distância entre itens. As variantes mínimo/máximo têm atualizações diferentes.

**Escopo:** aplicação da busca oficial da aula 2, presente no original I. [Template da variante mínimo para comparação](../homework-2/templates/binary_search_resposta.cpp); [original I preservado](../homework-2/solucoes/I.cpp).

<a id="bitmask"></a>
## Bitmask — enumerar subconjuntos

**Busca:** máscara de bits, subset, subconjunto, força bruta, todas as escolhas, 2ⁿ, entra/não entra. **Gatilho:** cada índice tem duas escolhas e n é pequeno.

**Semântica:** bit i ligado significa escolher `a[i]`. Máscaras representam conjuntos de **índices**; valores repetidos continuam sendo itens distintos.

**Entradas:** `a`, `n`, com `0 <= n < 64` e 2ⁿ viável; `long long alvo`. **Resultado:** `quantidade`, incluindo o subconjunto vazio se alvo=0.

```cpp
long long quantidade = 0;
for (uint64_t mask = 0; mask < (uint64_t{1} << n); ++mask) {
    long long soma = 0;
    for (int i = 0; i < n; ++i)
        if (mask & (uint64_t{1} << i)) soma += a[i];
    if (soma == alvo) ++quantidade;
}
```

**Custo:** O(n·2ⁿ), memória extra O(1). n<64 evita shift inválido, mas **não** garante tempo viável; perto de 20 já exige estimativa.

**Salva na prova:** ligar bit: `mask |= bit`; desligar: `mask &= ~bit`; alternar: `mask ^= bit`, com `uint64_t bit = uint64_t{1} << i` e i<64.

**Pegadinhas:** `1<<n` usa int antes de atribuir; se vazio é proibido, comece mask=1. Somas parciais e quantidade devem caber em long long. `std::popcount` é C++20; em C++17, um laço `while(m){m&=m-1;++cont;}` conta bits ligados com m sem sinal.

**Escopo:** oficial da aula 2, slide 47. [Template: particionar pesos](../homework-2/templates/bitmask.cpp).

<a id="backtracking"></a>
## Recursão / backtracking — escolher, visitar, desfazer

**Busca:** DFS, árvore de decisões, recursão, subset sum, gerar soluções, backtrack, poda, rainhas. **Gatilho:** explorar possibilidades com restrições e restaurar o estado entre ramos.

**Semântica/invariante:** `dfs(i,soma)` decide somente índices i…n−1; `escolhidos` contém os índices aceitos de 0…i−1. Cada push tem seu pop antes do próximo ramo.

**Entradas:** `a`, `n` pequeno; `long long alvo`. **Resultado:** `quantidade`; conta subconjuntos de índices, inclusive o vazio se alvo=0.

```cpp
vector<int> escolhidos;
long long quantidade = 0;
function<void(int, long long)> dfs = [&](int i, long long soma) {
    if (i == n) {
        if (soma == alvo) ++quantidade; // pode usar escolhidos aqui
        return;
    }
    dfs(i + 1, soma); // não escolher
    escolhidos.push_back(i);
    dfs(i + 1, soma + a[i]); // escolher
    escolhidos.pop_back(); // desfazer antes de retornar
};
dfs(0, 0);
```

**Custo:** O(2ⁿ) sem imprimir soluções; memória O(n) da pilha e do estado. `function` permite a lambda chamar a si mesma em C++17.

**Salva na prova:** em rainhas, marcar coluna/diagonais torna a validação O(1); teste restrição antes de recursar. Se só precisa de existência, pare na primeira solução e restaure estado compartilhado quando necessário.

**Pegadinhas:** a poda `soma > alvo` só é segura se nenhum valor restante puder diminuir a soma. Negativos são aceitos pelo fragmento porque ele não faz essa poda. Recursão profunda pode exceder a pilha mesmo com poucas operações.

**Escopo:** oficial da aula 2. [Template de subconjuntos](../homework-2/templates/recursao_subset.cpp); [template com restrições: rainhas](../homework-2/templates/backtracking.cpp).

<a id="pilha-monotonica"></a>
## Pilha monotônica — menor estrito mais próximo à esquerda

**Busca:** monotonic stack, nearest smaller, menor anterior, vizinho menor, próximo maior/menor, histogramas. **Gatilho:** procurar vizinho por valor mantendo a ordem original.

**Semântica/invariante:** a pilha guarda índices crescentes cujos valores são estritamente crescentes. Remova valores ≥ atual; o topo restante é o menor estrito mais próximo à esquerda.

**Entradas:** `a`, `n`. **Resultado:** `anterior[i]` é índice 0-based ou -1 quando não existe.

```cpp
vector<int> pilha, anterior(n, -1);
for (int i = 0; i < n; ++i) {
    while (!pilha.empty() && a[pilha.back()] >= a[i]) pilha.pop_back();
    if (!pilha.empty()) anterior[i] = pilha.back();
    pilha.push_back(i);
}
```

**Custo:** O(n), memória O(n); cada índice entra uma vez e sai no máximo uma vez.

**Salva na prova:** `[3,5,2,7,8]` → `[-1,0,-1,2,3]`. Para procurar à direita, percorra i em ordem inversa.

**Pegadinhas:** menor **estrito** remove ≥; menor **ou igual** remove somente >. `back()` exige pilha não vazia. Ordenar a entrada destrói os vizinhos originais.

**Escopo:** oficial da aula 1, slides 59–67; histogramas são aplicação extra. [Template completo, saída 1-based/0](../homework-2/templates/pilha_monotonica.cpp).

<a id="compressao"></a>
## Compressão de coordenadas — valor → posição ordenada

**Busca:** coordinate compression, discretização, rank, coordenadas grandes, índices pequenos, sort unique lower_bound. **Gatilho:** poucos valores distintos, mas domínio enorme; só ordem/igualdade importam.

**Semântica:** iguais recebem o mesmo índice; x<y implica id(x)<id(y). Distância entre índices **não** é distância entre valores.

**Entradas:** `a`, `n`. **Resultado:** `id[i]`; `coord[id[i]]` recupera `a[i]`.

```cpp
vector<long long> coord = a;
sort(coord.begin(), coord.end());
coord.erase(unique(coord.begin(), coord.end()), coord.end());
vector<int> id(n);
for (int i = 0; i < n; ++i)
    id[i] = static_cast<int>(lower_bound(coord.begin(), coord.end(), a[i])
                            - coord.begin());
```

**Custo:** O(n log(n+1)), memória O(n). Vetor vazio é permitido: o laço não executa.

**Salva na prova:** `[100,5,100,-2]` → coord=`[-2,5,100]`, id=`[2,1,2,0]`. Para comprimento real em sweep, use diferenças de `coord`, não diferenças de id.

**Pegadinhas:** unique não reduz size sozinho: complete com erase. Valor de consulta ausente retorna ponto de inserção via lower_bound, não um índice de igualdade; confira end e o valor antes de tratá-lo como existente.

**Escopo:** oficial da aula 2. [Template das buscas usadas na compressão](../homework-2/templates/bounds.cpp).

<a id="greedy-heap"></a>
## Greedy + min-heap — aceitar e retirar o pior

**Busca:** greedy, guloso, priority_queue, min-heap, Potions, vida não negativa, selecionar máximo, troca, descartar menor. **Gatilho:** escolher o máximo de itens em ordem, mantendo soma de cada prefixo da subsequência ≥0.

**Semântica/invariante:** tente incluir o novo item; se a vida ficar negativa, retire o menor escolhido. Excluir um negativo melhora todos os prefixos posteriores à posição dele. Uma remoção basta: antes da inclusão a vida era ≥0 e o menor valor é ≤ ao novo.

**Entradas:** `a`; vida inicial 0; cada escolha vale uma unidade. Somas e subtrações cabem em long long. **Resultado:** `quantidade`.

```cpp
priority_queue<long long, vector<long long>, greater<long long>> heap;
long long vida = 0;
for (long long x : a) {
    vida += x;
    heap.push(x);
    if (vida < 0) {
        vida -= heap.top(); // top consulta antes da remoção
        heap.pop();        // pop retorna void
    }
}
auto quantidade = heap.size();
```

**Custo:** O(n log(n+1)), memória O(n). `greater` coloca o **menor** no topo; a priority_queue padrão colocaria o maior.

**Salva na prova:** `[4,-3,-2]` descarta -3, mantém `[4,-2]` e responde 2. A regra de troca conserva mais vida com a mesma quantidade de itens, favorecendo futuras escolhas.

**Pegadinhas:** o heap não representa a ordem da subsequência; ele decide qual valor descartar. Esta regra não serve automaticamente se itens têm recompensas diferentes, outras restrições ou outro objetivo. Não atribua `heap.pop()` a uma variável.

**Escopo:** aplicação das soluções da semana 1; não apresentada aqui como algoritmo novo da aula 2. [Template completo](../templates/greedy_priority_queue.cpp).

**Antes de adaptar qualquer receita:** confira negativos, limites, duplicatas, pontas do intervalo, convenção dos índices e monotonicidade. Compare contra força bruta em entradas pequenas quando a adaptação mudar a lógica.
