#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define m 23

typedef struct {
    int num;
    struct No* prox;
}No;

int multiplicacao(int chave){
    float A = ((sqrt(5)-1)/2);
    float chave2 = chave*A;
    chave2 = chave2-(int)chave2;
    return chave2*m;
}
int divisao(int chave){
    return chave%m;
}

void incerir(No*lista[],int num){
    int end = divisao(num);
    No *aux = lista[end], *novo;
    novo = (No*)malloc(sizeof(No));
    novo->num = num;
    novo->prox = NULL;
    //lista vazia
    if(aux == NULL){
        lista[end] = novo;
        return;
    }
    while(aux!= NULL&& aux ->num != num){
        if(aux->prox == NULL){
            novo->prox = lista[end]->prox;
            lista[end]->prox = novo;
            return;
        }
    aux = aux->prox;
    }
    if(aux->num == num){
        printf("Essa chave = %d ja existe\n",num);
    }
}
void imprime(No*lista[]){
    No *aux;
    int i;
    for ( i = 0; i < m; i++){
        printf("%d: [ ]", i);
        aux = lista[i];
        if(aux == NULL){
            printf("->NULL\n");
        }else{
            while(aux!=NULL){
                printf("->[%d]",aux->num);
                aux = aux->prox;
            }
            printf("\n");
        }
    }
    
}
No* busca(No* lista[],int num){
    No *aux;
    for(int i = 0;i<m;i++){
        aux = lista[i];
        while (aux!=NULL){
            if(aux->num == num)return aux;
            aux = aux->prox;
        }
        
    }
    return NULL;
}
int main(){
    No *lista[m];
    for (int i = 0; i < m; i++){
        lista[i] = NULL;
    }
    incerir(lista,10);
    incerir(lista,23);
    incerir(lista,7);
    incerir(lista,5);
    incerir(lista,31);
    incerir(lista,0);
    imprime(lista);
    incerir(lista,10);
    imprime(lista);
    if(busca(lista,9)){
        No* aux = busca(lista,9);
        printf("numero = %d\n",aux->num);
    }else{
        printf("numero nao achado\n");
    }
}