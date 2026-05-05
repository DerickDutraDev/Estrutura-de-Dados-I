#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct No {
    int valor;
    struct No* proximo;
} No;


typedef struct Fila {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;


Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}


bool fila_vazia(Fila* f) {
    if (f == NULL) return true;
    return f->inicio == NULL;
}


void inserir(Fila* f, int valor) {
    if (f == NULL) return;
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (fila_vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
    f->tamanho++;
}


bool remover(Fila* f, int* valor_removido) {
    if (fila_vazia(f)) return false;
    
    No* temp = f->inicio;
    if (valor_removido != NULL) {
        *valor_removido = temp->valor;
    }
    
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    f->tamanho--;
    return true;
}


void exibir_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    No* atual = f->inicio;
    printf("Elementos da fila: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}


int contar_elementos(Fila* f) {
    if (f == NULL) return 0;
    return f->tamanho;
}


bool consultar_primeiro(Fila* f, int* primeiro) {
    if (fila_vazia(f)) return false;
    if (primeiro != NULL) {
        *primeiro = f->inicio->valor;
    }
    return true;
}

int main() {
    printf("=== Teste da Fila Simples ===\n");
    Fila* minha_fila = criar_fila();
    
    inserir(minha_fila, 10);
    inserir(minha_fila, 20);
    inserir(minha_fila, 30);
    
    exibir_fila(minha_fila);
    printf("Quantidade de elementos: %d\n", contar_elementos(minha_fila));
    
    int primeiro;
    if (consultar_primeiro(minha_fila, &primeiro)) {
        printf("Primeiro elemento (sem remover): %d\n", primeiro);
    }
    
    int removido;
    if (remover(minha_fila, &removido)) {
        printf("Elemento removido: %d\n", removido);
    }
    
    exibir_fila(minha_fila);
    printf("Quantidade de elementos agora: %d\n", contar_elementos(minha_fila));
    
    return 0;
}
