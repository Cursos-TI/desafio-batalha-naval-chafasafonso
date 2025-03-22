#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0

// tabuleiro 
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d  ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser colocado sem sobreposição
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < 3; i++) {
        int r = linha + (diagonal == 1 ? i : (diagonal == 2 ? i : (direcao == 1 ? i : 0)));
        int c = coluna + (diagonal == 1 ? i : (diagonal == 2 ? -i : (direcao == 0 ? i : 0)));

        if (r >= TAMANHO || c >= TAMANHO || r < 0 || c < 0 || tabuleiro[r][c] != AGUA) {
            return 0; // Não pode posicionar
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < 3; i++) {
        int r = linha + (diagonal == 1 ? i : (diagonal == 2 ? i : (direcao == 1 ? i : 0)));
        int c = coluna + (diagonal == 1 ? i : (diagonal == 2 ? -i : (direcao == 0 ? i : 0)));
        tabuleiro[r][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa com água (0)

    // Posicionando dois navios horizontais/verticais
    if (podePosicionar(tabuleiro, 1, 2, 1, 0)) {
        posicionarNavio(tabuleiro, 1, 2, 1, 0); // Vertical
    }
    if (podePosicionar(tabuleiro, 5, 4, 0, 0)) {
        posicionarNavio(tabuleiro, 5, 4, 0, 0); // Horizontal
    }

    // Posicionando dois navios diagonais
    if (podePosicionar(tabuleiro, 7, 2, 0, 1)) {
        posicionarNavio(tabuleiro, 7, 2, 0, 1); // Diagonal principal "\"
    }
    if (podePosicionar(tabuleiro, 7, 7, 0, 2)) {
        posicionarNavio(tabuleiro, 7, 7, 0, 2); // Diagonal secundária "/"
    }

    // Exibir tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}

