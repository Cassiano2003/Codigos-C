//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Estrutura
typedef struct{
  int info;
  struct No *esq, *dir;
}No;

//Print pos-ordem

//Cria No
No * novo_no(int x) {
  No *novo;
  novo = (No*) malloc (sizeof(No));
  novo->esq = NULL;
  novo->dir = NULL;
  novo->info = x;
  return novo;
}
//Busca valores na arvore
No* busca_bin(No *pt, int x,int *f) {
  No* aux;
  if (pt == NULL) {
    *f = 0;
    printf("Arvore vazia!\n");
  }
  else {
    if (pt->info == x) {
      *f = 1;
      printf("O elemento %d foi encontrado em no %p\n", x, pt);
    }
    else {
      if (x < pt->info) {
        if (pt->esq == NULL) {
          *f = 2;
          printf("esqElemento %d nao encontrado!\n", x);
          return pt;
        }
        else {
          pt = pt->esq;
          busca_arvore(pt, x,f);
        }
      }
      else {
        if (pt->dir == NULL) {
          *f = 3;
          return pt;
          printf("dirElemento %d nao encontrado!\n", x);
        }
        else {
          pt = pt->dir;
          busca_arvore(pt, x,f);
        }
      }
    }
  }
}
//Insere valores na arvore
void insere_bin(No **raiz, int num, int *f){
    No* lu = busca_bin((*raiz),num,f);
    if(*f == 1){
        printf("Numero ja existente!!!\n");
    }else{
        No* novo = novo_no(num);
        if(*f == 0){
            printf("novo num\n");
            (*raiz) = novo;
        }else{
            if(*f == 2){
                printf("esq num\n");
                lu->esq = novo;
            }else if(*f == 3){
                printf("dir num\n");
                lu->dir = novo;
            }
        }
    }
}
//remove
No* remove_bin(No **avr,int num,int *f){
  No* quero = busca_bin((*avr),num,f);
  if(quero->esq){
    
  }
}
//Main
int main() {
  No *raiz = NULL;
  int i,*num,*f=0,n;
  scanf("%d",&n);
  *num = dive(num);
  for (i=0;num[i] != '\n';i++){
    printf("%d numero: %d\n",i+1,num[i]);
    insere(&raiz,num[i],&f);
    //printf("\n");
  }
  pre_orden(raiz);
  return 0;
}