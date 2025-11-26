#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h" 

void inicializarFila(Fila *f) {
    f->fim = NULL;
}

void inserirElemento(Fila *f) { // Recebe Fila *f
    Software *novo = (Software*)malloc(sizeof(Software));
    if (novo == NULL) return;

    printf("Digite Titulo, Autor, Ling e Ano: ");
    scanf("%s", novo->titulo);
    scanf("%s", novo->autor);
    scanf("%s", novo->linguagem);
    scanf("%d", &novo->ano);

    if (f->fim == NULL) {
        novo->prox = novo; // Aponta para si mesmo
        f->fim = novo;
    } else {
        novo->prox = f->fim->prox; // Novo aponta para o Início (que é fim->prox)
        f->fim->prox = novo;       // Antigo fim aponta para o Novo
        f->fim = novo;             // Novo se torna o fim
    }
}

void retiraElemento(Fila *f) {
    if (f->fim == NULL) {
        printf("Fila Vazia!\n");
        return;
    }

    // Em lista circular com ponteiro Fim, o Início é fim->prox
    Software *remover = f->fim->prox; 

    if (remover == f->fim) { // Só tem 1 elemento
        f->fim = NULL;
    } else {
        f->fim->prox = remover->prox; // O fim pula o removido e aponta pro novo inicio
    }
    
    printf("Removendo: %s\n", remover->titulo);
    free(remover);
}
