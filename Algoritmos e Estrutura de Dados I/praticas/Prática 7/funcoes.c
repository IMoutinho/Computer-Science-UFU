#include "funcoes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Circular* criarListavazia(){
    return NULL;
} 

void inserirInicio(Circular** lista, char name[], int* qnt){
    Circular* new = (Circular*) malloc (sizeof(Circular));
    if (new == NULL){
        return;
    }

    strcpy(new->person, name);

    if(*lista == NULL){
        new->next = new;
        new->prev = new;
        *lista = new;
        *qnt=1;
    }
    else{
        Circular* last = (*lista)->prev;

        new->next = *lista; //o ponteiro próximo do novo item está apontando para o começo da lista
        new->prev = last; //o ponteiro anterior do novo item deve apontar para o anterior do ultimo ultimo item

        last->next = new; //o ponteiro proximo do ultimo(anterior) item aponta para o novo nó (novo ultimo nó)
        (*lista)->prev = new; //o anterior do primeiro item da lista aponta para o novo ultimo nó.

        *lista = new;
        *qnt+=1;

    }
}

void carregarNomesArquivo(Circular** lista, const char* nomeArquivo, int* qnt){
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo==NULL){
        printf ("Erro ao abrir o arquivo.\n");
        return;
    }
    char name[30];
    while (fgets(name, sizeof(name), arquivo)){
        name[strcspn(name, "\n")] = '\0';
        inserirInicio(lista,name, qnt);
    }
    fclose(arquivo);
}

void sortearPrimeira(Circular** lista, int qnt){
    if (*lista == NULL) {
        return;
    }

    int valorAleatorio = rand() % qnt;
    for (int i = 0; i < valorAleatorio; i++) {
        *lista = (*lista)->next;
    }
}

void removerNo(Circular** lista, Circular* atual, int* qnt) {
    if (*lista == NULL || atual == NULL) return;

    if (atual->next == atual) {
        free(atual);
        *lista = NULL;
    } else {
        atual->prev->next = atual->next;
        atual->next->prev = atual->prev;

        if (*lista == atual) {
            *lista = atual->next;
        }

        free(atual);
    }

    (*qnt)--;
}



void percursoFrente(Circular** lista, int k, int* qnt){
    if(lista==NULL){
        printf("Lista Vazia!\n");
        return;
    }
    Circular* actual = *lista;
    
    printf("Percorrendo %d passos à frente.\n", k-1);

    for (int i=0; i<k-1; i++){
        actual = actual->next;
    }
    printf("Pessoa a ser eliminada: %s\n", actual->person);

    Circular* ajustaCaixa = actual->prev;
    removerNo(lista, actual, qnt);

    *lista = ajustaCaixa ; 
}



void percursoTras(Circular** lista, int k, int* qnt){
    if(lista==NULL){
        printf("Lista Vazia!\n");
        return;
    }
    Circular* actual = *lista;

    printf("Percorrendo %d passos para trás.\n", k-1);

    for(int i=0; i<k-1; i++){
        actual = actual->prev;
    }
    printf ("Pessoa a ser eliminada: %s\n", actual->person);

    Circular* ajustaCaixa = actual->next;
    removerNo(lista, actual, qnt);

    *lista = ajustaCaixa;
}

void escolhaLider(Circular** lista, int* qnt, int k){
    int percurso=0;
    while (*qnt>1){
        if(percurso==0){
            percursoFrente(lista, k, qnt);
            percurso=1;
        }
        else {
            percursoTras(lista, k, qnt);
            percurso=0;
        }
    }
    if (*lista != NULL) {
        printf("\nLíder escolhido: %s\n", (*lista)->person);
        free(*lista);
        *lista = NULL;
    }
}