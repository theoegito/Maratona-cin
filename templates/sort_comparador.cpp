// Ordena palavras para obter a menor concatenacao lexicografica (estilo N.cpp).
// Entrada: n; depois n strings sem espacos.
// Saida: a concatenacao minima, seguida de '\n'.
// Pre-condicoes: n >= 0; comparacao lexicografica padrao de string e a desejada.
// Custo: O(n log(n + 1) * L), em que L e o maior comprimento de uma string.
// Cada comparacao cria a+b e b+a, portanto custa O(|a| + |b|), nao O(1).
// Memoria: O(S + L + log(n + 1)), em que S e a soma dos comprimentos armazenados.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool vemAntes(const string& a, const string& b) {
    // const impede alterar as strings; & evita copiar os parametros.
    // Devolver true significa que a deve aparecer antes de b.
    // Exemplo: "ba"+"b" = "bab" e "b"+"ba" = "bba": "ba" vem antes.
    // Use <, nunca <=: para empates e para comparar um item com ele mesmo, deve ser false.
    return a + b < b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<string> palavras(n);
    for (int i = 0; i < n; ++i) cin >> palavras[i];

    // begin e end delimitam [inicio, fim): o iterador end nao e um elemento.
    sort(palavras.begin(), palavras.end(), vemAntes);

    for (const string& palavra : palavras) cout << palavra;
    cout << '\n';
}
