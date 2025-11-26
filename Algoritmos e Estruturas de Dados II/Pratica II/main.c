// Gabriel Henrique Carneiro Amorim - 12411BCC055
// Gabriel Antonio Gomes Moutinho - 12311BCC073
//Amanda Resende Fernandes - 12411BCC004
//Maria Clara Freitas de Oliveira  - 12411BCC106

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NTAMANHOS 3
#define NTIPOS 3

void bubbleSort(int vetor[], int n, int *comparacoes, int *trocas) {
    int temp, check;
    for (int i = 0; i < n; i++) {
        check = 0; // verifica se houve troca
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                (*trocas)++;
                check = 1;
            }
            (*comparacoes)++;
        }
        // se não houve troca encerra
        if (check == 0) {
            break;
        }
    }
}

void selectionSort(int vetor[], int n, int *comparacoes, int *trocas) {
    int menor, temp;
    for ( int i = 0; i < n; i++) {
        // encontra o menor elemento no restante do vetor
        menor = i;
        for (int j = i + 1; j < n; j++) {
            if (vetor[j] < vetor [menor]) {
                menor = j;
            }
            (*comparacoes)++;
        }
        // troca o menor elemento encontrado
        if (menor != i) {
            temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
            (*trocas)++;
        }
    }
}

void insertionSort(int vetor[], int n, int *comparacoes, int *trocas) {
    int j, chave;
    for (int i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;

        // move os elementos maiores que a chave em uma casa
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
            (*trocas)++;
        }
        (*comparacoes)++;
        vetor[j + 1] = chave;
    }
}

void shellSort(int vetor[], int n, int *comparacoes, int *trocas) {
    int j, aux;
    int h = 1;

    // calcula a sequencia do gap de knuth
    while (h < n /3) {
        h = 3 * h + 1;
    }

    while (h > 0) {
        for (int i = h; i < n; i++) {
            aux = vetor[i];
            j = i - 1;
            while ( j >= h && vetor[j - h] > aux) {
                vetor[j] = vetor[j - h];
                j -= h;
                (*trocas)++;
            }
            vetor[j] = aux;
            (*comparacoes)++;
        }

        // reduz o gap
        h = (h - 1) / 3;
    }
}

typedef enum { ORDENADO, DECRESCENTE, ALEATORIO} TipoEntrada;

const char *nomesTiposEntrada[] = {"Ordenado", "Decrescente", "Aleatorio"};

void preencheVetor(int vetor[], int n, TipoEntrada tipo) {
    switch (tipo) {
        case ORDENADO:
            for (int i = 0; i < n; i++) {
                vetor[i] = i;
            }
            break;
        case DECRESCENTE:
            for (int i = 0; i < n; i++) {
                vetor[i] = n - 1 - i;
            }
            break;
        case ALEATORIO:
            for (int i = 0; i < n; i++) {
                vetor[i] = rand() % 10000;
            }
            break;
    }
}

void tabelaSort(void (*funcaoSort)(int[], int, int*, int*), const char *nomeAlgoritmo, int *vetoresBase[NTIPOS][NTAMANHOS], int tamanhos[]) {
    printf("\n ---------- Resultados para o Algoritmo: %s ---------- \n", nomeAlgoritmo);
    printf("-------------------------------------------------------------------\n");
    printf("| Entrada  (Tamanho) | Tempo (s) | Nro Comparações  | Nro Trocas  |\n");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < NTIPOS; i++) {
        const char *nomeTipo = nomesTiposEntrada[i];

        for (int k = 0; k < NTAMANHOS; k++) {
            int tamanhoVetor = tamanhos[k];

            int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));
            if (vetor == NULL) {
                printf("Erro na alocacao de memoria\n");
                exit(1);
            }

            // cria copia isolada do vetor original
            //memcpy(destino, origem, tamanho em  bytes)
            memcpy(vetor, vetoresBase[i][k], tamanhoVetor * sizeof(int));

            int comparacoes = 0;
            int trocas = 0;

            // permite medir o tempo
            clock_t tempoInicial, tempoFinal;
            double tempoTotal;

            tempoInicial = clock();
            funcaoSort(vetor, tamanhoVetor, &comparacoes, &trocas);
            tempoFinal = clock();
            tempoTotal = (double)(tempoFinal - tempoInicial) / CLOCKS_PER_SEC;

            printf("| %-11s (%5d)| %9.4f | %16d | %11d |\n", nomeTipo, tamanhoVetor, tempoTotal, comparacoes, trocas);
            // %-11s string alinhada à esquerda, 15 colunas
            // %5d string com 5 colunas
            // %9.4f float com 4 casas decimais, mínimo 10 colunas
            // %16d inteiro com 20 colunas, alinhado à direita
            // %11d inteiro com 10 colunas, alinhado à direita

            free(vetor);
        }
        printf("-------------------------------------------------------------------\n");
    }
    printf("\n");
}

int main() {
    // inicia o gerador de números aleatórios uma única vez
    srand(time(NULL));

    int tamanhos[] = {5000, 10000, 20000};
    TipoEntrada tipos[] = {ORDENADO, DECRESCENTE, ALEATORIO};

    int *vetoresBase[NTIPOS][NTAMANHOS];

    // gera o valor dos vetores uma unica vez
    for (int i = 0; i < NTIPOS; i++) {
        for (int j = 0; j < NTAMANHOS; j++) {
            int tamanho = tamanhos[j];
            vetoresBase[i][j] = (int*)malloc(tamanho * sizeof(int));
            if (vetoresBase[i][j] == NULL) {
                printf("Erro na alocacao de memoria\n");
                exit(1);
            }
            preencheVetor(vetoresBase[i][j], tamanho, tipos[i]);
        }
    }

    tabelaSort(bubbleSort, "Bubble Sort", vetoresBase, tamanhos);
    tabelaSort(selectionSort, "Selection Sort", vetoresBase, tamanhos);
    tabelaSort(insertionSort, "Insertion Sort", vetoresBase, tamanhos);
    tabelaSort(shellSort, "Shell Sort", vetoresBase, tamanhos);

    for (int i = 0; i < NTIPOS; i++) {
        for (int j = 0; j < NTAMANHOS; j++) {
            free(vetoresBase[i][j]);
        }
    }

    return 0;
}
