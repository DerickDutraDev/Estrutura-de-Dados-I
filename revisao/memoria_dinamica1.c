#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    printf("Tamanho inicial N: ");
    scanf("%d", &N);
    
    int *vetor = (int*)malloc(N * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocacao!\\n");
        return 1;
    }
    
    printf("Novo tamanho M: ");
    scanf("%d", &M);
    
    vetor = (int*)realloc(vetor, M * sizeof(int));
    if (vetor == NULL) {
        printf("Erro no realloc!\\n");
        free(vetor);
        return 1;
    }
    
    printf("Insira %d valores:\\n", M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &vetor[i]);
    }
    
    printf("Elementos: ");
    for (int i = 0; i < M; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\\n");
    
    free(vetor);
    return 0;
}
