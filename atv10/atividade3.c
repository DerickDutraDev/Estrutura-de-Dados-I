#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tarefa {
    char descricao[200];
    char prioridade[10]; 
    char status[20];    
    struct Tarefa* prev;
    struct Tarefa* next;
} Tarefa;

Tarefa* head = NULL;
Tarefa* tail = NULL;

Tarefa* criar_tarefa(char* desc, char* prio, char* stat) {
    Tarefa* nova = (Tarefa*)malloc(sizeof(Tarefa));
    strcpy(nova->descricao, desc);
    strcpy(nova->prioridade, prio);
    strcpy(nova->status, stat);
    nova->prev = NULL;
    nova->next = NULL;
    return nova;
}

void inserir_final() {
    char desc[200], prio[10], stat[20];
    printf("Descricao: ");
    scanf(" %199[^\\n]", desc);
    printf("Prioridade (baixa/media/alta): ");
    scanf(" %9[^\\n]", prio);
    printf("Status (pendente/concluida): ");
    scanf(" %19[^\\n]", stat);
    Tarefa* nova = criar_tarefa(desc, prio, stat);
    if (tail == NULL) {
        head = tail = nova;
    } else {
        tail->next = nova;
        nova->prev = tail;
        tail = nova;
    }
    printf("Tarefa inserida!\\n");
}

void remover(char* desc_busca) {
    Tarefa* atual = head;
    while (atual != NULL) {
        if (strcmp(atual->descricao, desc_busca) == 0) {
            if (atual == head && atual == tail) {
                head = tail = NULL;
            } else if (atual == head) {
                head = head->next;
                head->prev = NULL;
            } else if (atual == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                atual->prev->next = atual->next;
                atual->next->prev = atual->prev;
            }
            free(atual);
            printf("Tarefa removida!\\n");
            return;
        }
        atual = atual->next;
    }
    printf("Tarefa nao encontrada!\\n");
}

void exibir_inicio_fim() {
    if (head == NULL) {
        printf("Lista vazia!\\n");
        return;
    }
    printf("\\n--- Lista Inicio -> Fim ---\\n");
    Tarefa* atual = head;
    while (atual != NULL) {
        printf("Desc: %s | Pri: %s | Stat: %s\\n", atual->descricao, atual->prioridade, atual->status);
        atual = atual->next;
    }
}

void exibir_fim_inicio() {
    if (tail == NULL) {
        printf("Lista vazia!\\n");
        return;
    }
    printf("\\n--- Lista Fim -> Inicio ---\\n");
    Tarefa* atual = tail;
    while (atual != NULL) {
        printf("Desc: %s | Pri: %s | Stat: %s\\n", atual->descricao, atual->prioridade, atual->status);
        atual = atual->prev;
    }
}

void liberar_memoria() {
    Tarefa* atual = head;
    while (atual != NULL) {
        Tarefa* temp = atual;
        atual = atual->next;
        free(temp);
    }
    head = tail = NULL;
}

int main() {
    int op;
    char desc[200];
    while (1) {
        printf("\\n=== GERENCIADOR DE TAREFAS ===\\n");
        printf("1. Inserir final\\n");
        printf("2. Remover\\n");
        printf("3. Exibir inicio->fim\\n");
        printf("4. Exibir fim->inicio\\n");
        printf("5. Sair\\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: inserir_final(); break;
            case 2: 
                printf("Descricao a remover: ");
                scanf(" %199[^\\n]", desc);
                remover(desc); 
                break;
            case 3: exibir_inicio_fim(); break;
            case 4: exibir_fim_inicio(); break;
            case 5: liberar_memoria(); return 0;
            default: printf("Opcao invalida!\\n");
        }
    }
    return 0;
}
