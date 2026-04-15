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

int buscarElemento(int valor) {
    No* atual = head;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;  
        }
        atual = atual->next;
    }
    return 0;  
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
        inserirNoFinal(val);
    }
    exibirLista();
    int busca;
    printf("Numero a buscar: ");
    scanf("%d", &busca);
    if (buscarElemento(busca)) {
        printf("%d ESTA na lista!\\n", busca);
    } else {
        printf("%d NAO esta na lista!\\n", busca);
    }
    liberar();
    return 0;
}
