#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* next;
} No;

No* head = NULL;

No* criar_no(int val) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = val;
    novo->next = NULL;
    return novo;
}

void inserirNoInicio(int val) {
    No* novo = criar_no(val);
    novo->next = head;
    head = novo;
}

void removerPrimeiro() {
    if (head == NULL) {
        printf("Lista vazia!\\n");
        return;
    }
    No* temp = head;
    head = head->next;
    free(temp);
    printf("Primeiro elemento removido!\\n");
}

void exibirLista() {
    if (head == NULL) {
        printf("Lista vazia!\\n");
        return;
    }
    No* atual = head;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->next;
    }
    printf("\\n");
}

void liberar() {
    while (head != NULL) {
        No* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        int val;
        printf("Insira numero %d: ", i+1);
        scanf("%d", &val);
        inserirNoInicio(val);
    }
    printf("Antes da remocao:\\n");
    exibirLista();
    removerPrimeiro();
    printf("Depois da remocao:\\n");
    exibirLista();
    liberar();
    return 0;
}
