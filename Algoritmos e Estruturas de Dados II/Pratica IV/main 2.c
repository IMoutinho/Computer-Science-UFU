#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Gabriel Antonio Gomes Moutinho - 12311bcc073
//Gabriel Henrique Carneiro Amorim - 12411bcc055

typedef struct cep {
    char cep[9];
    char estado[3];
    char cidade[50];
    char rua[100];
    struct cep *prox;
} Cep;

Cep* insereNoInicio(Cep *lista, char *cep, char *estado, char *cidade, char *rua) {
    Cep *novoCep = (Cep*) malloc(sizeof(Cep));
    if (!novoCep) return lista;
    strcpy(novoCep->cep, cep);
    strcpy(novoCep->estado, estado);
    strcpy(novoCep->cidade, cidade);
    strcpy(novoCep->rua, rua);
    novoCep->prox = lista;
    return novoCep;
}

Cep* criaListaVazia() {
    return NULL;
}

int tamanhoLista(Cep *lista) {
    int t = 0;
    while (lista) {
        t++;
        lista = lista->prox;
    }
    return t;
}

void listaParaVetor(Cep *lista, Cep *vetor) {
    int i = 0;
    while (lista) {
        vetor[i++] = *lista;
        lista = lista->prox;
    }
}

void shellSort(Cep *dados, int tamanho) {
    int h = 1;
    while (h < tamanho / 3) h = 3 * h + 1;
    while (h > 0) {
        for (int i = h; i < tamanho; i++) {
            Cep temp = dados[i];
            int j = i;
            while (j >= h && strcmp(dados[j - h].cep, temp.cep) > 0) {
                dados[j] = dados[j - h];
                j -= h;
            }
            dados[j] = temp;
        }
        h = (h - 1) / 3;
    }
}

int buscaBinaria(Cep *dados, int tamanho, char *chave) {
    int esquerda = 0, direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        int cmp = strcmp(dados[meio].cep, chave);
        if (cmp == 0) return meio;
        else if (cmp < 0) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return -1;
}

int main() {
    Cep *lista = criaListaVazia();
    FILE *arquivo = fopen("cep.txt", "r");
    if (!arquivo) return 1;

    char cep[9], estado[3], cidade[50], rua[100];
    while (fscanf(arquivo, " %8[^\t]\t%2[^\t]\t%49[^\t]\t%99[^\n]", cep, estado, cidade, rua) == 4) {
        lista = insereNoInicio(lista, cep, estado, cidade, rua);
    }
    fclose(arquivo);

    int n = tamanhoLista(lista);
    Cep *vetor = malloc(n * sizeof(Cep));
    listaParaVetor(lista, vetor);
    shellSort(vetor, n);

    char chave[9];
    printf("Digite o CEP para buscar: ");
    scanf("%8s", chave);

    int pos = buscaBinaria(vetor, n, chave);
    if (pos != -1) {
        printf("Encontrado: %s - %s - %s - %s\n",
               vetor[pos].cep, vetor[pos].estado, vetor[pos].cidade, vetor[pos].rua);
    } else {
        printf("CEP nao encontrado.\n");
    }

    free(vetor);
    return 0;
}
