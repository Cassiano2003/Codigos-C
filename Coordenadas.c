//Bibliotecas usadas.
#include <stdlib.h>
#include <stdio.h>

int main(){
    int x, z;
    printf("Digite as coordenadas:\nX e Z\n");
    while(1){
        scanf("%d%d",&x,&z);
        if(x == 0 || z == 0){
            break;
        }
        if(x%8==0){
            printf("X = %d\n",x/8);
        }else{
            printf("Nao X\n");
        }
        if(z%8==0){
            printf("Z = %d\n",z/8);
        }else{
            printf("Nao Z\n");
        }
    }
}