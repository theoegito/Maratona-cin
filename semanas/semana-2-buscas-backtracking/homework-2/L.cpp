#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;

    cin >> n >> x;

    vector <pair<long long, long long>> lista;



    for (long long i = 0; i < n; i++){
        long long numero;
        cin >> numero;

    lista.push_back({numero, i+1});


    }

    sort (lista.begin(), lista.end());

    long long l,r;
    l = 0;
    r = n - 1;

    bool achou = false;

    while (l < r){
        
        if (lista[l].first + lista[r].first == x){
            cout << lista[l].second << ' ' << lista[r].second;
            achou = true;
            break;
        }
        else if (lista[l].first + lista[r].first < x) {
            l += 1;
        }
        else {
            r -= 1;
        }

    } 

    if (achou == false){
        cout << "IMPOSSIBLE";
    }
    

    return 0;
}