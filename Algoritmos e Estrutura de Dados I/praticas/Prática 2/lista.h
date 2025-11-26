#ifndef _LISTA_H
#define _LISTA_H


struct no {
    int item;
    struct no* prox;
  };
  
  // Definição do tipo No
  typedef struct no No;

No* insereInicio(No *l, int elem);

No* criaListaVazia();
int ehVazia();


#endif