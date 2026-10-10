#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,x;

    cin >> n >> x;
    map <long long, long long> freq;
    long long resposta = 0;
    long long soma = 0;

    freq[0] = 1;


    for (int i = 0; i < n; i++){
        long long numero;
        cin >> numero;
        soma += numero;
        resposta += freq[soma - x];
        if (freq[soma] == 0){
            freq[soma] = 1;
        }
        else{
            freq[soma] += 1;
        }
    }

    cout << resposta;
    

    return 0;
}