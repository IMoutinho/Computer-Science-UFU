#ifndef _FUNCOES_H
#define _FUNCOES_H

typedef struct circular {
    char person[30];
    struct circular* next;
    struct circular* prev;
} Circular;


Circular* criarListavazia();
void inserirInicio(Circular** lista, char name[], int* qnt);
void carregarNomesArquivo(Circular** lista, const char* nomeArquivo, int* qnt);
void escolhaLider(Circular** lista, int* qnt, int k);
void sortearPrimeira(Circular** lista, int qnt);
void removerNo(Circular** lista, Circular* actual, int* qnt);
void percursoFrente(Circular** lista, int k, int* qnt);
void percursoTras(Circular** lista, int k, int* qnt);
void escolhaLider(Circular** lista, int* qnt, int k);



#endif