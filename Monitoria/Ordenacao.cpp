#include <stdlib.h>
#include <stdio.h>

void Troca(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void insersion_sort(int n, int *vetor){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(vetor[j] > vetor[i]){
                Troca(&vetor[i],&vetor[j]);
            }
        }
    }
}

void imprime(int n,int *v){
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    //printf("\n");
}

int main(){
    int n;
    int *v;
    //printf("Qual vai ser o tamnho do vetor: ");
    scanf("%d",&n);

    v = (int *)malloc(n *sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    insersion_sort(n,v);
    imprime(n,v);


    return 0;
}