#include <stdio.h>
#define TAM 20
#define MAX 100

struct tipoA{
	char nome[TAM];
	float p1, p2;
	float media;
};

float mediaGeral(int n, tipoA v[]) {
    float soma_medias = 0.0;
    for(int i = 0; i < n; i++) {
        soma_medias += v[i].media;
    }
    return soma_medias / n;
}

int buscaMaior (int n,  tipoA   v[MAX]){
	int indice_maior;
	float maior = v[0].media;
	for(int i=1;i<n;i++){
		if(v[i].media > maior){
			maior = v[i].media;
			indice_maior = i;
		}
	}
	return indice_maior;
}

int main()
{
	tipoA vetor[MAX];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %f %f",vetor[i].nome,&vetor[i].p1,&vetor[i].p2);
		vetor[i].media = (vetor[i].p1 * 0.2) + (vetor[i].p2 * 0.3);
	}
	printf("Media total da turma: %.1f\n",mediaGeral(n,vetor));
	printf("O aluno com a maior media: %s",vetor[buscaMaior(n,vetor)].nome);
	return 0;
}


/*
3
cassiano
7.6
6

kim
10
6.7

stf
8
8


*/