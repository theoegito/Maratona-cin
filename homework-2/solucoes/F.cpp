
#include <bits/stdc++.h>
using namespace std;

int resposta = 0;

vector<string> tabuleiro;

vector<bool> colunas(8, false);
vector<bool> diagonal_1(15, false);
vector<bool> diagonal_2(15, false);

void resolver(int linha){

    if (linha == 8){
        resposta +=1;
        return;

    }

    for (int i = 0; i < 8; i ++){
        if (tabuleiro[linha][i] == '.' && colunas [i] == false && diagonal_1[linha + i] == false && diagonal_2[linha - i + 7] == false){

            colunas[i] = true;
            diagonal_1[linha + i] = true;
            diagonal_2[linha - i + 7] = true;

            resolver (linha + 1);
            
            colunas[i] = false;
            diagonal_1[linha + i] = false;
            diagonal_2[linha - i + 7] = false;

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 8; i ++){
    string linha;
    cin >> linha;
    
    tabuleiro.push_back(linha);
    }

    resolver(0);
    cout << resposta;


    return 0;
}