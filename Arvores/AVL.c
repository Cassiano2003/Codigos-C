//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
//Etrutura que componhe a arvore
struct no{
    char info;
    struct no *esq,*dir;
};
//novo no
struct no* novo_no(char elemento){
    struct no* novo =(struct no*)malloc(sizeof(struct no));
    novo->dir = novo->esq = NULL;
    novo->info = elemento;
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
        printf("%c\n", raiz->info);
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
    printf("%c \n",aux->info);
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

//Inicio
int main(){
    struct no* avl = (struct no*)malloc(sizeof(struct no));
    //e
    avl = novo_no('e');
    avl->esq = novo_no('b');
    avl->dir = novo_no('j');
    //b
    avl->esq->esq = novo_no('a');
    avl->esq->dir = novo_no('c');
    //j
    avl->dir->esq = novo_no('h');
    avl->dir->dir = novo_no('k');
    //k
    avl->dir->dir->dir = novo_no('l');
    //h
    avl->dir->esq->esq = novo_no('g');
    avl->dir->esq->dir = novo_no('i');
    //g
    avl->dir->esq->esq->esq = novo_no('f');
    imprima_estrutura(avl,0);
    dupla_esquerda(avl);
    printf("\n");
    imprima_estrutura(avl,0);
    return 0;
}
/*avl = novo_no('g');
avl->dir= novo_no('j');
avl->esq = novo_no('p');
imprima_estrutura(avl,0);
printf("\n");
avl->dir->esq = novo_no('t');
avl->dir->dir = novo_no('k');
avl->dir->dir->dir = novo_no('h');
imprima_estrutura(avl,0);
printf("\n");
avl->dir->dir->dir->dir = novo_no('m');
avl->dir->dir->esq = novo_no('q');
avl->esq->esq->esq->esq = novo_no('a');
imprima_estrutura(avl,0);
printf("\n");
avl->esq->esq->dir->esq = novo_no('n');
avl->esq->esq->dir->dir = novo_no('w');
avl->esq->dir = novo_no('f');
imprima_estrutura(avl,0);
printf("\n");
avl->esq->esq = novo_no('u');
avl->esq->esq->dir = novo_no('v');
avl->esq->esq->esq =  novo_no('b');
imprima_estrutura(avl,0);
printf("\n");
rotacao_direita(avl->esq);
rotacao_esquerda(avl->dir);
printf("\n");
imprima_estrutura(avl,0);*/