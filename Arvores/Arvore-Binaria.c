//Biblioteca
#include <stdio.h>
#include <stdlib.h>

//Os nos da arvore
typedef struct{
    char elemento;
    struct no *esq,*dir;
    int nivel;
}no;

//novo no
no* novo_no(char elemento){
    no* novo =(no*)malloc(sizeof(no));
    novo->dir = novo->esq = NULL;
    novo->nivel = 1;
    novo->elemento = elemento;
    return novo;
}

//Pre-ordem
void pre_ordem(no *raiz){
  printf("%c ",raiz->elemento);
  if(raiz->esq){
    pre_ordem(raiz->esq);
  }
  if(raiz->dir){
    pre_ordem(raiz->dir);
  }  
}
//Ordem
void ordem(no *raiz){
  if(raiz->esq){
    ordem(raiz->esq);
  }
  printf("%c ",raiz->elemento);
  if(raiz->dir){
    ordem(raiz->dir);
  }  
}
//pos_ordem
void pos_ordem(no *raiz){
  if(raiz->esq){
    pos_ordem(raiz->esq);
  }
  if(raiz->dir){
    pos_ordem(raiz->dir);
  }
  printf("%c ",raiz->elemento);
}

no* busca_arvore(no *pt, int x) {
    no* aux;
  if (pt == NULL) {
    printf("Arvore vazia!\n");
  }
  else {
    if (pt->elemento == x) {
      printf("O elemento %d foi encontrado em no %p\n", x, pt);
    }
    else {
      if (x < pt->elemento) {
        if (pt->esq == NULL) {
            printf("esqElemento %d nao encontrado!\n", x);
            return pt;
        }
        else {
          pt = pt->esq;
          busca_arvore(pt, x);
        }
      }
      else {
        if (pt->dir == NULL) {
            return pt;
            printf("dirElemento %d nao encontrado!\n", x);
        }
        else {
          pt = pt->dir;
          busca_arvore(pt, x);
        }
      }
    }
  }
}

//Insece
void insere(no **arv, char letra[], int *i, int *nivel){
  no* aux = (*arv);
  if((*arv)->esq == NULL){
    (*arv)->esq = novo_no(letra[(*i)]);
    *i = *i + 1;
  }else{
    aux = (*arv)->esq;
    insere(&aux, letra, i,nivel);
  }
  if(letra[*i] == '\n'){
    return;
  }
  if((*arv)->dir == NULL){
    (*arv)->dir = novo_no(letra[(*i)]);
    *i = *i + 1;
  }else if((*arv)->dir != NULL){
    aux = (*arv)->dir;
    insere(&aux, letra, i,nivel);
  }
}

//Principal
int main(){
  no *arv = NULL;
  char palavra[100];
  int i = 1,nivel_total = 0;
  fprintf("chcp 6500","%s");
  printf("Insira uma fase ou uma palavra: ");
  printf("\t",10);
  fgets(palavra,100,stdin);
  arv = novo_no(palavra[0]);
  if(palavra[0] == '\n'){
    printf("Entrada invalida!!!");
  }else{
    while(palavra[i] != '\n'){
      insere(&arv,palavra,&i,&nivel_total);
    }
    pre_ordem(arv);
    printf("\n");
    ordem(arv);
    printf("\n");
    pos_ordem(arv);
    printf("\nNivel: %d\n",nivel_total);
  }
}