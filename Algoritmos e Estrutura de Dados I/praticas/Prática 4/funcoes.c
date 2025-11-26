#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

Alunos* criaListaVazia() {
    return NULL;
}

Alunos* insereInicio(Alunos *l, Alunos novo) {
    Alunos* novoAluno = (Alunos*) malloc(sizeof(Alunos));

    if (novoAluno == NULL) {
        printf("Erro ao alocar memória!\n");
        return l;
    }

    strcpy(novoAluno->nome, novo.nome);
    novoAluno->pratica = novo.pratica;
    novoAluno->teorica = novo.teorica;
    novoAluno->prox = l;

    return novoAluno;
}

void imprimeAprovados(Alunos *l) {
    float notaFinal;
    printf("Notas maiores que 70:\n");

    while (l != NULL) {
        notaFinal = (l->pratica + l->teorica);
        if (notaFinal > 70) {
            printf("Soma das Notas de %s: %.2f\n", l->nome, notaFinal);
        }
        l = l->prox;
    }
}

float pesquisaNota(Alunos *l, char *buscaNome) {
    float notaFinal;

    while (l != NULL) {
        if (strcmp(l->nome, buscaNome) == 0) {
            notaFinal = l->pratica + l->teorica;
            return notaFinal;
        }
        l = l->prox;
    }

    printf("Aluno não encontrado!\n");
    return -1;
}

Alunos* removeAluno(Alunos *l, char *buscaNome) {
    if (l == NULL) {
        printf("Lista vazia!\n");
        return l;
    }

    Alunos *atual = l, *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, buscaNome) == 0) {
            if (anterior == NULL) {
                l = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            printf("Aluno removido!\n");
            return l;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Aluno não localizado!\n");
    return l;
}

void liberaLista(Alunos *l) {
    Alunos *atual = l;
    Alunos *prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}
