#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *cria_fila(void)
{
    Fila *fi = malloc(sizeof(Fila));
    if (fi != NULL)
    {
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

void libera_fila(Fila *fi)
{
    if (fi == NULL)
    {
        return;
    }

    Cliente *atual = fi->inicio;
    while (atual != NULL)
    {
        Cliente *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(fi);
}

void insere_cliente(Fila *fi, int id, int tempoEstimado)
{
    if (fi == NULL)
    {
        return;
    }

    Cliente *novo = malloc(sizeof(Cliente));
    if (novo == NULL)
    {
        printf("Falha ao alocar memoria para o cliente.\n");
        return;
    }

    novo->id = id;
    novo->tempoEstimado = tempoEstimado;
    novo->prox = NULL;

    if (fi->inicio == NULL)
    {
        fi->inicio = novo;
        fi->fim = novo;
    }
    else
    {
        fi->fim->prox = novo;
        fi->fim = novo;
    }

    printf("Cliente %d adicionado na fila com tempo estimado de atendimento %d minutos.\n", id, tempoEstimado);
}

bool fila_vazia(const Fila *fi)
{
    return fi == NULL || fi->inicio == NULL;
}

void atende_cliente(Fila *fi)
{
    if (fila_vazia(fi))
    {
        printf("Nao ha clientes na fila para atendimento.\n");
        return;
    }

    Cliente *remover = fi->inicio;
    printf("Atendendo cliente %d (tempo estimado: %d minutos).\n", remover->id, remover->tempoEstimado);
    fi->inicio = fi->inicio->prox;
    if (fi->inicio == NULL)
    {
        fi->fim = NULL;
    }
    free(remover);
}

void exibe_fila(const Fila *fi)
{
    if (fila_vazia(fi))
    {
        printf("Fila de espera vazia.\n");
        return;
    }

    printf("Fila de clientes em espera:\n");
    printf("ID\tTempo estimado\n");

    Cliente *atual = fi->inicio;
    while (atual != NULL)
    {
        printf("%d\t%d\n", atual->id, atual->tempoEstimado);
        atual = atual->prox;
    }
}

int tempo_espera_total(const Fila *fi)
{
    int total = 0;
    Cliente *atual = fi->inicio;
    while (atual != NULL)
    {
        total += atual->tempoEstimado;
        atual = atual->prox;
    }
    return total;
}
