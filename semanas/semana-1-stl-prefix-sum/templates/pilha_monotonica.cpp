#include <iostream>
#include <vector>
// Oficial aula 1, slides 59-67. Entrada n>=0, n valores.
// Saída: índice 1-based do menor ESTRITO mais próximo à esquerda, ou 0.
// O(n) tempo e memória: cada índice é empilhado e retirado no máximo uma vez.
int main(){
    int n;if(!(std::cin>>n)||n<0)return 0;
    std::vector<long long>a(n);for(auto& x:a)std::cin>>x;
    std::vector<int>st;
    for(int i=0;i<n;++i){
        while(!st.empty()&&a[st.back()]>=a[i])st.pop_back();
        if(i)std::cout<<' ';
        std::cout<<(st.empty()?0:st.back()+1);
        st.push_back(i);
    }
    std::cout<<'\n';
}
