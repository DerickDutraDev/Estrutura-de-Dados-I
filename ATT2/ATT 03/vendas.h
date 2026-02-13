#ifndef VENDAS_H
#define VENDAS_H

#define MAX_PRODUTOS_VENDA 50

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    int id;
    char nome[50];
} Cliente;

typedef struct {
    Cliente cliente;
    Produto produtos[MAX_PRODUTOS_VENDA];
    int qtd_produtos;
    float valor_total;
} Venda;


Produto criar_produto(int cod, char* nome, float preco);
Cliente criar_cliente(int id, char* nome);
Venda iniciar_venda(Cliente c);
void adicionar_produto(Venda* v, Produto p);
void exibir_venda(Venda v);

#endif