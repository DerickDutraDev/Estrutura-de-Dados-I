#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10

int main() {
    int N;
    int matriz[MAX_N][MAX_N];
    int i, j;
    int soma_diag_principal = 0;
    int soma_diag_secundaria = 0;
    int soma_total = 0;
    float media_matriz;
    int acima_media = 0;
    bool simetrica = true;

    printf("Digite o tamanho da matriz quadrada (max. %d): ", MAX_N);
    scanf("%d", &N);

    if (N > MAX_N || N <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    printf("--- Leitura da Matriz %dx%d ---\n", N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("  Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            
            soma_total += matriz[i][j];
            
            if (i == j) {
                soma_diag_principal += matriz[i][j];
            }
            if (i + j == N - 1) {
                soma_diag_secundaria += matriz[i][j];
            }
        }
    }

    media_matriz = (float)soma_total / (N * N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (matriz[i][j] > media_matriz) {
                acima_media++;
            }
            if (matriz[i][j] != matriz[j][i]) {
                simetrica = false;
            }
        }
    }

    printf("\n--- Resultados ---\n");
    printf("Soma da diagonal principal: %d\n", soma_diag_principal);
    printf("Soma da diagonal secundaria: %d\n", soma_diag_secundaria);
    printf("Media da matriz: %.2f\n", media_matriz);
    printf("Elementos acima da media: %d\n", acima_media);
    printf("A matriz e simetrica? %s\n", simetrica ? "Sim" : "Nao");

    printf("\n--- Matriz ---\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
