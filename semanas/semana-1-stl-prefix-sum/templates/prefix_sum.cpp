// Soma de intervalos com prefix sum.
// Entrada: n q; depois n inteiros; depois q pares l r.
// Cada consulta usa indices de 1 a n e inclui as duas pontas.
// Saida: uma soma por linha.
// Pre-condicoes: n >= 1, q >= 0, 1 <= l <= r <= n;
// todos os prefixos e resultados devem caber em long long.
// Custo: O(n) para construir, O(1) por consulta, O(n + q) total; memoria O(n).

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    // prefixo[i] guarda a soma dos primeiros i numeros.
    // A posicao 0 representa nenhum numero: sua soma e 0.
    vector<long long> prefixo(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long valor;
        cin >> valor;
        prefixo[i] = prefixo[i - 1] + valor;
    }

    while (q--) {
        int l, r;
        cin >> l >> r; // Cada >> extrai uma entrada; nao use cin >> l, r.
        // Tiramos os numeros anteriores a l da soma ate r.
        cout << prefixo[r] - prefixo[l - 1] << '\n';
    }
}
