#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    vector <long long> v(n+1);
    v[0] = 0;

    long long soma = 0;


    for (long long i = 0; i < n; i++){
        long long j;
        cin >> j;
        soma += j;
        v[i+1] = soma;

    }

    for (long long k = 0; k < q; k++){
        long long p,r;
        cin >> p >> r;
        long long valor = v[r] - v[p-1];
        cout << valor << '\n';

    }
    

    return 0;
}