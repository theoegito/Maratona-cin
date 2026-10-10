#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
// Entrada: n, valores. Saída: valor índice original 1-based, por valor crescente.
// O(n log n), O(n) memória. Empates por índice; comparador estrito.
int main(){
    int n; if(!(std::cin>>n) || n<0) return 0;
    std::vector<std::pair<long long,int>> a;
    for(int i=0;i<n;++i){long long x; std::cin>>x; a.push_back({x,i+1});}
    std::sort(a.begin(),a.end(),[](const auto& x,const auto& y){
        if(x.first!=y.first) return x.first<y.first;
        return x.second<y.second;
    });
    for(const auto& [value,index]:a) std::cout<<value<<' '<<index<<'\n';
}
