#include <stdio.h>
#define MAX 100


void imprime_matricula(int i,int n,int mes,int v[]){
    if(i < n){
        if(v[i]%mes == 0){
            printf("%d ",v[i]);
        }
        imprime_matricula(i+1,n,mes,v);
    }
}

int main(){
    int num,vetor[MAX],mes;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&vetor[i]);
    }
    scanf("%d",&mes);
    printf("Os valores de matrículas que receberão o brinde:\n");
    imprime_matricula(0,num,mes,vetor);
    return 0;
}