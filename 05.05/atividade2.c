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
    printf("[ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}


void inserir_normal(Fila* f, int valor) {
    if (f == NULL) return;
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return;
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


void inserir_prioridade(Fila* f, int valor) {
    if (f == NULL) return;
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return;
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (fila_vazia(f) || valor < f->inicio->valor) {
        novo->proximo = f->inicio;
        f->inicio = novo;
        if (f->fim == NULL) {
            f->fim = novo;
        }
    } else {
        No* atual = f->inicio;
        while (atual->proximo != NULL && atual->proximo->valor <= valor) {
            atual = atual->proximo;
        }
        
        novo->proximo = atual->proximo;
        atual->proximo = novo;
        
        if (novo->proximo == NULL) {
            f->fim = novo;
        }
    }
    f->tamanho++;
}

void inverter_fila(Fila* f) {
    if (fila_vazia(f)) {
        return;
    }
    int valor;
    remover(f, &valor);
    inverter_fila(f);
 * e invertemos a fila com elegância e complexidade O(N).
 */
void inverter_fila(Fila* f) {
    if (fila_vazia(f)) {
        return;
    }
    int valor;
    remover(f, &valor);
    inverter_fila(f);
    inserir_normal(f, valor); 
}

Fila* copiar_fila(Fila* original) {
    Fila* copia = criar_fila();
    if (original == NULL || fila_vazia(original)) return copia;
    
    No* atual = original->inicio;
    while (atual != NULL) {
        inserir_normal(copia, atual->valor);
        atual = atual->proximo;
    }
    return copia;
}

Fila* concatenar_filas(Fila* f1, Fila* f2) {
    Fila* resultado = criar_fila();
    
    if (f1 != NULL) {
        No* atual = f1->inicio;
        while (atual != NULL) {
            inserir_normal(resultado, atual->valor);
            atual = atual->proximo;
        }
    }
    
    if (f2 != NULL) {
        No* atual = f2->inicio;
        while (atual != NULL) {
            inserir_normal(resultado, atual->valor);
            atual = atual->proximo;
        }
    }
    
    return resultado;
}

int main() {
    printf("=== Atividade 2 ===\n\n");
    

    printf("1. Fila de Prioridade (menor valor = maior prioridade):\n");
    Fila* fila_prio = criar_fila();
    inserir_prioridade(fila_prio, 30);
    inserir_prioridade(fila_prio, 10);
    inserir_prioridade(fila_prio, 20);
    inserir_prioridade(fila_prio, 5);
    exibir_fila(fila_prio); 
    
 
    printf("\n2. Inverter Fila:\n");
    printf("Antes da inversao: ");
    exibir_fila(fila_prio);
    inverter_fila(fila_prio);
    printf("Depois da inversao: ");
    exibir_fila(fila_prio);
    

    printf("\n3. Copiar Fila:\n");
    Fila* copia = copiar_fila(fila_prio);
    printf("Fila Original: ");
    exibir_fila(fila_prio);
    printf("Fila Copiada:  ");
    exibir_fila(copia);
    
    printf("\n4. Concatenar Filas:\n");
    Fila* f3 = criar_fila();
    inserir_normal(f3, 100);
    inserir_normal(f3, 200);
    printf("Fila A: ");
    exibir_fila(copia);
    printf("Fila B: ");
    exibir_fila(f3);
    
    Fila* f_concat = concatenar_filas(copia, f3);
    printf("Fila Concatenada: ");
    exibir_fila(f_concat);
    
    return 0;
}
