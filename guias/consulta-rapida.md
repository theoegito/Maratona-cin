# C++ para maratona · consulta rápida

[Início](../README.md) · [Consulta de contest](../consulta/README.md) · [lower_bound](../consulta/funcoes/lower_bound.md) · [Funções A–Z](../consulta/funcoes/README.md)

**Primeira vez no assunto?** Abra o [guia explicado](guia-cpp.md). Esta página serve para lembrar a sintaxe. O [PDF](consulta-rapida.pdf) é uma versão para impressão.

## 1. Começo de toda questão

```cpp
#include <bits/stdc++.h>  // Atalho do GCC; não é cabeçalho padrão.
using namespace std;    // Permite escrever cin em vez de std::cin.

int main() {            // O programa começa aqui.
    ios::sync_with_stdio(false); // Desliga sincronização com stdio.
    cin.tie(nullptr);            // Desvincula cin do flush de cout.

    // Leia os dados, resolva e imprima a resposta.

    return 0;          // Termina normalmente.
}
```

Com essas configurações, use `cin`/`cout` de forma consistente. Em problemas interativos, faça o flush solicitado pelo protocolo.

| Quero usar | Cabeçalho padrão |
|---|---|
| `cin`, `cout` | `<iostream>` |
| `vector`, `string` | `<vector>`, `<string>` |
| `map`, `set` e `multiset` | `<map>`, `<set>` |
| `stack`, `queue` e `priority_queue` | `<stack>`, `<queue>` |
| `deque` | `<deque>` |
| `sort`, `min`, `max` | `<algorithm>` |
| `greater<T>` | `<functional>` |
| `numeric_limits<T>` | `<limits>` |

## 2. Entrada, tipos e operações

```cpp
int a, b;
cin >> a >> b;              // Lê dois valores; precisa de >> entre eles.
cout << a + b << '\n';      // Imprime e quebra a linha.
long long produto = 1LL * a * b; // Multiplica como long long desde o início.

string s;
cin >> s;                  // Lê uma palavra, sem espaços.
```

Para ler uma linha depois de ler um número:

```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, s);            // Lê até a quebra de linha, incluindo espaços.
```

| Sintaxe | O que faz |
|---|---|
| `int`, `long long` | Inteiros; em juízes usuais, cerca de ±2×10⁹ e ±9×10¹⁸ |
| `double` | Número real aproximado |
| `char c = '0';` | Um caractere; diferente do número `0` |
| `bool ok = true;` | Verdadeiro/falso |
| `x += y;`, `x++;` | Soma `y` a `x`; soma 1 a `x` |
| `a / b`, `a % b` | Divisão inteira se ambos inteiros; resto, com `b != 0` |
| `==`, `!=`, `<`, `<=` | Igual, diferente, menor, menor ou igual |
| `&&`, `||`, `!` | E, ou, negação; `&&`/`||` usam curto-circuito |

## 3. STL: comandos que mais aparecem

`n` representa o tamanho da estrutura. `log n` indica custo logarítmico. Operações que leem/removem uma ponta exigem que a estrutura tenha elementos.

