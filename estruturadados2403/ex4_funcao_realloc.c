#include <stdio.h>
#include <stdlib.h>

void alocarVetor(int **ptr, int tam) {
    *ptr = (int *)calloc(tam, sizeof(int));
    if (*ptr == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
}

void exibirVetor(int *v, int tam) {
    printf("Vetor: [ ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

int main() {
    int *vetor = NULL;
    int tam, i;

    printf("Digite o tamanho inicial do vetor: ");
    scanf("%d", &tam);

    alocarVetor(&vetor, tam);

    printf("\nPreenchendo o vetor inicial:\n");
    for (i = 0; i < tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("\nValores iniciais:\n");
    exibirVetor(vetor, tam);

    int novoTam;
    printf("\nDigite o novo tamanho para o redimensionamento (realloc): ");
    scanf("%d", &novoTam);

    int *temp = (int *)realloc(vetor, novoTam * sizeof(int));
    if (temp == NULL) {
        printf("Erro no realloc! A memória original ainda existe.\n");
    } else {
        vetor = temp;
        
        if (novoTam > tam) {
            printf("\nPreenchendo os novos %d elementos:\n", novoTam - tam);
            for (i = tam; i < novoTam; i++) {
                printf("Elemento %d: ", i + 1);
                scanf("%d", &vetor[i]);
            }
        }
        
        tam = novoTam;
    }

    printf("\nValores após realloc:\n");
    exibirVetor(vetor, tam);

    free(vetor);

    return 0;
}
