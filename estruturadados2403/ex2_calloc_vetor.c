#include <stdio.h>
#include <stdlib.h>

void exibirVetor(int *v, int n) {
    printf("Vetor: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

int main() {
    int n, i;
    int *vetor;

    printf("Digite o valor de N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("N inválido!\n");
        return 1;
    }
    vetor = (int *)calloc(n, sizeof(int));

    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    printf("\nVetor logo após alocação com calloc (inicializado com zeros):\n");
    exibirVetor(vetor, n);

    printf("\nDigite os %d novos valores:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor atualizado:\n");
    exibirVetor(vetor, n);

    free(vetor);

    return 0;
}
