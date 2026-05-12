#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Para a funcao getch()

Pilha *cria_pilha() {
    /*alocacao do ponteiro pi para controlar a pilha*/
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));
    if (pi != NULL) {
        pi->topo = NULL; /*a pilha inicia-se vazia, portanto seu topo e igual a NULL*/
    }
    return pi;
}

/*todo elemento sera inserido no topo da pilha*/
void insere_elemento(Pilha *pi) {
    /*a cada insercao alocamos dinamicamente um espaco para um novo elemento*/
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL) {
        printf("\nErro de alocacao!");
        return;
    }
    printf("\nDigite o numero a ser inserido na pilha: ");
    scanf("%d", &novo->num);
    /*como o numero inserido sera o novo topo, ele apontara para o topo atual que sera o segundo elemento da pilha*/
    novo->prox = pi->topo;
    /*topo aponta para o endereco de novo*/
    pi->topo = novo;
    printf("\nNumero inserido na pilha!");
    getch();
}

/*os elementos da pilha serao mostrados do ultimo inserido(topo) ao primeiro*/
void consulta_pilha(Pilha *pi) {
    /*caso a pilha esteja vazia*/
    if (pi->topo == NULL) {
        printf("\nPilha Vazia!!");
        /*caso a pilha nao esteja vazia*/
    } else {
        // Variavel aux agora e local, o que e uma boa pratica de software
        Elemento *aux = pi->topo;
        do {
            printf("\n %d ", aux->num);
            aux = aux->prox;
        } while (aux != NULL);
    }
    getch();
}

/*o elemento a ser removido sera sempre o topo(ultimo elemento inserido)*/
void remove_elemento_pilha(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("\nPilha Vazia!!");
    } else {
        Elemento *aux = pi->topo;
        printf("\n%d removido!", pi->topo->num);
        pi->topo = pi->topo->prox;
        free(aux);
    }
    getch();
}

/*a pilha sera esvaziada e o espaco ocupado por ela sera desalocado*/
void esvazia_pilha(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("\nPilha Vazia!!");
    } else {
        Elemento *aux = pi->topo;
        do {
            pi->topo = pi->topo->prox;
            free(aux);
            aux = pi->topo;
        } while (aux != NULL);
        printf("\nPilha Esvaziada!!");
    }
    getch();
}
