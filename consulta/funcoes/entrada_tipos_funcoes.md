# Entrada, tipos e funções — sintaxe básica para C++17
[Início](../../README.md) · [Consulta rápida](../README.md) · [Catálogo de funções](README.md)
**Pesquise:** cin, cout, getline, linha, espaço, whitespace, ws, ignore, EOF, long long, overflow, cast, divisão inteira, referência, reference, const, auto, função, function, return, void, lambda, capture, min, max, swap, abs, gcd, lcm, sqrt, pow.
**Convenção dos exemplos:** C++17, cabeçalhos `<iostream>`, `<string>`, `<vector>`, `<limits>`, `<algorithm>`, `<numeric>`, `<cmath>`, `<cstdlib>`, `<utility>` e `using namespace std;`. Trechos de leitura e chamadas ficam dentro de `main`; definições de funções ficam fora de `main`.
**Atalhos:** [entrada/saída](#cin-cout) · [getline](#getline) · [tipos/overflow](#tipos-overflow) · [funções/return](#funcoes) · [referências/auto](#referencias-auto) · [lambda](#lambda) · [funções úteis](#funcoes-uteis).
<a id="cin-cout"></a>

## `cin` / `cout`: tokens, saída e fim de arquivo

| Sintaxe | Semântica | Retorno | Custo |
|---|---|---|---|
| `cin >> x;` | Lê próximo valor; pula espaços iniciais | Referência a `cin` | Proporcional aos caracteres lidos |
| `cin >> s;` | Lê uma palavra; para em espaço/quebra de linha | Referência a `cin` | O(tamanho da palavra) |
| `cout << x << '\n';` | Escreve valor e quebra de linha | Referência a `cout` | Proporcional à saída |
| `while (cin >> x) { ... }` | Repete enquanto a leitura tiver sucesso | Conversão do stream para `bool` | Depende do corpo e da entrada |

```cpp
ios::sync_with_stdio(false);      // coloque antes de ler/escrever
cin.tie(nullptr);
int n;
cin >> n;
vector<int> v(n);
for (int& x : v) cin >> x;
```
Após desligar a sincronização, prefira usar apenas `cin`/`cout`, sem misturar `scanf`/`printf`. `endl` também força descarga da saída; prefira `'\n'` em contest comum. Em problemas interativos, siga a regra de descarga exigida.
<a id="getline"></a>
<a id="ws"></a>
<a id="ignore"></a>

## `getline`, `ws`, `ignore`: ler linha inteira
`getline(cin, s)` lê até a quebra de linha, guarda os espaços e **consome a quebra sem guardá-la**. Retorna referência ao stream; pode ser usada em `while (getline(cin, s))`. Custo O(tamanho da linha). [Leitura de string](https://eel.is/c++draft/string.io).

```cpp
int n;
string linha;
cin >> n;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, linha);              // preserva espaços iniciais e linha vazia
```
`ignore(..., '\n')` descarta o restante da linha anterior, incluindo sua quebra. Use após `>>` quando a próxima informação começar na **próxima linha**; não use se ainda precisa de dados na mesma linha. [Operação ignore](https://eel.is/c++draft/istream.unformatted).
Alternativa: `getline(cin >> ws, linha);` pula **todos** os espaços iniciais, inclusive quebras e linhas vazias. Ótima quando isso é permitido; inadequada quando linha vazia ou espaços iniciais fazem parte da entrada. `ws` retorna referência ao stream e custa o número de espaços consumidos. [Manipulador ws](https://eel.is/c++draft/istream.manip).
<a id="tipos-overflow"></a>
<a id="long-long"></a>
<a id="divisao-inteira"></a>

## Tipos, promoção e divisão inteira

| Sintaxe / tipo | Semântica e uso |
|---|---|
| `int x;` | Inteiro; no ambiente usual do contest, cerca de -2·10⁹ a 2·10⁹ |
| `long long soma = 0;` | Inteiro de pelo menos 64 bits; use para somas/produtos grandes |
| `double media;` | Número aproximado; não substitui inteiro exato |
| `char c = 'a';` / `string s = "abc";` | Um caractere / texto |
| `bool ok = true;` | Verdadeiro ou falso |
| `1LL * a * b` | Promove **antes** de multiplicar; resultado `long long` |
| `a / b` com ambos inteiros | Quociente truncado em direção a zero |
| `static_cast<double>(a) / b` | Divisão real aproximada; exige `b != 0` |
**Pegadinha:** `long long p = a * b;` ainda multiplica como `int` se `a` e `b` são `int`. O overflow já ocorreu antes da atribuição. `1LL` não evita overflow se o resultado também exceder `long long`.
`5 / 2 == 2`, `-5 / 2 == -2`, `5.0 / 2 == 2.5`. Resto `%` exige inteiros e divisor não zero; com negativos, `-5 % 2 == -1`. [Divisão e resto](https://eel.is/c++draft/expr.mul).
<a id="funcoes"></a>
<a id="return"></a>
<a id="void"></a>

## Definir e chamar funções: retorno, nome, parâmetros

```cpp
long long soma(const vector<int>& v) {  // definição fora de main
    long long total = 0;
    for (int x : v) total += x;
    return total;                     // entrega long long ao chamador
}
void incrementa(int& x) { ++x; }       // modifica o argumento; não devolve valor
```
Dentro de `main`: `vector<int> v = {2, 3}; long long s = soma(v);` dá 5; `int x = 7; incrementa(x);` deixa `x == 8`. `soma` custa O(n); `incrementa`, O(1). Chame funções definidas antes da chamada ou declare antes um protótipo com a mesma assinatura.
Uma função que retorna valor deve fornecer esse valor em todos os caminhos possíveis. `void` significa sem valor de retorno; pode usar `return;` para sair cedo. Não devolva referência ou ponteiro para variável local que vai deixar de existir.
<a id="referencias-auto"></a>
<a id="const"></a>
<a id="auto"></a>

## Valor, referência, `const` e `auto`

| Sintaxe | Semântica | Retorno / efeito | Custo |
|---|---|---|---|
| `f(vector<int> v)` | Recebe cópia quando passado um vetor comum | Alterações não mudam o original | Copiar custa O(n) |
| `f(vector<int>& v)` | Recebe referência ao original | Pode modificar o original | Sem cópia do vetor |
| `f(const vector<int>& v)` | Referência para leitura | Não permite modificar por `v` | Sem cópia do vetor |
| `auto x = v[0];` | Deduz o tipo e copia o valor | `x` é independente | Custo da cópia |
| `auto& x = v[0];` | Referência ao elemento | Alterar `x` altera `v[0]` | Sem cópia |
| `const auto& x = v[0];` | Referência para leitura | Evita cópia e alteração por `x` | Sem cópia |
Todos os acessos a `v[0]` exigem vetor não vazio. Em `for (auto x : v)`, `x` é cópia; em `for (auto& x : v)`, alterações chegam ao vetor. Para ler objetos grandes, use `for (const auto& x : v)`.
<a id="lambda"></a>

## Lambda: função curta com captura

```cpp
int limite = 10;
auto cabe = [limite](int x) -> bool { return x <= limite; };
bool ok = cabe(8);                // true
cout << ok << '\n';
```
`[]` não captura variáveis locais; `[limite]` copia o valor; `[&limite]` referencia a variável original; `[&]` captura por referência o que for usado. O retorno pode ser deduzido; `-> bool` o deixa explícito. Não guarde uma lambda por referência além da vida das variáveis capturadas. [Regras de captura](https://eel.is/c++draft/expr.prim.lambda.capture).
<a id="funcoes-uteis"></a>
<a id="min-max"></a>
<a id="gcd-lcm"></a>
<a id="sqrt-pow"></a>

## Funções numéricas frequentes

| Sintaxe | Semântica | Retorno | Custo usual |
|---|---|---|---|
| `min(a,b)` / `max(a,b)` | Menor / maior; argumentos do mesmo tipo | `const T&`; copie para guardar | O(1) para números |
| `swap(a,b);` | Troca os valores | `void` | O(1) para números |
| `abs(x)` | Valor absoluto; resultado precisa caber no tipo | Tipo da sobrecarga | O(1) para números |
| `gcd(a,b)` / `lcm(a,b)` | MDC / MMC; inteiros, em `<numeric>` desde C++17 | Tipo inteiro comum | O(log(M+2)) usual, M = maior módulo |
| `sqrt(x)` | Raiz quadrada; use `x >= 0` | Ponto flutuante | Operação matemática de máquina |
| `floor(x)` / `ceil(x)` | Arredonda para baixo / para cima | Ponto flutuante | Operação matemática de máquina |
| `pow(a,b)` | Potência aproximada | Ponto flutuante | Depende da implementação |
`min(1LL, x)` exige `x` compatível com o mesmo tipo: use `min(1LL, 1LL*x)`. `gcd(0,0)` retorna 0; `lcm` retorna 0 se algum argumento for 0. Módulos e resultado do MMC devem caber no tipo; cuidado com overflow. [min/max](https://eel.is/c++draft/alg.min.max), [gcd](https://eel.is/c++draft/numeric.ops.gcd), [lcm](https://eel.is/c++draft/numeric.ops.lcm).
**Dica salvadora:** evite `pow` para potência inteira exata; use multiplicação ou exponenciação binária. Para quadrado, `1LL*x*x`. `ceil(a/b)` com `a` e `b` inteiros recebe o quociente já truncado; para `a >= 0, b > 0`, a divisão inteira arredondada para cima é `a/b + (a%b != 0)`. [Funções matemáticas](https://eel.is/c++draft/cmath.syn).
