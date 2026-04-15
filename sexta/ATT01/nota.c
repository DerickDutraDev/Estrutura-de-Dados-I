#include "nota.h"
#include <stdio.h>

void insert_grade(float notas[], int *contar) {
  if (*contar >= MAX_SIZE) {
    printf("Erro: O vetor esta cheio!\n");
    return;
  }

  float grade;
  printf("Digite a nota a ser inserida: ");
  scanf("%f", &grade);
  notas[*contar] = grade;
  (*contar)++;
  printf("Nota %.2f inserida com sucesso!\n", grade);
}

void remove_grade(float notas[], int *contar) {
  if (*contar == 0) {
    printf("Erro: Nao ha notas para remover.\n");
    return;
  }
  int index;
  display_grades(notas, *contar);
  printf("Digite o indice da nota a remover (0 a %d): ", *contar - 1);
  scanf("%d", &index);

  if (index < 0 || index >= *contar) {
    printf("Erro: Indice invalido!\n");
    return;
  }

  for (int i = index; i < *contar - 1; i++) {
    notas[i] = notas[i + 1];
  }
  (*contar)--;
  printf("Nota removida com sucesso!\n");
}

void update_grade(float notas[], int contar) {
  if (contar == 0) {
    printf("Erro: Nao ha notas para atualizar.\n");
    return;
  }
  int index;
  display_grades(notas, contar);
  printf("Digite o indice da nota a atualizar (0 a %d): ", contar - 1);
  scanf("%d", &index);

  if (index < 0 || index >= contar) {
    printf("Erro: Indice invalido!\n");
    return;
  }

  float new_grade;
  printf("Digite a nova nota: ");
  scanf("%f", &new_grade);
  notas[index] = new_grade;
  printf("Nota atualizada com sucesso!\n");
}

void display_grades(float notas[], int contar) {
  if (contar == 0) {
    printf("Nenhuma nota cadastrada.\n");
    return;
  }
  printf("\n--- Lista de Notas ---\n");
  for (int i = 0; i < contar; i++) {
    printf("[%d]: %.2f\n", i, notas[i]);
  }
}

void display_stats(float notas[], int contar) {
  if (contar == 0) {
    printf("Nenhuma nota cadastrada para calcular estatisticas.\n");
    return;
  }
  float sum = 0, max = notas[0], min = notas[0];

  for (int i = 0; i < contar; i++) {
    sum += notas[i];
    if (notas[i] > max)
      max = notas[i];
    if (notas[i] < min)
      min = notas[i];
  }

  printf("\n--- Estatisticas ---\n");
  printf("Media: %.2f\n", sum / contar);
  printf("Maior Nota: %.2f\n", max);
  printf("Menor Nota: %.2f\n", min);
}
