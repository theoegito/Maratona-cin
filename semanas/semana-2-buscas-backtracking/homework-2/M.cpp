#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector <long long> lista;

    for (int i = 0; i < n; i++){

        long long peso_maca;

        cin >> peso_maca;

        lista.push_back(peso_maca);
    }

    long long soma_total = accumulate(lista.begin(), lista.end(), 0LL);
    long long menor_diferenca = 1000000000000000000;
    


    for(int mascara = 1 ; mascara < (1 << n); mascara++){
        long long soma_parcial = 0;

        for (int j = 0; j < n; j ++){
            if (mascara & (1 << j)){
                soma_parcial += lista[j];
            }

        }

        menor_diferenca = min (menor_diferenca, abs ((soma_total - soma_parcial) - soma_parcial));
        
        
        
    }

    cout << menor_diferenca;
    

    return 0;
}