# `map`, `set`, `multiset` — chaves, frequências e busca ordenada
[Início](../../README.md) · [Consulta rápida](../README.md) · [Catálogo de funções](README.md)
**Pesquise:** map, mapa, dicionário, dictionary, frequência, frequency, chave, key, set, conjunto, multiset, repetidos, duplicatas, find, count, erase, lower_bound, upper_bound, unordered_map, hash.
**Convenção dos exemplos:** C++17, cabeçalhos `<map>`, `<set>`, `<unordered_map>`, `<string>`, `<iostream>` e `using namespace std;`. `n` é o tamanho; `k` é a quantidade de ocorrências de uma chave. Custos abaixo assumem comparação e hash O(1).
**Atalhos:** [escolher estrutura](#escolher) · [map/find](#map-find) · [frequências](#frequencias) · [erase](#erase) · [set/multiset](#set) · [bounds](#bounds) · [hash](#unordered-map).
<a id="escolher"></a>

## Qual usar?

| Estrutura | Guarda | Ordem padrão | Gatilho do problema |
|---|---|---|---|
| `map<Chave, Valor>` | Uma entrada por chave | Chave crescente | Frequência, associar nome a pontos |
| `set<T>` | Valores sem duplicatas | Valor crescente | Distintos, vizinho menor/maior |
| `multiset<T>` | Valores com duplicatas | Valor crescente | Remover uma ocorrência, manter valores ordenados |
| `unordered_map<Chave, Valor>` | Uma entrada por chave | Sem ordem garantida | Consultas exatas; não precisa de vizinhos |
`map` e `set` são ordenados automaticamente. Os métodos membros `find`, `lower_bound` e `upper_bound` aproveitam essa organização. [Requisitos dos contêineres associativos](https://eel.is/c++draft/associative.reqmts).
<a id="map"></a>
<a id="map-find"></a>
<a id="map-count"></a>
<a id="map-operator"></a>

## `map`: acessar, buscar e descobrir se existe

| Sintaxe | Semântica | Retorno | Custo |
|---|---|---|---|
| `map<string,int> m;` | Cria mapa vazio | Objeto | O(1) |
| `m[chave]` | Acessa valor; se ausente, **insere** valor inicial (`int` vira 0) | Referência ao valor | O(log n) |
| `m.at(chave)` | Acessa valor existente; ausente lança `out_of_range` | Referência ao valor | O(log n) |
| `m.find(chave)` | Busca uma entrada | Iterador ou `m.end()` | O(log n) |
| `m.count(chave)` | Quantas entradas têm a chave | `size_t`, 0 ou 1 | O(log n) |
| `m.insert({chave, valor})` | Insere somente se a chave não existir | `pair<iterator,bool>` | O(log n) |
| `m.size()` / `m.empty()` | Quantidade de chaves / está vazio? | `size_t` / `bool` | O(1) |

```cpp
map<string, int> pontos;
pontos["ana"] += 10;              // insere 0, depois soma 10
auto it = pontos.find("bia");
if (it != pontos.end()) cout << it->second << '\n';
for (const auto& [nome, valor] : pontos) cout << nome << ' ' << valor << '\n';
```
`it->first` é a chave; `it->second` é o valor. **Nunca use `it->second` se `it == m.end()`**. Para perguntar se existe sem inserir, use `find` ou `count`; `m[chave]` altera o mapa mesmo em uma consulta. [Acesso aos elementos do map](https://eel.is/c++draft/map.access).
<a id="frequencias"></a>

## Frequências: contar e remover a última ocorrência

```cpp
map<int, int> freq;
int x = 7;
++freq[x];                         // contador de 7 vira 1
auto it = freq.find(x);
if (it != freq.end() && --it->second == 0) freq.erase(it);
cout << freq.size() << '\n';       // distintos: só se não restarem chaves com zero
```
Use contadores `long long` se podem crescer muito. Em prefix sum + mapa, a chave também deve comportar a soma: `map<long long, long long>`.
<a id="erase"></a>
<a id="map-erase"></a>
<a id="multiset-erase"></a>

## `erase(chave)` × `erase(iterador)`

| Sintaxe | Semântica | Retorno | Custo |
|---|---|---|---|
| `m.erase(chave)` / `s.erase(chave)` | Remove a chave, se existir | Quantidade removida: 0 ou 1 | O(log n) |
| `ms.erase(x)` | Remove **todas** as ocorrências de `x` | Quantidade removida | O(log n + k) |
| `c.erase(it)` | Remove **uma** entrada apontada por `it` | Iterador para a próxima, ou `end()` | O(1) amortizado |
`erase(it)` exige iterador válido para um elemento: **`erase(end())` é inválido**. Só iteradores dos elementos apagados são invalidados; os demais permanecem válidos.

```cpp
multiset<int> ms = {2, 2, 5};
auto it = ms.find(2);
if (it != ms.end()) ms.erase(it);  // sobra {2, 5}
ms.erase(2);                      // agora sobra {5}
```
<a id="set"></a>
<a id="multiset"></a>
<a id="set-insert"></a>

## `set` / `multiset`: inserir e contar

| Sintaxe | Semântica | Retorno | Custo |
|---|---|---|---|
| `s.insert(x)` | Insere em `set` se ainda não existir | `pair<iterator,bool>` | O(log n) |
| `ms.insert(x)` | Insere em `multiset`, inclusive repetido | Iterador para o inserido | O(log n) |
| `s.find(x)` / `ms.find(x)` | Busca uma ocorrência | Iterador ou `end()` | O(log n) |
| `s.count(x)` / `ms.count(x)` | Conta ocorrências | `size_t` | O(log n) / O(log n + k) |
Se não vazio: `*s.begin()` é o menor e `*s.rbegin()` o maior. `set` não tem `operator[]`: não use `s[0]`. Não mude o valor de um elemento pelo iterador; remova e reinsira.
<a id="bounds"></a>
<a id="lower-bound"></a>
<a id="upper-bound"></a>

## `lower_bound` / `upper_bound` em contêiner ordenado

| Sintaxe | Semântica com ordem crescente padrão | Retorno | Custo |
|---|---|---|---|
| `s.lower_bound(x)` / `m.lower_bound(x)` | Primeiro valor/chave **>= x** | Iterador ou `end()` | O(log n) |
| `s.upper_bound(x)` / `m.upper_bound(x)` | Primeiro valor/chave **> x** | Iterador ou `end()` | O(log n) |
Use **o método membro** em `set`, `map` e `multiset`. A função livre `std::lower_bound` pode fazer O(n) avanços de iterador nessas estruturas. Em `vector`, use a [função livre lower_bound](lower_bound.md).
Para o maior valor **<= x**, faça `auto it = s.upper_bound(x);` e só use `*--it` se `it != s.begin()`. Isso também evita decrementar o `begin()` de um conjunto vazio.
<a id="unordered-map"></a>

## `unordered_map`: busca exata por hash
`unordered_map<int,int> freq;` oferece `[]`, `find`, `count` e `erase`: custo **O(1) médio**, O(n) no pior caso. Não oferece `lower_bound` nem `upper_bound`, e a iteração não segue ordem crescente. Rehash pode invalidar iteradores; não os guarde através de inserções sem conferir as regras. [Requisitos de hash e iteração](https://eel.is/c++draft/unord.req).
**C++17:** não use `.contains()`; esse método só existe a partir de C++20. O equivalente aqui é `c.find(x) != c.end()`.
