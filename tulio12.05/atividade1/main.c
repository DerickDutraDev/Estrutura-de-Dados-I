#include "pilha.h"
#include <stdio.h>

int main() {
    Pilha *pi = cria_pilha();

    insere_elemento(pi);
    insere_elemento(pi);
    insere_elemento(pi);
    consulta_pilha(pi);
    remove_elemento_pilha(pi);
    remove_elemento_pilha(pi);
    consulta_pilha(pi);
    esvazia_pilha(pi);
    
    return 0;
}
