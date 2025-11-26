#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



// Função para criar uma lista vazia

int main(){
 No *lnum; // lista de números com encadeamento de nós 
 int val; 
 lnum = criaListaVazia();  
 for(int i=0;i<10;i++){  //  inserir 10 elementos    
    scanf("%d",&val);
    lnum = insereInicio(lnum, val);
 }
}