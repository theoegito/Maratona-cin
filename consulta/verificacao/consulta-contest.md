# Verificação da organização e consulta de contest
Registro histórico: nomes e caminhos nos resultados JSON/TXT descrevem a estrutura da época. Veja a [organização e validação atuais](organizacao-semanas.md).
[Início](../../README.md) · [Consulta de contest](../README.md) · [Resultados e hashes](consulta-resultados.json)
Conferido em **10/10/2026**, a partir do commit `bf0bd43c0af65de8fd5b852404de36044deb029c`.

## O que foi reorganizado
A entrada agora destaca funções usadas no contest, oferece um índice por palavras-chave, um catálogo A–Z, receitas de algoritmos e os 17 templates. O conteúdo anterior da primeira semana foi mantido em [semana-1/README.md](../../semanas/semana-1-stl-prefix-sum/README.md), ajustando título, navegação, links relativos e a indicação de executar comandos a partir da raiz. Os guias existentes receberam atalhos; as explicações anteriores continuam disponíveis.

## Integridade
- **23 soluções originais**: 9 da primeira semana e 14 do Homework 2, comparadas byte a byte com o commit anterior.
- **17 templates**: conteúdo inalterado. **2 PDFs**: preservados byte a byte.
- Nenhum original foi corrigido, reformatado ou substituído.
- A migração do índice da semana 1 foi comparada por conteúdo após normalizar apenas os ajustes de navegação indicados acima.
Os hashes e tamanhos constam em [consulta-resultados.json](consulta-resultados.json). Nos templates do Homework 2, o checkout Windows tem CRLF e o blob anterior usa LF; a comparação registra essa conversão de quebras de linha separadamente. Os originais têm conversão desativada e foram comparados byte a byte. A compilação já registrada dos originais e templates continua em [semana 1](../../semanas/semana-1-stl-prefix-sum/verificacao/validacao.md) e [Homework 2](../../semanas/semana-2-buscas-backtracking/verificacao/validacao.md); esta mudança acrescenta a verificação dos **novos fragmentos de consulta**.

## Exemplos C++17

| Material novo | Verificação | Resultado |
|---|---|---|
| 13 páginas de funções | 32 blocos extraídos do Markdown e compilados em wrappers independentes | Sem erros |
| Bounds, ordenação, duplicatas, permutações, soma, extremos e busca linear | 46 casos semânticos | Todos passaram |
| Containers, string, entrada, tipos, referências e lambda | 61 assertions executadas + 7 verificações de tipos de retorno | Todas passaram |
| 13 receitas de algoritmos | Compilação C++17 e 731 comparações com referências simples | Sem erros, avisos ou falhas |
Nas 9 páginas de algoritmos da STL, os wrappers geram avisos de **variáveis didáticas não usadas** (os valores são explicados nos comentários). Não houve outra categoria de aviso. Os 14 blocos de containers/entrada compilaram sem avisos. Os resultados registram isso separadamente; não se afirma que toda a consulta compilou sem avisos.
As receitas foram comparadas com soma direta, enumeração de pares/subconjuntos/partições, pertinência direta aos intervalos e referências por conjuntos. Foram incluídos vazios quando permitidos, zeros, duplicatas, negativos permitidos, valores de magnitude 10¹², k>n, distância zero, intervalos fechados de comprimento zero e consultas repetidas.
**Limite da evidência:** os testes cobrem as receitas documentadas e suas hipóteses. Adaptações para outro problema exigem conferir limites, índices, negativos, pontas e monotonicidade; esta verificação não comprova aceitação dos originais em juiz online.

## Navegação
Os links locais foram percorridos em todos os arquivos Markdown, verificando destinos e âncoras. O resumo final está no campo `navegacao` do [registro](consulta-resultados.json). As referências externas documentam as funções e os atalhos do GitHub; a varredura de links locais não testa disponibilidade da rede.
PDFs permanecem sendo as consultas por semana. A consulta unificada e os exemplos detalhados estão em Markdown, acessíveis pelos novos índices.

## Ajuste do foco geral nas funções
O catálogo de funções passou a ser o primeiro acesso da página inicial. A entrada traz uma tabela de chamadas com sintaxe, significado e retorno, distribuída entre entrada, parâmetros, containers, strings, algoritmos STL e operações numéricas. O índice por palavras-chave segue essas categorias; o destaque individual de bounds foi substituído pela navegação geral.
Este ajuste modifica os índices e as navegações, preservando os exemplos C++17 já verificados, os códigos e os PDFs. Os links foram conferidos novamente; o registro está em `ajuste_foco_funcoes` no [JSON](consulta-resultados.json).
