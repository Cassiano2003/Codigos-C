#include <stdio.h>


int soma_par(int num){
    if(num == 0){
        return 0;
    }else{
        if(num%2 == 0){
            return num + soma_par(num-1);
        }else{
            return soma_par(num-1);
        }
    }
}

int fibonacci(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void imprime_espaco(int quant){
    for(int i=0;i<quant;i++){
        printf("\t");
    }
}

int main(){
    int num;
    int fibo[100];
    printf("Digite um numero: ");
    scanf("%d",&num);
    printf("Soma dos numeros pares é: %d",soma_par(num));
    int sum = 0;
    for(int i=0;i<num;i++){
        fibo[i] = fibonacci(i);
        sum += fibo[i];
    }
    sum /= num;
    printf("\n");
    int utimo = fibo[num-1]-sum;
    for(int i=0;i<num;i++){
        imprime_espaco(utimo/fibo[i]);
        for(int j=0;j<fibo[i];j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}