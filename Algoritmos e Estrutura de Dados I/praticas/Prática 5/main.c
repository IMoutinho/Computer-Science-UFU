#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h" 

int main() {
    Fila fila; 
    inicializarFila(&fila);

    for (int i = 0; i < 5; i++) {
        inserirElemento(&fila); 
    }
    
    retiraElemento(&fila); 
    return 0;
}
