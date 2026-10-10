# `pair` e `tuple` — guardar informações que precisam ficar juntas

[Início](../../README.md) · [Consulta](../README.md) · [Catálogo](README.md)

**Palavras-chave:** pair, par, first, second, make_pair, tuple, tupla, get, tie, desempate, ordenação, valor e índice, posição original, structured bindings, decomposição, referência.

**Base da aula:** `pair` e `tuple` aparecem nas páginas 33–34 de **#1 Introdução.pdf**. Os exemplos abaixo explicam a sintaxe C++17 e aplicações. [Semana 1: STL e Prefix Sum](../../semanas/semana-1-stl-prefix-sum/README.md).

**Atalhos:** [pair](#pair) · [make_pair](#make-pair) · [comparação](#comparacao) · [índices originais](#indices-originais) · [cópia/referência](#structured-bindings) · [tuple/get](#tuple) · [tie](#tie).

Os blocos são independentes e ficam dentro de `main`. Use `<utility>`, `<tuple>`, `<vector>`, `<algorithm>`, `<string>` e `<iostream>`, com `using namespace std;`.

<a id="pair"></a>
## `pair<T, U>`: dois campos, que podem ter tipos diferentes

| Sintaxe | Significado | Tipo/retorno |
|---|---|---|
| `pair<long long, int> p{42, 3};` | Cria um par; o primeiro campo recebe 42 e o segundo recebe 3 | `pair<long long, int>` |
| `p.first` | Acessa o primeiro campo | Referência a `long long` |
| `p.second` | Acessa o segundo campo | Referência a `int` |
| `p.second = 9;` | Altera o segundo campo do próprio par | Atribuição |
| `get<0>(p)` / `get<1>(p)` | Outra forma de acessar os campos | Referência ao campo |

```cpp
pair<long long, int> item{42, 3}; // Escolhemos: {valor, posição original}.
item.first += 10;
cout << item.first << ' ' << item.second << '\n'; // 52 3
```

**Semântica:** `first` não significa automaticamente valor, e `second` não significa automaticamente índice. Você escolhe o significado ao montar o par e mantém essa convenção no restante do programa. `pair` não tem acesso `p[0]`.

<a id="make-pair"></a>
## `{a, b}`, `make_pair` e inserir no vector

```cpp
auto p = make_pair(7LL, 2);       // pair<long long, int>: tipos deduzidos.
vector<pair<long long, int>> v;
v.push_back({p.first, p.second}); // Acrescenta um par ao fim.
v.emplace_back(9LL, 3);          // Constrói o par no vector.
cout << v[1].first << '\n';      // 9
```

`push_back` retorna `void`; `emplace_back` retorna referência ao novo elemento em C++17. Ambos têm custo amortizado O(1) no vector. Aqui, `{valor, indice}` é uma forma curta de fornecer os dois campos para o tipo que o vector já conhece.

**Tipos:** `make_pair(7, 2)` cria dois `int`; use `7LL` ou uma variável `long long` quando precisar desse tipo. `make_pair` normalmente guarda valores; use `ref`/`cref` de `<functional>` apenas quando quiser referências deliberadamente.

<a id="comparacao"></a>
## Comparação e `sort`: primeiro `first`, depois `second`

```cpp
vector<pair<int, int>> v = {{4, 2}, {1, 9}, {4, 1}};
sort(v.begin(), v.end());
// Resultado: {1,9}, {4,1}, {4,2}.
```

A ordem é **lexicográfica**: compara `first`; se houver empate, compara `second`. `{4,1} < {4,2}` é verdadeiro, e `{3,100} < {4,0}` também. Dois pares são iguais somente se os dois campos forem iguais. Isso permite guardar prioridade e desempate juntos. [Regra C++17 de comparação de pares](https://timsong-cpp.github.io/cppwp/n4659/pairs.spec).

Se a regra do problema for diferente, forneça um comparador:

```cpp
vector<pair<int, int>> v = {{4, 2}, {1, 9}, {4, 1}};
sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second; // No empate, segundo campo decrescente.
});
```

**Pegadinha:** o comparador usa `<` ou `>`, nunca `<=`/`>=` como regra de ordenação. Se pares empatados precisam manter sua ordem de entrada, veja [`stable_sort`](sort.md).

<a id="indices-originais"></a>
## Ordenar valores sem perder suas posições originais

```cpp
vector<long long> entrada = {2, 7, 5, 1};
vector<pair<long long, int>> itens;
for (int i = 0; i < static_cast<int>(entrada.size()); ++i) {
    itens.push_back({entrada[i], i + 1}); // Posição de entrada 1-based.
}
sort(itens.begin(), itens.end());
// {1,4}, {2,1}, {5,3}, {7,2}: valor e posição continuam associados.
cout << itens[0].first << ' ' << itens[0].second << '\n'; // 1 4
```

Depois de ordenar, `itens[j].first` é o **valor na posição j da ordem nova**; `itens[j].second` é sua **posição na entrada**. O próprio `j` não é a resposta quando o enunciado pede posições originais. Valores repetidos continuam tendo posições diferentes.

**Aplicações:** soma de dois/três valores, eventos `{tempo,tipo}`, tarefas `{prazo,duração}`. O par guarda a associação; o algoritmo decide quais itens escolher. Veja [como escolher a abordagem](../como-escolher.md#soma-tres-valores) e o [exemplo do Contest 3](../../semanas/semana-2-buscas-backtracking/contest-3/README.md).

<a id="structured-bindings"></a>
## `auto [a,b]` × `auto& [a,b]` × `const auto& [a,b]`

```cpp
pair<int, int> p{10, 3};
auto [valor, indice] = p;         // Copia p para a decomposição.
valor = 99;                      // p.first continua sendo 10.
auto& [valor_ref, indice_ref] = p;// Referências aos campos de p.
valor_ref = 20;                  // Agora p.first é 20.
const auto& [v, i] = p;          // Consulta sem copiar nem alterar p.
cout << valor << ' ' << v << ' ' << i << '\n'; // 99 20 3
```

Em `for (auto [valor, indice] : itens)`, você trabalha com uma cópia de cada par. Use `auto&` para alterar os campos armazenados e `const auto&` para consultar sem copiar. Em um `map`, a chave é constante: ela não pode ser alterada por `it->first` nem por decomposição. [Map/set](map_set.md).

<a id="tuple"></a>
## `tuple<T...>` e `get`: três ou mais informações

```cpp
tuple<long long, int, string> tarefa{12LL, 4, "ler"};
get<0>(tarefa) += 3;            // Primeiro campo; índice fixo na compilação.
auto [prazo, id, nome] = tarefa;
cout << prazo << ' ' << id << ' ' << nome << '\n'; // 15 4 ler
```

Use `<tuple>`. Os índices de `get<0>`, `get<1>` etc. começam em zero e precisam ser conhecidos na compilação. Tuplas não têm `.first`/`.second`. `make_tuple(a,b,c)` deduz os tipos; a comparação padrão considera o primeiro campo, depois o segundo e assim por diante. [Interface de tuplas C++17](https://timsong-cpp.github.io/cppwp/n4659/tuple).

<a id="tie"></a>
## `tie`: preencher variáveis existentes ou comparar campos

```cpp
int valor = 0, indice = 0;
pair<int, int> p{8, 2};
tie(valor, indice) = p; // Atribui 8 e 2 às variáveis já declaradas.
int prazo_a = 5, id_a = 3, prazo_b = 5, id_b = 7;
bool vem_antes = tie(prazo_a, id_a) < tie(prazo_b, id_b); // true.
cout << valor << ' ' << indice << ' ' << vem_antes << '\n';
```

`tie` cria uma tupla de **referências**, por isso exige variáveis apropriadas e não valores temporários como `tie(3,4)`. Para criar dados independentes, use `make_tuple`. Não guarde referências a variáveis que já saíram de escopo.

**Custo:** acessar um campo é O(1). Copiar/comparar o conjunto depende dos campos: dois inteiros custam O(1), mas uma string pode exigir percorrer caracteres. Ordenar n pares de inteiros com `sort` custa O(n log n).
