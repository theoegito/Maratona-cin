#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, t;

    cin >> n >> t;

    vector <long long> lista_t;

    for (int i = 0; i < n; i++){
        long long tempo_maq;
        cin >> tempo_maq;
        lista_t.push_back(tempo_maq);
    }

    long long l = 0;
    long long r = 1000000000000000000;

    while (l < r){
        long long meio = (l + r)/2;
        long long prod_feitos = 0;

        for (long long tempo: lista_t){

            prod_feitos += meio/tempo;
            if (prod_feitos >= t){
                break;
            }
        }

        if (prod_feitos >= t){
            r = meio;

        }
        else if (prod_feitos < t){
            l = meio + 1; 
        }

    }

    cout << l;



    return 0;
}