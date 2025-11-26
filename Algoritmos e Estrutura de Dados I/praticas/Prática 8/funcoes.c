#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

Dicionario* criarListaVazia(){
    return NULL;
}

void iniciaPilha(Pilha *p){
    p->topo = NULL;
    p->qtd = 0;
}

int empty(Pilha *p) {
    return (p->topo == NULL);
}

Dicionario* inserirOrdenado(Dicionario* lista, Dicionario* novo) {
    novo->prox = NULL;
    
    if(lista == NULL || strcmp(novo->verbete, lista->verbete) < 0){
        novo->prox = lista;
        return novo;
    }
    
    Dicionario* atual = lista;
    while(atual->prox != NULL && strcmp(atual->prox->verbete, novo->verbete) < 0){
        atual = atual->prox;
    }
    
    novo->prox = atual->prox;
    atual->prox = novo;
    
    return lista;
}

Dicionario* pesquisaVerbete(Dicionario* lista, char* palavra){
    while(lista != NULL){
        if (strcmp(lista->verbete, palavra) == 0){
            return lista;
        }
        lista = lista->prox;
    }
    return NULL;
}

void push(Pilha *p, Dicionario* item){
    Dicionario* novo = (Dicionario*) malloc(sizeof(Dicionario));
    if (novo == NULL) {
        return;
    }

    strcpy(novo->verbete, item->verbete);
    strcpy(novo->classificacao, item->classificacao);
    strcpy(novo->significado, item->significado);

    novo->prox = p->topo;
    p->topo = novo;
    p->qtd++;
}

Dicionario* pop(Pilha *p){
    if(empty(p)){
        return NULL;
    }
    Dicionario *item = p->topo;
    p->topo = item->prox;
    p->qtd--;
    return item;
}

Dicionario* carregarDicionario(const char* nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return NULL;
    }

    Dicionario *lista = NULL;
    char verbete[25], classificacao[50], significado[100];

    while (fgets(verbete, sizeof(verbete), arquivo) &&
           fgets(classificacao, sizeof(classificacao), arquivo) &&
           fgets(significado, sizeof(significado), arquivo)) {

        verbete[strcspn(verbete, "\n")] = '\0';
        classificacao[strcspn(classificacao, "\n")] = '\0';
        significado[strcspn(significado, "\n")] = '\0';

        Dicionario *novo = (Dicionario*) malloc(sizeof(Dicionario));
        if (novo != NULL) {
            strcpy(novo->verbete, verbete);
            strcpy(novo->classificacao, classificacao);
            strcpy(novo->significado, significado);
            lista = inserirOrdenado(lista, novo);
        }
    }
    fclose(arquivo);
    return lista;
}

void carregarFrases(Dicionario* lista, const char* nomeArquivo){
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL){
        return;
    }

    char frase[200];
    while (fgets(frase, sizeof(frase), arquivo)){
        Pilha p;
        iniciaPilha(&p);
        
        frase[strcspn(frase, "\n")] = '\0';

        printf("\nFrase: %s\n", frase);

        char* palavra = strtok(frase, " ");
        while (palavra != NULL){
            Dicionario* resultado = pesquisaVerbete(lista, palavra);
            
            if (resultado != NULL){
                push(&p, resultado);
            } else {
                printf("Palavra \"%s\" nao encontrada.\n", palavra);
            }
            palavra = strtok(NULL, " ");
        }

        printf("\nSignificados (Pilha):\n");
        while (!empty(&p)){
            Dicionario* item = pop(&p);
            if (item != NULL){
                printf("Verbete: %s\nClassificacao: %s\nSignificado: %s\n\n", 
                    item->verbete, item->classificacao, item->significado);
                free(item);
            }
        }
        printf("-------------------------------\n");
    }

    fclose(arquivo);
}

void liberaLista(Dicionario* lista) {
    while (lista != NULL) {
        Dicionario* libera = lista;
        lista = lista->prox;
        free(libera);
    }
}
