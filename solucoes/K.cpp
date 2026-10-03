#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long testes;
    cin >> testes;
    for (long long i = 0; i < testes; i++){
        long long maior_bloco1 = 0;
        long long maior_bloco0 = 0;
        long long bloco_atual;
        long long qtd_1 = 0;
        long long qtd_0 = 0;
        char ultimo_numero;
        long long tamanho_bloco;
        string bloco;
        cin >> tamanho_bloco;
        cin >> bloco;
        for (long long j = 0; j < tamanho_bloco; j++){
            if (bloco[j] == '0'){
                qtd_0 += 1;
            }
            else{
                qtd_1 += 1;
            }

            if (j == 0 && bloco[j] == '0'){
                ultimo_numero = bloco[j];
                maior_bloco0 = 1;
                bloco_atual = 1;

            }
            else if(j == 0 && bloco[j] == '1') {
                ultimo_numero = bloco[j];
                maior_bloco1 = 1;
                bloco_atual = 1;

            }
            else{
                if (ultimo_numero == bloco[j]){
                    bloco_atual += 1;
                    if ((bloco_atual > maior_bloco1) && (ultimo_numero == '1')){
                        long long aux;
                        aux = bloco_atual;
                        maior_bloco1 = aux;
                        
                    }
                    if ((bloco_atual > maior_bloco0) && (ultimo_numero == '0')){
                        long long aux;
                        aux = bloco_atual;
                        maior_bloco0 = aux;
                        
                    }
                
                }else{
                    if ((bloco_atual > maior_bloco1) && (ultimo_numero == '1')){
                        long long aux;
                        aux = bloco_atual;
                        maior_bloco1 = aux;
                    
                    }
                    if ((bloco_atual > maior_bloco0) && (ultimo_numero == '0')){
                        long long aux;
                        aux = bloco_atual;
                        maior_bloco0 = aux;
                        
                    }
                
                    bloco_atual = 1;
                    ultimo_numero = bloco[j];
                }
            
            

            

            }
        }
        
        long long tudo1, tudo0, resultado;
        tudo1 = (qtd_1 - maior_bloco1)*2 + qtd_0;
        tudo0 = (qtd_0 - maior_bloco0)*2 + qtd_1;
        resultado = min (tudo0,tudo1);

        cout << resultado << '\n';
    
        

        }
}