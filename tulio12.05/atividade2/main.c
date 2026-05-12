#include "tarefas.h"
#include <stdio.h>
#include <string.h>

int main() {
    PilhaTarefas pilha;
    inicializarPilha(&pilha);
    int opcao;
    char descricao[MAX_TAREFA];

    do {
        printf("\n--- Gerenciador de Tarefas ---\n");
        printf("1. Inserir tarefa na pilha\n");
        printf("2. Obter a proxima tarefa da pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            // Se ler algo não numérico, limpa e continua
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); // Limpar o buffer do teclado (newline)

        switch (opcao) {
            case 1:
                printf("Digite a descricao da tarefa: ");
                if (fgets(descricao, MAX_TAREFA, stdin) != NULL) {
                    descricao[strcspn(descricao, "\n")] = 0; // Remover o \n
                    push(&pilha, descricao);
                }
                break;
            case 2:
                pop(&pilha);
                break;
            case 0:
                printf("Encerrando programa...\n");
                liberarPilha(&pilha);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
