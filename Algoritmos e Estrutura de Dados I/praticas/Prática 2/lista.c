#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criaListaVazia(){
    return NULL;
 }
 
 // Função para inserir um elemento na lista
 No* insereInicio(No *l, int elem){
   No* novo;
   novo = (No*) malloc (sizeof(No)); 
   if (novo == NULL) return novo;
 
   novo->item= elem;
   novo->prox = l;
   return novo;
 }

int ehVazia(No l*){
    if(l==NULL){
        return 1;
    else return 0;
    }
}
 