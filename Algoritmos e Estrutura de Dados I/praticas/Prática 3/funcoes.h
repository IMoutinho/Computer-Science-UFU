#ifndef _FUNCOES_H
#define _FUNCOES_H

// Definição da estrutura Nó para encadeamento de inteiros
struct no {
    int item;
    struct no* prox;
};

// Definição do tipo No
typedef struct no No;

// Protótipos das funções
No* criaListaVazia();
No* insereInicio(No *l, int elem);
No* insereVarios(No *l, int qtd);
int ehvazia(No *l);
int qnt(No *l);
No* removeElemento(No *l, int valor);
No* removerMaior(No *l);
int par(int num);
No* filtraPares(No *l) ;
int contaIterativa(No *l) ;
int contaRecursiva(No *l);
int* listaParaVetor(No *l, int *tamanho) ;



#endif
