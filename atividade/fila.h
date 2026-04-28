#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef struct Cliente
{
    int id;
    int tempoEstimado;
    struct Cliente *prox;
} Cliente;

typedef struct Fila
{
    Cliente *inicio;
    Cliente *fim;
} Fila;

Fila *cria_fila(void);
void libera_fila(Fila *fi);
void insere_cliente(Fila *fi, int id, int tempoEstimado);
bool fila_vazia(const Fila *fi);
void atende_cliente(Fila *fi);
void exibe_fila(const Fila *fi);
int tempo_espera_total(const Fila *fi);

#endif
