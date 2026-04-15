#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Contato {
    char nome[100];
    char telefone[20];
    char email[100];
    struct Contato* next;
} Contato;

Contato* head = NULL;

Contato* criar_contato(char* n, char* t, char* e) {
    Contato* novo = (Contato*)malloc(sizeof(Contato));
    strcpy(novo->nome, n);
    strcpy(novo->telefone, t);
    strcpy(novo->email, e);
    novo->next = NULL;
    return novo;
}

void inserir_inicio() {
    char nome[100], tel[20], email[100];
    printf("Nome: ");
    scanf(" %99[^\\n]", nome);
    printf("Telefone: ");
    scanf(" %19[^\\n]", tel);
    printf("Email: ");
    scanf(" %99[^\\n]", email);
    Contato* novo = criar_contato(nome, tel, email);
    novo->next = head;
    head = novo;
    printf("Contato inserido!\\n");
}

void remover(char* nome_busca) {
    if (head == NULL) {
        printf("Lista vazia!\\n");
        return;
    }
    if (strcmp(head->nome, nome_busca) == 0) {
        Contato* temp = head;
        head = head->next;
        free(temp);
        printf("Contato removido!\\n");
        return;
    }
    Contato* atual = head;
    while (atual->next != NULL) {
        if (strcmp(atual->next->nome, nome_busca) == 0) {
            Contato* temp = atual->next;
            atual->next = temp->next;
            free(temp);
            printf("Contato removido!\\n");
            return;
        }
        atual = atual->next;
    }
    printf("Contato nao encontrado!\\n");
}

Contato* buscar(char* nome_busca) {
    Contato* atual = head;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome_busca) == 0) {
            return atual;
        }
        atual = atual->next;
    }
    return NULL;
}

void exibir() {
    if (head == NULL) {
        printf("Lista vazia!\\n");
        return;
    }
    printf("\\n--- Lista Telefonica ---\\n");
    Contato* atual = head;
    while (atual != NULL) {
        printf("Nome: %s\\n", atual->nome);
        printf("Telefone: %s\\n", atual->telefone);
        printf("Email: %s\\n\\n", atual->email);
        atual = atual->next;
    }
}

void liberar_memoria() {
    while (head != NULL) {
        Contato* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int op;
    char nome[100];
    while (1) {
        printf("\\n=== LISTA TELEFONICA ===\\n");
        printf("1. Inserir inicio\\n");
        printf("2. Remover\\n");
        printf("3. Buscar\\n");
        printf("4. Exibir\\n");
        printf("5. Sair\\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: inserir_inicio(); break;
            case 2: 
                printf("Nome a remover: ");
                scanf(" %99[^\\n]", nome);
                remover(nome); 
                break;
            case 3: 
                printf("Nome a buscar: ");
                scanf(" %99[^\\n]", nome);
                if (buscar(nome)) {
                    printf("Encontrado!\\n");
                } else {
                    printf("Nao encontrado!\\n");
                }
                break;
            case 4: exibir(); break;
            case 5: liberar_memoria(); return 0;
            default: printf("Opcao invalida!\\n");
        }
    }
}
