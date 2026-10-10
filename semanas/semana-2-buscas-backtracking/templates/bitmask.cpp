#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
// Oficial: aula 2, Subconjuntos. Entrada: n<=22, pesos não negativos com soma<=LLONG_MAX/2.
// Saída: menor diferença entre grupos, incluindo grupo vazio.
// O(n*2^n), memória O(n). Limite pequeno por viabilidade, não só por bits.
int main(){
    int n;if(!(std::cin>>n)||n<0||n>22)return 0;
    std::vector<long long>a(n);long long total=0;
    for(auto& x:a){std::cin>>x;total+=x;}
    long long best=total;
    for(std::uint64_t mask=0;mask<(1ULL<<n);++mask){
        long long sum=0;
        for(int j=0;j<n;++j)if(mask&(1ULL<<j))sum+=a[j];
        long long diff=std::llabs(total-2*sum);
        if(diff<best)best=diff;
    }
    std::cout<<best<<'\n';
}
