#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
// Entrada: n q, n intervalos FECHADOS [l,r], q coordenadas de consulta.
// Saída: cobertura em cada consulta, na ordem original.
// Tipos: entrada=0, consulta=1, saída=2. Empates incluem ambas as pontas.
// O((n+q)log(n+q)) tempo e O(n+q) memória; suporta l=r.
int main(){
    int n,q;if(!(std::cin>>n>>q)||n<0||q<0)return 0;
    std::vector<std::tuple<long long,int,int>> events;
    for(int i=0;i<n;++i){
        long long l,r;std::cin>>l>>r;if(l>r)return 0;
        events.emplace_back(l,0,-1);events.emplace_back(r,2,-1);
    }
    for(int i=0;i<q;++i){long long x;std::cin>>x;events.emplace_back(x,1,i);}
    std::sort(events.begin(),events.end());
    std::vector<int> answer(q);int active=0;
    for(const auto& e:events){
        int type=std::get<1>(e);
        if(type==0)++active;
        else if(type==2)--active;
        else answer[std::get<2>(e)]=active;
    }
    for(int x:answer)std::cout<<x<<'\n';
}
