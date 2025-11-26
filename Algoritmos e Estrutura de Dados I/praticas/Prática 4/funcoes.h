#ifndef _FUNCOES_H
#define _FUNCOES_H


typedef struct aluno {
    char nome[40];
    float pratica;
    float teorica;

    struct aluno* prox;
}Alunos;

Alunos* insereInicio(Alunos *l, Alunos novo);
void imprimeAprovados(Alunos *l);
float pesquisaNota(Alunos *l, char *buscaNome);
Alunos* removeAluno(Alunos *l, char *buscaNome);
Alunos* criaListaVazia();
void liberaLista(Alunos *l);




#endif