| Estrutura e declaração | Comando | Significado | Custo usual |
|---|---|---|---|
| `vector<int> v;` | `v.push_back(7)` | Acrescenta 7 no fim | O(1) amortizado |
| | `v.pop_back()` | Remove o último; não retorna valor | O(1) |
| | `v[i]`, `v.at(i)` | Acessa índice; `at` verifica limites | O(1) |
| | `v.front()`, `v.back()` | Lê primeiro/último | O(1) |
| | `v.resize(n)` | Ajusta o número de elementos | O(n) no pior caso |
| `map<int,int> m;` | `m[x]++` | Incrementa; cria chave com 0 se faltar | O(log n) |
| | `m.find(x)` | Iterador da chave ou `m.end()` se faltar | O(log n) |
| | `m.erase(x)` | Remove a chave e seu valor | O(log n) |
| `set<int> s;` | `s.insert(x)` | Insere sem duplicatas | O(log n) |
| | `s.count(x)` | 0 ou 1: verifica presença | O(log n) |
| | `s.erase(x)` | Remove x | O(log n) |
| `multiset<int> ms;` | `ms.insert(x)` | Insere, permitindo duplicatas | O(log n) |
| | `ms.count(x)` | Quantidade de cópias | O(log n + cópias) |
| | `ms.erase(x)` | Remove **todas** as cópias | O(log n + cópias) |
| `stack<int> st;` | `st.push(x)` / `st.top()` / `st.pop()` | Insere / lê topo / remove topo | O(1) com container padrão |
| `queue<int> q;` | `q.push(x)` / `q.front()` / `q.pop()` | Entra no fim / lê início / sai do início | O(1) com container padrão |
| `deque<int> d;` | `d.push_front(x)` / `d.push_back(x)` | Insere na primeira/última ponta | O(1) |
| | `d.front()` / `d.back()` | Lê primeira/última ponta | O(1) |
| | `d.pop_front()` / `d.pop_back()` | Remove primeira/última ponta | O(1) |
| `priority_queue<int> pq;` | `pq.push(x)` / `pq.top()` / `pq.pop()` | Insere / lê maior / remove maior | O(log n) amortizado / O(1) / O(log n) |
| Todas acima | `.empty()` / `.size()` | Está vazia? / quantidade | O(1) |

`amortizado` significa que, somando muitas operações, o custo médio é constante; um `push_back` isolado pode realocar o vetor e custar O(n).

```cpp
vector<int> v(3);         // Já tem 3 posições: [0, 0, 0].
v[0] = 7;                // Preenche uma posição existente.
v.push_back(9);          // Agora tem 4 posições: [7, 0, 0, 9].

if (!st.empty()) {       // Confere ANTES de top/pop.
    int saiu = st.top(); // Salva o valor.
    st.pop();            // Só remove; não retorna o valor.
}

auto it = ms.find(4);
if (it != ms.end()) ms.erase(it); // Remove UMA cópia de 4.

priority_queue<long long, vector<long long>, greater<long long>> menor;
menor.push(8);
menor.push(3);
cout << menor.top();     // 3: heap mínimo. Não é uma fila ordenada para iterar.
```

## 4. Ordenar e comparar

```cpp
sort(v.begin(), v.end());                 // Crescente.
sort(v.begin(), v.end(), greater<int>()); // Decrescente.
```

Para strings não vazias, declare a função antes de `main`:

```cpp
bool compara(const string& a, const string& b) {
    return a + b < b + a; // a vai antes de b se isso melhora a concatenação.
}
```

Dentro de `main`, depois de ler `vector<string> palavras`:

```cpp
sort(palavras.begin(), palavras.end(), compara);
```

`begin()` aponta para o início; `end()` aponta **depois do último**. O comparador significa “o primeiro deve vir antes do segundo?”. Use uma relação consistente; **não use `<=`**. Para valores equivalentes, comparar nos dois sentidos deve dar `false`. `sort` faz O(n log n) comparações; concatenar strings também custa tempo proporcional aos seus comprimentos.

## 5. Escolha da estratégia

| Sinal no problema | Estratégia | Custo |
|---|---|---|
| Muitas somas em intervalos; array não muda | Prefix sum | O(n) preparo, O(1) consulta |
| Intervalos de exatamente k posições | Janela fixa | O(n), ou O(n log n) com `map` |
| Contar intervalos com soma x, incluindo negativos | Prefix sum + frequências | O(n log n) com `map` |
| Manter escolhas; descartar a pior quando necessário | Greedy + heap, com justificativa | O(n log n) |
| Reordenar elementos conforme uma regra | `sort` + comparador | O(n log n) comparações |

### Prefix sum: soma inclusiva [l, r], índices começando em 1

```cpp
vector<long long> pref(n + 1, 0);
for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
long long soma = pref[r] - pref[l - 1]; // 1 <= l <= r <= n.
```

Exemplo: `a = [2, 4, 1]`, `pref = [0, 2, 6, 7]`. Soma das posições 2 a 3: `7 - 2 = 5`. Para índices a partir de 0 e intervalo `[l, r)`, use `pref[r] - pref[l]`.

### Janela fixa: retirar quem sai e adicionar quem entra

```cpp
long long soma = 0;
for (int i = 0; i < k; ++i) soma += a[i];
// A primeira janela já está pronta; use soma aqui.
for (int r = k; r < n; ++r) {
    soma -= a[r - k];
    soma += a[r];
    // Use soma: janela que termina em r.
}
```

