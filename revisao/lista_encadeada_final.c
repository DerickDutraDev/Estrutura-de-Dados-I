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

void inserirNoFinal(int val) {
    No* novo = criar_no(val);
    if (head == NULL) {
        head = novo;
        return;
    }
    No* atual = head;
    while (atual->next != NULL) {
        atual = atual->next;
    }
    atual->next = novo;
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

int contarElementos() {
    int cont = 0;
    No* atual = head;
    while (atual != NULL) {
        cont++;
        atual = atual->next;
    }
    return cont;
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
        inserirNoFinal(val);
    }
    exibirLista();
    printf("Quantidade de elementos: %d\\n", contarElementos());
    liberar();
    return 0;
}
