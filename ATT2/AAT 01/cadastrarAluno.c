#include <stdio.h>
#include "turma.h"

void cadastrarAlunoEmTurma(Turma turmas[], int qtdTurmas) {
    int codigo;

    printf("Informe o código da turma: ");
    scanf("%d", &codigo);
    while (getchar() != '\n');

    for (int i = 0; i < qtdTurmas; i++) {
        if (turmas[i].codigo == codigo) {

            if (turmas[i].quantidadeAlunos >= MAX_ALUNOS) {
                printf("Turma cheia!\n");
                return;
            }

            Aluno *a = &turmas[i].alunos[turmas[i].quantidadeAlunos];

            printf("ID do aluno: ");
            scanf("%d", &a->id);
            while (getchar() != '\n');

            printf("Nome do aluno: ");
            fgets(a->nome, 50, stdin);

            printf("Nota do aluno: ");
            scanf("%f", &a->nota);
            while (getchar() != '\n');

            turmas[i].quantidadeAlunos++;
            printf("Aluno cadastrado com sucesso!\n");
            return;
        }
    }

    printf("Turma não encontrada!\n");
}

void listarAlunosDaTurma(Turma turmas[], int qtdTurmas) {
    int codigo;

    printf("Informe o código da turma: ");
    scanf("%d", &codigo);
    while (getchar() != '\n');

    for (int i = 0; i < qtdTurmas; i++) {
        if (turmas[i].codigo == codigo) {

            printf("\nTurma: %s", turmas[i].nome);
            printf("Alunos cadastrados:\n");

            for (int j = 0; j < turmas[i].quantidadeAlunos; j++) {
                printf(
                    "ID: %d | Nome: %s | Nota: %.2f\n",
                    turmas[i].alunos[j].id,
                    turmas[i].alunos[j].nome,
                    turmas[i].alunos[j].nota
                );
            }
            return;
        }
    }

    printf("Turma não encontrada!\n");
}
