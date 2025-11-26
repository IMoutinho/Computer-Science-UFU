#ifndef _FUNCOES_H
#define _FUNCOES_H

typedef struct Nave {
    int capacidade;
    int combustivelAt;
    struct Nave* prox;
} Nave;

typedef struct Descritor {
    Nave* ultimo;
    Nave* primeiro;
    int tamanho;
} Descritor;

void inicializarLista(Descritor *lista);
void adicionarnoFinal(Descritor **lista, Nave novaNave);
void retiraCombustivel(Descritor *lista);
void abastecimento(Descritor *lista);
int checaAbastecimento(Descritor *lista);
void liberarLista(Descritor *lista);

#endif