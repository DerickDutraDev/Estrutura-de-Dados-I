#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, i;
    float *notas;
    float soma = 0, media, maior, menor;

    printf("Digite a quantidade de alunos: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade inválida!\n");
        return 1;
    }

    notas = (float *)malloc(n * sizeof(float));

    if (notas == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];

        if (i == 0) {
            maior = menor = notas[i];
        } else {
            if (notas[i] > maior) maior = notas[i];
            if (notas[i] < menor) menor = notas[i];
        }
    }

    media = soma / n;

    printf("\n--- Resultados ---\n");
    printf("Média da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
    free(notas);

    return 0;
}
