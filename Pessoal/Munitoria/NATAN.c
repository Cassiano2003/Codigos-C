#include <stdio.h>

int main(){
    int estudantes;
    printf("Digite a quantidade de estudantes: ");
    scanf("%d", &estudantes);

    int acertos[estudantes];
    char caracteres[estudantes][20];
    for (int i = 0; i < estudantes; i++) {
        acertos[i] = 0; 
    }

    char gabarito[20] = {'A', 'E', 'B', 'D', 'E', 'A', 'B', 'D', 'E', 'D', 'A', 'E', 'B', 'D', 'E', 'A', 'B', 'D', 'E', 'D'};

    for(int i = 0; i < estudantes; i++){
        printf("Respostas do Estudante %d (digite 20 caracteres separados por espaco):\n", i + 1);
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

    return 0;
}