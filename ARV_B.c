#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define D 3

//Strutura
typedef struct Page{
    short int totalchave;// So podem asumir D-1 total de chaves se for D da overflow
    int chaves[D-1]; //So podem haver D-1 chaves
    struct Page *folhas[D];
    struct Page *pai;
}Page;

//Nova page
Page *nova_page(){
    Page *novo = (Page*) malloc(sizeof(Page));
    novo->totalchave = 0;
    novo->pai = NULL;
    for(int i=0; i < D;i++){
        novo->chaves[i] = INT_MAX;
    }
    for(int i=0; i < D;i++){
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

//Subir
void subir(Page **arv, int *valor, int *pai,Page *lista[]){
    int j=0;
    if((*arv)->totalchave == D){//Deu overfllow
        Page *novo = nova_page(),*aux1 = nova_page(), *aux2 = nova_page();//Novas folhas
        int media = (*arv)->totalchave/2;//valor medio do vetor
        *valor = (*arv)->chaves[media];//valor recebe o num do meio
        if((*arv)->folhas[0] != NULL){
            for(int i=0; i <= media;i++){
                aux1->folhas[i] = (*arv)->folhas[i];
                aux1->folhas[i]->pai = aux1;
            }
            for(int i=media+1;i < D;i++){
                aux2->folhas[j] = (*arv)->folhas[i];
                aux2->folhas[j]->pai = aux2;
                j++; 
            }
        }
        if(*pai == 0){
            //Nao tem pai
            novo->chaves[0] = *valor;//pai recebe valor medio
            for(int i=0; i < media;i++){
                aux1->chaves[i] = (*arv)->chaves[i];
            }
            aux1->totalchave = media;
            j = 0;
            for(int i=media+1;i < D;i++){
                aux2->chaves[j] = (*arv)->chaves[i];
                j++;
            }
            aux2->totalchave = j;

            aux2->folhas[j] = lista[0];
            lista[0] = NULL;
            aux2->pai = aux1->pai = novo;
            novo->folhas[0] = aux1;
            novo->folhas[1] = aux2;
            novo->totalchave = novo->totalchave + 1;
            (*arv) = novo;
        }else{
            //Tem pai
            //Coloca as chaves no aux e a quantidade de chaves em cada no
            for(int i=0; i < media;i++){
                aux1->chaves[i] = (*arv)->chaves[i];
            }
            aux1->totalchave = media;
            for(int i=media+1;i < D;i++){
                aux2->chaves[j] = (*arv)->chaves[i];
                j++;
            }
            aux2->totalchave = j;
            //Fim
            //Atualiza os ponteiros do pai
            aux2->pai = aux1->pai = (*arv)->pai;
            int cont = 0;
            for(int i=0;i < D;i++){
                if((*arv)->pai->folhas[i] == (*arv)){
                    (*arv)->pai->folhas[i] = aux1;
                    aux1 = NULL;
                }else if((*arv)->pai->folhas[i] == NULL){
                    (*arv)->pai->folhas[i] = aux2;
                    aux2 = NULL;
                }
                if((*arv)->pai->chaves[i] == INT_MAX && cont == 0){
                    (*arv)->pai->chaves[i] = *valor;
                    cont = 1;
                }
            }
            if(aux2 != NULL) lista[0] = aux2;
            //Atualiza a quantidade total de chaves
            (*arv)->pai->totalchave = (*arv)->pai->totalchave + 1;
        }
    }
    *pai = 0;
    return;
}

//
void insere(Page **arv, int num,int *valor,int*pai,Page *lista[]){
    int cont1 = -1;
    if((*arv) == NULL){
        Page *novo = nova_page();
        (*arv) = novo;
    }
    if((*arv)->pai == NULL){
        *pai = 0;
    }else{
        *pai = 1;
    }
    for(int i=0; (*arv)->folhas[i] != NULL;i++){
        cont1 = i;
    }
    if(cont1 != -1){
        insere(&(*arv)->folhas[cont1],num,valor,pai,lista);
        if((*arv)->totalchave == D){
            subir(arv,valor,pai,lista);
        }
    }else{
        int temp = -1, cont = 0;
        for(int j=0;j < D;j++){
            if(num < (*arv)->chaves[j]){
                temp = num;
                num = (*arv)->chaves[j];
                if(temp == INT_MAX) continue;
                (*arv)->chaves[j] = temp;
            }
        }
        (*arv)->totalchave = (*arv)->totalchave+1;
        if((*arv)->totalchave == D){
            subir(arv,valor,pai,lista);
        }
    }
}


//MAIN
int main(){
    struct Page *avr_b = NULL,*lista[D];
    int valor = 0,pai = 0,over = 0;

    insere(&avr_b,5,&valor,&pai,lista);
    insere(&avr_b,0,&valor,&pai,lista);
    insere(&avr_b,7,&valor,&pai,lista);
    insere(&avr_b,4,&valor,&pai,lista);
    insere(&avr_b,9,&valor,&pai,lista);
    insere(&avr_b,1,&valor,&pai,lista);
    insere(&avr_b,8,&valor,&pai,lista);
    insere(&avr_b,6,&valor,&pai,lista);
    insere(&avr_b,99,&valor,&pai,lista);

    

    emOrdem(avr_b);
    return 0;
}




    /*
    for(int i=0;i < D;i++){
        printf("Raiz chaves[%d]: %d\n",i,avr_b->chaves[i]);
    }
    for(int i=0;i < D;i++){
        for(int j=0;j < D;j++){
            printf("Folhas[%d]: %d\n",i,avr_b->folhas[i]->chaves[j]);
        }
        printf("\n");
    }

    for(int i=0;i<D;i++){
        printf("lista[%d]: %d\n",i,lista[i]->chaves[0]);
    }

    */