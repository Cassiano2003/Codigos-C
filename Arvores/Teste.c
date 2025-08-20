#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define D 3

//Strutura
typedef struct Page{
    short int totalchave;// So podem asumir D-1 total de chaves se for D da overflow
    int chaves[D-1]; //So podem haver D-1 chaves
    struct Page *folhas[D+1];
    struct Page *pai;
}Page;

//Nova page
Page *nova_page(){
    Page *novo = (Page*) malloc(sizeof(Page));
    novo->totalchave = 0;
    novo->pai = NULL;
    for(int i=0; i < D-1;i++){
        novo->chaves[i] = INT_MAX;
    }
    for(int i=0; i <= D;i++){
        novo->folhas[i] = NULL;
    }
    return novo;
}

//Imprimir ordem
void emOrdem (struct Page *raiz) {
    if(raiz==NULL)return;

    for(int i=0;i < raiz->totalchave;i++){
        emOrdem(raiz->folhas[i]);
        //printf("%d ",raiz->chaves[i]);
        printf("Chaves[%d]: %d ",i,raiz->chaves[i]);
    }
    printf("\n");
    emOrdem(raiz->folhas[raiz->totalchave]);
}

//Organiza cahves
void organiza(Page **arv,int num){
    int temp = 0;
    for(int j=0;j < D;j++){
        if(num < (*arv)->chaves[j]){
            temp = num;
            num = (*arv)->chaves[j];
            if(temp == INT_MAX) continue;
            (*arv)->chaves[j] = temp;
        }
    }
    (*arv)->totalchave = (*arv)->totalchave+1;
}

//Calcula a altura da arvore
void calt(Page *arv,int *calt1){
    if(arv->folhas[0] != NULL){
        *calt1 = *calt1+1;
        calt(arv->folhas[1],calt1);
    }
}

void rotacion(Page **arv,Page **aux,int *valor){
    Page *novo = nova_page();
    *aux = nova_page();
    int media = (*arv)->totalchave/2, cont = 0;
    *valor = (*arv)->chaves[media];
    novo->chaves[0] = *valor;
    novo->totalchave += 1;

    for(int i=media+1;i <= D;i++){
        (*aux)->folhas[cont] = (*arv)->folhas[i];
        (*arv)->folhas[i] = NULL;
        cont++;
    }

    cont = 0;
    (*arv)->totalchave = media;
    for(int i=media;i < D;i++){
        if((*arv)->chaves[i] == *valor){
            (*arv)->chaves[i] = INT_MAX;
        }else{
            (*aux)->chaves[cont] = (*arv)->chaves[i];
            (*arv)->chaves[i] = INT_MAX;
            cont++;
        }
    }
    (*aux)->totalchave = cont;
    novo->folhas[0] = (*arv);
    for(int i=0;i <= D;i++){
        if(novo->folhas[i] == NULL){
            novo->folhas[i] = (*aux);
            novo->totalchave = 2;
            break;
        }
    }
    if((*arv)->pai == NULL){ //Nao tem pai
        (*aux)->pai = (*arv)->pai = novo;
        novo->pai = (*arv)->pai;
        (*arv) = novo;
    }else{//Tem pai
        organiza(&(*arv)->pai,*valor);
        (*aux)->pai = (*arv)->pai;
        for(int i=0;i <= D;i++){
            if((*arv)->pai->folhas[i] == NULL){
                (*arv)->pai->folhas[i] = (*aux);
                break;
            }
        }
    }
    printf("Fim rotacion\n");
    return;
}


void insere(Page **arv,Page **aux,int num,int *valor,int *f){
    int temp = -1,cont = 0,num2 = -1;
    if((*arv) == NULL){
        (*arv) = nova_page();
        (*arv)->chaves[0] = num;
        (*arv)->totalchave += 1;
    }else{
        for(int i=0; (*arv)->folhas[i] != NULL && i < D;i++){
            num2 = i;
        }
        if(num2 != -1){
            *f = *f+1;
            insere(&(*arv)->folhas[num2],aux,num,valor,f);
            *f = *f-1;
        }else{
            organiza(arv,num);
        }
    }
    if((*arv)->totalchave == D){
        printf("Overflow\n");
        if(*f == 0)(*arv)->pai = NULL;
        rotacion(arv,aux,valor);
    }
}


int main(){
    Page *arv_b = NULL, *aux = NULL;
    int valor = -1, pai = 0, calt1 = 0,f = 0;
    printf("1\n");
    insere(&arv_b,&aux,1,&valor,&f);
    printf("2\n");
    insere(&arv_b,&aux,2,&valor,&f);
    printf("3\n");
    insere(&arv_b,&aux,3,&valor,&f);
    printf("4\n");
    insere(&arv_b,&aux,4,&valor,&f);
    printf("5\n");
    insere(&arv_b,&aux,5,&valor,&f);
    printf("6\n");
    insere(&arv_b,&aux,6,&valor,&f);
    printf("7\n");
    insere(&arv_b,&aux,7,&valor,&f);
    calt(arv_b,&calt1);
    printf("calt: %d\n",calt1);//*/
    emOrdem(arv_b);
    printf("8\n");
    insere(&arv_b,&aux,8,&valor,&f);
    emOrdem(arv_b);
    printf("9\n");
    insere(&arv_b,&aux,9,&valor,&f);
    emOrdem(arv_b);
    for(int i=0;i < D;i++){
        printf("Pai chaves[%d]: %d\n",i,arv_b->folhas[0]->folhas[2]->pai->chaves[i]);
    }//*/
}



/*
for(int i=0;i < D;i++){
    printf("Folhas chaves[%d]: %d\n",i,arv_b->folhas[0]->pai->chaves[i]);
}
}*/