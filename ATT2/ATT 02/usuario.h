#ifndef USUARIO_H
#define USUARIO_H

#define MAX_NOME 100

typedef struct {
    int id;
    char nome[MAX_NOME];
} Usuario;

void cadastrarUsuario(Usuario usuarios[], int *qtdUsuarios, int maxUsuarios);
void listarUsuarios(Usuario usuarios[], int qtdUsuarios);
Usuario* buscarUsuario(Usuario usuarios[], int qtdUsuarios, int id);

#endif
