#include <stdio.h>
#include <string.h>
#include "vendas.h"

Produto criar_produto(int cod, char* nome, float preco) {
    Produto p;
    p.codigo = cod;
    strcpy(p.nome, nome);
    p.preco = preco;
    return p;
}

Cliente criar_cliente(int id, char* nome) {
    Cliente c;
    c.id = id;
    strcpy(c.nome, nome);
    return c;
}

Venda iniciar_venda(Cliente c) {
    Venda v;
    v.cliente = c;
    v.qtd_produtos = 0;
    v.valor_total = 0;
    return v;
}

void adicionar_produto(Venda* v, Produto p) {
    if (v->qtd_produtos < MAX_PRODUTOS_VENDA) {
        v->produtos[v->qtd_produtos] = p;
        v->qtd_produtos++;
        v->valor_total += p.preco;
    }
}

void exibir_venda(Venda v) {
    printf("\n--- TOTAL DA VENDA ---\n");
    printf("Cliente: %s\n", v.cliente.nome);
    printf("Total: R$ %.2f\n", v.valor_total);
}