# Conferência desta versão

## Preservação dos anexos

Os nove arquivos em `solucoes/` foram comparados byte a byte com os anexos recuperados da conversa de origem. Todos eram idênticos no momento da preparação. O arquivo [originais-sha256.txt](originais-sha256.txt) registra o SHA-256 de cada um, incluindo espaços e quebras de linha.

O SHA-256 é uma impressão digital do arquivo: uma alteração nos bytes muda esse registro. `.gitattributes` desativa a conversão automática de quebras de linha para os originais.

## Compilação e testes

| Material | Verificação | Resultado |
|---|---|---|
| 9 soluções originais | Compilação individual com GCC, C++17, `-O2 -Wall -Wextra` | Todas compilaram |
| 9 soluções originais | Um teste pequeno por arquivo, com saída esperada pela leitura do código | Todos passaram |
| 6 templates adicionais | C++17, `-Wall -Wextra -pedantic` | Todos compilaram sem avisos |
| Templates | 480 casos ao todo | Todos passaram |
| PDF complementar | 7 páginas renderizadas e inspecionadas visualmente | Sem cortes, sobreposição ou caracteres quebrados |

Nos templates, a validação incluiu consultas de prefixos, janelas `k=1`/`k=n`, duplicatas, valores negativos, somas maiores que `int`, soma alvo zero e casos que exigem trocar uma escolha no greedy. Para subarrays, greedy e ordenação, resultados pequenos foram comparados com enumeração direta dos intervalos, subsequências ou permutações. A contagem total inclui um teste de execução do template base, que ainda não resolve um problema.

Os testes dos originais são verificações simples de execução, não uma validação completa contra os enunciados. Não há comprovação de submissão aceita pelo juiz nesta versão.

## Avisos dos originais, mantidos sem alteração

- **C.cpp:** compara inteiros com sinal (`long long`) com os tamanhos sem sinal retornados por `size(...)`. O compilador avisa sobre essa diferença. A função livre `size(...)` também depende de C++17 ou posterior.
- **K.cpp:** o compilador avisa que `bloco_atual` e `ultimo_numero` podem ser usados sem inicialização. Pela leitura do código, ambos são inicializados no primeiro caractere quando ele é `'0'` ou `'1'`. Essa análise pressupõe uma string binária não vazia e tamanho informado compatível; sem o enunciado, essas hipóteses devem ser conferidas.

## Hipóteses que merecem atenção ao estudar os originais

| Arquivo | Hipótese observada no código |
|---|---|
| A.cpp | Remoções só devem ocorrer quando a `deque` não estiver vazia |
| B.cpp | Cada registro `AC` válido acumula pontos; o código não deduplica submissões repetidas |
| C.cpp | Os números são guardados em `stack<int>`; confira a faixa dos valores |
| E.cpp | `1 <= k <= n`; os valores precisam caber em `int`, pois `seq` é `vector<int>` |
| I.cpp | Consultas com `1 <= p <= r <= n` |
| K.cpp | String binária com tamanho igual ao informado |
| D.cpp, I.cpp, M.cpp | Somas e resultados precisam caber em `long long` |

Essas observações explicam pré-condições e decisões do código, sem afirmar que violam os respectivos enunciados. Qualquer correção futura deve aparecer em uma mudança explícita, preservando este histórico.
