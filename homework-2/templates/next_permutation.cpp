#include <algorithm>
#include <iostream>
#include <string>
// Entrada: palavra não vazia. Saída: permutações distintas em ordem, uma por linha.
// O(nP) tempo, O(n) estado. P pode ser n!: use palavras pequenas.
int main(){
    std::string s; if(!(std::cin>>s)) return 0;
    std::sort(s.begin(),s.end());
    do {std::cout<<s<<'\n';} while(std::next_permutation(s.begin(),s.end()));
}
