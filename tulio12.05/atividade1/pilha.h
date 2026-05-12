#ifndef PILHA_H
#define PILHA_H

/*registro que representara cada elemento da pilha*/
typedef struct Elemento {
    int num;
    struct Elemento *prox;
} Elemento;

/*registro do tipo Pilha contento um ponteiro "topo" do tipo Elemento para controlar a pilha*/
typedef struct Pilha {
    Elemento *topo; /*aponta para o elemento que esta no topo da pilha*/
} Pilha;

/* Prototipos das funcoes */
Pilha *cria_pilha();
void insere_elemento(Pilha *pi);
void consulta_pilha(Pilha *pi);
void remove_elemento_pilha(Pilha *pi);
void esvazia_pilha(Pilha *pi);

#endif // PILHA_H
