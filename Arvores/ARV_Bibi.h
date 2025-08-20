//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//Etrutura que componhe a arvore
struct no{
    char info;
    int balanço;
    struct no *esq,*dir;
};
//novo no
struct no* novo_no(char elemento,int num){
    struct no* novo =(struct no*)malloc(sizeof(struct no));
    novo->dir = novo->esq = NULL;
    novo->info = elemento;
    novo->balanço = num;
    return novo;
}
//Imprime para facilitar a visualizaçao da arvore rotacionada
void imprima_estrutura(struct no *raiz, int nivel) {
    int i;
    if (raiz == NULL) {
        padding('\t', nivel);
        puts ("~");
    } else {
        imprima_estrutura(raiz->dir, nivel + 1);
        padding('\t', nivel);
        printf("%c:%d\n", raiz->info,raiz->balanço);
        imprima_estrutura(raiz->esq, nivel + 1);
    }
}
void padding (char ch, int n) {
    for (int i = 0; i < n; i++) putchar(ch);
}
//Rotaçao a direita
void simples_direita(struct no* avl){
    //copia
    struct no* aux = avl->esq->esq;
    //troca
    char temp = avl->info;
    avl->info = avl->esq->info;
    avl->esq->info = temp;
    //rotaciona
    avl->esq->esq = avl->esq->dir;
    avl->esq->dir = avl->dir;
    avl->dir = avl->esq;
    avl->esq = aux;
}
//Rotaçao a esquerda
void simples_esquerda(struct no* avl){
    //copia
    struct no* aux = avl->dir->dir;
    //troca
    char temp = avl->info;
    avl->info = avl->dir->info;
    //rotaciona
    avl->dir->info = temp;
    avl->dir->dir = avl->dir->esq;
    avl->dir->esq = avl->esq;
    avl->esq = avl->dir;
    avl->dir = aux;
}
//Rotaçao dupla a direita
void dupla_direita(struct no*avl){
    //copia
    struct no * aux = avl->esq->dir;
    //troca
    char temp = avl->info;
    avl->info = avl->esq->dir->info;
    avl->esq->dir->info = temp;
    //rotaçao
    avl->esq->dir = aux->esq;
    aux->esq = aux->dir;
    aux->dir = avl->dir;
    avl->dir = aux;
}
//Rotaçao dupla a esquerda
void dupla_esquerda(struct no*avl){
    //copia
    struct no * aux = avl->dir->esq;
    //troca
    char temp = avl->info;
    avl->info = avl->dir->esq->info;
    avl->dir->esq->info = temp;
    //rotaçao
    avl->dir->esq = aux->dir;
    aux->dir = aux->esq;
    aux->esq = avl->esq;
    avl->esq = aux;
}
//Pre-ordem
void pre_ordem(struct no *raiz){
  printf("%c ",raiz->info);
  if(raiz->esq){
    pre_ordem(raiz->esq);
  }
  if(raiz->dir){
    pre_ordem(raiz->dir);
  }  
}
//Ordem
void ordem(struct no *raiz){
  if(raiz->esq){
    ordem(raiz->esq);
  }
  printf("%c ",raiz->info);
  if(raiz->dir){
    ordem(raiz->dir);
  }  
}
//pos_ordem
void pos_ordem(struct no *raiz){
  if(raiz->esq){
    pos_ordem(raiz->esq);
  }
  if(raiz->dir){
    pos_ordem(raiz->dir);
  }
  printf("%c ",raiz->info);
}

//Rotaçao
void define_rotation(struct no *avl,int h){
  if(h == -2){//Direita

  }else if(h == 2){//Esquerda
    define_rotation(avl->esq,2);
    switch (avl->balanço){
      int bala = avl->balanço+1;
      case 1:
        if(bala == 2)define_rotation(avl,2);
        break;
      case 0:
        if(bala == 1) avl->balanço = bala;
        break;
      case -1:
        if(bala == 0);
        break;
      default:
        break;
    }
  }
}
//Insere AVL
struct no* insere_AVL(struct no *avl,char chave, int *h){
  if(avl == NULL){//Arvore vazia
    *h = 1;
    return novo_no(chave,0);
  }else{
    if(chave == avl->info){//O elemento ja existe na arvore
      return NULL;
    }
    if(avl->info > chave){//Anda para a esquerda
      insere_AVL(avl->esq,chave,h);
      if(*h == 1){
        switch (avl->balanço){
          int bala = avl->balanço+1;
          case 1:
            if(bala == 2)define_rotation(avl,2);
            break;
          case 0:
            if(bala == 1) avl->balanço = bala;
            break;
          case -1:
            if(bala == 0)*h = 0;
            break;
          default:
            break;
        }
      }
    }else{
      insere_AVL(avl->dir,chave,h);
      if(*h == 1){
        switch (avl->balanço){
          int bala = avl->balanço-1;
          case 1:
            if(bala == 0)*h = 0;
            break;
          case 0:
            if(bala == -1) avl->balanço = bala;
            break;
          case -1:
            if(bala == -2)define_rotation(avl,-2);
            break;
          default:
            break;
        }
      }
    }
  }
}







//Busca valores na arvore
struct no* busca_bin(struct no *pt, char x,int *f) {
  struct no* aux;
  if (pt == NULL) {//Arvore vazia
    *f = 0;
  }
  else {
    if (pt->info == x) {//Elemento encontrado
      *f = 1;
    }
    else {
      if (x < pt->info) {
        if (pt->esq == NULL) {//Elemento nao encontrotrado
          *f = 2;
          return pt;
        }else {
          pt = pt->esq;
          busca_bin(pt, x,f);
        }
      }else {
        if (pt->dir == NULL) {//Elemento nao encontrotrado
          *f = 3;
          return pt;
        }else {
          pt = pt->dir;
          busca_bin(pt, x,f);
        }
      }
    }
  }
}
//Insere valores na arvore
void insere_bin(struct no **raiz, char num, int *f){
    struct no* lu = busca_bin((*raiz),num,f);
    if(*f == 1){
        printf("Numero ja existente!!!\n");
    }else{
        struct no* novo = novo_no(num,0);
        if(*f == 0){
            (*raiz) = novo;
        }else{
            if(*f == 2){
              //lu->esq->balanço = lu->balanço + 1;
              lu->esq = novo;
            }else if(*f == 3){
              //lu->dir->balanço = lu->balanço + 1;
              lu->dir = novo;
            }
        }
    }
}
//remove
struct no* remove_bin(struct no **avr,int num,int *f){
  struct no* quero = busca_bin((*avr),num,f);
}

//Insece
void insere_arv(struct no **arv, char letra[], int *i, int *nivel){
    struct no* aux = (*arv);
    if((*arv)->esq == NULL){
      (*arv)->esq = novo_no(letra[*i],0);
      *i = *i + 1;
    }else{
      aux = (*arv)->esq;
      insere_arv(&aux, letra, i,nivel);
    }
    if(letra[*i] == '\n'){
      return;
    }
    if((*arv)->dir == NULL){
      (*arv)->dir = novo_no(letra[(*i)],0);
      *i = *i + 1;
    }else if((*arv)->dir != NULL){
      aux = (*arv)->dir;
      insere_arv(&aux, letra, i,nivel);
    }
}   