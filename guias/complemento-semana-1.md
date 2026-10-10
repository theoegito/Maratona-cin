# Complemento da primeira semana

[Início](../README.md) · [Semana 1](../semana-1/README.md) · [Consulta de contest](../consulta/README.md)

Complemento independente aos guias anteriores. O [índice completo da primeira semana](../semana-1/README.md) reúne o material original; a [entrada de contest](../consulta/README.md) liga as consultas das duas semanas.

## Pontos oficiais a reforçar

- Referência: `for(auto& x:v)` permite alterar; `for(const auto& x:v)` evita cópia e alteração; `for(auto x:v)` copia. Passar vetor grande por valor custa O(n) por chamada. Atenção a shadowing: uma variável interna pode esconder a externa.
- Pair/tuple: agregam dados e comparam lexicograficamente. `auto [valor,indice]=p` usa structured bindings C++17. Em tuple, `get<0>(t)` acessa o campo.
- `getline(cin >> ws,s)` lê linha após consumo de espaços, mas descarta linhas vazias e espaços iniciais. Se isso importa, use ignore até a quebra de linha após a leitura anterior.
- `accumulate(v.begin(),v.end(),0LL)` acumula em long long; destino long long não corrige soma interna feita com int. O mesmo vale para `1LL*a*b`. Divisão inteira `3/4` dá zero; `3.0/4` dá 0.75.
- `unique` compacta duplicatas consecutivas e devolve fim lógico; finalize com erase. Não precisa sort se a intenção é só compactar blocos consecutivos. Para eliminar duplicatas em toda a sequência, ordene primeiro.
- `map[key]` insere valor padrão se ausente. Para consulta sem inserção, use find. `multiset.erase(valor)` apaga todas as cópias; para uma só, ache o iterador e confira end antes de erase(it).
- `vector.reserve(n)` só reserva capacidade; `resize(n)` cria elementos. push_back pode invalidar referências/iteradores ao realocar; erase desloca elementos no vector.
- `end()` não é elemento. Não use top/front/back/pop em estrutura vazia. size() retorna tipo sem sinal: `v.size()-1` em vetor vazio pode estourar antes da conversão.
- Prefixos: pref[0]=0, pref[i+1]=pref[i]+a[i], soma [l,r]=pref[r+1]-pref[l]. Para contar soma K, inicialize freq[0]=1, consulte freq[pref-K] antes de incrementar freq[pref].
- Memória: n*sizeof(T) é estimativa do conteúdo; map/set têm nós e overhead. Tamanhos de tipos nos slides são típicos, consulte sizeof no ambiente.

## Esclarecimentos de precisão

String é uma classe própria, não literalmente vector<char>. '\n' não força flush e não garante saída somente no fim. Sort C++17 tem O(n log n) no pior caso. Bounds genéricos em iteradores não aleatórios podem fazer O(n) avanços; use os métodos do set/map. Erase tem custo dependente do container e sobrecarga. Sinais de falha não identificam uma causa única: investigue o erro e a entrada. 10^8 operações por segundo é heurística, não promessa de tempo.

## Extras úteis na prova

Compressão de coordenadas (oficial da aula 2, retomada para ligar os assuntos): ordenar cópia, unique+erase, localizar cada valor por lower_bound; preserva ordem, não distância. Vetor de diferenças acelera atualizações em intervalos quando as coordenadas são pequenas. Hash map tem custo esperado, não garantia de O(1); map é previsível em O(log n).

Revise os gatilhos e pegadinhas na [consulta do Homework 2](../homework-2/guias/consulta-rapida.md).

## Pilha monotônica - lacuna oficial da aula 1

Os slides 59-67 mostram como achar o elemento estritamente menor mais próximo à esquerda. Mantenha na pilha índices com valores estritamente crescentes. Para cada i, enquanto a[stack.top()]>=a[i], retire o topo. O topo restante é o índice da resposta; se vazia, não existe. Depois empilhe i.

Por que retirar é seguro? Um elemento anterior maior ou igual a a[i] nunca será uma resposta melhor para um elemento futuro: i está mais perto e tem valor menor ou igual. Cada índice entra uma vez e sai no máximo uma vez, então o total é O(n), embora haja um while dentro do for. Memória O(n).

**Gatilho:** próximo/último maior ou menor, vizinho por valor preservando posição, problemas de histogramas (aplicação extra). **Pegadinha:** para menor estrito, retire >=; para menor ou igual, retire apenas >. Para procurar à direita, percorra em sentido contrário. Guarde índices se precisa da posição, não só valores.

O [template completo](../homework-2/templates/pilha_monotonica.cpp) imprime índices 1-based e 0 quando não existe vizinho menor. Para [3,5,2,7,8], a saída é [0,1,0,3,4]. A aula também apresenta existência de subarray com soma K usando prefixos e set; o mapa de frequências da semana 1 amplia essa ideia para contar todas as ocorrências.

## Compressão de coordenadas - conexão oficial da aula 2

Ordene os valores, remova duplicatas, substitua cada valor pelo índice do lower_bound. Use O(n log n) para montar. Consultas de coordenadas não presentes precisam de lower/upper adequados, não de uma igualdade inventada. Índices comprimidos preservam ordem e igualdade, mas não diferença, comprimento ou distância original. Um vetor de cobertura numa coordenada comprimida responde pontos, não mede automaticamente comprimento de união.
