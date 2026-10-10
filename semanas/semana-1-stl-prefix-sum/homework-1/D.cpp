#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long vida, n;
    vida = 0;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> fila;

    for (int i = 0; i < n; i++){
        long long numero;
        cin >> numero;
        vida += numero;
        if (vida < 0){
            if(fila.empty() == false && fila.top() < numero){
                long long saiu;
                saiu = fila.top();
                fila.pop();
                fila.push(numero);
                vida -= saiu;
            }
            else{
            vida -= numero;}
        }
        else{
            fila.push(numero);
        }


    }
    long long tamanho;
    tamanho = fila.size();
    cout << tamanho;


    return 0;
}