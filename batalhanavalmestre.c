#include <stdio.h>

#define TAMANHO 10
#define TAM_HAB 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para aplicar uma habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HAB][TAM_HAB], int x, int y) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int nx = x + i - TAM_HAB / 2;
            int ny = y + j - TAM_HAB / 2;
            if (nx >= 0 && nx < TAMANHO && ny >= 0 && ny < TAMANHO && habilidade[i][j] == 1) {
                tabuleiro[nx][ny] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    
    // Matriz Cone
    int cone[TAM_HAB][TAM_HAB] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    // Matriz Cruz
    int cruz[TAM_HAB][TAM_HAB] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    
    // Matriz Octaedro
    int octaedro[TAM_HAB][TAM_HAB] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    
    // Posicionando habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 7, 2);
    aplicarHabilidade(tabuleiro, octaedro, 6, 7);
    
    // Imprimir tabuleiro final
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}
