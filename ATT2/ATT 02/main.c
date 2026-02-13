#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

int main() {
    Livro livros[100];
    Usuario usuarios[100];
    Emprestimo emprestimos[100];
    int qtdLivros = 0, qtdUsuarios = 0, qtdEmprestimos = 0;
    int opcao;

    do {
        system("cls");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Cadastrar Usuario\n");
        printf("4. Listar Usuarios\n");
        printf("5. Emprestar\n");
        printf("6. Listar Emprestimos\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                cadastrarLivro(livros, &qtdLivros, 100);
                break;
            case 2:
                listarLivros(livros, qtdLivros);
                break;
            case 3:
                cadastrarUsuario(usuarios, &qtdUsuarios, 100);
                break;
            case 4:
                listarUsuarios(usuarios, qtdUsuarios);
                break;
            case 5:
                realizarEmprestimo(emprestimos, &qtdEmprestimos, 100, usuarios, qtdUsuarios, livros, qtdLivros);
                break;
            case 6: {
                int id;
                printf("ID Usuario: ");
                scanf("%d", &id);
                listarEmprestimosUsuario(emprestimos, qtdEmprestimos, id, livros, qtdLivros);
                break;
            }
        }
        system("pause");
    } while (opcao != 0);

    return 0;
}
