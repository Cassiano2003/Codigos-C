#include <stdio.h>
#include <stdlib.h>
#define L 0
#define U 99

typedef struct{
    char el;
    struct Celula *seg;
}Celula;


//incere
void incere(Celula*lista[],int*pend,int*corent,int pri,char el){
    if(pri<*corent) {
        printf("pend = %d\npri = %d\ntrocou o pend pela pri\n",*pend,pri);
        *pend = pri;
    }
    Celula* novo = (Celula*)malloc(sizeof(Celula));
    novo->el = el;
    novo->seg = NULL;
    Celula *aux=lista[pri];
    if(lista[pri]==NULL){
        lista[pri] = novo;
        return;
    }
    while(aux!=NULL){
        if(aux->seg == NULL){
            novo->seg = lista[pri]->seg;
            lista[pri]->seg = novo;
            return;
        }
        aux = aux->seg;
    } 
}


//remove
void remuve(Celula*lista[],int*pend,int*corent,int pri){
    Celula*p;
    int cont = *corent;

    if(*pend<*corent && *pend!= -1){
        p = lista[*pend];
        lista[*pend] = lista[*pend]->seg;
    }
    //corent = 0
    if(lista[*corent]!=NULL){
        p = lista[*corent];
        lista[*corent] = lista[*corent]->seg;
        if(lista[*corent] == NULL){
            for(int i=*corent;i<U;i++){
                if(lista[i] != NULL) {
                    *corent = i-1;
                    break;
                }
            }
        }
        printf("Letra removida = %c\nPrioridade = %d\n",p->el,*corent);
        free(p);

    //corent > 0
    }else if(lista[*corent] == NULL){
        p = lista[cont+1];
        lista[cont+1] = lista[cont+1]->seg;
        if(lista[cont+1] == NULL){
            for(int i=cont+1;i<U;i++){
                if(lista[i] != NULL) {
                    *corent = i-1;
                    break;
                }
            }
        }
        printf("Letra removida = %c\nPrioridade = %d\n",p->el,cont+1);
        free(p);
    }
}


//imprime
void imprime(Celula*lista[]){
    Celula *aux;
    for (int i = 0; i < (U-L+1); i++){
        printf("%d: [ ]", i);
        aux = lista[i];
        if(aux == NULL){
            printf("->NULL\n");
        }else{
            while(aux!=NULL){
                printf("->[%c]",aux->el);
                if(aux->seg == NULL){
                    printf("->%s",aux->seg);
                }
                aux = aux->seg;
            }
            printf("\n");
        }
    }
    
}

//começo
int main(){
    Celula *lista[U-L+1];
    char el;
    int *pend=-1,*corent=0,pri=0;
     for (int i = 0; i < (U-L+1); i++){
        lista[i] = NULL;
     }
     //imprime(lista);
     incere(lista,&pend,&corent,0,'A');
     incere(lista,&pend,&corent,3,'B');
     incere(lista,&pend,&corent,0,'C');
     incere(lista,&pend,&corent,5,'D');
     incere(lista,&pend,&corent,4,'E');
     incere(lista,&pend,&corent,6,'F');
     incere(lista,&pend,&corent,4,'G');
     incere(lista,&pend,&corent,1,'H');
     incere(lista,&pend,&corent,1,'I');
     remuve(lista,&pend,&corent,pri);//a
     imprime(lista);
     remuve(lista,&pend,&corent,pri);//c
     imprime(lista);
     remuve(lista,&pend,&corent,pri);//b
     imprime(lista);
     remuve(lista,&pend,&corent,pri);//e
     imprime(lista);//*/
     remuve(lista,&pend,&corent,pri);//e
     imprime(lista);//*/
     return 0;
}