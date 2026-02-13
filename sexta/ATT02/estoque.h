#ifndef ESTOQUE_H
#define ESTOQUE_H

#define MAX_PRODUTOS 100
#define MAX_NOME 50

void adicionarProduto();
void atualizarQuantidade();
void removerProduto();
void listarProdutos();
int buscarIndice(int codigo);

#endif
