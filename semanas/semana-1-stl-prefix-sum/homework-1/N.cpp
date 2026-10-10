#include <bits/stdc++.h>
using namespace std;

bool compara_strings (string a, string b){
        return a + b < b + a;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    vector <string> palavras;
    
    
    for (int i = 0; i < n; i++){
        string palavra;
        cin >> palavra;
        palavras.push_back(palavra);
        
    }

    sort(palavras.begin(), palavras.end(), compara_strings);

    for (string x: palavras) {
        cout << x;

    }
    

    return 0;
}