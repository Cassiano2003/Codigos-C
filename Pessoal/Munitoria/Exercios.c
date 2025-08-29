#include <stdio.h>
#define MAX 100

int busca_binaria_NRec(int k, int n, int v[]){
    int esq = 0;//Ponteiro da esquerda
    int dir = n-1;//Ponteiro da direita

    while (esq <= dir)//Fica ata a esquerda ficar maior q a direita
    {
        int meio = esq + (dir - esq) / 2;//Divide o vertor no meio
        
        //Se achar o numero retorna
        if (v[meio] == k)
        {
            return meio;
        }
        //Vai mover os ponteiros dependendo na onde esta o numero, ja que estamaos trabalhando com nummeros ordenados
        else if (v[meio] < k)
        {
            esq = meio + 1;
        }else{
            dir = meio - 1;
        }
    }
    //Caso nao ache o numero
    return -1;
}

int main(){
    int k, n, v[MAX];//Variaveis 

    scanf("%d %d",&k,&n);//Pega as duas variveis mais importantes
    for(int i=0; i < n; i++){
        scanf("%d",&v[i]);//Cira o vetor
    }

    printf("Lugar do %d = %d\n",k,busca_binaria_NRec(k,n,v));//Chama a funçao

    return 0;
}