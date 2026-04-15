#include <stdio.h>
#include "turma.h"

void cadastrarTurma(Turma turmas[], int *qtdTurmas) {
    if (*qtdTurmas >= MAX_TURMAS) {
        printf("Limite de turmas atingido!\n");
        return;
    }

    Turma *t = &turmas[*qtdTurmas];

    printf("Informe o código da Turma: ");
    scanf("%d", &t->codigo);
    getchar();

    printf("Informe o nome da Turma: ");
    fgets(t->nome, 50, stdin);

    t->quantidadeAlunos = 0;

    (*qtdTurmas)++;
    printf("Turma cadastrada com sucesso!\n");
}
