#include "containers.h"
#include <stdio.h>
#include <string.h>

int main() {
    PilhaContainers pilha;
    inicializarPilha(&pilha);
    int opcao;
    Container c;

    do {
        printf("\n--- Porto: Gerenciamento de Pilha de Containers ---\n");
        printf("1. Inserir um container na pilha\n");
        printf("2. Desembarcar (remover) o container\n");
        printf("3. Exibir todos os containers aguardando desembarque\n");
        printf("4. Informar o proximo container a ser desempilhado\n");
        printf("0. Encerrar o programa\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); // Limpar o buffer

        switch (opcao) {
            case 1:
                printf("Digite o ID do container: ");
                scanf("%d", &c.id);
                getchar(); // Limpar o buffer
                
                printf("Digite o nome do container: ");
                if (fgets(c.nome, 50, stdin) != NULL)
                    c.nome[strcspn(c.nome, "\n")] = 0;
                
                printf("Digite o destino do container: ");
                if (fgets(c.destino, 50, stdin) != NULL)
                    c.destino[strcspn(c.destino, "\n")] = 0;
                
                push(&pilha, c);
                break;
            case 2:
                pop(&pilha);
                break;
            case 3:
                exibirTodos(&pilha);
                break;
            case 4:
                proximoContainer(&pilha);
                break;
            case 0:
                printf("Encerrando sistema do porto...\n");
                liberarMemoria(&pilha);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
