#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
// Entrada: n k, vetor NÃO NEGATIVO; n>=1 e k>=1.
// Saída: menor capacidade para dividir em ATÉ k grupos contíguos.
// Soma total deve caber em long long. O(n log(soma+1)), memória O(n).
int main(){
    int n,k;if(!(std::cin>>n>>k)||n<1||k<1)return 0;
    std::vector<long long>a(n);long long lo=0,hi=0;
    for(auto& x:a){
        std::cin>>x;
        if(x<0||x>std::numeric_limits<long long>::max()-hi)return 0;
        lo=std::max(lo,x);hi+=x;
    }
    auto ok=[&](long long cap){
        int groups=1;long long sum=0;
        for(long long x:a){
            // sum+x>cap sem somar além do limite.
            if(x>cap-sum){++groups;sum=x;}else sum+=x;
            if(groups>k)return false;
        }
        return true;
    };
    while(lo<hi){long long mid=lo+(hi-lo)/2;if(ok(mid))hi=mid;else lo=mid+1;}
    std::cout<<lo<<'\n';
}
