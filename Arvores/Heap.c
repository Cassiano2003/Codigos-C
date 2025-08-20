#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define m 100

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
//desse se o numero pai for menor que o filho
void desecer(int lista[], int i){
    int j = (2*i)+1;//filho esquerdo
    if (j < m){//se filho esquerdo existe
        if (j < m-1){//sse fiho direito existe
            if (lista[j+1] > lista[j]){//qual e o maior filho
                j = j + 1;
            }
        }
        if(lista[i] < lista[j]){
            int temp;
            temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
            desecer(lista,j);
        }
    }
}

//Incere o elemento
void incerir(int lista[],int num,int *cont){
    if(*cont<m){
        lista[*cont] = num;
        subir(lista,*cont);
        *cont = *cont + 1;
    }
}

//Seleciona o indice de maior prioridade
void selecao(int lista[]){
    if (lista[0]>=0){
        printf("O elemento de maior prioridade é o: %d\n",lista[0]);
    }else{
        printf("A lista esta vazia!!!\n");
    }
}

//Remoçao do elemento de maior prioridade
void remocao(int lista[],int *cont){  
    lista[0] = lista[*cont];
    desecer(lista,0);
    *cont = *cont - 1;
}

//Trocar pioridade
bool alteracao(int lista[],int num, int alt,bool *chave){
    int j;
    for(int i=0;i<m;i++){
        if(lista[i]==num){
            j = i;
            *chave = false;
            //printf("Entrou!!!\n");
            break;
        }
    }
    if(*chave){
        printf("Esse numero nao esta na lista!!\n");
        return false;
    }else if(!*chave){
        lista[j] = alt;
        subir(lista,j);
        desecer(lista,j);
        return true;
    }
    return true;
}

//Imprime a lista
void imprime(int lista[],int *cont){
    for (int i = 0; i < *cont; i++){
        printf("%d: [%d]", i,lista[i]);
        printf("\n");
    }
    if(*cont == 0) {
        printf("Vetor vasio!!!\n");
    }
}

//ordena
void ordena(int lista[]){
    for(int i=1;i<m;i++){
        subir(lista,i);
    }
}

void ordena_vet(int lista[],int ordenado[],int *num){
    ordena(lista);
    int valor = lista[0];
    lista[0] = lista[*num];
    lista[*num] = -1;
    for(int i=0;i < m;i++){
        //printf("entrou: %d\nnum: %d\n",i,*num);
        if(i == *num) {
            //printf("if: %d\n",*num);
            ordenado[*num] = valor;
            *num = *num - 1;
            break;
        }
    }
    if(*num == -1) return;
    //printf("ordena_vet\n");
    ordena_vet(lista,ordenado,num);
}
void imprime_menu(){
    printf("-------------------------------------------------------\n");
}

int main(){
    int lista[m],ordenado[m];
    int cont = 0,num,escolha=0,alt,num1=m-1;
    bool chave;
    while(1){
        imprime_menu();
        printf("1 - Imprime lista\n");
        printf("2 - Adiciona novo elemento\n");
        printf("3 - Remove elemento\n");
        printf("4 - Troca a prioridade\n");
        printf("5 - Ordena o vetor\n");
        printf("6 - Gera vetor aleatoriamente\n");
        imprime_menu();
        num = alt = 0;
        chave = true;
        setbuf(stdin,NULL);
        scanf("%d",&escolha);
        setbuf(stdin,NULL);
        switch (escolha){
        case 1://imprime a lista
            printf("Seu vetor é:\n");
            imprime(lista,&cont);
            imprime_menu();
            break;
        case 2://Adiciona novo elemento
            printf("Incira elementos em um vetor de tamanho 20\n");
            printf("Coleque os elementos na mesma linha separados por espaço\n");
            for(int i=0;i<m;i++){
                scanf("%d",&num);
                incerir(lista,num,&cont);
            }
            imprime_menu();
            break;
        case 3://remove elemento de maior prioridade
            printf("Ira remover o elemento de maior prioridade!!!\n");
            remocao(lista,&cont);
            printf("Removido com sucesso!!!\n");
            break;
        case 4://troca a priorida
            printf("Qual numero elemendo deseja trocar a sua prioridade: ");
            scanf("%d",&num);
            printf("\n");
            if(alteracao(lista,num,alt,&chave)){
                printf("Digite sua nova prioridade: ");
                scanf("%d",&alt);
                alteracao(lista,num,alt,&chave);
                printf("Elemento trocado com sucesso!!!\n");
            }
            imprime_menu();
            break;
        case 5://ordena o vetor
            printf("Iremos ordenar o seu vetor\n");
            ordena_vet(lista,ordenado,&num1);
            cont = m;
            printf("Vetor ordenado com sucesso!!!\n");
            imprime_menu();
            imprime(ordenado,&cont);
            break;
        case 6://gera vetor aleatoriamente
            printf("Estou gerando o seu vetor!!!\n");
            for (int i = 0; i < m; i++) {
                lista[i] = rand()%100;
                if(cont==0) cont = m;
            }
            printf("Vetor gerado com sucesso!!!\n");
            imprime_menu();
            break;
        default:
            break;
        }
        if(escolha!=1&&escolha!=2&&escolha!=3&&escolha!=4&&escolha!=5&&escolha!=6) {
            imprime_menu();
            printf("1 - Sim\nQualquer numero - Nao\n");
            printf("Deseja mesmo encerar o programa: ");
            setbuf(stdin,NULL);
            scanf("%d",&escolha);
            if(escolha==1){
                printf("Fim do programa!!!\n");
                break;
            }
        }
    }
}