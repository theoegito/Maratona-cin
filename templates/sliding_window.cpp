// Quantidade de valores distintos em cada janela de tamanho fixo k.
// Entrada: n k; depois n inteiros (podem ser negativos).
// Saida: as n-k+1 quantidades, separadas por espacos, com '\n' ao final.
// Pre-condicoes: n >= 0 e 1 <= k <= n.
// Se k estiver fora desse intervalo, imprime "Janela invalida".
// Custo: O(n log(k + 1)) com map; memoria O(n + k) por guardar o vetor e o map.

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    if (k < 1 || k > n) {
        cout << "Janela invalida\n";
        return 0;
    }

    vector<long long> a(n); // n posicoes ja existem: podemos preencher a[i].
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<long long, int> frequencia;

    for (int direita = 0; direita < n; ++direita) {
        ++frequencia[a[direita]]; // [] cria a chave com 0 se ela ainda nao existir.

        if (direita >= k) {
            long long saiu = a[direita - k];
            --frequencia[saiu]; // Remove uma ocorrencia do elemento que saiu.
            if (frequencia[saiu] == 0) {
                frequencia.erase(saiu); // Apaga a chave: ela nao esta mais na janela.
            }
        }

        if (direita >= k - 1) { // So imprime depois que a janela tiver k elementos.
            if (direita > k - 1) cout << ' ';
            cout << frequencia.size(); // Cada chave restante e um valor distinto.
        }
    }
    cout << '\n';
}
