#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void exibirLista(No *l) {
    printf("Lista: ");
    while (l != NULL) {
        printf("%d -> ", l->item);
        l = l->prox;
    }
    printf("NULL\n");
}

int main() {
    No *lnum = criaListaVazia(); // Criando a lista vazia
    int val, opcao, tamanho;

    do {
        printf("\nMENU:\n");
        printf("1 - Inserir elemento no início\n");
        printf("2 - Inserir múltiplos elementos aleatórios\n");
        printf("3 - Exibir lista\n");
        printf("4 - Contar elementos (iterativo)\n");
        printf("5 - Contar elementos (recursivo)\n");
        printf("6 - Remover um elemento específico\n");
        printf("7 - Remover o maior elemento\n");
        printf("8 - Criar uma nova lista apenas com pares\n");
        printf("9 - Converter lista para vetor\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para inserir no início: ");
                scanf("%d", &val);
                lnum = insereInicio(lnum, val);
                break;

            case 2:
                printf("Quantos elementos aleatórios deseja inserir? ");
                scanf("%d", &val);
                lnum = insereVarios(lnum, val);
                break;

            case 3:
                exibirLista(lnum);
                break;

            case 4:
                printf("Número de elementos (Iterativo): %d\n", contaIterativa(lnum));
                break;

            case 5:
                printf("Número de elementos (Recursivo): %d\n", contaRecursiva(lnum));
                break;

            case 6:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &val);
                lnum = removeElemento(lnum, val);
                break;

            case 7:
                lnum = removerMaior(lnum);
                printf("Maior elemento removido!\n");
                break;

            case 8: {
                No *novaLista = filtraPares(lnum);
                printf("Lista apenas com pares:\n");
                exibirLista(novaLista);
                break;
            }

            case 9: {
                int *vetor = listaParaVetor(lnum, &tamanho);
                if (vetor != NULL) {
                    printf("Vetor: ");
                    for (int i = 0; i < tamanho; i++) {
                        printf("%d ", vetor[i]);
                    }
                    printf("\n");
                    free(vetor); // Liberando a memória do vetor
                } else {
                    printf("A lista está vazia!\n");
                }
                break;
            }

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
