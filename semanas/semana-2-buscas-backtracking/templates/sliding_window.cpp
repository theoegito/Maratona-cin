#include <algorithm>
#include <iostream>
#include <vector>
// Entrada: n S, valores NÃO NEGATIVOS; S>=0; soma total cabe em long long.
// Saída: maior tamanho de segmento com soma<=S. O(n), memória O(n).
int main(){
    int n;long long limit;if(!(std::cin>>n>>limit)||n<0||limit<0)return 0;
    std::vector<long long>a(n);for(auto& x:a){std::cin>>x;if(x<0)return 0;}
    int l=0,answer=0;long long sum=0;
    for(int r=0;r<n;++r){
        sum+=a[r];
        while(l<=r && sum>limit)sum-=a[l++];
        answer=std::max(answer,r-l+1);
    }
    std::cout<<answer<<'\n';
}
