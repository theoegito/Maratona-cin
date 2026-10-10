#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string palavra;

    cin >> palavra;

    vector <string> lista;

    sort(palavra.begin(), palavra.end());
    

    do {
        lista.push_back(palavra);

    }
    while (next_permutation(palavra.begin(),palavra.end()));

    cout << lista.size() << '\n';
    

    for (string x:lista){

        cout << x << '\n';

    }
    
    return 0;
}