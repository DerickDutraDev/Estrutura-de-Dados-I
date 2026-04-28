#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

static void exibir_menu(void)
{
    printf("\n--- SIMULACAO DE BANCO ---\n");
    printf("1. Inserir cliente na fila\n");
    printf("2. Atender proximo cliente\n");
    printf("3. Exibir fila de espera\n");
    printf("4. Exibir tempo total de espera\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main(void)
{
    Fila *fi = cria_fila();
    if (fi == NULL)
    {
        printf("Nao foi possivel criar a fila.\n");
        return 1;
    }

    int opcao = -1;
    while (opcao != 0)
    {
        exibir_menu();
        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida. Tente novamente.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (opcao)
        {
            case 1:
            {
                int id, tempo;
                printf("Digite o numero de identificacao do cliente: ");
                scanf("%d", &id);
                printf("Digite o tempo estimado de atendimento (minutos): ");
                scanf("%d", &tempo);
                insere_cliente(fi, id, tempo);
                break;
            }
            case 2:
                atende_cliente(fi);
                break;
            case 3:
                exibe_fila(fi);
                break;
            case 4:
                printf("Tempo total de espera dos clientes: %d minutos\n", tempo_espera_total(fi));
                break;
            case 0:
                printf("Encerrando o sistema.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    libera_fila(fi);
    return 0;
}
