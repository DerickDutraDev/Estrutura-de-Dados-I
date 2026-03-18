#include <stdio.h>

int main() {
    int n;
    int somaDiagonal = 0;

    printf("--- Soma da Diagonal Principal ---\n");
    printf("Digite a ordem da matriz quadrada (n x n): ");
    scanf("%d", &n);

    int matriz[n][n];

    printf("\nDigite os elementos da matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            
            if (i == j) {
                somaDiagonal += matriz[i][j];
            }
        }
    }

    printf("\nA soma da diagonal principal é: %d\n", somaDiagonal);

    return 0;
}