Exige `1 <= k <= n`. Para contar distintos, mantenha frequências: mudou de 0 para 1? Mais um distinto. Mudou de 1 para 0? Menos um. Uma janela variável que encolhe enquanto a soma é grande depende de monotonicidade; a regra usual exige valores não negativos.

### Subarrays de soma x: prefix sum + map

```cpp
map<long long, long long> freq;
freq[0] = 1; // Prefixo vazio: permite intervalos que começam no início.
long long soma = 0, resposta = 0;
for (long long valor : a) {
    soma += valor;
    resposta += freq[soma - x]; // Conta prefixos ANTERIORES compatíveis.
    ++freq[soma];              // Só depois registra o prefixo atual.
}
```

Motivo: `prefixo_atual - prefixo_anterior = x`, então precisamos de `prefixo_anterior = soma - x`. Funciona com negativos e zero. Atualizar a frequência antes de consultar pode contar o intervalo vazio quando `x = 0`.

### Greedy + heap mínimo: manter saúde não negativa

```cpp
priority_queue<long long, vector<long long>, greater<long long>> pq;
long long saude = 0;
for (long long valor : a) {
    saude += valor;
    pq.push(valor);
    if (saude < 0) {
        saude -= pq.top(); // Desfaz o valor mais prejudicial escolhido.
        pq.pop();
    }
}
cout << pq.size() << '\n';
```

Hipótese: escolher uma subsequência na ordem original, maximizar sua quantidade e manter a saúde não negativa a cada valor escolhido. Ao ficar negativa, remover o menor valor restaura mais saúde com uma única remoção. Confira a justificativa completa no guia antes de adaptar para outro objetivo.

## 6. Pegadinhas para conferir antes de enviar

| Evite | Lembrete correto |
|---|---|
| `cin >> a, b;` | `cin >> a >> b;` lê os dois |
| `cout << '/n';` ou `"\\n"` | `cout << '\n';` quebra a linha; a barra é invertida |
| `int x = st.pop();` | `int x = st.top(); st.pop();` |
| `s[i] == 0` ao procurar o dígito zero | Use `s[i] == '0'`; `0` é um número |
| `vector<int> v; v[0] = 8;` | Crie posições com `vector<int> v(n)` ou acrescente com `push_back` |
| `st.top() == x && !st.empty()` | `!st.empty() && st.top() == x` protege o acesso |
| `long long z = a * b;` com `int` | `long long z = 1LL * a * b;` evita overflow intermediário de int |
| `ms.erase(x)` para apagar uma ocorrência | `find` + `erase(it)` apaga só uma |
| Usar `m[x]` só para perguntar se x existe | `m.find(x) != m.end()` não cria a chave |
| Acessar `v[v.size()]` | Último índice é `size() - 1`, se não estiver vazio |
| Comparador com `<=` | Comparador deve usar ordem estrita e consistente |
| Ordenar antes de procurar subarrays | Ordenar muda a vizinhança e os intervalos |

## 7. Complexidade: conferir o tamanho da entrada

| Custo | Com n = 200.000 | Leitura prática |
|---|---|---|
| O(1) | Constante | Acesso a um índice |
| O(log n) | Cerca de 18 níveis | Busca em árvore balanceada |
| O(n) | 200 mil passos de ordem de grandeza | Uma passagem |
| O(n log n) | Cerca de 3,6 milhões na estimativa | Ordenar / muitas operações de `map` |
| O(n²) | 40 bilhões na estimativa | Geralmente inviável para esse n |

Esses números ilustram crescimento, não medem tempo exato. Limite de tempo, máquina, custo de cada operação e memória também contam. Dois loops separados são O(n); dois loops aninhados podem ser O(n²). Na janela deslizante, cada ponteiro avançar no máximo n vezes pode manter O(n), mesmo com `while` dentro do `for`.

**Checklist:** formato de entrada → casos mínimos → limites de índice → vazios → overflow → custo → saída exatamente como pedida.

Referências e explicações completas: [Guia de C++](guia-cpp.md). Programas prontos para testar: [templates](../templates/).
