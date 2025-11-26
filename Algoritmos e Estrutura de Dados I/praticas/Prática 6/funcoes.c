#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

// INICIALIZA O DESCRITOR
void inicializarLista(Descritor *lista) {
    lista->ultimo = NULL; // LISTA VAZIA
    lista->primeiro = NULL;
    lista->tamanho = 0; // NENHUMA NAVE ADICIONADA
}

// ADICIONA NO INICIO
void adicionarnoInicio(Descritor **lista, Nave novaNave) {
    Nave* nova = (Nave*)malloc(sizeof(Nave));
    if (nova == NULL) {
        printf("Erro na alocação da memória!\n");
        return;
    }

    *nova = novaNave;

    if ((*lista)->ultimo == NULL) { // LISTA VAZIA
        nova->prox = nova; // O ITEM APONTA PARA ELE MESMO
        (*lista)->ultimo = nova;
        (*lista)->primeiro = nova;
    } else {
        nova->prox = (*lista)->primeiro; // O NOVO PRIMEIRO APONTA PARA O ANTIGO PRIMEIRO
        (*lista)->ultimo->prox = nova; // O ULTIMO ELEMENTO APONTA PARA O NOVO PRIMEIRO
        (*lista)->primeiro = nova;
    }

    (*lista)->tamanho++;
}

// ADICIONA NO FINAL
void adicionarnoFinal(Descritor **lista, Nave novaNave) {
    Nave* nova = (Nave*)malloc(sizeof(Nave));
    if (nova == NULL) {
        printf("Erro na alocação da memória!\n");
        return;
    }

    *nova = novaNave;

    if ((*lista)->ultimo == NULL) { // LISTA VAZIA
        nova->prox = nova; // O ITEM APONTA PARA ELE MESMO
        (*lista)->ultimo = nova;
        (*lista)->primeiro = nova;
    } else {
        nova->prox = (*lista)->primeiro; // O NOVO ULTIMO APONTA PARA O PRIMEIRO
        (*lista)->ultimo->prox = nova; // O ANTIGO ULTIMO APONTA PARA O NOVO ULTIMO
        (*lista)->ultimo = nova;
    }

    (*lista)->tamanho++;
}

// RETIRA COMBUSTIVEL COM VALORES ALEATORIOS DE 0 ATÉ O VALOR DO COMBUSTIVEL ATUAL
void retiraCombustivel(Descritor *lista) {
    if (lista->ultimo == NULL) {
        return;
    }
//VERIFICA SE A LISTA ESTÁ VAZIA
    Nave* atual = lista->primeiro;
    int i=0;

    do {
        i++;
        printf("Combustivel atual da nave %d: %d\n", i, atual->combustivelAt);
        if (atual->combustivelAt > 0) {
            int numeroAleatorio = rand() % 2;
            if (numeroAleatorio == 0) {
                int valorAleatorio = rand() % (atual->combustivelAt);
                atual->combustivelAt -= valorAleatorio;
                printf("A nave %d gastou %d litros de combustível. \nCombustível restante: %d\n", i, valorAleatorio, atual->combustivelAt);
            }
        }
        atual = atual->prox;
    } while (atual != lista->primeiro);
}

// ABASTECE A NAVE DE ACORDO COM O VALOR ESTABELECIDO PARA O CICLO
void abastecimento(Descritor *lista) {
    int combustivelCiclo;

    printf("Quanto de combustível você deseja adicionar por ciclo?:\n");
    scanf("%d", &combustivelCiclo);
    if (combustivelCiclo<=0){
        printf ("Valor inválido. Não pode ser valor negativo ou 0.");
        return;
    }

    if (lista->ultimo == NULL) {
        return;
    }

    int checaTodas = 1;
    int ciclo = 0;

    while (checaTodas != 0) {
        ciclo++;
        int i = 1;
        Nave* atual = lista->primeiro;

        printf("\n--- Ciclo %d ---\n", ciclo);

        do {
            printf("Combustivel atual da nave %d: %d\n", i, atual->combustivelAt);

            if (atual->combustivelAt < atual->capacidade) {
                atual->combustivelAt += combustivelCiclo;
                if (atual->combustivelAt > atual->capacidade) {
                    atual->combustivelAt = atual->capacidade;
                }
            }
            i++;
            atual = atual->prox;

        } while (atual != lista->primeiro);
        printf ("\n------------------------\n");

        checaTodas = checaAbastecimento(lista);
    }
}

// CHECA ABASTECIMENTO
int checaAbastecimento(Descritor *lista) {
    if (lista->ultimo == NULL) {
        printf("Lista vazia!\n");
        return 0;
    }

    Nave* atual = lista->primeiro;
    int navesComCompleto = 0;

    do {
        if (atual->combustivelAt == atual->capacidade) {
            navesComCompleto++;
        }
        atual = atual->prox;
    } while (atual != lista->primeiro);

    if (navesComCompleto < lista->tamanho) {
        return 1;
    } else {
        return 0;
    }
}

void liberarLista(Descritor *lista) {
    if (lista == NULL || lista->primeiro == NULL) {
        return;
    }

    Nave *atual = lista->primeiro;
    int i;

    for (i = 0; i < lista->tamanho; i++) {
        Nave *prox = atual->prox; 
        free(atual);              
        atual = prox;             
    }

    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}