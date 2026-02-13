#include "estoque.h"
#include <stdio.h>
#include <string.h>

int codigos[MAX_PRODUTOS];
char nomes[MAX_PRODUTOS][MAX_NOME];
int quantidades[MAX_PRODUTOS];
int totalProdutos = 0;

int buscarIndice(int codigo) {
  for (int i = 0; i < totalProdutos; i++) {
    if (codigos[i] == codigo) {
      return i;
    }
  }
  return -1;
}

void adicionarProduto() {
  if (totalProdutos >= MAX_PRODUTOS) {
    printf("Erro: Estoque cheio!\n");
    return;
  }

  int codigo;
  printf("Digite o codigo do produto: ");
  scanf("%d", &codigo);

  if (buscarIndice(codigo) != -1) {
    printf("Erro: Codigo ja existe!\n");
    return;
  }

  printf("Digite o nome do produto: ");
  scanf(" %[^\n]s", nomes[totalProdutos]);

  int quantidade;
  printf("Digite a quantidade: ");
  scanf("%d", &quantidade);

  if (quantidade < 0) {
    printf("Erro: Quantidade nao pode ser negativa!\n");
    return;
  }

  codigos[totalProdutos] = codigo;
  quantidades[totalProdutos] = quantidade;
  totalProdutos++;
  printf("Produto cadastrado com sucesso!\n");
}

void atualizarQuantidade() {
  int codigo;
  printf("Digite o codigo do produto para atualizar: ");
  scanf("%d", &codigo);

  int indice = buscarIndice(codigo);
  if (indice == -1) {
    printf("Erro: Produto nao encontrado!\n");
    return;
  }

  int novaQuantidade;
  printf("Digite a nova quantidade: ");
  scanf("%d", &novaQuantidade);

  if (novaQuantidade < 0) {
    printf("Erro: Quantidade nao pode ser negativa!\n");
    return;
  }

  quantidades[indice] = novaQuantidade;
  printf("Quantidade atualizada com sucesso!\n");
}

void removerProduto() {
  int codigo;
  printf("Digite o codigo do produto para remover: ");
  scanf("%d", &codigo);

  int indice = buscarIndice(codigo);
  if (indice == -1) {
    printf("Erro: Produto nao encontrado!\n");
    return;
  }

  for (int i = indice; i < totalProdutos - 1; i++) {
    codigos[i] = codigos[i + 1];
    strcpy(nomes[i], nomes[i + 1]);
    quantidades[i] = quantidades[i + 1];
  }

  totalProdutos--;
  printf("Produto removido com sucesso!\n");
}

void listarProdutos() {
  if (totalProdutos == 0) {
    printf("Nenhum produto cadastrado.\n");
    return;
  }

  printf("\n--- Lista de Produtos ---\n");
  printf("%-10s %-20s %-10s\n", "Codigo", "Nome", "Quantidade");
  for (int i = 0; i < totalProdutos; i++) {
    printf("%-10d %-20s %-10d\n", codigos[i], nomes[i], quantidades[i]);
  }
  printf("-------------------------\n");
}
