//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "ARV_Bibi.h"

int main(){
    struct no * arv,*arv_bin,*avl;
    avl = arv = arv_bin = NULL;
    char nome[100];
    avl = novo_no('g',1);
    //j
    avl->dir = novo_no('j',-1);
    avl->dir->dir = novo_no('k',0);
    //e
    avl->esq = novo_no('e',1);
    avl->esq->dir = novo_no('f',0);
    avl->esq->esq = novo_no('c',0);
    //c
    avl->esq->esq->esq = novo_no('b',0);
    avl->esq->esq->dir = novo_no('d',0);
    //imprima_estrutura(avl,0);
    fgets(nome,100,stdin);
    
    pre_ordem(avl);
    printf("\n");
    pos_ordem(avl);
    printf("\n");
    ordem(avl);
  /*struct no *arv = NULL;
  char palavra[100];
  int i = 1,nivel_total = 0;
  printf("Insira uma fase ou uma palavra: ");
  printf("\t",10);
  fgets(palavra,100,stdin);
  arv = novo_no(palavra[0],0);
  if(palavra[0] == '\n'){
    printf("Entrada invalida!!!");
  }else{
    while(palavra[i] != '\n'){
      insere_arv(&arv,palavra,&i,&nivel_total);
    }
    pre_ordem(arv);
    printf("\n");
    ordem(arv);
    printf("\n");
    pos_ordem(arv);
    printf("\nNivel: %d\n",nivel_total);
    imprima_estrutura(arv,0);
  }*/
}