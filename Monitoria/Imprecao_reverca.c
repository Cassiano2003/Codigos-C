#include <stdio.h>
#define MAX 100


//Vai imprimir recursivamente invertido
void imprime_invertido(char v[],int n){
    if(n > 0){
        printf("%c",v[n-1]);
        imprime_invertido(v,n-1);
    }
}

//Vai percorrer ate achar o elemento desejado e retornar o tamnho
int calcula_tamanho(char v[]){
    int tam = 0;
    for(int i=0; v[i] != '\n';i++){
        tam ++;
    }
    return tam;
}


int main(){
    char palavra[MAX];
    //scanf("%s",palavra);// O final dapalava é um '\0'(siguinifica nulo)
    fgets(palavra,sizeof(palavra),stdin);// O final é um '\n'(siguinifica que ouve uma quebra de linha)
    int tam = calcula_tamanho(palavra);
    printf("Tamanho da palavra: %d\n", tam);
    printf("A palavra invertida e: ");
    imprime_invertido(palavra,tam);
    return 0;
}