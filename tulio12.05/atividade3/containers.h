#ifndef CONTAINERS_H
#define CONTAINERS_H

// Estrutura do Container
typedef struct {
    char nome[50];
    int id;
    char destino[50];
} Container;

// Nó da pilha
typedef struct No {
    Container container;
    struct No* prox;
} No;

// Estrutura da Pilha
typedef struct {
    No* topo;
} PilhaContainers;

void inicializarPilha(PilhaContainers* p);
int pilhaVazia(PilhaContainers* p);
void push(PilhaContainers* p, Container c);
void pop(PilhaContainers* p);
void exibirTodos(PilhaContainers* p);
void proximoContainer(PilhaContainers* p);
void liberarMemoria(PilhaContainers* p);

#endif // CONTAINERS_H
