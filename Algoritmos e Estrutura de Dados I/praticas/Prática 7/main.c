#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"
#include <time.h>


int main(){

    Circular* lista = criarListavazia(); 
    int qnt = 0, k, opcao;
    char name[30];

    srand(time(NULL));

    printf ("ESCOLHA DO LIDER!\n");


    do {
        printf("\nO que deseja fazer?\n");
        printf ("\n 1 - Inserir nomes manualmente.\n");
        printf ("\n 2 - Inserir nomes via arquivo TXT.\n");
        printf ("\n 3 - Sortear líder aleatório.\n");
        printf("4 - Sair.\n");
        printf("Opção: ");
        
        scanf ("%d",&opcao);
        getchar();

        switch(opcao) {
            case 1:
                do {
                    printf("Digite o nome a ser inserido: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0'; // remove o \n do final

                    inserirInicio(&lista, name, &qnt);

                    printf("Deseja inserir mais algum nome? (1 - Sim / 2 - Não): ");
                    scanf("%d", &opcao);
                    getchar();
                } while(opcao == 1);
                break;
            
            case 2: 
            carregarNomesArquivo(&lista, "nomes.txt", &qnt);
            break;

            case 3: 
            if (qnt == 0) {
                printf("Lista vazia! Adicione nomes primeiro.\n");
                break;
            }

            k = rand() % qnt + 1; 
            printf("Número aleatório escolhido: %d\n", k);
            escolhaLider(&lista, &qnt, k);
            break;
            
            case 4:
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opção inválida!\n");
    }
} while(opcao != 4);

return 0;
}