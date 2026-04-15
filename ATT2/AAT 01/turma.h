#ifndef TURMA_H
#define TURMA_H

#include "aluno.h"

#define MAX_ALUNOS 30
#define MAX_TURMAS 10

typedef struct {
    int codigo;
    char nome[50];
    int quantidadeAlunos;
    Aluno alunos[MAX_ALUNOS];
} Turma;

void cadastrarTurma(Turma turmas[], int *qtdTurmas);
void cadastrarAlunoEmTurma(Turma turmas[], int qtdTurmas);
void listarAlunosDaTurma(Turma turmas[], int qtdTurmas);

#endif
