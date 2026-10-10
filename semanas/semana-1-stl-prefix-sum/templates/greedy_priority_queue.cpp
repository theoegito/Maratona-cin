// Escolhe o maior numero de elementos mantendo a ordem original.
// A saude comeca em 0. A soma de cada prefixo da subsequencia escolhida deve ser >= 0.
// Entrada: n; depois n variacoes de saude (positivas, negativas ou zero).
// Saida: a quantidade maxima de elementos que podem ser escolhidos.
// Pre-condicoes: n >= 0; somas e subtracoes cabem em long long.
// Custo: O(n log(n + 1)); memoria O(n).

#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    // greater torna o menor valor acessivel por top(): uma min-heap.
    priority_queue<long long, vector<long long>, greater<long long>> escolhidos;
    long long saude = 0;

    for (int i = 0; i < n; ++i) {
        long long valor;
        cin >> valor;
        saude += valor;
        escolhidos.push(valor); // Tentamos incluir o novo elemento.

        if (saude < 0) {
            // Descartar o menor valor recupera mais saude com uma unica remocao.
            // Isso preserva a chance de aceitar o maximo de elementos futuros.
            // Uma remocao basta: antes da inclusao, a saude era >= 0.
            saude -= escolhidos.top(); // top consulta o valor antes de apagar.
            escolhidos.pop();          // pop apaga e NAO retorna o valor.
        }
    }

    // A heap ajuda a decidir quais elementos descartar; nao reordena a subsequencia.
    cout << escolhidos.size() << '\n';
}
