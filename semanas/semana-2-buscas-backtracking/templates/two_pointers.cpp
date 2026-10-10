#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
// Entrada: n alvo, n valores; n>=0. Somas devem caber em long long.
// Saída: dois índices originais distintos 1-based ou IMPOSSIBLE.
// Ordenação O(n log n), varredura O(n), memória O(n). Permite negativos.
int main(){
    int n; long long target; if(!(std::cin>>n>>target) || n<0) return 0;
    std::vector<std::pair<long long,int>> a;
    for(int i=0;i<n;++i){long long x;std::cin>>x;a.push_back({x,i+1});}
    std::sort(a.begin(),a.end());
    int l=0,r=n-1;
    while(l<r){
        long long sum=a[l].first+a[r].first;
        if(sum==target){std::cout<<a[l].second<<' '<<a[r].second<<'\n';return 0;}
        if(sum<target) ++l; else --r;
    }
    std::cout<<"IMPOSSIBLE\n";
}
