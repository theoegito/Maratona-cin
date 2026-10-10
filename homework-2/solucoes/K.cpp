#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,x;

    cin >> n >> x;

    
    vector <long long> lista;


    for (long long i = 0; i < n ; i++){
        long long numero;
        cin >> numero;
        lista.push_back(numero);

        
    }

    long long l = 0;
    long long soma = 0;
    long long maior_sequencia = 0;

    for (long long r = 0; r < n ; r++){

        soma += lista[r];
         
        while (soma > x)
        {
            soma -= lista[l];
            l++;
               
        }

        maior_sequencia = max (maior_sequencia, (r-l) + 1);
        
        

    }

    cout << maior_sequencia;


    return 0;
}