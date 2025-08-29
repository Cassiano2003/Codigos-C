#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define m 50
//Visual
void imprime_menu(){
    printf("-------------------------------------------------------\n");
}

//Gera vetor aletorio
void gera_aleatorio(int lista[], int *cont){
    for (int i = 0; i < m; i++) {
        lista[i] = rand()%100;
        if(*cont==0) *cont = m;
    }
}

//Imprime a lista
void imprime(int lista[]){
    if(lista[0] == -1) {
        printf("Vetor vazio!!!\n");
        return;
    }
    for (int i = 0; i < m; i++){
        printf("%d: [%d]", i,lista[i]);
        printf("\n");
    }
}

//Sobe se o numero adicionado ou trocado for menor q o pai
void subir(int lista[],int i){
    if(i > 0){//se tem pai ou nao
        int j = (i-1)/2;//calcula o pai
        if(lista[i]>lista[j]){//verifica se o filho e maior q o pai
            int temp;
            temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
            subir(lista,j);
        }
    }
}

//ordena
void ordena(int lista[]){
    for(int i=1;i<m;i++){
        subir(lista,i);
    }
}

//Ordena vetor
void ordena_vet(int lista[],int ordenado[],int num){
    ordena(lista);
    int valor = lista[0];
    lista[0] = lista[num];
    lista[num] = -1;
    ordenado[num] = valor;
    num -= 1;
    if(num == -1) return;
    ordena_vet(lista,ordenado,num);
}

int main(){
    int lista[m] = {36,1,55,80,12,52,69,37,15,39,13,11,71,41,89,25,41,71,25,47,90,12,8,45,43,32,38,92,42,97,6,17,49,56,96,88,33,63,68,17,79,63,37,27,33,76,87,41,28,77},ordenado[m],copia[m],cont=0,num;
    char escolha =' ',qual =' ';
    copia[0] = ordenado[0] = -1;
    while(1){
        imprime_menu();
        printf("          MENU\n");
        printf("1 - Imprime lista\n");
        printf("2 - Gera aleatoriamente\n");
        printf("3 - Ordena em Heap\n");
        printf("4 - Ordena em heapsort\n");
        imprime_menu();
        setbuf(stdin,NULL);
        scanf("%s",&escolha);
        switch (escolha){
        case ('1'):
        imprime_menu();
        printf("1 - Imprime lista\n");
        printf("2 - Imprime copia\n");
        printf("3 - Imprime ordenado\n");
        imprime_menu();
        setbuf(stdin,NULL);
        scanf("%c",&qual);
        switch (qual){
            case ('1'):
            imprime(lista);
                break;
            case ('2'):
            imprime(copia);
                break;
            case ('3'):
            imprime(ordenado);
                break;
            default:
            printf("Entrada invalida!!!\n");
                break;
        }
        imprime_menu();
        escolha = ' ';
            break;
        case ('2'):
        printf("Estou gerando o vetor\n");
        gera_aleatorio(lista,&cont);
        printf("Vetor gerado\n");
        imprime_menu();
            break;
        case ('3'):
        ordena(lista);
        imprime_menu();
            break;
        case ('4'):
        num = m-1;
        for(int i=0;i<m;i++){
            copia[i] = lista[i];
        }
        ordena_vet(copia,ordenado,num);
        imprime_menu();
            break;
        default:
            printf("1 - sim\n2 - nao\nDeseja encerrar o programa: ");
            scanf("%s",&escolha);
            break;
        }
        if(escolha == '1') break;
    }
}