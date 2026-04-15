#include <stdio.h>

#define SETORES 2
#define PRODUTOS 3

int main() {
    int estoque[SETORES][PRODUTOS];
    int soma_setores[SETORES] = {0};
    int soma_produtos[PRODUTOS] = {0};
    int i, j;

    // Nomes dos setores
    char setores[SETORES][20] = {"Almoxarifado", "Informatica"};

    // Nomes dos produtos
    char produtos[PRODUTOS][20] = {"Produto 1", "Produto 2", "Produto 3"};

    // Entrada de dados
    printf("--- Cadastro de Estoque ---\n");
    for (i = 0; i < SETORES; i++) {
        printf("\nSetor: %s\n", setores[i]);
        for (j = 0; j < PRODUTOS; j++) {
            printf("Quantidade de %s: ", produtos[j]);
            scanf("%d", &estoque[i][j]);

            soma_setores[i] += estoque[i][j];
            soma_produtos[j] += estoque[i][j];
        }
    }

    // Exibir matriz com identificação
    printf("\n--- Estoque por Setor ---\n");
    for (i = 0; i < SETORES; i++) {
        printf("%s:\n", setores[i]);
        for (j = 0; j < PRODUTOS; j++) {
            printf("  %s: %d\n", produtos[j], estoque[i][j]);
        }
        printf("  Total do setor: %d\n", soma_setores[i]);
    }

    // Soma total por produto (colunas)
    printf("\n--- Total por Produto (todos os setores) ---\n");
    for (j = 0; j < PRODUTOS; j++) {
        printf("%s: %d\n", produtos[j], soma_produtos[j]);
    }

    return 0;
}