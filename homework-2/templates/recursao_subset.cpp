#include <iostream>
#include <vector>
// Entrada: n<=25 alvo, n inteiros; somas devem caber em long long.
// Saída: quantidade de subconjuntos de índices cuja soma é alvo.
// Inclui vazio e aceita negativos. O(2^n) tempo, O(n) pilha+dados.
// Não podar sum>target: valores restantes podem ser negativos!
long long count(int i,long long sum,long long target,const std::vector<long long>& a){
    if(i==static_cast<int>(a.size()))return sum==target;
    return count(i+1,sum,target,a)+count(i+1,sum+a[i],target,a);
}
int main(){
    int n;long long target;if(!(std::cin>>n>>target)||n<0||n>25)return 0;
    std::vector<long long>a(n);for(auto& x:a)std::cin>>x;
    std::cout<<count(0,0,target,a)<<'\n';
}
