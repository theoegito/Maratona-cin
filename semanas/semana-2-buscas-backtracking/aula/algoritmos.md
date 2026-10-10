# Semana 2 · receitas de algoritmos

[Semana 2](../README.md) · [Roteiro oficial](roteiro.md) · [Consulta de C++](../../../consulta/README.md)

- [Janela variável](#janela-variavel)
- [Two pointers](#two-pointers)
- [Sweep line](#sweep-line)
- [Busca do mínimo viável](#busca-minimo)
- [Busca do máximo viável](#busca-maximo)
- [Bitmask](#bitmask)
- [Backtracking](#backtracking)
- [Compressão de coordenadas](#compressao)

## Como copiar os fragmentos

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

**Escopo:** aplicação de two pointers oficial da aula 2. [Template completo](../templates/sliding_window.cpp).
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

**Escopo:** two pointers oficial da aula 2; pares são aplicação adicional. [Template completo](../templates/two_pointers.cpp).
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

**Escopo:** oficial da aula 2; tabela explicita os cuidados de fronteiras. [Template de intervalos fechados](../templates/sweep_line.cpp).
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

**Escopo:** busca na resposta oficial da aula 2; divisão em grupos é aplicação. [Template completo](../templates/binary_search_resposta.cpp).
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

**Escopo:** aplicação da busca oficial da aula 2, presente no original I. [Template da variante mínimo para comparação](../templates/binary_search_resposta.cpp); [original I preservado](../homework-2/I.cpp).
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

**Escopo:** oficial da aula 2, slide 47. [Template: particionar pesos](../templates/bitmask.cpp).
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

**Escopo:** oficial da aula 2. [Template de subconjuntos](../templates/recursao_subset.cpp); [template com restrições: rainhas](../templates/backtracking.cpp).
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

**Escopo:** oficial da aula 2. [Template das buscas usadas na compressão](../templates/bounds.cpp).
