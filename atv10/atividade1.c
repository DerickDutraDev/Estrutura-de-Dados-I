#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char nome[100];
    int quantidade;
    float preco_unitario;
} Item;

Item lista[MAX_ITEMS];
int tamanho = 0;

void inserir() {
    if (tamanho >= MAX_ITEMS) {
        printf("Lista cheia!\\n");
        return;
    }
    Item *novo = &lista[tamanho];
    printf("Nome do produto: ");
    scanf(" %99[^\\n]", novo->nome);
    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);
    printf("Preco unitario: ");
    scanf("%f", &novo->preco_unitario);
    tamanho++;
    printf("Produto inserido!\\n");
}

void remover() {
    char nome[100];
    printf("Nome do produto a remover: ");
    scanf(" %99[^\\n]", nome);
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            for (int j = i; j < tamanho - 1; j++) {
                lista[j] = lista[j + 1];
            }
            tamanho--;
            printf("Produto removido!\\n");
            return;
        }
    }
    printf("Produto nao encontrado!\\n");
}

void atualizar() {
    char nome[100];
    int nova_qtd;
    printf("Nome do produto: ");
    scanf(" %99[^\\n]", nome);
    printf("Nova quantidade: ");
    scanf("%d", &nova_qtd);
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            lista[i].quantidade = nova_qtd;
            printf("Quantidade atualizada!\\n");
            return;
        }
    }
    printf("Produto nao encontrado!\\n");
}

float total() {
    float tot = 0;
    for (int i = 0; i < tamanho; i++) {
        tot += lista[i].quantidade * lista[i].preco_unitario;
    }
    return tot;
}

void listar() {
    if (tamanho == 0) {
        printf("Lista vazia!\\n");
        return;
    }
    printf("\\n--- Lista de Compras ---\\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s: %d x R$%.2f = R$%.2f\\n", lista[i].nome, lista[i].quantidade, 
               lista[i].preco_unitario, lista[i].quantidade * lista[i].preco_unitario);
    }
    printf("Total: R$%.2f\\n", total());
}

int main() {
    int op;
    while (1) {
        printf("\\n=== LISTA DE COMPRAS ===\\n");
        printf("1. Inserir\\n");
        printf("2. Remover\\n");
        printf("3. Atualizar quantidade\\n");
        printf("4. Listar\\n");
        printf("5. Sair\\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: inserir(); break;
            case 2: remover(); break;
            case 3: atualizar(); break;
            case 4: listar(); break;
            case 5: return 0;
            default: printf("Opcao invalida!\\n");
        }
    }
}
