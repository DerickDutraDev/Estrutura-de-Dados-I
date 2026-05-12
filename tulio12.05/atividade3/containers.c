#include "containers.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarPilha(PilhaContainers* p) {
    p->topo = NULL;
}

int pilhaVazia(PilhaContainers* p) {
    return (p->topo == NULL);
}

void push(PilhaContainers* p, Container c) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }
    novo->container = c;
    novo->prox = p->topo;
    p->topo = novo;
    printf("Container %d (%s) inserido com sucesso.\n", c.id, c.nome);
}

void pop(PilhaContainers* p) {
    if (pilhaVazia(p)) {
        printf("A pilha de containers esta vazia.\n");
        return;
    }
    No* temp = p->topo;
    printf("Container desembarcado:\n");
    printf("ID: %d | Nome: %s | Destino: %s\n", temp->container.id, temp->container.nome, temp->container.destino);
    p->topo = p->topo->prox;
    free(temp);
}

void exibirTodos(PilhaContainers* p) {
    if (pilhaVazia(p)) {
        printf("A pilha de containers esta vazia.\n");
        return;
    }
    printf("\n--- Containers Aguardando Desembarque ---\n");
    No* atual = p->topo;
    while (atual != NULL) {
        printf("ID: %d | Nome: %s | Destino: %s\n", atual->container.id, atual->container.nome, atual->container.destino);
        atual = atual->prox;
    }
    printf("-----------------------------------------\n");
}

void proximoContainer(PilhaContainers* p) {
    if (pilhaVazia(p)) {
        printf("A pilha de containers esta vazia.\n");
        return;
    }
    printf("\nProximo container a ser desempilhado:\n");
    printf("ID: %d | Nome: %s | Destino: %s\n", p->topo->container.id, p->topo->container.nome, p->topo->container.destino);
}

void liberarMemoria(PilhaContainers* p) {
    while (!pilhaVazia(p)) {
        No* temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
    }
    printf("Memoria liberada com sucesso.\n");
}
