// Template independente para C++17: coloque a solucao dentro de main().
// Entrada e saida: dependem do problema; este modelo vazio nao imprime nada.
// Pre-condicoes e complexidade: dependem do algoritmo que voce adicionar.

// Headers padrao: mantenha apenas os que sua solucao precisar.
#include <algorithm>  // sort, min, max, lower_bound, upper_bound
#include <deque>      // deque
#include <functional> // greater: usado, por exemplo, na fila de menor prioridade
#include <iostream>   // cin, cout
#include <limits>     // numeric_limits
#include <map>        // map
#include <numeric>    // accumulate, gcd
#include <queue>      // queue, priority_queue
#include <set>        // set, multiset
#include <stack>      // stack
#include <string>     // string, getline
#include <utility>    // pair
#include <vector>     // vector

using namespace std; // Permite escrever cout em vez de std::cout.

int main() {
    ios::sync_with_stdio(false); // Acelera cin/cout; evite misturar com scanf/printf.
    cin.tie(nullptr);           // Remove a descarga automatica de cout antes de cin.
                               // Em problemas interativos, descarregue cout ao pedir resposta.

    // Exemplo de leitura: int n; cin >> n;
    // Exemplo de escrita: cout << n << '\n';
    // Use long long para somas grandes; 1LL * a * b multiplica em long long.

    return 0; // Encerra o programa com sucesso.
}
