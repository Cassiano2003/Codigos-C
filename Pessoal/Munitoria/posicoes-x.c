#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int *posicoes_de_repeticoes(int i,int n,int k,int v[]){
    int *resposta = (int *) malloc(i * sizeof(int));
    if(n > 0){
        if(v[n-1] == k){
            resposta = posicoes_de_repeticoes(i+1,n-1,k,v);
            resposta[i] = i;
        }else{
            resposta = posicoes_de_repeticoes(i,n-1,k,v);
        }
    }
    return resposta;
}

int main(){
    int n,k,vetor[MAX],*resposta;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
    scanf("%d",&k);
    resposta = posicoes_de_repeticoes(0,n,k,vetor);
    for(int i=0;i<n;i++){
        printf("%d ",resposta[i]);
    }
    return 0;
}

/*
10 102   201   102   555  789  1918   3024   102    87   102 102
*/