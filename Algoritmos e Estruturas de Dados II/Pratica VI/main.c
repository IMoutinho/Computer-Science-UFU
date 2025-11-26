
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

typedef struct produto {
    char nome[51];
    char tipo;
    int qtd;
} Produtos;

typedef Produtos* Hash[MAX];

void inicializarHash(Hash tabela) {
    for (int i = 0; i < MAX; i++) {
        tabela[i] = NULL;
    }
}

int hash(char tipo) {
    return ((int)tipo % MAX);
}


void hsh_insere(Hash tabela, char tipo, const char* nome, int quantidade) {
    int indice = hash(tipo);
    int indice_original = indice;

    while (tabela[indice] != NULL) {
        indice = (indice + 1) % MAX;
        if (indice == indice_original) {
            printf("\nERRO: Tabela cheia! Não foi possível inserir o produto.\n");
            return;
        }
    }

    tabela[indice] = (Produtos*)malloc(sizeof(Produtos));
    if (tabela[indice] == NULL) {
        printf("\nERRO: Falha ao alocar memória!\n");
        return;
    }

    strcpy(tabela[indice]->nome, nome);
    tabela[indice]->tipo = tipo;
    tabela[indice]->qtd = quantidade;
    printf("\nProduto %s inserido com sucesso!\n", nome);
}

void hsh_lista_por_tipo(Hash tabela, char tipo) {
    int indice = hash(tipo);
    int indice_original = indice;
    int encontrou_algum = 0;

    printf("\n--- Produtos do tipo '%c' ---\n", tipo);

    while (tabela[indice] != NULL) {
        if (tabela[indice]->tipo == tipo) {
            printf("- %s\n", tabela[indice]->nome);
            encontrou_algum = 1;
        }
        indice = (indice + 1) % MAX;
        if (indice == indice_original) {
            break;
        }
    }

    if (encontrou_algum == 0) {
        printf("Nenhum produto encontrado para este tipo.\n");
    }
}

void hsh_conta_todos_tipos(Hash tabela) {
    char chaves_tipo[] = {'A', 'H', 'L', 'V'};
    char* nomes_tipo[] = {"Alimentação", "Higiene", "Limpeza", "Vestuário"};
    int num_tipos = sizeof(chaves_tipo) / sizeof(chaves_tipo[0]);
    int contadores[num_tipos];

    for (int i = 0; i < num_tipos; i++) {
        contadores[i] = 0;
    }

    for (int i = 0; i < MAX; i++) {
        if (tabela[i] != NULL) {
            for (int j = 0; j < num_tipos; j++) {
                if (tabela[i]->tipo == chaves_tipo[j]) {
                    contadores[j]++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < num_tipos; i++) {
        printf("%s - %d produto\n", nomes_tipo[i], contadores[i]);
    }
}

int main() {
    Hash minhaTabela;
    inicializarHash(minhaTabela);
    int opcao;

    do {
        
        printf("\n=================== MENU ===================\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar produtos por tipo\n");
        printf("3 - Contar produtos por tipo\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1: {
            Produtos novo;
            char tipo_valido;

            printf("\n--- Cadastrar Produto ---\n");
            printf("Descrição: ");
            fgets(novo.nome, 51, stdin);
            novo.nome[strcspn(novo.nome, "\n")] = '\0';

            do {
                printf("Tipo (A-Alimentação, H-Higiene, L-Limpeza, V-Vestuário): ");
                scanf(" %c", &novo.tipo);
                tipo_valido = (novo.tipo == 'A' || novo.tipo == 'H' || novo.tipo == 'L' || novo.tipo == 'V');
                if (!tipo_valido) {
                    printf("Tipo inválido! Por favor, insira uma das opções válidas em maiúsculo.\n");
                }
            } while (!tipo_valido);

            printf("Quantidade: ");
            scanf("%d", &novo.qtd);

            hsh_insere(minhaTabela, novo.tipo, novo.nome, novo.qtd);
            break;
        }
        case 2: {
            char tipo_buscado;
            printf("\n--- Consultar por Tipo ---\n");
            printf("Digite o tipo a ser consultado (A, H, L, V): ");
            scanf(" %c", &tipo_buscado);
            hsh_lista_por_tipo(minhaTabela, tipo_buscado);
            break;
        }
        case 3: {
            printf("\n--- Resumo de Produtos por Tipo ---\n");
            hsh_conta_todos_tipos(minhaTabela);
            break;
        }
        case 4:
            printf("\nAté mais!\n");
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
            break;
        }
    } while (opcao != 4);

    for (int i = 0; i < MAX; i++) {
        if (minhaTabela[i] != NULL) {
            free(minhaTabela[i]);
        }
    }

    return 0;
}



