#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct Alunos
{
    char nome[MAX];
    int RGA;
    float nota1,nota2;
    float media;
    int tamanho = 0;
};

Alunos** Cria_Matriz_Alunos(FILE *arq,int tam){
    int n,in;
    Alunos **matriz_alunos = (Alunos **)malloc(tam*sizeof(Alunos *));
    for(int i=0;i<tam;i++){
        fscanf(arq,"%d",&n);
        matriz_alunos[i] = (Alunos *)malloc(n*sizeof(Alunos));
        int media_total = 0;
        for(int j=0;j<n;j++){
            fscanf(arq,"%s %d %f %f",&matriz_alunos[i][j].nome,&matriz_alunos[i][j].RGA,&matriz_alunos[i][j].nota1,&matriz_alunos[i][j].nota2);
            matriz_alunos[i][j].media = (matriz_alunos[i][j].nota1+matriz_alunos[i][j].nota2)/2;
            matriz_alunos[i][j].tamanho = n;
            media_total += matriz_alunos[i][j].media;
        }
    }
    return matriz_alunos;
}

float* Cria_Lista_Media(Alunos **matriz_alunos,int tam){
    float *media_turmas = (float *)malloc(tam*sizeof(float));
    for(int i=0;i<tam;i++){
        int n = matriz_alunos[i][0].tamanho;
        float media_final = 0;
        for(int j=0;j<n;j++){
            media_final += matriz_alunos[i][j].media;
        }
        media_turmas[i] = media_final / n;
    }
    return media_turmas;
}

float Media_Da_Escola(float *media_turmas,int tam){
    float media_escola = 0;
    for(int i=0;i<tam;i++){
        media_escola += media_turmas[i];
    }
    return media_escola/tam;
}

void Coloca_no_Arquivo(FILE *arq,Alunos **matriz_alunos,float *media_turmas,float media_escola,int tam){
    fprintf(arq,"Media da escola é: %.2f\n",media_escola);
    for(int i=0;i<tam;i++){
        int n = matriz_alunos[i][0].tamanho;
        float media_t = media_turmas[i];
        fprintf(arq,"Turma %d\n",i+1);
        for(int j=0;j<n;j++){
            if(matriz_alunos[i][j].media > media_t){
                fprintf(arq,"%s %d %.2f\n",matriz_alunos[i][j].nome,matriz_alunos[i][j].RGA,matriz_alunos[i][j].media);
            }
        }
        fprintf(arq,"\n");
    }
}

void Imprime(Alunos **matriz_alunos,int tam){
    for(int i=0;i<tam;i++){
        int n = matriz_alunos[i][0].tamanho;
        for(int j=0;j<n;j++){
            printf("%s %d %.2f\n",matriz_alunos[i][j].nome,matriz_alunos[i][j].RGA,matriz_alunos[i][j].media);
        }
        printf("\n");
    }
    printf("\n");
}



int main(){
    FILE *inicio,*saida;
    int t;
    float *media_turmas,media_escola;
    Alunos **matriz_alunos;

    inicio = fopen("questao3.txt","r");
    saida = fopen("resposta_questao3.txt","w");
    if(inicio == NULL){
        printf("Nao foi possivel abrir o arquivo!!!");
        return 1;
    }
    fscanf(inicio,"%d",&t);
    matriz_alunos = Cria_Matriz_Alunos(inicio,t);
    media_turmas = Cria_Lista_Media(matriz_alunos,t);
    media_escola = Media_Da_Escola(media_turmas,t);
    Coloca_no_Arquivo(saida,matriz_alunos,media_turmas,media_escola,t);
    //Imprime(matriz_alunos,t);

    fclose(inicio);
    fclose(saida);
}