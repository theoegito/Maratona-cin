
#include <bits/stdc++.h>
using namespace std;

int sudoku[9][9];

bool pode_botar(int linha, int coluna, int numero) {

    for (int i = 0; i < 9; i++) {
        if (sudoku[linha][i] == numero ||
            sudoku[i][coluna] == numero) {
            return false;
        }
    }

    int inicio_linha = (linha / 3) * 3;
    int inicio_coluna = (coluna / 3) * 3;

    for (int i = inicio_linha; i < inicio_linha + 3; i++) {
        for (int j = inicio_coluna; j < inicio_coluna + 3; j++) {
            if (sudoku[i][j] == numero) {
                return false;
            }
        }
    }

    return true;
}


bool resolver() {

    for (int l = 0; l < 9; l++) {
        for (int r = 0; r < 9; r++) {
            if (sudoku[l][r] == 0) {
                for (int numero = 1; numero <= 9; numero++) {
                    if (pode_botar(l, r, numero)) {
                        sudoku[l][r] = numero;

                        if (resolver()) {
                            return true;
                        }
                        sudoku[l][r] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int numero_casos;
    cin >> numero_casos;



    for (int i = 0; i < numero_casos; i++){
        for (int j = 0; j < 9; j++){
            for (int k = 0; k < 9; k++){
                int numero;
                cin >> numero;
                sudoku[j][k] = numero; 

            }
        }

            if (resolver()) {
        for (int v = 0; v < 9; v++) {
            for (int s = 0; s < 9; s++) {
                if (s > 0) cout << ' ';
                cout << sudoku[v][s];
            }
            cout << '\n';
        }
    }
    else {
        cout << "No solution\n";
    }
        }

    return 0;
}