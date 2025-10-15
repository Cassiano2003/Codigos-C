#include <stdio.h>
#include <stdlib.h>

//Imprime o vetor normalmento 
void Imprimir(int *v,int tam){
    for(int i=0;i < tam;i++){
        printf("%d,",v[i]);
    }
    printf("%d\n",v[tam]);
}

//Usada para imrimir o vetor inveritdo 
void Imprimir_Invetido(int *v,int tam){
    for(int i=tam;i > 0;i--){
        printf("%d,",v[i]);
    }
    printf("%d\n",v[0]);
}

//Criando um novo vetor e colocando os valores la dentro
int* Tranfere_vetor(int *v,int tam,int soma){
    int *temp = (int *)malloc(soma*sizeof(int));
    for(int i=0;i < tam;i++){
        temp[i] = v[i];
    }
    free(v);
    return temp;
}

//Usando a realocaçao de sempre aumentando o tamanho tamanho do vetor
int* Realocacao(int *v,int tam,int soma){
    int *t = (int *)realloc(v,soma*sizeof(int));
    return t;
}

//Faz a verificaçao para ve se ele gerou mesmo o vetor coretamente
void Verifica_Resposta(int *v,int *resposta,int tam){
    for(int i=0;i<tam;i++){
        if(v[i] != resposta[i]){
            printf("Os vetores sao diferentes!!!\n");
            return;
        }
    }
    printf("Os vetores sao iguais!!!!\n");
}


int main(){
    FILE *vetores;
    //char *nome_arquivo = "questao1.txt";
    int *vetor,n,total = 0,in;
    int Resposta[] = {
    85, 14, 63, 28, 97, 10, 52, 73, 31, 44, 19, 90,
    66, 13, 54, 27, 32, 89, 42,
    11, 95, 22, 38, 77, 40, 58, 74, 9, 83, 61, 5, 48, 20, 99,
    71, 3, 84, 29, 55, 60,
    92, 14, 39, 65, 2, 88, 53, 7, 96, 30,
    18, 77, 23, 44, 11, 95, 36, 62,
    41, 59, 86, 17, 68, 4, 35, 72, 19, 50, 8, 91, 25,
    99, 33, 71, 46, 12, 64, 58, 21, 87,
    26, 79, 8, 95, 62, 34, 47, 70, 18, 53, 5
    };


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
    //printf("Total = %d\n",total);
    //Imprimir(vetor,total);
    while (in != EOF){
        in = fscanf(vetores,"%d",&n);
        //printf("O valor de n: %d\n",n);
        //printf("Total = %d\n",total);
        int soma  = total+n;
        //vetor = Tranfere_vetor(vetor,total,soma);
        vetor = Realocacao(vetor,total,soma);
        //printf("Total2 = %d\n",soma);
        if(in == EOF) break;
        for(int i=total;i < soma;i++){
            in = fscanf(vetores,"%d",&vetor[i]);
            //printf("%d ",vetor[i]);
        }
        //printf("\n");
        total = soma;
        //Imprimir(vetor,total);
    }
    fclose(vetores);
    Imprimir_Invetido(vetor,total);
    Verifica_Resposta(vetor,Resposta,total);
    Imprimir(vetor,total);
    
    return 0;
}