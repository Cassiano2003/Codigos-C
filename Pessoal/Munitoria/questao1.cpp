#include <stdio.h>
#include <stdlib.h>


void Imprimir(int *v,int tam){
    for(int i=0;i < tam;i++){
        printf("%d,",v[i]);
    }
    printf("%d\n",v[tam]);
}

void Imprimir_Invetido(int *v,int tam){
    for(int i=tam-1;i > 0;i--){
        printf("%d,",v[i]);
    }
    printf("%d\n",v[0]);
}

int* Tranfere_vetor(int *v,int *t,int tam){
    for(int i=0;i < tam;i++){
        t[i] = v[i];
    }
    free(v);
    return t;
}

int main(){
    FILE *vetores;
    //char *nome_arquivo = "questao1.txt";
    int *vetor,n,total = 0,in;

    //Fazer a leitura do arquivo
    vetores = fopen("questao1.txt","r");
    if (vetores == NULL){
        printf("Nao foi posivel abrir o arquivo!!!\n");
        return 1;
    }
    in = fscanf(vetores,"%d",&n);
    vetor = (int *)malloc(n*sizeof(int));
    for(int i=0;i < n;i++){
        in = fscanf(vetores,"%d",&vetor[i]);
    }
    //printf("O valor de n: %d\n",n);
    total += n;
    while (in != EOF){
        in = fscanf(vetores,"%d",&n);
        if(in == EOF) break;
        //printf("O valor de n: %d\n",n);
        //printf("Total = %d\n",total);
        //int *temp = (int *)realloc(vetor,total+n);
        int soma  = total+n;
        int *temp = (int *)malloc(soma*sizeof(int));
        if(temp == NULL){
            printf("Nao foi posivel ser realocado o vetor!!!");
            return 1;
        }
        vetor = Tranfere_vetor(vetor,temp,total);
        //printf("Total2 = %d\n",total+n);
        for(int i=total;i < n+total;i++){
            //printf("%d ",i);
            in = fscanf(vetores,"%d",&vetor[i]);
        }
        //printf("\n");
        total += n;
        //Imprimir(vetor,total);
    }
    fclose(vetores);
    Imprimir_Invetido(vetor,total);
    
    return 0;
}