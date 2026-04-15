#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

void cadastrarUsuario(Usuario usuarios[], int *qtdUsuarios, int maxUsuarios) {
    if (*qtdUsuarios >= maxUsuarios) {
        printf("Cheio!\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &usuarios[*qtdUsuarios].id);
    fflush(stdin);

    printf("Nome: ");
    gets(usuarios[*qtdUsuarios].nome);
    fflush(stdin);

    (*qtdUsuarios)++;
    printf("Salvo!\n");
}

void listarUsuarios(Usuario usuarios[], int qtdUsuarios) {
    printf("\n--- Usuarios ---\n");
    for (int i = 0; i < qtdUsuarios; i++) {
        printf("%d - %s\n", usuarios[i].id, usuarios[i].nome);
    }
}

Usuario* buscarUsuario(Usuario usuarios[], int qtdUsuarios, int id) {
    for (int i = 0; i < qtdUsuarios; i++) {
        if (usuarios[i].id == id) {
            return &usuarios[i];
        }
    }
    return NULL;
}
