#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long clientes;

    cin >> clientes;
    vector <pair<long long, int>> lista_clientes;


    for (int i = 0; i < clientes; i++){
        long long entrada, saida;

        cin >> entrada >> saida;

        lista_clientes.push_back({entrada, +1});
        lista_clientes.push_back({saida, -1});

    }


    long long sequencia_atual = 0;
    long long maior_sequencia = 0;

    sort (lista_clientes.begin(), lista_clientes.end());

    for (int j = 0; j < (clientes * 2); j++){
        
        sequencia_atual += lista_clientes[j].second;
        maior_sequencia = max (sequencia_atual, maior_sequencia);


    }

    cout << maior_sequencia;

    return 0;
}