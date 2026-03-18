#include <stdio.h>

int main() {
    int linhas, colunas;
    int soma = 0;

    printf("--- Soma dos Elementos da Matriz ---\n");
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    int matriz[linhas][colunas];

    printf("\nDigite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            soma += matriz[i][j];
        }
    }

    printf("\nA soma de todos os elementos da matriz é: %d\n", soma);

    return 0;
}
