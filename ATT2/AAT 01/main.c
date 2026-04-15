#include <stdio.h>
#include "turma.h"

int main() {
    Turma turmas[MAX_TURMAS];
    int qtdTurmas = 0;
    int opcao;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Cadastrar Turma\n");
        printf("2 - Cadastrar Aluno em Turma\n");
        printf("3 - Listar Alunos da Turma\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTurma(turmas, &qtdTurmas);
                break;
            case 2:
                cadastrarAlunoEmTurma(turmas, qtdTurmas);
                break;
            case 3:
                listarAlunosDaTurma(turmas, qtdTurmas);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
