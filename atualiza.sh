# Auto-sync do trabalho de ProgMobile com merge
#!/bin/bash

#cd /caminho/para/seu/repositorio || exit

# Pega a data/hora para o commit
data_hora=$(date '+%d-%m-%Y_%H-%M-%S')

echo "✅ Salvando alterações locais..."
git add .
git commit -m "${data_hora}-Cassiano" || echo "⚠️ Nenhuma alteração para commit."

echo "🌐 Buscando alterações do repositório remoto..."
git fetch origin

echo "🔀 Tentando mesclar com o remoto..."
git merge origin/main -m "Merge remoto automático (${data_hora})" || {
    echo "⚠️ Conflitos detectados! Resolva manualmente com 'git status'";
    exit 1;
}

echo "🚀 Enviando para o repositório remoto..."
git push origin main #--force

echo "✅ Tudo sincronizado com sucesso!"
