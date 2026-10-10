# C++ para Maratona CIn — um caderno para quem está começando

[Início](../README.md) · [Consulta de contest](../consulta/README.md) · [Funções A–Z](../consulta/funcoes/README.md) · [Semana 1](../semana-1/README.md)

Este guia usa **C++17** e parte de uma pergunta prática: **o que eu escrevo, o que isso faz e quando eu uso?** As conexões com suas questões vêm da leitura dos arquivos enviados. Sem os enunciados e os resultados do juiz, elas descrevem os conceitos presentes no código, não comprovam que cada solução foi aceita.

**Como estudar:** leia as seções 1 a 5, escolha uma estrutura da STL e execute seus exemplos. Depois avance para as estratégias. Para procurar uma sintaxe durante um exercício, use a [consulta rápida](consulta-rapida.md).

> **Como usar os exemplos:** salvo os blocos marcados como programa completo, os códigos abaixo são **fragmentos**. Coloque declarações de funções antes de `main` e as instruções dentro de `main`, usando os cabeçalhos necessários. Os arquivos da pasta [`templates`](../templates/) são programas completos separados; não junte vários `main` no mesmo arquivo.

## Sumário

1. [Template base e bibliotecas](#1-template-base-e-bibliotecas)
2. [Tipos, contas e overflow](#2-tipos-contas-e-overflow)
3. [Entrada e saída](#3-entrada-e-saída)
4. [Condições, laços e funções](#4-condições-laços-e-funções)
5. [Índices, iteradores e intervalos](#5-índices-iteradores-e-intervalos)
6. [STL: escolher a estrutura](#6-stl-escolher-a-estrutura)
7. [`vector`](#7-vector)
8. [`map`](#8-map)
9. [`set` e `multiset`](#9-set-e-multiset)
10. [`stack` e `queue`](#10-stack-e-queue)
11. [`deque`](#11-deque)
12. [`priority_queue`](#12-priority_queue)
13. [`sort` e comparadores](#13-sort-e-comparadores)
14. [Prefix sum](#14-prefix-sum)
15. [Sliding window](#15-sliding-window)
16. [Prefix sum + map: somas de subarrays](#16-prefix-sum--map-somas-de-subarrays)
17. [Greedy + priority_queue](#17-greedy--priority_queue)
18. [Complexidade e memória](#18-complexidade-e-memória)
19. [Pegadinhas para guardar](#19-pegadinhas-para-guardar)
20. [Como escolher uma estratégia](#20-como-escolher-uma-estratégia)
21. [Fontes e próximos passos](#21-fontes-e-próximos-passos)

## 1. Template base e bibliotecas

**Programa completo para ambientes GNU que disponibilizam `bits/stdc++.h`:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Leia a entrada, resolva o problema e imprima a resposta aqui.

    return 0;
}
```

| Linha | O que faz |
| --- | --- |
| `#include <bits/stdc++.h>` | Inclui muitos cabeçalhos de uma vez; é uma conveniência do ambiente GNU. |
| `using namespace std;` | Permite escrever `cin`, `vector` e `sort` sem o prefixo `std::`. |
| `int main()` | É a função por onde começa a execução do programa. |
| `{ ... }` | Delimita um bloco de instruções. |
| `ios::sync_with_stdio(false);` | Desliga a sincronização entre os fluxos C++ e a entrada/saída de C, ajudando no desempenho. |
| `cin.tie(nullptr);` | Desliga o envio automático da saída pendente antes de uma leitura com `cin`. |
| `return 0;` | Encerra `main` indicando sucesso. |

`bits/stdc++.h` **não é um cabeçalho padrão do C++**. Se o compilador não o encontrar, use os cabeçalhos padrão. O [manual do GCC sobre cabeçalhos](https://gcc.gnu.org/onlinedocs/libstdc++/manual/using_headers.html) distingue os cabeçalhos da biblioteca e os detalhes da implementação.

**Programa completo com cabeçalhos padrão:**

```cpp
#include <iostream>   // cin, cout
#include <vector>     // vector
#include <string>     // string, getline
#include <algorithm>  // sort, min, max, reverse, lower_bound
#include <map>        // map
#include <set>        // set, multiset
#include <stack>      // stack
#include <queue>      // queue, priority_queue
#include <deque>      // deque
#include <functional> // greater
#include <limits>     // numeric_limits
#include <iomanip>    // fixed, setprecision
#include <utility>    // pair
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
```

Você pode incluir só o que usa. Nos exemplos deste guia, considere que esses cabeçalhos já foram incluídos.

Depois de desligar a sincronização, prefira usar `cin`/`cout` ao longo de todo o programa. Em problemas **interativos**, uma pergunta precisa chegar ao juiz antes da leitura da resposta: use `cout << pergunta << flush;` quando o protocolo pedir. Para os problemas comuns, `cout << resposta << '\n';` costuma ser suficiente.

Template para copiar: [`base.cpp`](../templates/base.cpp).

## 2. Tipos, contas e overflow

| Tipo | Uso comum | Exemplo |
| --- | --- | --- |
| `int` | Índices e inteiros dentro do limite do tipo | `int n = 10;` |
| `long long` | Somas grandes, produtos e quantidade de pares | `long long soma = 0;` |
| `double` | Valores com parte decimal | `double media = 2.5;` |
| `char` | Um caractere | `char letra = 'A';` |
| `string` | Uma sequência de caracteres | `string nome = "Ana";` |
| `bool` | Verdadeiro ou falso | `bool achou = false;` |

Nos ambientes de competição usuais, `int` tem 32 bits, aproximadamente de −2,1 bilhões a +2,1 bilhões; `long long` costuma ter 64 bits, aproximadamente de −9,2 × 10¹⁸ a +9,2 × 10¹⁸. O tamanho exato depende da implementação. Para consultar o limite do seu compilador:

```cpp
cout << numeric_limits<int>::max() << '\n';
cout << numeric_limits<long long>::max() << '\n';
```

**Overflow** acontece quando uma conta não cabe no tipo usado para calculá-la. Não conte com a ideia de que um inteiro com sinal vai simplesmente “dar a volta”: em C++, overflow aritmético com sinal tem comportamento indefinido.

```cpp
int a = 100000;
int b = 100000;

// ERRADO: a * b é calculado como int antes de ser guardado.
// long long produto = a * b;

long long produto = 1LL * a * b; // 10000000000
```

`1LL` é o inteiro 1 do tipo `long long`. Como ele participa da primeira multiplicação, a conta passa a ser feita nesse tipo. Colocar `1LL` **depois** de `a * b` não corrige um overflow que já ocorreu.

Para uma soma, vale a mesma ideia: `long long total = 1LL * a + b;`. Usar variáveis `long long` desde o início costuma deixar somas acumuladas mais claras. Ainda é preciso conferir se o resultado cabe nelas.

Outras contas frequentes:

```cpp
int quociente = 7 / 2;          // 3: divisão entre inteiros
int resto = 7 % 2;             // 1: resto da divisão
double valor = 7.0 / 2;        // 3.5
long long pares = 1LL * n * (n - 1) / 2;
```

Divisão por zero é inválida. `%` é usado com inteiros. Para converter um caractere que representa um dígito, use `int digito = c - '0';`, supondo que `c` esteja entre `'0'` e `'9'`.

**No seu código:** [`A.cpp`](../solucoes/A.cpp) guarda a quantidade de pares em `long long`; [`I.cpp`](../solucoes/I.cpp) e [`M.cpp`](../solucoes/M.cpp) usam esse tipo para somas acumuladas.

## 3. Entrada e saída

### Ler vários valores

```cpp
int a, b;
cin >> a >> b;
cout << a + b << '\n';
```

`>>` lê um valor e o guarda na variável à direita. Os extratores devolvem o próprio fluxo, permitindo encadear leituras. **Para ler dois valores, escreva `cin >> a >> b;`.** `cin >> a, b;` não lê `b`: a vírgula tem outro significado. Veja a [especificação dos extratores numéricos](https://eel.is/c++draft/istream.formatted.arithmetic).

Para esses tipos, espaços e quebras de linha separam os dados; a entrada `4 9` funciona assim como `4` e `9` em linhas separadas.

```cpp
string palavra;
cin >> palavra; // lê até o próximo espaço em branco
```

### Ler uma linha com espaços

```cpp
int idade;
string nome;
cin >> idade;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, nome);
```

Depois da leitura de `idade`, a quebra de linha pode continuar na entrada. `ignore` descarta o restante **dessa linha**, incluindo `\n`; `getline` então lê a linha seguinte até a quebra de linha, sem incluí-la na string. Use esse descarte quando o formato da entrada realmente coloque o nome na próxima linha.

Uma alternativa é `getline(cin >> ws, nome);`: `ws` consome os espaços em branco antes do texto. Isso também remove linhas vazias e espaços iniciais; portanto, não serve se eles forem parte importante da entrada.

### Imprimir

```cpp
cout << "Resposta: " << 42 << '\n';
cout << fixed << setprecision(2) << 3.14159 << '\n'; // 3.14
```

`<<` envia valores à saída. `fixed` e `setprecision(2)` escolhem duas casas após a vírgula decimal; a saída usa ponto, como `3.14`. `\n` é uma quebra de linha. `endl` faz uma quebra e também força o envio imediato da saída pendente; usá-lo em todo laço pode ser mais lento.

No juiz, imprima exatamente o formato solicitado. Um texto como `"Resposta: "` só entra se o enunciado o pedir.

## 4. Condições, laços e funções

### Comparar e decidir

```cpp
if (a == b) {
    cout << "iguais\n";
} else if (a < b) {
    cout << "a menor\n";
} else {
    cout << "b menor\n";
}
```

| Sintaxe | Significado |
| --- | --- |
| `x = 5` | Atribui 5 a `x`. |
| `x == 5` | Pergunta se `x` é igual a 5. |
| `x != 5` | Pergunta se é diferente. |
| `<`, `>`, `<=`, `>=` | Comparam a ordem. |
| `a && b` | Verdadeiro quando as duas condições são verdadeiras. |
| `a || b` | Verdadeiro quando pelo menos uma é verdadeira. |
| `!a` | Inverte verdadeiro/falso. |

**Curto-circuito:** o `&&` comum do C++ avalia a esquerda primeiro e só avalia a direita se a esquerda for verdadeira. Isso permite proteger um acesso. [Regra do operador `&&`](https://eel.is/c++draft/expr.log.and).

```cpp
if (!pilha.empty() && pilha.top() == alvo) {
    pilha.pop();
}
```

Se a pilha estiver vazia, `top()` não será chamado. Inverter as condições perde essa proteção. `&` não substitui `&&`: ele é outro operador.

**No seu código:** [`C.cpp`](../solucoes/C.cpp) verifica `empty()` antes de `top()`; [`B.cpp`](../solucoes/B.cpp) combina condições para conferir resultado e chaves do `map`.

### Repetir

```cpp
for (int i = 0; i < n; ++i) {
    cout << i << '\n'; // 0, 1, ..., n - 1
}

while (!pilha.empty()) {
    cout << pilha.top() << '\n';
    pilha.pop();
}
```

`for` traz a inicialização, a condição para continuar e a atualização. `while` repete enquanto a condição for verdadeira. `++i` soma 1; `--i` subtrai 1; `soma += x` significa `soma = soma + x`. `break` sai do laço mais próximo; `continue` pula para a próxima repetição.

### Percorrer com e sem referência

```cpp
vector<int> v = {1, 2, 3};

for (int x : v) { x *= 2; }          // altera só a cópia x
for (int& x : v) { x *= 2; }         // altera os elementos de v
for (const int& x : v) { cout << x; } // lê sem modificar
```

`&` nessa declaração cria uma **referência** ao elemento original. `const` impede modificações por essa referência. Para strings, `for (const string& s : palavras)` evita copiar cada palavra.

### Criar uma função

Declare esta função antes de `main`:

```cpp
long long quadrado(long long x) {
    return x * x;
}
```

Dentro de `main`, `cout << quadrado(7) << '\n';` imprime 49. O tipo antes do nome é o tipo devolvido; os parâmetros ficam entre parênteses; `return` entrega o resultado. Uma função `void` faz uma ação sem devolver um valor. Esse tipo explica por que `pop()` não pode ser atribuído a uma variável.

## 5. Índices, iteradores e intervalos

Um `vector` ou uma `string` de tamanho `n` tem índices **de 0 a `n - 1`**.

```cpp
vector<int> v = {10, 20, 30};
cout << v[0]; // 10
cout << v[2]; // 30
// v[3] está fora do vetor: não acesse.
```

Um **iterador** indica uma posição dentro de uma estrutura. `begin()` indica o primeiro elemento; `end()` indica a posição **depois do último**. Essa posição serve para comparar e delimitar intervalos, não para ler um elemento.

```cpp
auto it = v.begin();
cout << *it; // *it acessa o elemento apontado: 10
sort(v.begin(), v.end());
```

`auto` pede ao compilador para deduzir o tipo. Em um iterador de `map`, `it->first` acessa a chave e `it->second` acessa o valor.

**Intervalo `[l, r)`** significa: inclui `l` e exclui `r`. Seu tamanho é `r - l`. Assim, `[0, n)` cobre o vetor inteiro. Esse padrão aparece em `sort`, `erase` e prefix sums. Quando o enunciado usa posições de 1 até `n`, escolha uma convenção e faça a conversão conscientemente.

## 6. STL: escolher a estrutura

STL é o nome usado para estruturas e algoritmos prontos da biblioteca. Você informa o tipo entre `< >`: `vector<int>` guarda inteiros, `stack<string>` guarda strings.

| Preciso de... | Estrutura | Ideia |
| --- | --- | --- |
| Sequência e acesso por índice | `vector<T>` | Um vetor que pode crescer. |
| Associar chave a valor | `map<K, V>` | Dicionário ordenado por chave. |
| Valores distintos em ordem | `set<T>` | Conjunto sem repetições. |
| Valores em ordem com repetições | `multiset<T>` | Conjunto que mantém duplicatas. |
| Último que entrou sair primeiro | `stack<T>` | Pilha, LIFO. |
| Primeiro que entrou sair primeiro | `queue<T>` | Fila, FIFO. |
| Inserir/remover nas duas pontas | `deque<T>` | Fila de duas pontas. |
| Consultar/remover o maior ou menor | `priority_queue<T>` | Fila por prioridade; não mantém a ordem de chegada. |

Nas tabelas abaixo, `n` é a quantidade atual de elementos. Os custos de comparação assumem tipos simples, como inteiros. Comparar strings também exige olhar seus caracteres. **Amortizado** significa que algumas operações podem custar mais, mas o custo médio ao longo de uma sequência de operações segue a ordem indicada.

## 7. `vector`

```cpp
vector<int> v;          // vazio: tamanho 0
v.push_back(7);        // agora {7}
v.push_back(9);        // agora {7, 9}
cout << v[0];          // 7
v[1] = 4;              // agora {7, 4}
v.pop_back();          // agora {7}

vector<int> pronto(3);    // {0, 0, 0}: já tem 3 posições
vector<int> cincos(3, 5); // {5, 5, 5}
```

| Comando | O que faz | Custo |
| --- | --- | --- |
| `v.push_back(x)` | Adiciona `x` no final. | O(1) amortizado |
| `v.pop_back()` | Remove o último; exige vetor não vazio. | O(1) |
| `v[i]` | Acessa/altera a posição; exige `0 <= i < size()`. | O(1) |
| `v.at(i)` | Acessa a posição e lança uma exceção se inválida. | O(1) |
| `v.front()`, `v.back()` | Acessam primeiro/último; exigem vetor não vazio. | O(1) |
| `v.size()`, `v.empty()` | Quantidade de elementos / se está vazio. | O(1) |
| `v.clear()` | Remove todos os elementos. | O(n) |
| `v.insert(v.begin() + i, x)` | Insere na posição `i`, deslocando os seguintes. | O(n) |
| `v.erase(v.begin() + i)` | Remove a posição `i`, deslocando os seguintes. | O(n) |
| `v.resize(k)` | Muda a quantidade de posições para `k`. | Linear no número de elementos criados/removidos |
| `v.reserve(k)` | Reserva capacidade; **não** cria posições. | O(n) se realocar |

As operações no fim e no meio têm custos diferentes. Veja a [descrição de `vector`](https://eel.is/c++draft/vector.overview) e seus [modificadores](https://eel.is/c++draft/vector.modifiers). `reserve` trata da capacidade, como explica a [seção de capacidade](https://eel.is/c++draft/vector.capacity).

**Duas formas corretas de ler `n` números:**

```cpp
vector<int> a(n);
for (int i = 0; i < n; ++i) cin >> a[i];

vector<int> b;
b.reserve(n); // opcional: evita algumas realocações
for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b.push_back(x);
}
```

Não comece com `vector<int> v(n)` e depois dê `n` vezes `push_back`, a menos que queira **2n elementos**: os `n` iniciais continuam lá. Também não acesse `v[0]` em um vetor vazio, mesmo depois de `reserve(n)`.

Inserções podem realocar o vetor e invalidar referências/iteradores antigos. Depois de uma operação que muda a estrutura, recalcule os iteradores que precisar.

**Nos seus arquivos:** [`E.cpp`](../solucoes/E.cpp) e [`N.cpp`](../solucoes/N.cpp) constroem vetores com `push_back`; [`I.cpp`](../solucoes/I.cpp) cria posições e as preenche por índice.

## 8. `map`

Um `map<Chave, Valor>` mantém uma entrada por chave. Por padrão, percorrê-lo visita as chaves em ordem crescente. [Descrição de `map`](https://eel.is/c++draft/map).

```cpp
map<string, long long> pontos;
pontos["Ana"] = 10;
pontos["Bia"] += 5; // se faltava, começa em 0 para long long

auto it = pontos.find("Ana");
if (it != pontos.end()) {
    cout << it->first << ' ' << it->second << '\n';
}

for (const auto& entrada : pontos) {
    cout << entrada.first << ' ' << entrada.second << '\n';
}
```

| Comando | O que faz | Custo |
| --- | --- | --- |
| `m[chave]` | Acessa o valor; **insere a chave se faltar**. | O(log n) |
| `m.find(chave)` | Devolve iterador da entrada ou `m.end()`; não insere. | O(log n) |
| `m.count(chave)` | Devolve 0 ou 1, pois as chaves são únicas. | O(log n) |
| `m.insert({chave, valor})` | Insere se faltar; não sobrescreve a entrada existente. | O(log n) |
| `m.erase(chave)` | Remove a entrada; devolve 0 ou 1. | O(log n) |
| `m.size()`, `m.empty()` | Quantidade de chaves / se está vazio. | O(1) |
| `m.clear()` | Remove as entradas. | O(n) |

Custos das buscas e alterações: [requisitos dos containers associativos](https://eel.is/c++draft/associative.reqmts).

Para contar frequência:

```cpp
map<int, int> freq;
for (int x : v) ++freq[x];
```

Se `x` não aparece no mapa, `freq[x]` cria o contador com 0; o incremento o leva a 1. Se você usa `freq[x]` só para consultar, lembre que a consulta também pode criar uma chave. Para conferir existência sem alterar, use `find`.

**Nos seus arquivos:** [`B.cpp`](../solucoes/B.cpp) associa nomes/problemas a pontos; [`E.cpp`](../solucoes/E.cpp) conta ocorrências na janela; [`M.cpp`](../solucoes/M.cpp) conta prefixos com determinada soma.

## 9. `set` e `multiset`

### `set`: valores distintos

```cpp
set<int> s;
s.insert(5);
s.insert(2);
s.insert(5); // não cria uma segunda cópia
// Ao percorrer, os elementos são 2, 5.

if (s.find(2) != s.end()) cout << "existe\n";
s.erase(2);
```

`set` mantém valores únicos e ordenados; não tem `s[i]`. [Descrição de `set`](https://eel.is/c++draft/set).

| Comando | O que faz | Custo |
| --- | --- | --- |
| `s.insert(x)` | Insere se ainda não existe. | O(log n) |
| `s.find(x)` | Busca; devolve `end()` se faltar. | O(log n) |
| `s.count(x)` | 0 ou 1. | O(log n) |
| `s.erase(x)` | Remove `x`, caso exista. | O(log n) |
| `s.lower_bound(x)` | Primeiro elemento **>= x**. | O(log n) |
| `s.upper_bound(x)` | Primeiro elemento **> x**. | O(log n) |
| `s.size()`, `s.empty()` | Quantidade / se está vazio. | O(1) |

```cpp
auto it = s.lower_bound(4);
if (it != s.end()) cout << *it << '\n';
```

Nunca leia `*it` antes de conferir se `it != end()`. `*s.begin()` é o menor e `*s.rbegin()` é o maior, **se o conjunto não estiver vazio**.

### `multiset`: valores com repetição

```cpp
multiset<int> ms = {2, 5, 5, 5};
auto it = ms.find(5);
if (it != ms.end()) ms.erase(it); // remove UMA cópia de 5
// ms agora tem {2, 5, 5}
ms.erase(5);                     // remove TODAS as cópias de 5
// ms agora tem {2}
```

Essa diferença entre apagar por **iterador** e por **valor** é essencial. `multiset` admite várias entradas equivalentes. [Descrição de `multiset`](https://eel.is/c++draft/multiset).

Inserir/buscar custa O(log n). `count(x)` e `erase(x)` custam O(log n + k), sendo `k` a quantidade de cópias encontradas/removidas. `erase(it)` é O(1) amortizado; o `find` anterior ainda custa O(log n). `lower_bound`, `upper_bound`, `size` e `empty` têm o mesmo significado usado acima.

## 10. `stack` e `queue`

### `stack`: pilha

**LIFO:** last in, first out — o último a entrar é o primeiro a sair.

```cpp
stack<int> pilha;
pilha.push(10);
pilha.push(20);
int saiu = pilha.top(); // consulta 20
pilha.pop();           // remove 20; não devolve nada
cout << saiu << '\n';
```

| Comando | O que faz |
| --- | --- |
| `pilha.push(x)` | Coloca `x` no topo. |
| `pilha.top()` | Consulta o topo; exige pilha não vazia. |
| `pilha.pop()` | Remove o topo; exige pilha não vazia. |
| `pilha.size()` | Informa a quantidade. |
| `pilha.empty()` | Diz se está vazia. |

Com o container padrão (`deque`), essas operações são O(1). `stack` não fornece `begin()`, `end()` nem acesso por índice. [Descrição de `stack`](https://eel.is/c++draft/stack).

**No seu código:** [`C.cpp`](../solucoes/C.cpp) transfere elementos entre pilhas usando `push(top())` seguido de `pop()`.

### `queue`: fila

**FIFO:** first in, first out — o primeiro a entrar é o primeiro a sair.

```cpp
queue<string> fila;
fila.push("Ana");
fila.push("Bia");
cout << fila.front(); // Ana: primeira
cout << fila.back();  // Bia: última
fila.pop();           // remove Ana
```

`push` insere no fim; `front` consulta o início; `back` consulta o fim; `pop` remove do início; `size` conta; `empty` verifica se está vazia. `front`, `back` e `pop` exigem fila não vazia. Com o container padrão, todas são O(1). [Descrição de `queue`](https://eel.is/c++draft/queue).

**Não confunda:** a remoção da fila é `pop()`, e não `pop_front()`; quem oferece `pop_front()` diretamente é o `deque`.

## 11. `deque`

Uma fila com acesso às duas pontas e acesso por índice.

```cpp
deque<char> d;
d.push_back('B');  // {'B'}
d.push_front('A'); // {'A', 'B'}
char primeiro = d.front();
d.pop_front();    // {'B'}
char ultimo = d.back();
d.pop_back();     // vazio
```

| Comando | O que faz | Custo |
| --- | --- | --- |
| `d.push_front(x)` | Insere no começo. | O(1) |
| `d.push_back(x)` | Insere no fim. | O(1) |
| `d.pop_front()` | Remove o começo; exige não vazio. | O(1) |
| `d.pop_back()` | Remove o fim; exige não vazio. | O(1) |
| `d.front()`, `d.back()` | Consultam as pontas; exigem não vazio. | O(1) |
| `d[i]` | Acesso por índice válido. | O(1) |
| `d.size()`, `d.empty()` | Quantidade / se está vazio. | O(1) |
| Inserir/remover no meio | Desloca elementos. | O(n) |

Esses custos distinguem as pontas do meio. [Descrição de `deque`](https://eel.is/c++draft/deque.overview).

**No seu código:** [`A.cpp`](../solucoes/A.cpp) usa exatamente as quatro operações nas pontas. O código original não verifica `empty()` antes de remover; se isso é garantido depende do enunciado. Ao adaptar a ideia para outro exercício, confirme essa garantia.

## 12. `priority_queue`

É uma estrutura para recuperar rapidamente o elemento de maior prioridade. Por padrão, o **maior valor** fica no topo.

```cpp
priority_queue<int> maior;
maior.push(4);
maior.push(9);
maior.push(2);
cout << maior.top(); // 9
maior.pop();         // remove 9
```

Para o **menor valor** no topo, use `greater`:

```cpp
priority_queue<long long, vector<long long>, greater<long long>> menor;
menor.push(-5);
menor.push(3);
cout << menor.top(); // -5
```

Leia a declaração em três partes: tipo dos elementos, container interno, regra de comparação. Essa configuração é chamada de **min-heap**; o padrão é um **max-heap**.

| Comando | O que faz | Custo com o container padrão |
| --- | --- | --- |
| `pq.push(x)` | Insere e ajusta a prioridade. | O(log n) amortizado |
| `pq.top()` | Consulta o elemento prioritário; exige não vazio. | O(1) |
| `pq.pop()` | Remove o prioritário; exige não vazio. | O(log n) |
| `pq.size()`, `pq.empty()` | Quantidade / se está vazio. | O(1) |

O custo de `push` inclui as realocações ocasionais do `vector` interno; o ajuste do heap usa O(log n) comparações. [Descrição de `priority_queue`](https://eel.is/c++draft/priority.queue).

Não existe acesso `pq[i]` nem busca direta de um valor. Os elementos internos não são apresentados como um vetor completamente ordenado. Para guardar e remover o topo, escreva `auto x = pq.top(); pq.pop();`.

**No seu código:** [`D.cpp`](../solucoes/D.cpp) usa um min-heap para consultar o menor elemento escolhido até então.

## 13. `sort` e comparadores

### Ordenação simples

```cpp
vector<int> v = {4, 1, 3};
sort(v.begin(), v.end());                 // {1, 3, 4}
sort(v.begin(), v.end(), greater<int>()); // {4, 3, 1}
```

`sort` ordena o intervalo `[begin, end)`, alterando o vetor. Usa O(n log n) comparações. A comparação deve dar uma **ordem estrita consistente**. [Regras de comparação e ordenação](https://eel.is/c++draft/alg.sorting).

### Função comparadora

Declare antes de `main`:

```cpp
bool vem_antes(int a, int b) {
    return a > b; // a vem antes de b se a é maior
}
```

Dentro de `main`: `sort(v.begin(), v.end(), vem_antes);`. **Passe o nome da função**, sem chamá-la como `vem_antes()`.

O retorno `true` quer dizer “o primeiro deve aparecer antes do segundo”. Para não quebrar a ordenação:

- `compara(a, a)` deve ser `false`.
- Se `a` vem antes de `b`, `b` não pode vir antes de `a`.
- Se `a` vem antes de `b` e `b` vem antes de `c`, `a` deve vir antes de `c`.
- Os empates definidos pelo comparador também devem ser consistentes.

Por isso, **não use `<=` no lugar de `<`**. Para ordenar por pontos decrescentes e desempatar por nome:

```cpp
// Fragmento dentro de main: pair.first = pontos, pair.second = nome.
vector<pair<int, string>> pessoas = {{10, "Bia"}, {10, "Ana"}, {7, "Caio"}};
sort(pessoas.begin(), pessoas.end(), [](const auto& a, const auto& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
});
```

`[](...) { ... }` é uma **lambda**, uma função escrita no próprio lugar de uso. Aqui, empates completos retornam `false`. `sort` não garante preservar a ordem de chegada dos elementos empatados; `stable_sort` serve quando essa preservação é necessária.

### Seu comparador em `N.cpp`: comparar concatenações

O código de [`N.cpp`](../solucoes/N.cpp) usa `a + b < b + a`. A pergunta é: “colocar `a` antes de `b` gera uma concatenação menor?”

```cpp
// Função antes de main; strings lidas como tokens são não vazias.
bool compara_strings(const string& a, const string& b) {
    return a + b < b + a;
}
```

Exemplo: `a = "9"`, `b = "34"`. `"934" < "349"` é falso, então `"34"` deve vir antes de `"9"` para obter a menor concatenação lexicográfica. Strings são comparadas caractere a caractere; isso não é comparar os números 934 e 349 como tipos numéricos.

Para **strings não vazias**, a regra permite ordenar pela menor concatenação: se um par vizinho estiver na ordem oposta, trocá-lo não aumenta o resultado. Comparações que empatam podem aparecer em qualquer ordem. Se adaptar para strings vazias, retire-as antes de ordenar: vazio empata com qualquer string e quebra a consistência geral dos empates desse comparador.

Cada comparação cria/analisa concatenações, por isso o tempo depende também do comprimento das strings. Se cada uma tem no máximo `L` caracteres, uma estimativa é O(n log n · L), além do armazenamento das palavras.

O uso de referências `const string&` acima evita cópias dos argumentos; é uma versão didática. O original enviado continua preservado. Programa completo: [`sort_comparador.cpp`](../templates/sort_comparador.cpp).

## 14. Prefix sum

**Quando usar:** muitas consultas de soma de intervalos em um vetor que não muda.

Defina `pref[i]` como a soma dos **primeiros `i` elementos**. O prefixo vazio tem soma 0.

```cpp
vector<long long> a = {2, 4, -1, 3};
int n = static_cast<int>(a.size());
vector<long long> pref(n + 1, 0);

for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + a[i];
}
// pref = {0, 2, 6, 5, 8}
```

`static_cast<int>(...)` faz uma conversão explícita; aqui, supomos que o tamanho cabe em `int`.

| Consulta | Fórmula | Exemplo |
| --- | --- | --- |
| Índices de 0; intervalo `[l, r)` | `pref[r] - pref[l]` | `[1, 3)` soma `4 + (-1) = 3` |
| Índices de 0; intervalo inclusivo `[l, r]` | `pref[r + 1] - pref[l]` | `[1, 2]` também soma 3 |
| Posições de 1; intervalo inclusivo `[L, R]` | `pref[R] - pref[L - 1]` | `[2, 3]` também soma 3 |

**Por que funciona?** `pref[r]` inclui tudo antes de `r`; subtrair `pref[l]` tira tudo antes de `l`. Sobram exatamente os elementos desejados.

Construção O(n), cada consulta O(1), memória O(n). Negativos funcionam normalmente. Se os valores mudam durante as consultas, esse prefixo fica desatualizado; atualizar o vetor exige recalcular os prefixos afetados ou escolher outra estrutura.

**No seu código:** [`I.cpp`](../solucoes/I.cpp) guarda as somas e usa `v[r] - v[p - 1]`: consultas inclusivas com posições começando em 1. Programa completo: [`prefix_sum.cpp`](../templates/prefix_sum.cpp).

## 15. Sliding window

Uma **janela** é um trecho contíguo. Ao movê-la, você reaproveita o resultado anterior em vez de recalcular tudo.

### Janela fixa: distintos em cada trecho de tamanho `k`

Na mudança de `[l, l + k)` para `[l + 1, l + k + 1)`, um elemento sai e outro entra.

```cpp
// Fragmento: a é vector<int>, n é seu tamanho e 1 <= k <= n.
map<int, int> freq;
int distintos = 0;

for (int i = 0; i < k; ++i) {
    if (freq[a[i]] == 0) ++distintos;
    ++freq[a[i]];
}
cout << distintos;

for (int r = k; r < n; ++r) {
    int sai = a[r - k];
    if (--freq[sai] == 0) --distintos;

    int entra = a[r];
    if (freq[entra] == 0) ++distintos;
    ++freq[entra];

    cout << ' ' << distintos;
}
cout << '\n';
```

`--freq[sai]` diminui o contador antes de testar o resultado. Um número deixa de ser distinto quando sua frequência cai de 1 para 0; passa a ser distinto quando sobe de 0 para 1. Os valores podem ser negativos: aqui, a janela tem tamanho fixo e só interessa a igualdade entre valores.

Com `map`, tempo O(n log n), memória O(n) no pior caso: chaves com frequência zero permanecem no mapa. Para guardar só as chaves ativas, pode-se apagá-las quando o contador chega a zero. Se os valores pertencem a um intervalo pequeno conhecido, um vetor de frequência pode permitir O(n) de tempo, com memória proporcional a esse intervalo.

**No seu código:** [`E.cpp`](../solucoes/E.cpp) usa a mesma estratégia. Sua leitura e o acesso aos primeiros `k` elementos exigem conferir o limite `1 <= k <= n` no enunciado. Programa completo: [`sliding_window.cpp`](../templates/sliding_window.cpp).

### Janela variável: maior trecho com soma <= limite

**Pré-condição deste algoritmo:** todos os elementos são **não negativos** e o limite é >= 0. Isso garante que acrescentar à direita não diminui a soma e retirar à esquerda não aumenta a soma.

```cpp
// Fragmento: a é vector<long long>, n é seu tamanho, limite >= 0.
int l = 0, melhor = 0;
long long soma = 0;
for (int r = 0; r < n; ++r) {
    soma += a[r];
    while (l <= r && soma > limite) {
        soma -= a[l];
        ++l;
    }
    melhor = max(melhor, r - l + 1);
}
cout << melhor << '\n';
```

Cada índice entra e sai no máximo uma vez: O(n) de tempo e O(1) de memória extra além do vetor. O `while` dentro do `for` **não implica automaticamente O(n²)**.

Não aplique essa regra de soma a números negativos. Exemplo: com `[4, -3]` e limite 2, retirar o 4 ao vê-lo impede encontrar o trecho inteiro, cuja soma é 1. Para contar subarrays com soma exata, use a estratégia seguinte, que admite negativos.

## 16. Prefix sum + map: somas de subarrays

**Problema de estudo:** contar quantos trechos contíguos **não vazios** têm soma igual a `x`. Os valores podem ser positivos, zero ou negativos.

Se a soma acumulada atual é `soma`, precisamos de um prefixo anterior com valor `soma - x`:

```text
soma_do_trecho = prefixo_atual - prefixo_anterior
x              = soma          - prefixo_anterior
prefixo_anterior = soma - x
```

```cpp
// Fragmento: a é vector<long long>; x é long long.
map<long long, long long> freq;
freq[0] = 1; // existe um prefixo vazio antes do primeiro elemento

long long soma = 0;
long long resposta = 0;
for (long long valor : a) {
    soma += valor;
    resposta += freq[soma - x]; // consulta prefixos ANTERIORES
    ++freq[soma];               // só depois registra o atual
}
cout << resposta << '\n';
```

**Por que `freq[0] = 1`?** Permite contar trechos que começam no primeiro elemento. **Por que consultar antes de registrar?** Se `x = 0`, registrar antes faria o prefixo atual formar um “trecho vazio” consigo mesmo.

Exemplo: `a = {1, -1, 1}` e `x = 1`:

| Valor lido | Soma atual | Prefixo procurado | Quantidade anterior | Resposta acumulada |
| --- | --- | --- | --- | --- |
| 1 | 1 | 0 | 1 | 1 |
| -1 | 0 | -1 | 0 | 1 |
| 1 | 1 | 0 | 2 | 3 |

Os três trechos são o primeiro `1`, o último `1` e `{1, -1, 1}`. Prefixos repetidos representam diferentes posições, por isso precisamos de **frequência**, não só presença em um `set`.

Tempo O(n log n) com `map`; memória O(n). Consultar `freq[soma - x]` também pode criar entradas zero, mas a ordem continua O(n). Use `long long` na resposta: com `n` zeros e `x = 0`, existem `n(n + 1)/2` trechos.

**No seu código:** [`M.cpp`](../solucoes/M.cpp) implementa essa relação. Programa completo: [`subarray_sum_map.cpp`](../templates/subarray_sum_map.cpp).

## 17. Greedy + priority_queue

**Problema de estudo:** uma sequência contém mudanças de vida. Você começa com vida 0, pode pular elementos e quer escolher o maior número possível, mantendo a ordem original e a vida **não negativa após cada escolha**.

Uma estratégia gulosa é tentar aceitar cada valor; se a vida ficar negativa, descartar o menor valor escolhido até agora.

```cpp
// Fragmento: a é vector<long long>.
priority_queue<long long, vector<long long>, greater<long long>> escolhidos;
long long vida = 0;

for (long long x : a) {
    vida += x;
    escolhidos.push(x);
    if (vida < 0) {
        long long pior = escolhidos.top();
        escolhidos.pop();
        vida -= pior; // retirar um negativo aumenta a vida
    }
}
cout << escolhidos.size() << '\n';
```

**Intuição de troca:** quando falta vida, remover uma escolha é necessário para essa tentativa. Remover o menor valor recupera o máximo de vida com uma remoção; manter um valor pior e descartar um maior reduz a margem disponível para os próximos passos. O min-heap permite corrigir uma escolha anterior.

Por que isso respeita o passado? Se a soma ficou negativa, o menor escolhido é negativo. Excluir esse valor não piora nenhum prefixo: depois da posição dele, a vida só aumenta. Uma remoção basta: antes de ler `x`, a vida era >= 0 e o menor elemento é <= `x`; portanto, a vida nova menos esse menor é pelo menos a vida anterior. Essa é a propriedade usada por essa estratégia para preservar a viabilidade e favorecer a maior quantidade de escolhas.

Exemplo: `[4, -3, -2]`. Após aceitar os três, a vida seria −1. O heap remove −3, ficando com escolhas `[4, -2]`, vida 2 e quantidade 2.

Tempo O(n log n), memória O(n). **Greedy precisa de justificativa para a regra específica**: “tirar o menor” não é um método universal para qualquer problema de seleção. Aqui, as escolhas valem uma unidade cada e a restrição é a soma acumulada da vida.

**No seu código:** [`D.cpp`](../solucoes/D.cpp) organiza a tentativa/rejeição/substituição em ramos e consulta o menor escolhido. O exemplo acima é uma implementação didática separada; não substitui nem modifica o original. Programa completo: [`greedy_priority_queue.cpp`](../templates/greedy_priority_queue.cpp).

## 18. Complexidade e memória

Complexidade descreve como o trabalho cresce quando a entrada aumenta. Não é um tempo exato em segundos.

| Ordem | Exemplo | Para `n = 100000`, tamanho aproximado da conta |
| --- | --- | --- |
| O(1) | Acessar `v[i]` | Constante |
| O(log n) | Buscar no `map` | Escala de 17 níveis quando a base é 2 |
| O(n) | Percorrer um vetor | 100000 |
| O(n log n) | `sort`, n operações no mapa | Escala de 1,7 milhão |
| O(n²) | Testar todos os pares | Escala de 10 bilhões |
| O(2ⁿ) | Testar todos os subconjuntos | Cresce muito rapidamente |

Os números da última coluna são uma ilustração do crescimento, **não uma garantia de operações reais ou de tempo**. Limite de tempo, linguagem, hardware, entrada/saída e custo das operações influenciam.

```cpp
for (int i = 0; i < n; ++i) { /* trabalho O(1) */ } // O(n)

for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) { /* trabalho O(1) */ }
} // O(n²)

for (int x : v) ++freq[x]; // O(n log n) com map
```

Conte também a memória. Um vetor com `n` elementos usa O(n); uma tabela `n × n` usa O(n²). Com `long long` de 8 bytes, um milhão de valores ocupa cerca de 8 MB só nos elementos; nós de `map`/`set` e as próprias estruturas têm custos adicionais. Não estime memória de um `map` como se fosse apenas um vetor de pares.

**Antes de programar:** confira o maior `n`, os limites dos valores e o número de testes. Se vários casos aparecem na entrada, considere o total de trabalho entre eles. Uma conta que cabe por elemento pode não caber como soma de todos.

## 19. Pegadinhas para guardar

Esta seção reúne os pontos pedidos para o caderno e os conecta aos padrões que aparecem nos arquivos. Os comentários não alteram as soluções nem presumem os limites dos enunciados.

| Pegadinha | Forma correta / como pensar |
| --- | --- |
| Ler duas variáveis | `cin >> a >> b;`, com um `>>` para cada variável. |
| Quebrar linha | `cout << x << '\n';`; a barra está **antes** do `n`. |
| `pop` devolver um elemento | `int x = pilha.top(); pilha.pop();`. `pop` remove e não devolve valor. |
| `'0'` ser igual a `0` | `'0'` é um caractere; `0` é um inteiro. Para string binária, teste `s[i] == '0'`. |
| Grafia de `push_back` | Tem sublinhado: `v.push_back(x)`, não `pushback(x)`. |
| Criar vetor com `n` e usar `push_back` | `vector<int> v(n)` já tem `n` elementos; preencha `v[i]` ou comece vazio e adicione. |
| `reserve(n)` criar posições | Só reserva capacidade; `size()` continua igual. |
| Acessar topo de pilha vazia | `!p.empty() && p.top() == alvo`; a ordem é parte da proteção. |
| Usar `&` no lugar de `&&` | `&&` combina condições com curto-circuito; `&` é outro operador. |
| `map[chave]` ser só leitura | Pode inserir uma chave ausente; use `find` para consultar sem inserir. |
| `end()` apontar o último | Aponta depois do último; não leia `*end()`. |
| Remover uma cópia no `multiset` | Use `find` e `erase(it)`; `erase(valor)` remove todas as equivalentes. |
| `long long resposta = a * b` evitar overflow de `int` | Use `1LL * a * b` ou operandos já do tipo `long long`. |
| Comparador usar `<=` | Use uma ordem estrita; `compara(a, a)` precisa ser falso. |
| Janela de soma funcionar com negativos | A janela variável apresentada exige não negativos. |
| Registrar prefixo antes de contar | Para subarray não vazio, consulte primeiro e registre depois. |
| Contar só prefixos não vazios | `freq[0] = 1` representa o prefixo inicial vazio. |
| `for (auto x : v)` modificar o vetor | `x` é cópia; use `auto& x` para alterar o elemento. |
| Usar índices até `n` em vetor de tamanho `n` | Último índice é `n - 1`; o laço comum usa `i < n`. |
| `int` receber um `long long` sem risco | Pode perder informação se não couber; escolha o tipo a partir dos limites. |

**Ligações com suas questões:**

- [`A.cpp`](../solucoes/A.cpp): guardar `front`/`back` antes de remover; validar se as remoções em estrutura vazia são proibidas pela entrada.
- [`B.cpp`](../solucoes/B.cpp): `find`/`end`, acesso por chave e condições com `&&`.
- [`C.cpp`](../solucoes/C.cpp): curto-circuito protegendo `top`, operações sem retorno e tipos da pilha.
- [`D.cpp`](../solucoes/D.cpp): `greater<long long>` e vida com soma acumulada.
- [`E.cpp`](../solucoes/E.cpp): `push_back`, janela e contadores. A leitura usa `long long`, mas vetor/map usam `int`; isso exige que os valores caibam em `int`.
- [`I.cpp`](../solucoes/I.cpp): vetor com `n + 1`, prefixo 0 e a fórmula `pref[r] - pref[l - 1]`.
- [`K.cpp`](../solucoes/K.cpp): comparar a string com `'0'`/`'1'`, acompanhar blocos consecutivos e reiniciar contadores entre testes.
- [`M.cpp`](../solucoes/M.cpp): `freq[0] = 1`, consultar antes de atualizar e contar várias ocorrências do mesmo prefixo.
- [`N.cpp`](../solucoes/N.cpp): função comparadora passada pelo nome; concatenação e ordenação de strings não vazias.

Em [`C.cpp`](../solucoes/C.cpp), as pilhas são `stack<int>`, mas os números lidos são `long long`; também é necessário conferir se os limites cabem em `int`. Esse é um ponto para revisar à luz do enunciado, sem reescrever o original às escondidas.

### Pequeno checklist antes de enviar ao juiz

1. A leitura segue exatamente a entrada? Existe número de casos de teste?
2. Os tipos comportam a maior soma/produto/resposta?
3. Todos os índices são válidos? As estruturas podem estar vazias?
4. A estratégia atende às pré-condições: negativos, `k`, ordem, mudanças no vetor?
5. A complexidade cabe nos limites de `n`?
6. A saída tem os espaços e as quebras pedidos, sem mensagens extras?
7. Os exemplos e alguns casos pequenos funcionam? Testei repetidos, zeros e extremos permitidos?

## 20. Como escolher uma estratégia

| Pista no problema | Primeira ideia para investigar | Condição importante |
| --- | --- | --- |
| Somar vários intervalos de vetor fixo | Prefix sum | Definir claramente os índices. |
| Todos os trechos de comprimento `k` | Janela fixa | Atualizar quem sai e quem entra. |
| Maior trecho com soma limitada | Janela variável de soma | Para o algoritmo deste guia, valores não negativos. |
| Quantidade de trechos com soma exata | Prefix sum + frequência em `map` | Contar prefixos anteriores, incluindo o inicial vazio. |
| Nomes associados a pontos/quantidades | `map` | Chave → valor. |
| Preciso manter só valores diferentes | `set` | Repetições são descartadas. |
| Preciso manter repetições em ordem | `multiset` | Diferenciar remover uma ou todas. |
| Desfazer/consultar a última operação | `stack` | Último entra, primeiro sai. |
| Processar na ordem de chegada | `queue` | Primeiro entra, primeiro sai. |
| Alterações nas duas pontas | `deque` | Consultar antes de remover. |
| Escolher sempre o menor/maior disponível | `priority_queue` | Justificar se a escolha gulosa resolve o problema. |
| Resultado depende da ordem dos itens | `sort` com comparador | A regra precisa ser consistente. |

Essas pistas ajudam a começar; não substituem a prova da ideia. Uma forma útil de estudar é escrever uma solução lenta para entradas minúsculas e comparar seus resultados com a solução rápida.

## 21. Fontes e próximos passos

Os exemplos e as explicações foram escritos para este caderno. As regras de biblioteca foram conferidas em fontes primárias:

- [Rascunho público do padrão C++: containers](https://eel.is/c++draft/containers), com links específicos ao longo das seções.
- [Rascunho: ordenação e requisitos dos comparadores](https://eel.is/c++draft/alg.sorting).
- [Rascunho: operador lógico `&&`](https://eel.is/c++draft/expr.log.and).
- [Rascunho: leitura numérica com `>>`](https://eel.is/c++draft/istream.formatted.arithmetic).
- [GCC/libstdc++: cabeçalhos](https://gcc.gnu.org/onlinedocs/libstdc++/manual/using_headers.html).

O rascunho online acompanha a evolução do C++; pode mostrar recursos posteriores ao C++17. Os comandos usados neste guia foram escolhidos para C++17.

**Para praticar agora:** execute o [template base](../templates/base.cpp), teste uma operação de cada estrutura e explique em voz alta qual elemento entra/sai. Depois compare os programas didáticos com seus originais, começando por [`I.cpp`](../solucoes/I.cpp), [`E.cpp`](../solucoes/E.cpp) e [`M.cpp`](../solucoes/M.cpp).
