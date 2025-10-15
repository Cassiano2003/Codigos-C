#include <stdio.h>


int soma_par(int num){
    if(num == 0){
        return 0;
    }else{
        if(num%2 == 0){
            return num + soma_par(num-2);
        }else{
            return soma_par(num-1);
        }
    }
}

int main(){
    int num;
    scanf("%d",&num);
    printf("Soma dos numeros pares é: %d",soma_par(num));
    return 0;
}