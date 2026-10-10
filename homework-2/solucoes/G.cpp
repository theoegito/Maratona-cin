#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;

    vector <vector<int>> lista_conjuntos;

    for (int i = 0; i < m; i ++){
        int qtd;
        cin >> qtd;
        vector <int> conjunto;
        for (int j = 0; j < qtd; j++){
            int numero;
            cin >> numero;
            conjunto.push_back(numero);

        }

        lista_conjuntos.push_back(conjunto);
        

    }

    long long resposta = 0;

    for (int mascara = 1; mascara < (1 << m); mascara++){

        vector<bool> encontrou (n, false);

        for (int k = 0; k < m; k++){

            if (mascara & (1 << k)){

                for (int numero : lista_conjuntos[k]){

                    encontrou [numero - 1] = true;


                }

            }


        }

        
        if (count(encontrou.begin() , encontrou.end(), true) == n) {
            resposta++;}


    }

    cout << resposta;
    

    return 0;
}