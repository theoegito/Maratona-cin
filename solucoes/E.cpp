#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k;
    cin >> n >> k;
    vector <int> seq;
    map <int, int> frequencia;
    long long numeros_distintos = 0;

    for (long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        seq.push_back(x);
    }

    for (long long j = 0; j < k; j++){
        if (frequencia[seq[j]] == 0){
            frequencia[seq[j]] = 1;
            numeros_distintos += 1;
        }
        else{
            frequencia[seq[j]] += 1;
        }
    }
    
    cout << numeros_distintos << ' ';

    for (long long l = 0; l < (n-k); l++){
        if (frequencia[seq[l]] == 1){
            numeros_distintos -= 1;
            frequencia[seq[l]] -= 1;
        }
        else{
            frequencia[seq[l]] -= 1;
        }

        if (frequencia[seq[l+k]] == 0) {
            numeros_distintos += 1;
            frequencia[seq[l+k]] = 1;
        }
        else {
            frequencia[seq[l+k]] += 1;
        }
    
        cout << numeros_distintos << ' ';
    }

    return 0;
}