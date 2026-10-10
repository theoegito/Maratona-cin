# Estado da publicação

**Publicado em main em 10/10/2026.** O envio por Git autenticado com a conta theoegito foi concluído. Após o envio, `git ls-remote origin refs/heads/main` e o HEAD local retornaram o mesmo SHA: `60461fab2e4feb4f070e9219e42671bce039b942`. A leitura desse commit pela API do GitHub também confirmou sua existência.

O commit de conteúdo é [e0c3970](https://github.com/theoegito/Maratona-cin/commit/e0c39701c40e8dec6d12d4c1732c76be45a92c06). O registro anterior de falhas é [60461fa](https://github.com/theoegito/Maratona-cin/commit/60461fab2e4feb4f070e9219e42671bce039b942). Este documento registra a confirmação posterior do envio.

A-D do Homework 2 continuam pendentes e precisam dos anexos originais para completar os 14 solicitados. Essa pendência de conteúdo é independente do acesso ao GitHub.

## Resolução

O isolamento impedia a execução do Git Credential Manager. O Git foi executado fora desse isolamento e a conta foi autenticada pelo fluxo oficial de código no navegador. O usuário concluiu a confirmação de identidade e a autorização do Git Credential Manager no próprio GitHub. O envio seguinte foi bem-sucedido.

A publicação foi feita por Git; não foi confirmada uma correção dos escopos de escrita do conector. O campo push=true descreve a permissão do usuário no repositório e, sozinho, não comprova autorização da integração.

## Histórico das tentativas iniciais

O conector GitHub falhou ao criar um blob com HTTP 403, `Resource not accessible by integration`. O campo `push=true` nos metadados não comprovou acesso de escrita da integração. A leitura por Git funcionou e confirmou a base `5b2436c19d1cdadfce45eb78212cd34b779d2d18`.

Inicialmente, foram tentados o Git instalado e o Git incluído no runtime. Ambos falharam ao iniciar o shell usado pelo Git Credential Manager, com acesso negado (`NtCreateDirectoryObject`, código 0xC0000022). Essas primeiras tentativas terminaram sem autenticação.

Depois dessas tentativas iniciais, main ainda estava em `5b2436c19d1cdadfce45eb78212cd34b779d2d18`. O envio posterior, já autenticado, publicou os commits e foi conferido conforme registrado no início deste documento.

Para corrigir separadamente o conector, revise a instalação do aplicativo GitHub associado ao ChatGPT/Codex, conceda acesso a theoegito/Maratona-cin e permissão de Contents para leitura/escrita; aceite eventuais permissões pendentes e reconecte a conta correta. O Git autenticado já funcionou para esta publicação.

Referência: [GitHub - troubleshooting da REST API](https://docs.github.com/en/rest/using-the-rest-api/troubleshooting-the-rest-api). O 403 indica permissões insuficientes do token da integração; para a criação de blobs, verifique Contents com escrita. Se a aplicação não oferecer essa permissão, use uma via de Git autenticada com escrita.

## Conferir envios futuros

No checkout local autenticado:

```sh
git fetch origin main
git log --oneline origin/main..main
git push origin main
git ls-remote origin refs/heads/main
git rev-parse HEAD
```

O SHA remoto deve ser igual ao HEAD local. Se o remoto avançar, revise e integre as mudanças antes de enviar; não use force push. O pacote ZIP contém os arquivos e o bundle separado conserva os commits. Não envie tokens ou senhas pela conversa.
