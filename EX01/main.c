#include "aluno.h"
#include "carro.h"
#include "cliente.h"
#include "conta.h"
#include "endereco.h"
#include "filme.h"
#include "funcionario.h"
#include "livro.h"
#include "produto.h"
#include "professor.h"
#include <stdio.h>
#include <stdlib.h>

void clear_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int main() {
  int opcao;

  do {
    printf("\n=== MENU DE EXERCICIOS ===\n");
    printf("1. Professor\n");
    printf("2. Produto\n");
    printf("3. Livro\n");
    printf("4. Cliente\n");
    printf("5. Funcionario\n");
    printf("6. Carro\n");
    printf("7. Conta Bancaria\n");
    printf("8. Endereco\n");
    printf("9. Filme\n");
    printf("10. Aluno\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    clear_buffer();

    printf("\n");

    switch (opcao) {
    case 1: {
      Professor p;
      printf("--- Professor ---\n");
      printf("ID: ");
      scanf("%d", &p.id);
      clear_buffer();
      printf("Nome: ");
      scanf(" %[^\n]", p.nome);
      printf("Salario: ");
      scanf("%f", &p.salario);

      printf("\nDados do Professor:\n");
      printf("ID: %d\n", p.id);
      printf("Nome: %s\n", p.nome);
      printf("Salario: %.2f\n", p.salario);
      break;
    }
    case 2: {
      Produto p;
      printf("--- Produto ---\n");
      printf("Codigo: ");
      scanf("%d", &p.codigo);
      clear_buffer();
      printf("Nome: ");
      scanf(" %[^\n]", p.nome);
      printf("Preco: ");
      scanf("%f", &p.preco);

      printf("\nDados do Produto:\n");
      printf("Codigo: %d\n", p.codigo);
      printf("Nome: %s\n", p.nome);
      printf("Preco: %.2f\n", p.preco);
      break;
    }
    case 3: {
      Livro l;
      printf("--- Livro ---\n");
      printf("ISBN: ");
      scanf(" %[^\n]", l.isbn);
      printf("Titulo: ");
      scanf(" %[^\n]", l.titulo);
      printf("Autor: ");
      scanf(" %[^\n]", l.autor);

      printf("\nDados do Livro:\n");
      printf("ISBN: %s\n", l.isbn);
      printf("Titulo: %s\n", l.titulo);
      printf("Autor: %s\n", l.autor);
      break;
    }
    case 4: {
      Cliente c;
      printf("--- Cliente ---\n");
      printf("ID: ");
      scanf("%d", &c.id);
      clear_buffer();
      printf("Nome: ");
      scanf(" %[^\n]", c.nome);
      printf("Telefone: ");
      scanf(" %[^\n]", c.telefone);

      printf("\nDados do Cliente:\n");
      printf("ID: %d\n", c.id);
      printf("Nome: %s\n", c.nome);
      printf("Telefone: %s\n", c.telefone);
      break;
    }
    case 5: {
      Funcionario f;
      printf("--- Funcionario ---\n");
      printf("Matricula: ");
      scanf("%d", &f.matricula);
      clear_buffer();
      printf("Nome: ");
      scanf(" %[^\n]", f.nome);
      printf("Salario: ");
      scanf("%f", &f.salario);

      printf("\nDados do Funcionario:\n");
      printf("Matricula: %d\n", f.matricula);
      printf("Nome: %s\n", f.nome);
      printf("Salario: %.2f\n", f.salario);
      break;
    }
    case 6: {
      Carro c;
      printf("--- Carro ---\n");
      printf("Placa: ");
      scanf(" %[^\n]", c.placa);
      printf("Modelo: ");
      scanf(" %[^\n]", c.modelo);
      printf("Ano: ");
      scanf("%d", &c.ano);

      printf("\nDados do Carro:\n");
      printf("Placa: %s\n", c.placa);
      printf("Modelo: %s\n", c.modelo);
      printf("Ano: %d\n", c.ano);
      break;
    }
    case 7: {
      Conta c;
      printf("--- Conta Bancaria ---\n");
      printf("Numero: ");
      scanf("%d", &c.numero);
      clear_buffer();
      printf("Titular: ");
      scanf(" %[^\n]", c.titular);
      printf("Saldo: ");
      scanf("%f", &c.saldo);

      printf("\nDados da Conta:\n");
      printf("Numero: %d\n", c.numero);
      printf("Titular: %s\n", c.titular);
      printf("Saldo: %.2f\n", c.saldo);
      break;
    }
    case 8: {
      Endereco e;
      printf("--- Endereco ---\n");
      printf("Rua: ");
      scanf(" %[^\n]", e.rua);
      printf("Numero: ");
      scanf("%d", &e.numero);
      clear_buffer();
      printf("Cidade: ");
      scanf(" %[^\n]", e.cidade);

      printf("\nDados do Endereco:\n");
      printf("Rua: %s\n", e.rua);
      printf("Numero: %d\n", e.numero);
      printf("Cidade: %s\n", e.cidade);
      break;
    }
    case 9: {
      Filme f;
      printf("--- Filme ---\n");
      printf("Titulo: ");
      scanf(" %[^\n]", f.titulo);
      printf("Genero: ");
      scanf(" %[^\n]", f.genero);
      printf("Duracao (min): ");
      scanf("%d", &f.duracao);

      printf("\nDados do Filme:\n");
      printf("Titulo: %s\n", f.titulo);
      printf("Genero: %s\n", f.genero);
      printf("Duracao: %d min\n", f.duracao);
      break;
    }
    case 10: {
      Aluno a;
      float media;
      printf("--- Aluno ---\n");
      printf("ID: ");
      scanf("%d", &a.id);
      clear_buffer();
      printf("Nome: ");
      scanf(" %[^\n]", a.nome);
      printf("Nota 1: ");
      scanf("%f", &a.nota1);
      printf("Nota 2: ");
      scanf("%f", &a.nota2);

      media = (a.nota1 + a.nota2) / 2.0;

      printf("\nDados do Aluno:\n");
      printf("ID: %d\n", a.id);
      printf("Nome: %s\n", a.nome);
      printf("Nota 1: %.2f\n", a.nota1);
      printf("Nota 2: %.2f\n", a.nota2);
      printf("Media: %.2f\n", media);
      break;
    }
    case 0:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0);

  return 0;
}
