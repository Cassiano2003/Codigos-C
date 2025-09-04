#include <stdio.h>

int potencia(int x, int n){
    if(n == 0)
        return 1;
    else if(n == 1)
        return x;
    else if (n % 2 == 0)
        return potencia(x,n/2) * potencia(x,n/2);
    else
        return x*potencia(x,n-1);
}

int main(){
    int x,n;
    printf("Digite a base e o expoente: ");
    scanf("%d %d",&x,&n);
    printf("%d\n",potencia(x,n));
}