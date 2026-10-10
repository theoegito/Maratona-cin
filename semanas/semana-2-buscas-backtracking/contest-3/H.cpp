#include <bits/stdc++.h>
#include <utility> 
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,x;

    cin >> n >> x;

    vector<pair<long long, long long>> lista_num;


    for (long long i = 0; i < n; i++){
        long long numero;
        cin >> numero;
        lista_num.push_back({numero, i+1});
        
    
    }

    sort(lista_num.begin(), lista_num.end());

    for (int j = 0; j )


   
        cout << "IMPOSSIBLE" << '\n';
    
    return 0;
}