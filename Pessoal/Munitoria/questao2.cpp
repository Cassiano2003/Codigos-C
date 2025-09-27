#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct Alunos
{
    char nome[MAX];
    int RGA;
    float nota1,nota2;
    float media;
};


int main(){
    FILE *inicio,*saida;
    int n;
    Alunos *lista_alunos;
    int media_total = 0;

    inicio = fopen("questao2.txt","r");
    saida = fopen("resposta_questao2.txt","w");
    if(inicio == NULL){
        printf("Nao foi possivel abrir o arquivo!!!");
        return 1;
    }
    fscanf(inicio,"%d",&n);
    lista_alunos = (Alunos *)malloc(n*sizeof(Alunos));
    for(int i=0;i<n;i++){
        fscanf(inicio,"%s %d %f %f",&lista_alunos[i].nome,&lista_alunos[i].RGA,&lista_alunos[i].nota1,&lista_alunos[i].nota2);
        lista_alunos[i].media = (lista_alunos[i].nota1+lista_alunos[i].nota2)/2;
        media_total += lista_alunos[i].media;
    }
    media_total /= n;
    fprintf(saida,"Media total da turma: %d\n",media_total);
    fprintf(saida,"Alunos com media maior que a da sala\n");
    for(int i=0;i<n;i++){
        if(lista_alunos[i].media > media_total){
            fprintf(saida,"%s %d %.2f\n",lista_alunos[i].nome,lista_alunos[i].RGA,lista_alunos[i].media);
        }
    }
    fclose(inicio);
    fclose(saida);
}
