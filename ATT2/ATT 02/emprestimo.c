#include <stdio.h>
#include <stdlib.h>
#include "emprestimo.h"

void realizarEmprestimo(Emprestimo emprestimos[], int *qtdEmprestimos, int maxEmprestimos, Usuario usuarios[], int qtdUsuarios, Livro livros[], int qtdLivros) {
    int id, cod;
    
    printf("ID Usuario: ");
    scanf("%d", &id);
    
    printf("Codigo Livro: ");
    scanf("%d", &cod);
    
    emprestimos[*qtdEmprestimos].idUsuario = id;
    emprestimos[*qtdEmprestimos].codigoLivro = cod;
    
    printf("Data (D M A): ");
    scanf("%d %d %d", &emprestimos[*qtdEmprestimos].dataEmprestimo.dia, &emprestimos[*qtdEmprestimos].dataEmprestimo.mes, &emprestimos[*qtdEmprestimos].dataEmprestimo.ano);
    
    (*qtdEmprestimos)++;
    printf("Emprestado!\n");
}

void listarEmprestimosUsuario(Emprestimo emprestimos[], int qtdEmprestimos, int idUsuario, Livro livros[], int qtdLivros) {
    printf("\n--- Emprestimos ---\n");
    for (int i = 0; i < qtdEmprestimos; i++) {
        if (emprestimos[i].idUsuario == idUsuario) {
            printf("Livro Cod: %d | Data: %d/%d/%d\n", emprestimos[i].codigoLivro, emprestimos[i].dataEmprestimo.dia, emprestimos[i].dataEmprestimo.mes, emprestimos[i].dataEmprestimo.ano);
        }
    }
}
