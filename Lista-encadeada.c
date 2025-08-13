//Bibliotecas usadas.
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int num;
    struct No* prox;
}No;
typedef struct{
    No* inicio;
    int cont;
}LISTA;



LISTA* inicializa(){
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    lista -> inicio = NULL;
    lista -> cont = 0;
    return lista;
}
void insercao(LISTA* lista, int num){
    No* ant = NULL;
    No* aux = lista -> inicio;
    No* novo = (No*)malloc(sizeof(No));
    novo -> num = num;
    while (aux!=NULL){
        if(num <= aux->num){
            ant->prox= novo;
            novo->prox=aux;
        }else if(aux->num >= num){
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        ant = aux;
        aux = aux->prox;
        break;
    }
        
}
 void removecao(LISTA* lista, int num){
    No* aux = lista->inicio;
    No* ant = NULL;
    while(aux!=NULL){
        if(aux -> num == num)break;
        ant = aux;
        aux = aux -> prox;
    }
    if(aux == NULL){
        lista -> inicio = aux -> prox;
    }else{
        ant -> prox = aux -> prox;
    }
    free(aux);
    lista -> cont--;
 }
 No* busca(LISTA* lista, int num){
    No* aux = lista->inicio;
    while (aux!=NULL){
        if (aux->num == num)return aux;
        aux = aux -> prox;
    }
    return NULL;
 }
void imprecao(LISTA * lista){
    No* aux = lista->inicio;
    while (aux!=NULL){
        printf("%d ",aux->num);
        aux = aux-> prox;
    }
    printf("\n");
}
int main(){
    int escolha,num=0,parada=0;
    LISTA* lista;
    lista = inicializa();
    printf("-----------------------------------------------------------\n");
    while (1){
        if(parada == 0){
            printf("-Imprime = 1\n");
            printf("-Insere = 2\n");
            printf("-Busca = 3\n");
            printf("-Remove = 4\n");
            printf("-----------------------------------------------------------\n");
            printf("-Escolha qual vai a ser operacao a ser aplicada na lista: ");
            scanf("%d",&escolha);
            switch (escolha){
            case 1:
                imprecao(lista);
            printf("-----------------------------------------------------------\n");
                break;
            case 2:
                printf("-Quantos numeros vao ser inseridos: ");
                int n;
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    printf("-");
                    scanf("%d",&num);
                    insercao(lista,num);
                }
            printf("-----------------------------------------------------------\n");
                break;
            case 3:
                printf("-Qual numero busca: ");
                int n1;
                scanf("%d",&n1);
                No* p = busca(lista,n1);
                if(p!=NULL){
                    printf("-Numero existente.\n");
                }else{
                    printf("-Esse numero nao esta na lista %d, adicione ele na lista.\n",n1);
                }
            printf("-----------------------------------------------------------\n");
                break;
            case 4:
                printf("-Qual numero quer remover: ");
                int n2;
                scanf("%d",&n2);
                removecao(lista,n2);
                printf("-Numero removido.\n");
            printf("-----------------------------------------------------------\n");
                break;
            default:
                parada++;
                break;
            }
        }else{
            printf("-Fim do programa, obrigado por usar.\n");
            printf("-----------------------------------------------------------\n");
            break;
        }

    }
    return 0;
    
}