#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_TAREFA 100

// Nó da pilha
typedef struct No {
    char descricao[MAX_TAREFA];
    struct No* prox;
} No;

// Estrutura da Pilha
typedef struct {
    No* topo;
} PilhaTarefas;

void inicializarPilha(PilhaTarefas* p);
int pilhaVazia(PilhaTarefas* p);
void push(PilhaTarefas* p, const char* descricao);
void pop(PilhaTarefas* p);
void liberarPilha(PilhaTarefas* p);

#endif // TAREFAS_H
