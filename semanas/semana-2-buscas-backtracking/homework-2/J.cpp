
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k;

    cin >> n >> k;

    vector <long long> lista_num;

    for (int i = 0; i < n; i ++){
        long long numero;
        cin >> numero;
        lista_num.push_back(numero);

    }

    long long l,r;
    l = *max_element(lista_num.begin(), lista_num.end());
    r = accumulate (lista_num.begin(), lista_num.end(), 0LL);
    long long maior_soma = 0;


    while (l <= r){
        long long meio = (l + r)/2;
        long long num_grupos = 1;
        long long soma_atual = 0;
        long long contador = 0;
        
        while (num_grupos <= k && contador < lista_num.size()){
            if ((soma_atual + lista_num[contador]) <= meio){
                soma_atual += lista_num[contador];
                contador += 1;
            
            }
            else{
                num_grupos += 1;
                soma_atual = lista_num[contador];
                contador++;

            }
        }

        
        if (num_grupos <= k){
            maior_soma = meio;
            r = meio - 1;
            
        }
        else {
            l = meio + 1;

        }

        

    }
    cout << maior_soma;


    return 0;
}