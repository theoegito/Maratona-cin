#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,p,s;

    cin >> c >> p >> s;

    map <string, long long> tabela_nomes;
    map <string, long long> tabela_pontos;
    vector <string> candidatos;


    for (int i = 0; i < c; i++){
        string nome;
        cin >> nome;
        candidatos.push_back(nome);
        tabela_nomes [nome] = 0;
    }

    for (int j = 0; j < p; j++){
        string problema;
        long long pontos;
        cin >> problema >> pontos;
        tabela_pontos [problema] = pontos;
    } 

    for (int k = 0; k < s; k++){
        string pessoa, problema, resultado;
        cin >> pessoa >> problema >> resultado;
        if ((resultado == "AC") && (tabela_nomes.find(pessoa) != tabela_nomes.end()) && tabela_pontos.find(problema) != tabela_pontos.end() ){
            long long pontos = tabela_pontos[problema];
            tabela_nomes[pessoa] += pontos;
        }

    }

    for (int l = 0; l < c; l++){
        string nome = candidatos[l];
        cout << nome << ' ' << tabela_nomes[nome] << '\n';

    }

    return 0;
}