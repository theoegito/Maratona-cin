# `vector` e `string` — índices, inserir, apagar e buscar texto

[Início](../../README.md) · [Consulta rápida](../README.md) · [Catálogo de funções](README.md)

**Pesquise:** vector, vetor, array dinâmico, índice, index, push_back, pop_back, insert, erase, reserve, resize, string, texto, find, npos, substr, substring, caractere.

**Convenção dos exemplos:** C++17, cabeçalhos `<vector>`, `<string>`, `<iostream>` e `using namespace std;`. `n` é o tamanho atual; `k` é a quantidade de caracteres ou elementos envolvidos.

**Atalhos:** [vector](#vector) · [push/pop](#vector-push-back) · [erase](#vector-erase) · [reserve × resize](#reserve-resize) · [string](#string) · [find/npos](#string-find) · [substr](#string-substr).

<a id="vector"></a>
## `vector`: lista com acesso por índice

| Sintaxe C++17 | Semântica | Retorno | Custo |
|---|---|---|---|
| `vector<int> v(n, 0);` | Cria `n` elementos iguais a zero | Objeto | O(n) |
| `v[i]` | Acessa o índice `i`; exige `0 <= i < v.size()` | Referência ao elemento | O(1) |
| `v.at(i)` | Acessa com verificação; índice inválido lança `out_of_range` | Referência | O(1) |
| `v.size()` / `v.empty()` | Quantidade / está vazio? | `size_t` / `bool` | O(1) |
| `v.front()` / `v.back()` | Primeiro / último; exige vetor não vazio | Referência | O(1) |
| `v.begin()` / `v.end()` | Primeiro / posição após o último | Iterador | O(1) |

`end()` **não é um elemento**: nunca use `*v.end()`. Um intervalo `[begin, end)` inclui a primeira posição e exclui a última.

<a id="vector-push-back"></a>
<a id="vector-pop-back"></a>
<a id="vector-insert"></a>
<a id="vector-erase"></a>
## `push_back`, `pop_back`, `insert`, `erase`

| Sintaxe | Semântica | Retorno | Custo |
|---|---|---|---|
| `v.push_back(x);` | Acrescenta `x` ao fim | `void` | O(1) amortizado; O(n) se realocar |
| `v.pop_back();` | Remove o último; exige `!v.empty()` | `void`, não entrega o valor | O(1) |
| `v.insert(v.begin()+i, x);` | Insere antes de `i`; `i == size()` é permitido | Iterador para o inserido | O(n) |
| `v.erase(v.begin()+i);` | Remove o índice `i`, que deve existir | Iterador para o próximo, ou `end()` | O(n) |
| `v.erase(v.begin()+l, v.begin()+r);` | Remove `[l,r)`; permite intervalo vazio | Iterador após o trecho | O(n) |
| `v.clear();` | Apaga os elementos; tamanho vira zero | `void` | O(n) |

```cpp
vector<int> v = {10, 20, 30};
v.push_back(40);                  // {10, 20, 30, 40}
v.insert(v.begin() + 1, 15);      // {10, 15, 20, 30, 40}
v.erase(v.begin() + 2);           // {10, 15, 30, 40}
if (!v.empty()) {
    int ultimo = v.back();        // salva o valor antes de remover
    v.pop_back();
    cout << ultimo << '\n';
}
```

**Pegadinha:** `v.erase(20)` não apaga o valor 20; `erase` recebe **iterador**, não valor. Para filtrar valores, veja [remove/erase](unique_erase.md).

Depois de realocação, ponteiros, referências e iteradores antigos do vetor ficam inválidos. Depois de `erase`, os que estavam na posição apagada ou depois também ficam inválidos. Confira o iterador retornado ao apagar durante um laço. [Regras de alteração do vector](https://eel.is/c++draft/vector.modifiers).

<a id="reserve-resize"></a>
<a id="vector-reserve"></a>
<a id="vector-resize"></a>
## `reserve` × `resize`: espaço reservado × elementos existentes

| Sintaxe | Semântica | Retorno | Custo |
|---|---|---|---|
| `v.reserve(k);` | Garante capacidade para pelo menos `k`; **não muda `size()`** | `void` | O(n) no pior caso |
| `v.resize(k, x);` | Faz o tamanho virar `k`; acrescenta `x` ou remove do fim | `void` | O(n+k) no pior caso |
| `v.capacity()` | Espaço disponível antes de precisar realocar | `size_t` | O(1) |

```cpp
vector<int> a;
a.reserve(100);                   // a.size() ainda é 0
a.push_back(7);                   // agora a[0] existe
a.resize(4, -1);                  // {7, -1, -1, -1}
```

Se vai ler `n` números com `cin >> v[i]`, crie `vector<int> v(n)`. Se vai acumular com `push_back`, `reserve(n)` evita realocações desnecessárias. Não chame `reserve(size()+1)` a cada inserção. [Capacidade e tamanho do vector](https://eel.is/c++draft/vector.capacity).

<a id="string"></a>
## `string`: sequência de caracteres

| Sintaxe | Semântica | Retorno | Custo |
|---|---|---|---|
| `string s = "cin";` | Cria texto | Objeto | O(n) |
| `s[i]` | Caractere no índice `i`; use `i < s.size()` | Referência `char&` | O(1) |
| `s.size()` / `s.empty()` | Quantidade de caracteres / está vazia? | `size_t` / `bool` | O(1) |
| `s += t;` | Concatena `t` ao fim | Referência a `s` | O(n+k) no pior caso |
| `s.push_back(c);` / `s.pop_back();` | Acrescenta / remove caractere no fim | `void` | O(n) no pior caso / O(1) |
| `s.erase(pos, k);` | Apaga até `k` caracteres a partir de `pos` | Referência a `s` | O(n) no pior caso |

`'7'` é um `char`; `"7"` é texto. Para dígito válido `c` entre `'0'` e `'9'`, `c - '0'` produz o inteiro de 0 a 9. `s.pop_back()`, `s.front()` e `s.back()` exigem string não vazia.

<a id="string-find"></a>
<a id="string-npos"></a>
## `find` / `npos`: localizar uma substring ou caractere

**Sintaxe:** `auto pos = s.find("abc");` ou `s.find('a', inicio)`. Retorna o **índice da primeira ocorrência** a partir de `inicio`, ou `string::npos` se não existir. Busca de substring pode custar O(n·k); de um caractere, O(n). [Semântica de busca de strings](https://eel.is/c++draft/string.find).

```cpp
string s = "maratona cin";
auto pos = s.find("cin");
if (pos != string::npos) cout << pos << '\n';  // 9
```

**Pegadinha:** não teste `if (pos)`: índice zero significa encontrado no começo. Não use `pos >= 0`: o tipo é sem sinal. Compare explicitamente com `string::npos`.

<a id="string-substr"></a>
## `substr`: recortar uma cópia do texto

**Sintaxe:** `string parte = s.substr(inicio, quantidade);`. O segundo argumento é **comprimento**, não índice final. Retorna nova `string`; copiar `k` caracteres custa O(k). Para o intervalo `[l,r)`, use `s.substr(l, r-l)`. [Operação substr](https://eel.is/c++draft/string.substr).

```cpp
string s = "abcdef";
string a = s.substr(2, 3);        // "cde": índices 2, 3, 4
string b = s.substr(2);           // "cdef": até o fim
```

`inicio == s.size()` retorna string vazia; `inicio > s.size()` lança `out_of_range`. Se a quantidade ultrapassar o fim, pega somente o trecho disponível.

**Dica salvadora:** apagar no começo do `vector` repetidamente pode virar O(n²); para remover nas duas pontas, veja [deque](pilha_fila_heap.md#deque). Para ordenar e buscar números, veja [sort](sort.md) e [lower_bound](lower_bound.md).
