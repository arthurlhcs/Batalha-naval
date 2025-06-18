#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    // ========================
    // DECLARAÇÃO E INICIALIZAÇÃO DO TABULEIRO
    // ========================
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializando todas as posições do tabuleiro com 0 (água)
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // ========================
    // POSICIONAMENTO DOS NAVIOS
    // ========================

    // Vetores que representam os navios (só com valor 3)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais (definidas diretamente no código)
    // Exemplo: navio horizontal começa na linha 2, coluna 4
    int linhaInicialH = 2;
    int colunaInicialH = 4;

    // Exemplo: navio vertical começa na linha 5, coluna 1
    int linhaInicialV = 5;
    int colunaInicialV = 1;

    // Validação: Garantir que os navios estão dentro dos limites
    if (colunaInicialH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal sairia do tabuleiro!\n");
        return 1;
    }

    if (linhaInicialV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical sairia do tabuleiro!\n");
        return 1;
    }

    // Validação: Garantir que não há sobreposição entre navios
    int sobreposicao = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaInicialH][colunaInicialH + i] == NAVIO ||
            tabuleiro[linhaInicialV + i][colunaInicialV] == NAVIO) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: Navios sobrepostos!\n");
        return 1;
    }

    // Posicionando o navio horizontal no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaInicialH][colunaInicialH + i] = navioHorizontal[i];
    }

    // Posicionando o navio vertical no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaInicialV + i][colunaInicialV] = navioVertical[i];
    }

    // ========================
    // EXIBIÇÃO DO TABULEIRO
    // ========================
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]); // Espaço para melhor visualização
        }
        printf("\n"); // Quebra de linha após cada linha da matriz
    }

    return 0;
}
