#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,l,r,x;

    cin >> n >> l >> r >> x;

    vector <long long> lista;

    for (int i = 0; i < n; i++){
        long long numero;
        cin >> numero;
        lista.push_back(numero);
    }

    long long resposta_formas = 0; 

    for (long long mascara = 1; mascara < (1 << n); mascara++){
        int num_prob = 0;
        long long soma_dif = 0;
        vector <long long> olimpiada;

        for (int j = 0; j < n; j++){
            if (mascara & (1 << j)){
                num_prob += 1;
                soma_dif += lista[j];
                olimpiada.push_back(lista[j]);

            }

        }

        long long menor = *min_element (olimpiada.begin(), olimpiada.end());
        long long maior = *max_element (olimpiada.begin(), olimpiada.end());

        if (soma_dif <= r && soma_dif >= l && (maior - menor) >= x && num_prob > 1){
            resposta_formas++;
        }


    }

    cout << resposta_formas;




    return 0;
}