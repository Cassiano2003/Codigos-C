#include <stdio.h>
#include <stdlib.h>

// Função que verifica se o vetor é estritamente decrescente
void verificaDecrescente(float *vetor, int n) {
    int decrescente = 1; // 1 = verdadeiro, 0 = falso

    for (int i = 1; i < n; i++) {
        if (vetor[i] >= vetor[i - 1]) {
            decrescente = 0;
            break;
        }
    }

    if (decrescente == 1)
        printf("A sequencia e decrescente.\n");
    else
        printf("A sequencia nao e decrescente.\n");
}

int main() {
    FILE *arquivo;
    char nome_arquivo[30];
    int n;

    printf("Digite o nome do arquivo (ex: dados.txt): ");
    scanf("%s", nome_arquivo);

    // Abre o arquivo para leitura
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê a quantidade de números
    fscanf(arquivo, "%d", &n);

    // Aloca o vetor dinamicamente
    float *vetor = (float *) malloc(n * sizeof(float));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        // Fecha o arquivo
        fclose(arquivo);
        return 1;
    }else{
        // Lê os números reais do arquivo
        for (int i = 0; i < n; i++) {
            fscanf(arquivo, "%f", &vetor[i]);
        }

        // Verifica e imprime o resultado
        verificaDecrescente(vetor, n);
        
        // Libera a memória alocada
        free(vetor);
    }
    
    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
