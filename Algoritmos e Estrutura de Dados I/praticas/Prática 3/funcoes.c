#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Função para criar uma lista vazia
No* criaListaVazia() {
    return NULL;
}

// Função para inserir um elemento no início da lista
No* insereInicio(No *l, int elem) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return l;
    }
    novo->item = elem;
    novo->prox = l;
    return novo;
}

No* insereVarios(No *l, int qtd) {
    for (int i = 0; i < qtd; i++) {
        No* novo = (No*) malloc(sizeof(No));
        if (novo == NULL) {
            printf("Erro ao alocar memória!\n");
            return l;  // Retorna a lista
        }

        novo->item = rand() % 21;  // Número aleatório entre 0 e 20
        novo->prox = l;  // Insere no início da lista
        l = novo;  // Atualiza a cabeça da lista
    }
    return l;  // Retorna o novo ponteiro da lista
}



int ehvazia (No *l){
    if (l == NULL){
        printf ("A lista é vazia");
        return 1;
    }
    else {
        return 0;
    }
}

int qnt (No *l){
    int cont=0;
    while (l!=NULL){
        cont++;
        l=l->prox;
        }
     return cont;
}

No* removeElemento(No *l, int valor) {
    No *atual = l, *anterior = NULL; // Declaro os ponteiros:
    // - 'atual' inicia na cabeça da lista e será usado para percorrê-la.
    // - 'anterior' armazena o nó anterior ao atual, necessário para reencadear a lista ao remover um nó.

    while (atual != NULL) {  // Percorre a lista enquanto não chegar ao final (NULL)
        if (atual->item == valor) {  // Se o valor do nó atual for o desejado:
            if (anterior == NULL) { // Se 'anterior' ainda for NULL, significa que o primeiro nó contém o valor buscado.
                // Como é o primeiro da lista, basta atualizar 'l' para apontar para o próximo nó.
                l = atual->prox; 
            } else {
                // Se não for o primeiro nó, ajustamos o ponteiro do nó anterior para "pular" o nó atual.
                anterior->prox = atual->prox;
            }
            free(atual);  // Libera a memória do nó removido para evitar vazamento.
            return l;  // Retorna a lista atualizada e interrompe a função (removendo apenas o primeiro valor encontrado).
        }
        anterior = atual;  // Atualiza o nó anterior para ser o nó atual.
        atual = atual->prox;  // Avança para o próximo nó na lista.
    }

    printf("Elemento %d não encontrado na lista.\n", valor);
    return l;  // Retorna a lista inalterada se o valor não foi encontrado.
}

No* removerMaior(No *l) {
    if (l == NULL) return NULL; // Se a lista for vazia, não há o que remover.

    No *atual = l, *anterior = NULL, *maiorNo = l, *anteriorMaior = NULL;

    // Percorre a lista para encontrar o maior valor
    while (atual != NULL) {
        if (atual->item > maiorNo->item) { 
            maiorNo = atual;
            anteriorMaior = anterior;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Remove o nó contendo o maior valor
    if (anteriorMaior == NULL) {
        // Caso especial: o maior elemento é o primeiro da lista
        l = maiorNo->prox;
    } else {
        // Pula o maior nó, conectando o anterior ao próximo nó
        anteriorMaior->prox = maiorNo->prox;
    }

    free(maiorNo); // Libera a memória do nó removido
    return l; // Retorna a lista atualizada
}

int par(int num) {
    return num % 2 == 0;
}

No* filtraPares(No *l) {
    No *novaLista = NULL, *ultimo = NULL; // Ponteiro para a nova lista e o último elemento adicionado

    while (l != NULL) {
        if (par(l->item)) { // Se for par
            No *novo = (No*)malloc(sizeof(No)); // Aloca memória para o novo nó
            if (novo == NULL) {
                printf("Erro de alocação de memória!\n");
                return NULL;
            }
            novo->item = l->item;
            novo->prox = NULL;

            if (novaLista == NULL) {
                novaLista = novo; // Primeiro elemento da nova lista
            } else {
                ultimo->prox = novo; // Adiciona ao final da nova lista
            }
            ultimo = novo; // Atualiza o último nó
        }
        l = l->prox; // Avança para o próximo nó da lista original
    }
    return novaLista;
}

int contaIterativa(No *l) {
    int contador = 0;
    while (l != NULL) {
        contador++;
        l = l->prox;
    }
    return contador;
}

int contaRecursiva(No *l) {
    if (l == NULL) return 0; // Caso base: lista vazia, retorna 0
    return 1 + contaRecursiva(l->prox); // Soma 1 e chama a função para o próximo nó
}

int* listaParaVetor(No *l, int *tamanho) {
    *tamanho = contaIterativa(l); // Conta quantos elementos tem na lista

    if (*tamanho == 0) return NULL; // Se a lista for vazia, retorna NULL

    int *vetor = (int*) malloc((*tamanho) * sizeof(int)); // Aloca memória para o vetor
    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }

    int i = 0;
    while (l != NULL) {
        vetor[i++] = l->item; // Adiciona os elementos ao vetor
        l = l->prox;
    }

    return vetor; // Retorna o vetor preenchido
}
