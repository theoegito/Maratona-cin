# `stack`, `queue`, `deque`, `priority_queue` — qual elemento sai?

[Início](../../README.md) · [Consulta rápida](../README.md) · [Catálogo de funções](README.md)

**Pesquise:** stack, pilha, LIFO, queue, fila, FIFO, deque, duas pontas, priority_queue, heap, min heap, max heap, menor, maior, top, front, back, push, pop, greater.

**Convenção dos exemplos:** C++17, cabeçalhos `<stack>`, `<queue>`, `<deque>`, `<vector>`, `<functional>`, `<utility>`, `<iostream>` e `using namespace std;`. `n` é o número de elementos.

**Atalhos:** [escolher](#escolher) · [stack/top/pop](#stack) · [queue/front/pop](#queue) · [deque](#deque) · [priority_queue](#priority-queue) · [heap mínimo](#min-heap) · [pares](#heap-pair).

<a id="escolher"></a>
## Reconheça a ordem de remoção

| Necessidade do problema | Estrutura | Elemento acessível | Gatilhos / palavras-chave |
|---|---|---|---|
| Último que entrou sai primeiro | `stack<T>` | `top()` | Desfazer, parênteses, pilha monotônica |
| Primeiro que entrou sai primeiro | `queue<T>` | `front()` | Ordem de chegada, BFS, atendimento |
| Inserir e retirar em ambas as pontas | `deque<T>` | `front()`, `back()` | Duas pontas, deque monotônico |
| Retirar sempre o maior ou menor | `priority_queue<T>` | `top()` | Prioridade, greedy, eventos, melhor disponível |

`stack`, `queue` e `priority_queue` não têm iteração direta com `begin()/end()` nem acesso por índice. Para listar seu conteúdo, normalmente se remove elemento a elemento de uma **cópia**.

<a id="stack"></a>
<a id="stack-top"></a>
<a id="stack-push"></a>
<a id="stack-pop"></a>
## `stack`: pilha — LIFO

| Sintaxe | Semântica | Retorno | Custo com contêiner padrão |
|---|---|---|---|
| `stack<int> st;` | Cria pilha vazia | Objeto | O(1) |
| `st.push(x);` | Insere no topo | `void` | O(1) |
| `st.top()` | Consulta o último inserido; exige não vazia | Referência ao elemento | O(1) |
| `st.pop();` | Remove o topo; exige não vazia | **`void`** | O(1) |
| `st.empty()` / `st.size()` | Está vazia? / quantidade | `bool` / `size_t` | O(1) |

```cpp
stack<int> st;
st.push(10); st.push(20);
if (!st.empty()) {
    int x = st.top();             // 20: leia antes de remover
    st.pop();                    // não devolve 20
    cout << x << '\n';
}
```

**Pegadinha:** `int x = st.pop();` não compila. `auto& x = st.top(); st.pop();` deixa a referência sem elemento válido. Salve uma **cópia** antes de remover. [Definição de stack](https://eel.is/c++draft/stack.defn).

<a id="queue"></a>
<a id="queue-front"></a>
<a id="queue-back"></a>
<a id="queue-push"></a>
<a id="queue-pop"></a>
## `queue`: fila — FIFO

| Sintaxe | Semântica | Retorno | Custo com contêiner padrão |
|---|---|---|---|
| `queue<int> q;` | Cria fila vazia | Objeto | O(1) |
| `q.push(x);` | Insere no fim | `void` | O(1) |
| `q.front()` / `q.back()` | Primeiro a sair / último inserido; exige não vazia | Referência | O(1) |
| `q.pop();` | Remove o **primeiro**; exige não vazia | **`void`** | O(1) |
| `q.empty()` / `q.size()` | Está vazia? / quantidade | `bool` / `size_t` | O(1) |

```cpp
queue<int> q;
q.push(10); q.push(20);
while (!q.empty()) {
    int x = q.front();            // 10, depois 20
    q.pop();
    cout << x << '\n';
}
```

**Lembrete:** `queue` usa `front()`; `stack` usa `top()`. Em BFS, marque o estado quando entrar na fila para evitar enfileirar repetidamente o mesmo estado. [Definição de queue](https://eel.is/c++draft/queue.defn).

<a id="deque"></a>
<a id="deque-push-front"></a>
<a id="deque-push-back"></a>
<a id="deque-pop-front"></a>
<a id="deque-pop-back"></a>
## `deque`: inserir e retirar nas duas pontas

| Sintaxe | Semântica | Retorno | Custo |
|---|---|---|---|
| `deque<int> d;` | Cria deque vazio | Objeto | O(1) |
| `d.push_front(x);` / `d.push_back(x);` | Insere no começo / fim | `void` | O(1) |
| `d.front()` / `d.back()` | Consulta começo / fim; exige não vazio | Referência | O(1) |
| `d.pop_front();` / `d.pop_back();` | Remove começo / fim; exige não vazio | **`void`** | O(1) |
| `d[i]` | Acessa índice válido `0 <= i < d.size()` | Referência | O(1) |

`deque` permite acesso por índice, mas sua memória não é um bloco contínuo como a do `vector`. Inserir/apagar no **meio** custa O(n); operações nas pontas podem invalidar iteradores. [Alterações em deque](https://eel.is/c++draft/deque.modifiers).

<a id="priority-queue"></a>
<a id="heap-top"></a>
<a id="heap-push"></a>
<a id="heap-pop"></a>
## `priority_queue`: heap máximo por padrão

| Sintaxe | Semântica | Retorno | Custo |
|---|---|---|---|
| `priority_queue<int> pq;` | Cria heap com **maior** no topo | Objeto | O(1) |
| `pq.push(x);` | Insere preservando a prioridade | `void` | O(log n) amortizado com vector padrão |
| `pq.top()` | Consulta a maior prioridade; exige não vazio | Referência **const** | O(1) |
| `pq.pop();` | Remove a maior prioridade; exige não vazio | **`void`** | O(log n) |
| `pq.empty()` / `pq.size()` | Está vazio? / quantidade | `bool` / `size_t` | O(1) |

Uma inserção individual pode custar O(n) por realocação do vetor interno. O heap **não está totalmente ordenado**: apenas garante qual elemento está no topo. Não permite apagar diretamente um elemento arbitrário pelo valor. [Semântica de priority_queue](https://eel.is/c++draft/priority.queue).

<a id="min-heap"></a>
## Heap mínimo: `greater` coloca o menor no topo

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(8); pq.push(3); pq.push(5);
while (!pq.empty()) {
    int x = pq.top();             // 3, depois 5, depois 8
    pq.pop();
    cout << x << '\n';
}
```

**Dica salvadora:** na declaração, lembre os três argumentos: **tipo do elemento, contêiner, comparador**. `greater<int>` precisa de `<functional>`.

<a id="heap-pair"></a>
## Pares: desempate automático

`priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;` coloca o menor par no topo: primeiro compara `.first`; em empate, compara `.second`. Útil para `(custo, id)` ou `(horário, evento)`.

**Pegadinha:** trocar `.first` e `.second` troca a prioridade. Um comparador customizado de heap retorna `true` quando o primeiro argumento deve ter **menor prioridade** que o segundo. Para ordenar vetores, consulte [comparadores de sort](sort.md).
