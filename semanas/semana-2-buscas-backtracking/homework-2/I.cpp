
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long casos;

    cin >> casos;
    
   
    for (int i = 0; i < casos; i++){

        long long est, vacas;
        cin >> est >> vacas;

        vector <long long> lista;

        long long resposta = 0;

        for (int j = 0; j < est; j++){
            long long estabulo;
            cin >> estabulo;
            lista.push_back(estabulo);

        }

        sort(lista.begin(), lista.end());

        long long l, r;
        l = 0; 
        r = (lista.back() - lista.front());

        while (l <= r){
            long long meio = (l + r)/2;
            long long distancia_atual = 0;
            long long vacas_colocadas = 1;
            long long ultima_pos = lista.front();
            bool estourou = false;


            while (vacas_colocadas < vacas){

                auto menor_possivel = lower_bound (lista.begin(), lista.end(), ultima_pos + meio);

                if (menor_possivel == lista.end()){
                    estourou = true;
                    break;
                }

                ultima_pos = *menor_possivel;
                vacas_colocadas++;
            }

            if (estourou == false){
                resposta = meio;
                l = meio + 1;

            }
            else {
                r = meio - 1;
            }

        }

        cout << resposta << '\n';

    }

    return 0;
}