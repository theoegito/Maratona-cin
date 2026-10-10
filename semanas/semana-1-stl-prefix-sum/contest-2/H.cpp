#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int qtd_numero;
    cin >> qtd_numero;
    
    long long numero_antigo, bloco_atual, bloco_antigo, maior_seq, seq_atual;
    numero_antigo = 0;
    bloco_atual = 0; 
    bloco_antigo = 0;
    seq_atual = 0; 
    maior_seq = 0;


    for (int i = 0; i < qtd_numero; i++){
        int numero_atual;
        cin >> numero_atual;

        if (numero_atual == numero_antigo){
            bloco_atual += 1;
        }
        else{
            seq_atual = (min(bloco_antigo, bloco_atual) * 2);
            maior_seq = (max(maior_seq, seq_atual));
            numero_antigo = numero_atual;
            bloco_antigo = bloco_atual;
            bloco_atual = 1;
            
        }

    }

    maior_seq = max (maior_seq, ((min(bloco_antigo, bloco_atual) * 2)));
    cout << maior_seq;


    return 0;
}