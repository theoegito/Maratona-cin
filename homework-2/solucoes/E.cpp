
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long salas, reuniao, operacoes;
    vector<long long> salas_reuniao;
    vector<long long> inicios;
    vector<long long> fins;

    cin >> salas >> reuniao >> operacoes;
    
    for (long long i = 0; i < reuniao; i++){
        long long sala_r;
        cin >> sala_r;
        salas_reuniao.push_back(sala_r);


    }

    for (long long j = 0; j < operacoes; j++){
        long long inicio, fim;
        cin >> inicio >> fim;
        inicios.push_back(inicio);
        fins.push_back(fim);

    }

    sort(inicios.begin(),inicios.end());
    sort(fins.begin(),fins.end());

    long long salas_ligadas = 0;

    for (long long sala_x : salas_reuniao){
        long long qtd_mudancas;
        long long comecaram = upper_bound(inicios.begin(), inicios.end(), sala_x) - inicios.begin();
        long long finalizaram = lower_bound (fins.begin(), fins.end(), sala_x) - fins.begin();\
        qtd_mudancas = comecaram - finalizaram;
        if (qtd_mudancas % 2 == 1){
            salas_ligadas += 1;
        }



    }

    cout << salas_ligadas;
    return 0;
}