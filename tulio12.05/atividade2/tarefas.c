#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializa a pilha
void inicializarPilha(PilhaTarefas* p) {
    p->topo = NULL;
}

// Verifica se a pilha está vazia
int pilhaVazia(PilhaTarefas* p) {
    return (p->topo == NULL);
}

// Inserir tarefa na pilha
void push(PilhaTarefas* p, const char* descricao) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }
    strncpy(novo->descricao, descricao, MAX_TAREFA - 1);
    novo->descricao[MAX_TAREFA - 1] = '\0'; // Garantir terminação
    novo->prox = p->topo;
    p->topo = novo;
    printf("Tarefa inserida na pilha: %s\n", novo->descricao);
}

// Obter a próxima tarefa da pilha (remover e retornar)
void pop(PilhaTarefas* p) {
    if (pilhaVazia(p)) {
        printf("Nenhuma tarefa pendente na pilha.\n");
        return;
    }
    No* temp = p->topo;
    printf("Proxima tarefa obtida: %s\n", temp->descricao);
    p->topo = p->topo->prox;
    free(temp);
}

// Liberar memória da pilha ao sair
void liberarPilha(PilhaTarefas* p) {
    while (!pilhaVazia(p)) {
        No* temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
    }
}
