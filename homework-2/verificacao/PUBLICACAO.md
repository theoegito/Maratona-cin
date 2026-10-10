# Estado da publicação

Preparação em 10/10/2026. Esta atualização contém guias, consulta Markdown/PDF, templates e os dez originais recuperados. A-D do Homework 2 continuam pendentes e precisam dos anexos originais para completar os 14 solicitados.

O conector GitHub falhou ao criar um blob com HTTP 403, `Resource not accessible by integration`. O campo `push=true` nos metadados não comprovou acesso de escrita da integração. A leitura por Git funcionou e confirmou a base `5b2436c19d1cdadfce45eb78212cd34b779d2d18`.

**Não publicado.** Foram tentados o Git instalado e o Git incluído no runtime. Ambos falharam ao iniciar o shell usado pelo Git Credential Manager, com acesso negado (`NtCreateDirectoryObject`, código 0xC0000022). O envio terminou sem autenticação. A leitura pública funciona, mas isso não comprova escrita.

Depois das tentativas, `git ls-remote origin refs/heads/main` confirmou que main permanece em `5b2436c19d1cdadfce45eb78212cd34b779d2d18`. O commit local de conteúdo é `e0c39701c40e8dec6d12d4c1732c76be45a92c06`. Este registro de falha é um segundo commit local. Nenhum commit novo foi confirmado no GitHub.

Se o envio por Git também falhar, o conteúdo preparado e os commits locais permanecem disponíveis. Para corrigir a integração, revise a instalação do aplicativo GitHub associado ao ChatGPT/Codex, conceda acesso a theoegito/Maratona-cin e permissão de Contents para leitura/escrita; aceite eventuais permissões pendentes e reconecte a conta correta. Alternativamente, use Git autenticado com uma conta que tenha escrita no repositório. Reconectar sem corrigir o acesso ao repositório pode manter o 403.

Referência: [GitHub - troubleshooting da REST API](https://docs.github.com/en/rest/using-the-rest-api/troubleshooting-the-rest-api). O 403 indica permissões insuficientes do token da integração; para a criação de blobs, verifique Contents com escrita. Se a aplicação não oferecer essa permissão, use uma via de Git autenticada com escrita.

## Publicar os commits preparados por um terminal normal

No checkout local preparado, depois de corrigir a autenticação:

```sh
git fetch origin main
git log --oneline origin/main..main
git push origin main
git ls-remote origin refs/heads/main
git rev-parse HEAD
```

O SHA remoto deve ser igual ao HEAD local. Se o remoto avançar, revise e integre as mudanças antes de enviar; não use force push. O pacote ZIP contém os arquivos e o bundle separado conserva os commits. Não envie tokens ou senhas pela conversa.
