#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Inicializa todas as posições com 0 (água)
        }
    }
}

void posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // Posiciona o navio horizontalmente
    }
}

void posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // Posiciona o navio verticalmente
    }
}

void posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 1) {
            tabuleiro[linha + i][coluna + i] = 3; // Diagonal principal
        } else {
            tabuleiro[linha + i][coluna - i] = 3; // Diagonal secundária
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[][5], int tamanhoHabilidade, int linhaOrigem, int colunaOrigem) {
    int offset = tamanhoHabilidade / 2;

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            int linha = linhaOrigem + i - offset;
            int coluna = colunaOrigem + j - offset;
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5; // Marca a área afetada pela habilidade
                }
            }
        }
    }
}

void aplicarHabilidade5x3(int tabuleiro[TAMANHO][TAMANHO], int habilidade[5][3], int linhaOrigem, int colunaOrigem) {
    int tamanhoHabilidadeLinha = 5;
    int tamanhoHabilidadeColuna = 3;
    int offsetLinha = tamanhoHabilidadeLinha / 2;
    int offsetColuna = tamanhoHabilidadeColuna / 2;

    for (int i = 0; i < tamanhoHabilidadeLinha; i++) {
        for (int j = 0; j < tamanhoHabilidadeColuna; j++) {
            int linha = linhaOrigem + i - offsetLinha;
            int coluna = colunaOrigem + j - offsetColuna;
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5; // Marca a área afetada pela habilidade
                }
            }
        }
    }
}

void aplicarHabilidade3x3(int tabuleiro[TAMANHO][TAMANHO], int habilidade[3][3], int linhaOrigem, int colunaOrigem) {
    int tamanhoHabilidade = 3;
    int offset = tamanhoHabilidade / 2;

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            int linha = linhaOrigem + i - offset;
            int coluna = colunaOrigem + j - offset;
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5; // Marca a área afetada pela habilidade
                }
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   A B C D E F G H I J\n"); // Cabeçalho das colunas

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // Numeração das linhas

        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3;
    int linhaNavioVertical = 5, colunaNavioVertical = 7;
    int linhaNavioDiagonal1 = 0, colunaNavioDiagonal1 = 0;
    int linhaNavioDiagonal2 = 7, colunaNavioDiagonal2 = 9;

    // Posiciona os navios no tabuleiro
    posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
    posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);
    posicionarNavioDiagonal(tabuleiro, linhaNavioDiagonal1, colunaNavioDiagonal1, 1);
    posicionarNavioDiagonal(tabuleiro, linhaNavioDiagonal2, colunaNavioDiagonal2, 2);

    // Matrizes de habilidades
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][3] = {
        {0, 1, 0},
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0},
        {0, 1, 0}
    };

    int octaedro[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 5, 9, 2); // Aplica habilidade cone
    aplicarHabilidade5x3(tabuleiro, cruz, 2, 7); // Aplica habilidade cruz
    aplicarHabilidade3x3(tabuleiro, octaedro, 5, 2); // Aplica habilidade octaedro

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}