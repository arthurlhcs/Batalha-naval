#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função auxiliar para verificar se há sobreposição
int verificaSobreposicao(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == NAVIO;
}

int main() {
    // =====================================
    // 1. INICIALIZAÇÃO DO TABULEIRO 10x10
    // =====================================
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Preenche todo o tabuleiro com "0", representando água
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // =====================================
    // 2. POSICIONAMENTO DOS NAVIOS
    // =====================================

    // --- NAVIO 1: Horizontal ---
    int linH = 1, colH = 2; // coordenadas iniciais
    if (colH + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (verificaSobreposicao(tabuleiro, linH, colH + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linH][colH + i] = NAVIO;
            }
        }
    }

    // --- NAVIO 2: Vertical ---
    int linV = 4, colV = 6;
    if (linV + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (verificaSobreposicao(tabuleiro, linV + i, colV)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linV + i][colV] = NAVIO;
            }
        }
    }

    // --- NAVIO 3: Diagonal Principal ( \ ) ---
    int linD1 = 0, colD1 = 0;
    if (linD1 + TAM_NAVIO <= TAM_TABULEIRO && colD1 + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (verificaSobreposicao(tabuleiro, linD1 + i, colD1 + i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linD1 + i][colD1 + i] = NAVIO;
            }
        }
    }

    // --- NAVIO 4: Diagonal Secundária ( / ) ---
    int linD2 = 2, colD2 = 9;
    if (linD2 + TAM_NAVIO <= TAM_TABULEIRO && colD2 - TAM_NAVIO + 1 >= 0) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (verificaSobreposicao(tabuleiro, linD2 + i, colD2 - i)) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linD2 + i][colD2 - i] = NAVIO;
            }
        }
    }

    // =====================================
    // 3. IMPRESSÃO DO TABULEIRO
    // =====================================
    printf("\n===== TABULEIRO DE BATALHA NAVAL =====\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
