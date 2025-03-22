#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho fixo dos navios
    int tamanho_navio = 3;

    // Posicionamento do navio horizontal (linha 1, coluna 2)
    int horiz_linha = 1;
    int horiz_col = 2;
    for(i = 0; i < tamanho_navio; i++){
        tabuleiro[horiz_linha][horiz_col + i] = 3;
    }

    // Posicionamento do navio vertical (linha 5, coluna 7)
    int vert_linha = 5;
    int vert_col = 7;
    for(i = 0; i < tamanho_navio; i++){
        tabuleiro[vert_linha + i][vert_col] = 3;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
