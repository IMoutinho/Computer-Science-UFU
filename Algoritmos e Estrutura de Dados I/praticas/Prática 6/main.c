#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int main() {
    srand(time(NULL)); 

    Descritor* lista = (Descritor*)malloc(sizeof(Descritor));
    if (lista == NULL) {
        printf("Erro ao alocar memória para o descritor!\n");
        return 1;
    }

    inicializarLista(lista);

    Nave nave1 = {80, 70, NULL};
    Nave nave2 = {55, 55, NULL};
    Nave nave3 = {90, 90, NULL};

    adicionarnoFinal(&lista, nave1);
    adicionarnoFinal(&lista, nave2);
    adicionarnoFinal(&lista, nave3);

    int opcao;
    Nave nave;

    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar nave no final\n");
        printf("2 - Retirar combustível\n");
        printf("3 - Abastecer\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a capacidade da nave: ");
                scanf("%d", &nave.capacidade);
                printf("Digite o combustível atual da nave: ");
                scanf("%d", &nave.combustivelAt);
                adicionarnoFinal(&lista, nave);
                break;
            case 2:
                retiraCombustivel(lista);
                printf("Combustível das naves atualizado.\n");
                break;
            case 3:
                abastecimento(lista);
                printf("Abastecimento concluído.\n");
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    liberarLista(lista);
    free(lista);

    return 0;
}