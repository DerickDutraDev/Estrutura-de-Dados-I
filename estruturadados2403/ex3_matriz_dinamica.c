#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, c, i, j;
    int **matriz;
    int maior;

    printf("Digite o número de linhas (L): ");
    scanf("%d", &l);
    printf("Digite o número de colunas (C): ");
    scanf("%d", &c);

    if (l <= 0 || c <= 0) {
        printf("Dimensões inválidas!\n");
        return 1;
    }

    matriz = (int **)malloc(l * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for (i = 0; i < l; i++) {
        matriz[i] = (int *)malloc(c * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro na alocação da linha %d!\n", i);
            return 1;
        }
    }

    printf("\nDigite os valores para a matriz %dx%d:\n", l, c);
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            if (i == 0 && j == 0) {
                maior = matriz[i][j];
            } else {
                if (matriz[i][j] > maior) maior = matriz[i][j];
            }
        }
    }

    printf("\n--- Soma por Linhas ---\n");
    for (i = 0; i < l; i++) {
        int somaLinha = 0;
        for (j = 0; j < c; j++) {
            somaLinha += matriz[i][j];
        }
        printf("Linha %d: %d\n", i, somaLinha);
    }

    printf("\nMaior elemento da matriz: %d\n", maior);

    for (i = 0; i < l; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
