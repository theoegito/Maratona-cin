#include <iostream>
#include <string>
#include <vector>
// Entrada: 1<=n<=12, n linhas de n caracteres '.' ou '*'.
// Saída: número de arranjos de n rainhas sem ataques/obstáculos.
// Pior caso O(n*n!) como limite conservador, memória O(n²) tabuleiro+O(n) estado.
long long solve(int row,const std::vector<std::string>& board,
                std::vector<bool>& col,std::vector<bool>& d1,std::vector<bool>& d2){
    int n=static_cast<int>(board.size());if(row==n)return 1;
    long long count=0;
    for(int c=0;c<n;++c){
        int a=row+c,b=row-c+n-1;
        if(board[row][c]!='.'||col[c]||d1[a]||d2[b])continue;
        col[c]=d1[a]=d2[b]=true;
        count+=solve(row+1,board,col,d1,d2);
        col[c]=d1[a]=d2[b]=false; // Restauração para o próximo ramo.
    }
    return count;
}
int main(){
    int n;if(!(std::cin>>n)||n<1||n>12)return 0;
    std::vector<std::string> board(n);
    for(auto& row:board){std::cin>>row;if(static_cast<int>(row.size())!=n)return 0;}
    std::vector<bool>col(n),d1(2*n-1),d2(2*n-1);
    std::cout<<solve(0,board,col,d1,d2)<<'\n';
}
