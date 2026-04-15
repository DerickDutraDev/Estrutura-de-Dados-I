#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

void cadastrarLivro(Livro livros[], int *qtdLivros, int maxLivros) {
    if (*qtdLivros >= maxLivros) {
        printf("Cheio!\n");
        return;
    }

    printf("Codigo: ");
    scanf("%d", &livros[*qtdLivros].codigo);
    fflush(stdin);

    printf("Titulo: ");
    gets(livros[*qtdLivros].titulo);
    fflush(stdin);

    printf("Autor: ");
    gets(livros[*qtdLivros].autor);
    fflush(stdin);

    (*qtdLivros)++;
    printf("Salvo!\n");
}

void listarLivros(Livro livros[], int qtdLivros) {
    printf("\n--- Livros ---\n");
    for (int i = 0; i < qtdLivros; i++) {
        printf("%d - %s - %s\n", livros[i].codigo, livros[i].titulo, livros[i].autor);
    }
}

Livro* buscarLivro(Livro livros[], int qtdLivros, int codigo) {
    for (int i = 0; i < qtdLivros; i++) {
        if (livros[i].codigo == codigo) {
            return &livros[i];
        }
    }
    return NULL;
}
