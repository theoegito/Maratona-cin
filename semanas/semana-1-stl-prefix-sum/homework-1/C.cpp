#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    stack <int> pilha_a, pilha_b, pilha_c;
    long long numero_atual = 1;

    vector <string> operacoes;
    bool morreu = false;

    for (long long i = 0; i < n; i++){
        long long numero;
        cin >> numero;
        pilha_a.push(numero);

    }


    while(size(pilha_c) != n){
        if (pilha_a.empty() == false && pilha_a.top() == numero_atual){
            pilha_c.push(pilha_a.top());
            pilha_a.pop();
            numero_atual += 1;
            operacoes.push_back("A C");
        }
        else if (pilha_b.empty() == false && pilha_b.top() == numero_atual){
            pilha_c.push(pilha_b.top());
            pilha_b.pop();
            numero_atual += 1;
            operacoes.push_back("B C");

        }
        else if (pilha_a.empty() == false){
            pilha_b.push(pilha_a.top());
            pilha_a.pop();
            operacoes.push_back("A B");

        }
        else{
            morreu = true;
            cout << -1;
            break;
        }
        

    }

    if (morreu == false){
        cout << size(operacoes) << '\n';
        for (long long j = 0; j < size(operacoes); j++){
            cout << operacoes[j] << '\n';
        }



    }

    return 0;
}