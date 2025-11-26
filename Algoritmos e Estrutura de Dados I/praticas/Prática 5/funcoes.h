#ifndef _FUNCOES_H
#define _FUNCOES_H

typedef struct software {
    char titulo[20];
    char autor[30];
    char linguagem[20];
    int ano;
    struct software *prox;
} Software;

typedef struct fila {
    Software *fim;
} Fila;

void inicializarFila(Fila *f);
void inserirElemento(Fila *f);
void retiraElemento(Fila *f);

#endif
