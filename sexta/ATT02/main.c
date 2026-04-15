#include "estoque.h"
#include <stdio.h>


int main() {
  int opcao;

  do {
    printf("\n--- Controle de Estoque ---\n");
    printf("1. Adicionar Produto\n");
    printf("2. Atualizar Quantidade\n");
    printf("3. Remover Produto\n");
    printf("4. Listar Produtos\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      adicionarProduto();
      break;
    case 2:
      atualizarQuantidade();
      break;
    case 3:
      removerProduto();
      break;
    case 4:
      listarProdutos();
      break;
    case 0:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0);

  return 0;
}
