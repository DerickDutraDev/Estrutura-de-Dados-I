#include <stdio.h>

#define DIAS 7
#define TURNOS 3

int main() {
    float clima[DIAS][TURNOS];
    float media_dia[DIAS] = {0};
    float media_turno[TURNOS] = {0};
    int i, j;
    float maior_media = -100.0;
    int dia_mais_quente = -1;
    char *nomes_dias[] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado", "Domingo"};
    char *nomes_turnos[] = {"Manha", "Tarde", "Noite"};

    printf("--- Registro de Temperaturas ---\n");
    for (i = 0; i < DIAS; i++) {
        printf("Dia %d (%s):\n", i + 1, nomes_dias[i]);
        for (j = 0; j < TURNOS; j++) {
            printf("  Temperatura no turno %s: ", nomes_turnos[j]);
            scanf("%f", &clima[i][j]);
            
            media_dia[i] += clima[i][j];
            media_turno[j] += clima[i][j];
        }
        
        media_dia[i] /= TURNOS;
        
        if (media_dia[i] > maior_media) {
            maior_media = media_dia[i];
            dia_mais_quente = i;
        }
    }

    for (j = 0; j < TURNOS; j++) {
        media_turno[j] /= DIAS;
    }

    printf("\n--- Resultados ---\n");
    printf("Media de cada dia:\n");
    for (i = 0; i < DIAS; i++) {
        printf("  %s: %.2f C\n", nomes_dias[i], media_dia[i]);
    }

    printf("\nMedia de cada turno:\n");
    for (j = 0; j < TURNOS; j++) {
        printf("  %s: %.2f C\n", nomes_turnos[j], media_turno[j]);
    }

    printf("\nO dia mais quente da semana foi %s, com media de %.2f C.\n", nomes_dias[dia_mais_quente], maior_media);

    return 0;
}
