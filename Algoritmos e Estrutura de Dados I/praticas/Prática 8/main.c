#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main() {
    Dicionario *lista = criarListaVazia();
    int opcao;

    do {
        printf("\n1 - Inserir verbetes manualmente\n");
        printf("2 - Inserir verbetes via arquivo TXT\n");
        printf("3 - Inserir frases via arquivo TXT\n");
        printf("4 - Pesquisar verbete\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1: {
                Dicionario *novo = (Dicionario*) malloc(sizeof(Dicionario));
                printf("Digite o verbete: ");
                fgets(novo->verbete, sizeof(novo->verbete), stdin);
                novo->verbete[strcspn(novo->verbete, "\n")] = '\0';

                printf("Digite a classificacao: ");
                fgets(novo->classificacao, sizeof(novo->classificacao), stdin);
                novo->classificacao[strcspn(novo->classificacao, "\n")] = '\0';

                printf("Digite o significado: ");
                fgets(novo->significado, sizeof(novo->significado), stdin);
                novo->significado[strcspn(novo->significado, "\n")] = '\0';

                lista = inserirOrdenado(lista, novo);
                printf("Inserido com sucesso!\n");
                break;
            }

            case 2: {
                char nomeArquivo[100];
                printf("Digite o nome do arquivo de dicionario: ");
                fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';
            
                Dicionario *temp = carregarDicionario(nomeArquivo);
                if (temp != NULL) {
                    if (lista == NULL) {
                        lista = temp;
                    } else {
                        Dicionario *aux = temp;
                        while (aux != NULL) {
                             Dicionario *prox = aux->prox;
                             lista = inserirOrdenado(lista, aux);
                             aux = prox;
                        }
                    }
                    printf("Carregado com sucesso!\n");
                } else {
                    printf("Erro ao carregar.\n");
                }
                break;
            }

            case 3: {
                char nomeArquivo[100];
                printf("Digite o nome do arquivo de frases: ");
                fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';
                carregarFrases(lista, nomeArquivo);
                break;
            }

            case 4: {
                char busca[50];
                printf("Digite o verbete: ");
                fgets(busca, sizeof(busca), stdin);
                busca[strcspn(busca, "\n")] = '\0';

                Dicionario *resultado = pesquisaVerbete(lista, busca);
                if (resultado) {
                    printf("\nVerbete: %s\nClassificacao: %s\nSignificado: %s\n", resultado->verbete, resultado->classificacao, resultado->significado);
                } else {
                    printf("Nao encontrado.\n");
                }
                break;
            }

            case 5:
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 5);

    liberaLista(lista);

    return 0;
}
