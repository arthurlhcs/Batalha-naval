#include <stdio.h>

#define TAM 10           // Tamanho do tabuleiro principal: 10x10
#define TAM_HAB 5        // Tamanho das habilidades: todas são 5x5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Mostra o tabuleiro na tela, com todos os elementos
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n====== TABULEIRO FINAL ======\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada célula do tabuleiro
        }
        printf("\n");
    }
}

// Função que aplica a área de efeito da habilidade no tabuleiro
// A matriz da habilidade é centralizada em uma posição escolhida (origem)
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int offset = TAM_HAB / 2; // O quanto a matriz se "espalha" para os lados do centro

    // Vamos percorrer cada posição da matriz da habilidade
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            // Calcula a posição real no tabuleiro onde queremos aplicar o efeito
            int linha = origemLinha - offset + i;
            int coluna = origemColuna - offset + j;

            // Antes de aplicar, verificamos se essa posição existe no tabuleiro
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                // Se for uma posição afetada pela habilidade (1) e não tiver navio, aplicamos
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != NAVIO) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Cria a matriz que representa um cone apontando para baixo
// Imagina uma pirâmide: começa fininha e vai ficando larga
void criarCone(int cone[TAM_HAB][TAM_HAB]) {
    // Primeiro zeramos tudo
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            cone[i][j] = 0;
        }
    }

    // Agora vamos "preencher" o cone expandindo a largura em cada linha
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = TAM_HAB / 2 - i; j <= TAM_HAB / 2 + i; j++) {
            if (j >= 0 && j < TAM_HAB) {
                cone[i][j] = 1; // Marca como área atingida
            }
        }
    }
}

// Cria uma cruz com centro e braços (linha do meio + coluna do meio)
void criarCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                cruz[i][j] = 1; // Linha ou coluna do meio
            } else {
                cruz[i][j] = 0; // Fora da cruz
            }
        }
    }
}

// Cria um losango (vista frontal de um octaedro)
void criarOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Usamos a distância de Manhattan para formar o losango
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Primeiro deixamos tudo como água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionamos 4 navios manualmente
    // 2 horizontais/verticais e 2 diagonais
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;
    tabuleiro[1][4] = NAVIO;

    tabuleiro[4][6] = NAVIO;
    tabuleiro[5][6] = NAVIO;
    tabuleiro[6][6] = NAVIO;

    tabuleiro[0][0] = NAVIO;
    tabuleiro[1][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;

    tabuleiro[2][7] = NAVIO;
    tabuleiro[3][6] = NAVIO;
    tabuleiro[4][5] = NAVIO;

    // Declaramos as três habilidades como matrizes 5x5
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // Criamos cada habilidade separadamente
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicamos as habilidades em três pontos diferentes do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone na parte superior
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz no meio do tabuleiro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro no canto inferior

    // Finalmente mostramos o tabuleiro completo com tudo aplicado
    imprimirTabuleiro(tabuleiro);

    return 0;
}
