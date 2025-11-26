#ifndef _FUNCOES_H
#define _FUNCOES_H

typedef struct dicionario{
    char verbete[25];
    char classificacao[50];
    char significado[100];
    struct dicionario* prox;
} Dicionario;

typedef struct pilha{
    Dicionario* topo;
    int qtd;
} Pilha;

Dicionario* criarListaVazia();
Dicionario* inserirOrdenado(Dicionario* lista, Dicionario* novo);
Dicionario* pesquisaVerbete(Dicionario* lista, char* palavra);
Dicionario* carregarDicionario(const char* nomeArquivo);
void iniciaPilha(Pilha *p);
int empty(Pilha *p);
void push(Pilha *p, Dicionario* item);
Dicionario* pop(Pilha *p);
void carregarFrases(Dicionario* lista, const char* nomeArquivo);
void liberaLista(Dicionario* lista);

#endif
