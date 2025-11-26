/*Alunos: Gabriel Antonio Gomes Moutinho - Matr�cula: 12311BCC073.
Gabriel Henrique Carneiro Amorim - Matr�cula: 12411BCC055*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1

// Aresta é a rodovia, com peso KM e a o indice da cidade de destino
typedef struct TipoAresta {
    int destino;
    int km;
} TipoAresta;

// Cada celula é um no da lista encadeada de arestas
typedef struct TipoCelula *TipoApontador;
struct TipoCelula {
    TipoAresta Item;
    TipoApontador Prox;
} TipoCelula;

// Lista encadeada de arestas
typedef struct TipoLista {
    TipoApontador Primeiro, Ultimo;
} TipoLista;

// Estrutura do grafo que
// Lista de adjacencias: conexões entre as cidades
// Nome das cidades
// Numero de cidade e arestas
typedef struct TipoGrafo {
    TipoLista Adj[MAXNUMVERTICES];
    char nomeCidades[MAXNUMVERTICES][50];
    int NumVertices;
    int NumArestas;
} TipoGrafo;

// Cria fila vazia
void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

// Verifica se a fila é vazia
short Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoAresta *x, TipoLista *Lista) {
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = *x;
    Lista->Ultimo->Prox = NULL;
}

// Verifica se o Grafo � vazio
void FGVazio(TipoGrafo *Grafo) {
    long i;
    for (i = 0; i < Grafo->NumVertices; i++)
        FLVazia(&Grafo->Adj[i]);
}

void InsereAresta(int origem, int destino, int km, TipoGrafo *Grafo) {
    TipoAresta x;
    x.destino = destino;
    x.km = km;
    Insere(&x, &Grafo->Adj[origem]);
    Grafo->NumArestas++;
}

short ExisteAresta(int origem, int destino, TipoGrafo *Grafo) {
    TipoApontador Aux;
    short EncontrouAresta = FALSE;
    Aux = Grafo->Adj[origem].Primeiro->Prox;
    while (Aux != NULL && EncontrouAresta == FALSE) {
        if (Aux->Item.destino == destino) EncontrouAresta = TRUE;
        Aux = Aux->Prox;
    }
    return EncontrouAresta;
}

int KM(int origem, int destino, TipoGrafo *Grafo) {
    TipoApontador Aux = Grafo->Adj[origem].Primeiro->Prox;
    while (Aux != NULL) {
        if (Aux->Item.destino == destino) return Aux->Item.km;
        Aux = Aux->Prox;
    }
    return 0;
}

short ListaAdjVazia(int vertice, TipoGrafo *Grafo) {
    return (Grafo->Adj[vertice].Primeiro == Grafo->Adj[vertice].Ultimo);
}

TipoApontador PrimeiroListaAdj(int vertice, TipoGrafo *Grafo) {
    return (Grafo->Adj[vertice].Primeiro->Prox);
}

void ProxAdj(int *Adj, int *Km, TipoApontador *Prox, short *FimListaAdj) {
    *Adj = (*Prox)->Item.destino;
    *Km = (*Prox)->Item.km;
    *Prox = (*Prox)->Prox;
    if (*Prox == NULL)
        *FimListaAdj = TRUE;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoAresta *Item) {
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf("Erro: Lista vazia ou posicao nao existe\n");
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if (p->Prox == NULL)
        Lista->Ultimo = p;
    free(q);
}

void RetiraAresta(int origem, int destino, TipoGrafo *Grafo) {
    TipoApontador AuxAnterior, Aux;
    short EncontrouAresta = FALSE;
    TipoAresta x;
    AuxAnterior = Grafo->Adj[origem].Primeiro;
    Aux = Grafo->Adj[origem].Primeiro->Prox;
    while (Aux != NULL && EncontrouAresta == FALSE) {
        if (Aux->Item.destino == destino) {
            Retira(AuxAnterior, &Grafo->Adj[origem], &x);
            Grafo->NumArestas--;
            EncontrouAresta = TRUE;
        }
        AuxAnterior = Aux;
        Aux = Aux->Prox;
    }
}

void LiberaGrafo(TipoGrafo *Grafo) {
    TipoApontador AuxAnterior, Aux;
    for (int i = 0; i < Grafo->NumVertices; i++) {
        Aux = Grafo->Adj[i].Primeiro->Prox;
        free(Grafo->Adj[i].Primeiro);
        Grafo->Adj[i].Primeiro = NULL;
        while (Aux != NULL) {
            AuxAnterior = Aux;
            Aux = Aux->Prox;
            free(AuxAnterior);
        }
    }
    Grafo->NumVertices = 0;
}

void ImprimeGrafo(TipoGrafo *Grafo) {
    for (int i = 0; i < Grafo->NumVertices; i++) {
        printf("%s:", Grafo->nomeCidades[i]);
        if (!Vazia(Grafo->Adj[i])) {
            TipoApontador Aux = Grafo->Adj[i].Primeiro->Prox;
            while (Aux != NULL) {
                printf(" -> %s (%dkm)", Grafo->nomeCidades[Aux->Item.destino], Aux->Item.km);
                Aux = Aux->Prox;
            }
        }
        putchar('\n');
    }
}

// Funções auxiliares para gerenciar os nomes das cidades
int obterIndiceCidade(TipoGrafo *g, char nome[]) {
    for (int i = 0; i < g->NumVertices; i++) {
        if (strcmp(g->nomeCidades[i], nome) == 0) return i;
    }
    return -1;
}

int inserirCidade(TipoGrafo *g, char nome[]) {
    int indice = obterIndiceCidade(g, nome);
    if (indice != -1) return indice;
    if (g->NumVertices >= MAXNUMVERTICES) return -1;
    strcpy(g->nomeCidades[g->NumVertices], nome);
    // Inicializar a lista de adjacências do novo vértice
    FLVazia(&g->Adj[g->NumVertices]);
    return g->NumVertices++;
}

// Função para percorrer o grafo e verificar se tem ciclos
short buscaProfundidadeCiclo(int v, int visitado[], int recursaoPilha[], TipoGrafo *Grafo) {
    visitado[v] = TRUE;
    // Pilha de recursão
    recursaoPilha[v] = TRUE;

    TipoApontador p = Grafo->Adj[v].Primeiro->Prox;
    while (p != NULL) {
        int u = p->Item.destino;

        if (!visitado[u]) {
            // Chama recursivamente caso o destino ainda não foi visitado
            // Detecta o ciclo em profundidade
            if (buscaProfundidadeCiclo(u, visitado, recursaoPilha, Grafo))
                return TRUE;
        }
        else if (recursaoPilha[u]) {
            // Se o destino já está na pilha, um ciclo foi encontrado
            return TRUE;
        }

        p = p->Prox;
    }

    // Remove da pilha de recursão
    recursaoPilha[v] = FALSE;
    return FALSE;
}

// Percorre todos os vértices e inicia a busca em profundidade
short VerificaCiclo(TipoGrafo *Grafo) {
    int visitado[MAXNUMVERTICES] = {FALSE};
    int recursaoPilha[MAXNUMVERTICES] = {FALSE};

    for (int i = 0; i < Grafo->NumVertices; i++) {
        if (!visitado[i]) {
            if (buscaProfundidadeCiclo(i, visitado, recursaoPilha, Grafo))
                return TRUE;
        }
    }
    return FALSE;
}

int main() {
    TipoGrafo Grafo;
    Grafo.NumVertices = 0;
    Grafo.NumArestas = 0;
    FGVazio(&Grafo);

    int opcao;
    char nome1[50], nome2[50];
    int km;

    do {
        printf("\n\tmenu\t\n");
        printf("1. Inserir cidade e rodovia\n");
        printf("2. Imprimir grafo\n");
        printf("3. Inserir rodovia\n");
        printf("4. Remover rodovia\n");
        printf("5. Verificar se há ligação entre cidades e a Km\n");
        printf("6. Listar conexões diretas até 100km\n");
        printf("7. Verificar se o grafo é aciclico\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("Digite cidade origem: ");
                fgets(nome1, sizeof(nome1), stdin);
                nome1[strcspn(nome1, "\n")] = 0;

                printf("Digite cidade destino: ");
                fgets(nome2, sizeof(nome2), stdin);
                nome2[strcspn(nome2, "\n")] = 0;

                printf("Digite a distância (km): ");
                scanf("%d", &km); getchar();

                int o = inserirCidade(&Grafo, nome1);
                int d = inserirCidade(&Grafo, nome2);
                if (!ExisteAresta(o, d, &Grafo)) {
                    InsereAresta(o, d, km, &Grafo);
                    printf("Rodovia inserida!\n");
                } else {
                    printf("Já existe uma rodovia.\n");
                }
                break;

            case 2:
                ImprimeGrafo(&Grafo);
                break;

            case 3:
                printf("Digite cidade origem: ");
                fgets(nome1, sizeof(nome1), stdin);
                nome1[strcspn(nome1, "\n")] = 0;

                printf("Digite cidade destino: ");
                fgets(nome2, sizeof(nome2), stdin);
                nome2[strcspn(nome2, "\n")] = 0;

                printf("Digite a distância (km): ");
                scanf("%d", &km); getchar();

                o = inserirCidade(&Grafo, nome1);
                d = inserirCidade(&Grafo, nome2);

                if (!ExisteAresta(o, d, &Grafo)) {
                    InsereAresta(o, d, km, &Grafo);
                    printf("Rodovia inserida!\n");
                } else {
                    printf("Já existe uma rodovia.\n");
                }
                break;

            case 4:
                // Remoção
                printf("Origem: ");
                fgets(nome1, sizeof(nome1), stdin);
                nome1[strcspn(nome1, "\n")] = 0;
                printf("Destino: ");
                fgets(nome2, sizeof(nome2), stdin);
                nome2[strcspn(nome2, "\n")] = 0;

                o = obterIndiceCidade(&Grafo, nome1);
                d = obterIndiceCidade(&Grafo, nome2);
                if (o != -1 && d != -1 && ExisteAresta(o, d, &Grafo)) {
                    RetiraAresta(o, d, &Grafo);
                    printf("Rodovia removida.\n");
                } else {
                    printf("Rodovia não encontrada.\n");
                }
                break;

            case 5:
                printf("Cidade 1: ");
                fgets(nome1, sizeof(nome1), stdin);
                nome1[strcspn(nome1, "\n")] = 0;

                printf("Cidade 2: ");
                fgets(nome2, sizeof(nome2), stdin);
                nome2[strcspn(nome2, "\n")] = 0;

                o = obterIndiceCidade(&Grafo, nome1);
                d = obterIndiceCidade(&Grafo, nome2);
                if (o != -1 && d != -1 && ExisteAresta(o, d, &Grafo)) {
                    km = KM(o, d, &Grafo);
                    printf("Existe rodovia de %dkm entre %s e %s\n", km, nome1, nome2);
                } else {
                    printf("Não existe rodovia entre as cidades.\n");
                }
                break;

            case 6:
                printf("Cidade: ");
                fgets(nome1, sizeof(nome1), stdin);
                nome1[strcspn(nome1, "\n")] = 0;

                o = obterIndiceCidade(&Grafo, nome1);
                if (o != -1) {
                    TipoApontador p = Grafo.Adj[o].Primeiro->Prox;
                    while (p != NULL) {
                        if (p->Item.km <= 100) {
                            printf("-> %s (%dkm)\n", Grafo.nomeCidades[p->Item.destino], p->Item.km);
                        }
                        p = p->Prox;
                    }
                } else {
                    printf("Cidade não encontrada.\n");
                }
                break;

            case 7:
                if (VerificaCiclo(&Grafo))
                    printf("O grafo possui ciclos.\n");
                else
                    printf("O grafo é acíclico.\n");
                break;

            case 0:
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while(opcao != 0);

    LiberaGrafo(&Grafo);
    return 0;
}

/*
Referencias:
- https://replit.com/@mcamilab/Exemplo-TAD-Grafos-Lista-Adjacencia
- Slides das aulas de grafos
- https://www.youtube.com/@progdescomplicada
- https://www.terra.com.br/noticias/brasil/estradas/sudeste-tem-a-malha-viaria-mais-ampla-e-diversificada,e04e9618d103427884440bf1310206f5h7xleps4.html

Exemplo de entrada:

*/
