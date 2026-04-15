#include <stdio.h>

int main() {
    int linhas, colunas;

    printf("--- Maior Elemento da Matriz ---\n");
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    int matriz[linhas][colunas];
    int maior;
    int maiorLinha = 0, maiorColuna = 0;

    printf("\nDigite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            
            if (i == 0 && j == 0) {
                maior = matriz[i][j];
                maiorLinha = i;
                maiorColuna = j;
            } else {
                if (matriz[i][j] > maior) {
                    maior = matriz[i][j];
                    maiorLinha = i;
                    maiorColuna = j;
                }
            }
        }
    }

    
    printf("\nO maior elemento da matriz é %d.\n", maior);
    printf("Posição: Linha %d, Coluna %d\n", maiorLinha, maiorColuna);

    return 0;
}
