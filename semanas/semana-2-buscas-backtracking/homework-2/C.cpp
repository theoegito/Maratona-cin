#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    vector <long long> lista_niveis;

    cin >> n; 

    for (long long i = 0; i < n; i++){
        long long numero;
        cin >> numero;
        lista_niveis.push_back(numero);

    }

    sort(lista_niveis.begin(), lista_niveis.end());
    long long maior_sequencia = 1;
    long long sequencia_atual = 1;
    long long r = 1;

    for (int l = 0; l < n; l ++){

        while (r < n && lista_niveis[r] - lista_niveis [l] <= 5){
            r++;
            sequencia_atual++ ;
            maior_sequencia = max(maior_sequencia, sequencia_atual);

        }

        sequencia_atual --;

        
    }

    cout << maior_sequencia;

    return 0;
}