#include <algorithm>
#include <iostream>
#include <vector>
// Entrada: n x, n valores. Saída: índices lower upper e ocorrências.
// Ordenação O(n log n), buscas O(log n), memória O(n).
int main(){
    int n; long long x;
    if(!(std::cin>>n>>x) || n<0) return 0;
    std::vector<long long> a(n);
    for(auto& v:a) std::cin>>v;
    std::sort(a.begin(),a.end());
    auto l=std::lower_bound(a.begin(),a.end(),x);
    auto r=std::upper_bound(a.begin(),a.end(),x);
    std::cout<<(l-a.begin())<<' '<<(r-a.begin())<<' '<<(r-l)<<'\n';
}
