#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long quant_a, quant_b, pares, operacoes;
    quant_a = 0;
    quant_b= 0;
    pares = 0;

    deque<char> fila;

    cin >> operacoes;

    for (long long i = 0; i < operacoes; i++){
        int operacao;
        cin >> operacao;
        if (operacao == 1){
            char torcedor;
            cin >> torcedor;
            if (torcedor == 'A'){
                fila.push_back('A');
                quant_a += 1;
            }
            if (torcedor == 'B') {
                fila.push_back('B');
                quant_b += 1;
                pares += quant_a;
            }

        }
        if (operacao == 2){
            char torcedor;
            cin >> torcedor;
            if (torcedor == 'A'){
                fila.push_front('A');
                quant_a += 1;
                pares += quant_b;
            }
            if (torcedor == 'B') {
                quant_b += 1;
                fila.push_front('B');
            }
            
        }
        if (operacao == 3){
            char ultimo;
            ultimo = fila.back();
            fila.pop_back();
            
            if (ultimo == 'A'){
                quant_a -= 1;
                
            }
            if (ultimo == 'B') {
                quant_b -= 1;
                pares -= quant_a;
            }
            
        }
        if (operacao == 4){
            char primeiro;
            primeiro = fila.front();
            fila.pop_front();
            
            if (primeiro == 'A'){
                quant_a -= 1;
                pares -= quant_b;
                
            }
            if (primeiro == 'B') {
                quant_b -= 1;
            }
            
            
        }
        cout << pares << '\n';




    }

    

    return 0;
}