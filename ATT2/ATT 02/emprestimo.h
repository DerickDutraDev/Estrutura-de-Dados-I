#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "usuario.h"
#include "livro.h"

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int idUsuario;
    int codigoLivro;
    Data dataEmprestimo;
    Data dataDevolucao; 
    int devolvido; 
} Emprestimo;

void realizarEmprestimo(Emprestimo emprestimos[], int *qtdEmprestimos, int maxEmprestimos, Usuario usuarios[], int qtdUsuarios, Livro livros[], int qtdLivros);
void listarEmprestimosUsuario(Emprestimo emprestimos[], int qtdEmprestimos, int idUsuario, Livro livros[], int qtdLivros);

#endif
