#ifndef LIVRO_H
#define LIVRO_H

#define MAX_TITULO 100
#define MAX_AUTOR 100

typedef struct {
    int codigo;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
} Livro;

// Funções para gerenciar livros
void cadastrarLivro(Livro livros[], int *qtdLivros, int maxLivros);
void listarLivros(Livro livros[], int qtdLivros);
Livro* buscarLivro(Livro livros[], int qtdLivros, int codigo);

#endif
