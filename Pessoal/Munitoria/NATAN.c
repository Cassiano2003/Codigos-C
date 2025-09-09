#include <stdio.h>

int main(){
    int estudantes,i=1;
    while (1){
        scanf(" %d", &estudantes);
        if(estudantes == 0) break;
        printf("\n------CASO DE TESTE %d------\n",i);
        int acertos[estudantes];
        char caracteres[estudantes][20];
        for (int i = 0; i < estudantes; i++) {
            acertos[i] = 0; 
        }
        char gabarito[20] = {'A', 'E', 'B', 'D', 'E', 'A', 'B', 'D', 'E', 'D', 'A', 'E', 'B', 'D', 'E', 'A', 'B', 'D', 'E', 'D'};

        for(int i = 0; i < estudantes; i++){
            for(int j = 0; j < 20; j++){
                scanf(" %c", &caracteres[i][j]);
                if (caracteres[i][j] == gabarito[j]){
                    acertos[i] = acertos[i] + 1;
                }
            }
        }
        
        printf("\n--- Resultados ---\n");
        for(int i = 0; i < estudantes; i++){
            printf("\nO estudante %d teve %d acertos.\n", i + 1, acertos[i]);
            printf("Respostas do estudante:\n");
            for(int j = 0; j < 20; j++){
                printf("%c ", caracteres[i][j]);
            }
            printf("\n");
        }
        i++;
    }
    

    return 0;
}