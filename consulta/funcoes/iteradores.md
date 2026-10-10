# Iteradores — posições, intervalos e retornos da STL

[Início](../../README.md) · [Consulta](../README.md) · [Catálogo](README.md)

**Palavras-chave:** iterator, iterador, begin, end, rbegin, rend, posição, ponteiro, asterisco, dereference, desreferenciar, seta, distance, next, prev, find, retorno, invalidation, invalidação.

**Base da aula:** a página 36 de **#1 Introdução.pdf** apresenta algoritmos sobre intervalos de iteradores; a página 44 aborda o laço por elementos. Aqui estão a sintaxe e os cuidados para usar essas interfaces. [Semana 1](../../semanas/semana-1-stl-prefix-sum/README.md).

**Atalhos:** [begin/end](#begin-end) · [ler/alterar](#acesso) · [índice/distância](#distancia) · [ordem reversa](#reversos) · [map/set](#map-set) · [invalidação](#invalidacao) · [tipos de retorno](#retornos).

Os blocos são independentes dentro de `main`; use `<vector>`, `<map>`, `<set>`, `<iterator>`, `<algorithm>` e `<iostream>`, com `using namespace std;`.

<a id="begin-end"></a>
## `begin()` e `end()`: intervalo com fim excluído

| Expressão | Semântica |
|---|---|
| `v.begin()` | Posição do primeiro elemento; igual a `end()` se estiver vazio |
| `v.end()` | Posição **depois** do último; não contém valor |
| `[v.begin(), v.end())` | Todos os elementos: início incluído, fim excluído |
| `v.begin()+l`, `v.begin()+r` | No vector, delimitam o trecho `[l,r)` |
| `v.cbegin()`, `v.cend()` | Iteradores que permitem consultar, mas não alterar o elemento |

```cpp
vector<int> v = {10, 20, 30};
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << ' '; // 10 20 30
}
sort(v.begin() + 1, v.end()); // Apenas índices 1 e 2.
```

**Pegadinha:** `*v.end()` é inválido. O último elemento é `v.back()` ou `*prev(v.end())`, exigindo que o vector não esteja vazio. `end()` pode ser retornado por uma busca sem que isso seja um erro.

<a id="acesso"></a>
## Posição (`it`) × valor (`*it`) × campo (`it->first`)

```cpp
vector<int> v = {10, 20, 30};
auto it = find(v.begin(), v.end(), 20);
if (it != v.end()) {
    cout << *it << '\n'; // 20: lê o valor na posição encontrada.
    *it = 25;            // Altera o elemento no vector.
}
```

O iterador aponta uma posição; `*it` acessa o elemento. Compare o resultado com o `end()` **do mesmo contêiner** antes de acessar. `it->campo` equivale a `(*it).campo` quando o elemento tem esse campo.

**Constância:** um iterador constante (`cbegin()`) impede alterar o elemento por ele; `const auto it = v.begin()` impede modificar a variável `it`, mas ainda pode permitir alterar `*it`. São coisas diferentes.

<a id="distancia"></a>
## Índice, `distance`, `next` e `prev`

| Sintaxe | Semântica | Custo |
|---|---|---|
| `it - v.begin()` | Índice 0-based no vector; ambos da mesma sequência | O(1) |
| `v.begin() + k` | Posição de índice k; respeite os limites | O(1) |
| `distance(a,b)` | Quantos passos de a até b | O(1) em acesso aleatório; O(k) em map/set |
| `next(it,k)` | Retorna uma cópia avançada k posições | O(1) em vector; O(\|k\|) em map/set |
| `prev(it,k)` | Retorna uma cópia recuada k posições | O(1) em vector; O(\|k\|) em map/set |
| `advance(it,k)` | Move a própria variável it; retorna `void` | Conforme a categoria do iterador |

```cpp
vector<int> v = {10, 20, 30};
auto it = next(v.begin(), 2);
cout << (it - v.begin()) << ' ' << *it << '\n'; // 2 30
auto anterior = prev(it);
cout << *anterior << '\n'; // 20; it continua na posição 2.
```

Subtração e `it+k` exigem **acesso aleatório**: funcionam com vector/string, mas não com map/set. `prev` exige poder recuar; não funciona com um iterador que só avança, como o de `forward_list`. Não avance além de `end()` nem recue antes de `begin()`. Para iteradores que só avançam, `distance(a,b)` exige que b seja alcançável avançando a. [Operações C++17](https://timsong-cpp.github.io/cppwp/n4659/iterator.operations).

<a id="reversos"></a>
## `rbegin()` e `rend()`: percorrer do último para o primeiro

```cpp
vector<int> v = {10, 20, 30};
for (auto it = v.rbegin(); it != v.rend(); ++it) {
    cout << *it << ' '; // 30 20 10: ++ anda na ordem reversa.
}
sort(v.rbegin(), v.rend()); // Vector fica {30,20,10}.
```

`rbegin()` acessa o último elemento quando ele existe; `rend()` encerra o percurso e não pode ser acessado. Em vetor vazio, são iguais. Use os dois extremos da mesma orientação: não misture `begin()` com `rend()` em um algoritmo.

<a id="map-set"></a>
## Iteradores de map e set

```cpp
map<int, int> frequencia = {{7, 2}, {9, 1}};
auto it = frequencia.find(7);
if (it != frequencia.end()) {
    cout << it->first << ' ' << it->second << '\n'; // Chave 7, valor 2.
    ++it->second; // Valor pode mudar; a chave não pode.
}
set<int> distintos = {2, 7, 9};
auto pos = distintos.find(7);
if (pos != distintos.end()) cout << *pos << '\n'; // Elemento, não par.
```

No map, `*it` é um par `{chave,valor}` com chave constante. No set, `*it` é o próprio valor e não pode ser alterado por esse iterador. Para obter um limite no map/set, prefira `s.lower_bound(x)` e `s.upper_bound(x)`: O(log n). [Map/set](map_set.md) · [pair/tuple](pair_tuple.md).

<a id="invalidacao"></a>
## Depois de inserir ou apagar, o iterador ainda vale?

| Operação | O que acontece com iteradores existentes |
|---|---|
| `vector.push_back` com realocação | Todos ficam inválidos; referências/ponteiros aos elementos também |
| `vector.push_back` sem realocação | Os dos elementos permanecem; o antigo `end()` fica inválido |
| `vector.erase(pos)` | Invalida os da posição apagada em diante, inclusive o antigo `end()` |
| Inserir em map/set | Os iteradores existentes permanecem válidos |
| Apagar em map/set | Só os do elemento apagado ficam inválidos |

`sort` de um vector não realoca seus elementos, mas **muda os valores nas posições**: um iterador para a posição 0 pode passar a acessar outro item. Não confunda validade da posição com identidade do dado.

```cpp
vector<int> v = {1, 2, 2, 3};
for (auto it = v.begin(); it != v.end(); ) {
    if (*it == 2) it = v.erase(it); // Retorno já aponta o próximo.
    else ++it;                    // Só avança quando não apagou.
}
// v = {1,3}; adequado para poucos elementos; repetidos erase podem custar O(n²).
```

Para filtrar um vector inteiro de uma vez em O(n), veja [remove/erase](unique_erase.md). [Regras do vector C++17](https://timsong-cpp.github.io/cppwp/n4659/vector.modifiers).

<a id="retornos"></a>
## Antes de usar uma função, confira o tipo de retorno

| Categoria | Exemplos | Como aproveitar |
|---|---|---|
| **Iterador** | `find`, `lower_bound`, `max_element` | Verificar `end()`; acessar com `*it` ou `it->campo` |
| **Bool** | `binary_search`, `empty`, `next_permutation` | Usar diretamente em condição |
| **Valor/contagem** | `size`, `count`, `accumulate`, `string.find` | Guardar o resultado; `string.find` usa `npos` para ausência |
| **Void** | `sort`, `reverse`, `push_back`, `pop` | A operação altera algo; não fornece resultado para atribuir |

`find(v.begin(),v.end(),x)` retorna iterador; `texto.find("abc")` retorna índice. `sort` ordena o próprio intervalo: não escreva `v = sort(...)`. Consulte sempre a página da função no [catálogo](README.md).
