#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Quantidade N de numeros: ");
    scanf("%d", &N);
    
    int *vetor = (int*)malloc(N * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocacao!\\n");
        return 1;
    }
    
    printf("Insira %d numeros:\\n", N);
    long long soma = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }
    
    double media = (double)soma / N;
    printf("Soma total: %lld\\n", soma);
    printf("Media: %.2f\\n", media);
    
    free(vetor);
    return 0;
}
