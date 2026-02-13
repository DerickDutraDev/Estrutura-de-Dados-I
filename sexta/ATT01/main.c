#include "nota.h"
#include <stdio.h>
#include <stdlib.h>

void print_menu();

int main() {
  float notas[MAX_SIZE];
  int contar = 0;
  int escolha;

  do {
    print_menu();
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      insert_grade(notas, &contar); // apontando para memotria
      break;
    case 2:
      remove_grade(notas, &contar); // apontando para memotria
      break;
    case 3:
      update_grade(notas, contar);
      break;
    case 4:
      display_grades(notas, contar);
      break;
    case 5:
      display_stats(notas, contar);
      break;
    case 0:
      printf("Saindo do programa...\n");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
    }
  } while (escolha != 0);

  return 0;
}

void print_menu() {
  printf("\n--- Gerenciamento de Notas ---\n");
  printf("1. Inserir nota\n");
  printf("2. Remover nota\n");
  printf("3. Atualizar nota\n");
  printf("4. Exibir todas as notas\n");
  printf("5. Exibir estatisticas (Media, Max, Min)\n");
  printf("0. Sair\n");
}
