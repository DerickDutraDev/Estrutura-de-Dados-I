#include <stdio.h>

int main() {
    int linhas, colunas;
    int contadorPares = 0;

    printf("--- Contagem de Números Pares ---\n");
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
            
            if (matriz[i][j] % 2 == 0) {
                contadorPares++;
            }
        }
    }

    printf("\nA matriz contém %d número(s) pare(s).\n", contadorPares);

    return 0;
}
