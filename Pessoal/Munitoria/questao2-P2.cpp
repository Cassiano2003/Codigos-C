#include <stdio.h>
#include <string.h>

#define MAX 30

// Definição da estrutura para armazenar os dados dos alunos
 struct Aluno{
    char nome[50];
    int idade;
    float nota;
};

// Função para exibir o vetor de alunos
void exibirAlunos(Aluno v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %d %.2f\n", v[i].nome, v[i].idade, v[i].nota);
    }
    printf("\n");
}

// Função de ordenação usando o algoritmo Insertion Sort 
// (ordem decrescente por idade)
void insertionSort(Aluno v[], int n) {
    int i, j;
    Aluno chave;
    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;

        // Move os elementos que têm idade menor que a do aluno "chave" para frente
        while (j >= 0 && v[j].idade < chave.idade) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

//BubbleSort
void BubbleSort(Aluno *vetor, int n){
	int i, j;
    Aluno aux;
	for(i=n-1; i > 0; i--){
		for(j=0; j < i; j++){
			if(vetor[j].idade < vetor[j+1].idade){
				aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}



int main() {
    Aluno alunos[MAX];
    int n, i;

    scanf("%d", &n);

    // Leitura dos dados dos alunos
    for (i = 0; i < n; i++) {
        scanf(" %s", alunos[i].nome);
        scanf("%d", &alunos[i].idade);
        scanf("%f", &alunos[i].nota);
    }

    //exibirAlunos(alunos, n);

    
    // Ordena o vetor em ordem decrescente pela idade
    BubbleSort(alunos, n);

    exibirAlunos(alunos, n);
    
    return 0;
}