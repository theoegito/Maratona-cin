// Conta subarrays (trechos contiguos nao vazios) cuja soma e igual ao alvo.
// Entrada: n alvo; depois n inteiros. Aceita valores negativos e zero.
// Saida: o numero de subarrays que somam alvo.
// Pre-condicoes: n >= 0; somas, soma-alvo e resposta cabem em long long.
// Custo: O(n log(n + 1)) com map; memoria O(n).

#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long alvo;
    if (!(cin >> n >> alvo)) return 0;

    map<long long, long long> frequencia;
    frequencia[0] = 1; // Prefixo vazio: permite contar trechos que comecam no indice 0.
    long long soma = 0, resposta = 0;

    for (int i = 0; i < n; ++i) {
        long long valor;
        cin >> valor;
        soma += valor;

        // somaAtual - somaAnterior = alvo, portanto somaAnterior = somaAtual - alvo.
        // [] retorna 0 (e cria a chave) quando esse prefixo ainda nao apareceu.
        resposta += frequencia[soma - alvo];
        // Consulte ANTES de registrar o prefixo atual para nao contar trecho vazio.
        ++frequencia[soma];
    }

    cout << resposta << '\n';
}
