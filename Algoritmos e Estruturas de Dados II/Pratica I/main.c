/*Alunos: Gabriel Antonio Gomes Moutinho - Matrícula: 12311bcc073
Gabriel Henrique Carneiro Amorim - Matrícula: 12411bcc055*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    char nome[50];
    char naturalidade[30];
    int idade;
    float salario;
    struct funcionario* prox;
}Funcionarios;

Funcionarios* criarListaVazia(){
    return NULL;
}

Funcionarios* insereInicio(Funcionarios *l, Funcionarios novo){
    Funcionarios* novoFuncionario = (Funcionarios*) malloc(sizeof(Funcionarios));

    if (novoFuncionario == NULL) {
        printf("Erro ao alocar memória!\n");
        return l;
    }


    strcpy(novoFuncionario->nome, novo.nome);
    strcpy(novoFuncionario->naturalidade, novo.naturalidade);
    novoFuncionario->idade = novo.idade;
    novoFuncionario->salario = novo.salario;
    novoFuncionario->prox = l;

    return novoFuncionario;
}

Funcionarios* ordenaBCSalario(Funcionarios *l){
    if (l == NULL || l->prox==NULL){
        printf ("Lista vazia ou lista com só um elemento!");
        return l;
    }

    int trocou;
    Funcionarios *ultimo = NULL;

    do {
        trocou = 0;
        Funcionarios *atual = l;

        while (atual->prox != ultimo) {
            if (atual->salario > atual->prox->salario) {

                Funcionarios temp = *atual;

                strcpy(atual->nome, atual->prox->nome);
                strcpy(atual->naturalidade, atual->prox->naturalidade);
                atual->idade = atual->prox->idade;
                atual->salario = atual->prox->salario;


                strcpy(atual->prox->nome, temp.nome);
                strcpy(atual->prox->naturalidade, temp.naturalidade);
                atual->prox->idade = temp.idade;
                atual->prox->salario = temp.salario;

                trocou = 1;
            }
            atual = atual->prox;
        }
        ultimo = atual;
    } while(trocou);
    return l;
}

Funcionarios* ordenaBDidade(Funcionarios *l){
    if (l == NULL || l->prox==NULL){
        printf ("Lista vazia ou lista com só um elemento!");
        return l;
    }

    int trocou;
    Funcionarios *ultimo = NULL;

    do {
        trocou = 0;
        Funcionarios *atual = l;

        while (atual->prox != ultimo) {
            if (atual->idade < atual->prox->idade) {

                Funcionarios temp = *atual;

                strcpy(atual->nome, atual->prox->nome);
                strcpy(atual->naturalidade, atual->prox->naturalidade);
                atual->idade = atual->prox->idade;
                atual->salario = atual->prox->salario;

                strcpy(atual->prox->nome, temp.nome);
                strcpy(atual->prox->naturalidade, temp.naturalidade);
                atual->prox->idade = temp.idade;
                atual->prox->salario = temp.salario;

                trocou = 1;
            }
            atual = atual->prox;
        }
        ultimo = atual;
    } while(trocou);
    return l;
}

Funcionarios* ordenaBAlfabetica(Funcionarios *l){
    if (l == NULL || l->prox==NULL){
        printf ("Lista vazia ou lista com só um elemento!");
        return l;
    }

    int trocou;
    Funcionarios *ultimo = NULL;

    do {
        trocou = 0;
        Funcionarios *atual = l;

        while (atual->prox != ultimo) {
            if (strcmp(atual->nome, atual->prox->nome)>0) {

                Funcionarios temp = *atual;

                strcpy(atual->nome, atual->prox->nome);
                strcpy(atual->naturalidade, atual->prox->naturalidade);
                atual->idade = atual->prox->idade;
                atual->salario = atual->prox->salario;

                strcpy(atual->prox->nome, temp.nome);
                strcpy(atual->prox->naturalidade, temp.naturalidade);
                atual->prox->idade = temp.idade;
                atual->prox->salario = temp.salario;

                trocou = 1;
            }
            atual = atual->prox;
        }
        ultimo = atual;
    } while(trocou);
    return l;
}


Funcionarios* ordenaSCsalario(Funcionarios *l) {
    if (l == NULL || l->prox == NULL) {
        return l;
    }

    Funcionarios *atual = l;

    while (atual != NULL) {

        Funcionarios *menor = atual;
        Funcionarios *temp = atual->prox;

        while (temp != NULL) {
            if (temp->salario < menor->salario) {
                menor = temp;
            }
            temp = temp->prox;
        }


        if (menor != atual) {
            Funcionarios aux = *atual;


            strcpy(atual->nome, menor->nome);
            strcpy(atual->naturalidade, menor->naturalidade);
            atual->idade = menor->idade;
            atual->salario = menor->salario;


            strcpy(menor->nome, aux.nome);
            strcpy(menor->naturalidade, aux.naturalidade);
            menor->idade = aux.idade;
            menor->salario = aux.salario;
        }

        atual = atual->prox;
    }

    return l;
}

Funcionarios* ordenaSDidade(Funcionarios *l) {
    if (l == NULL || l->prox == NULL) {
        return l;
    }

    Funcionarios *atual = l;

    while (atual != NULL) {

        Funcionarios *maior = atual;
        Funcionarios *temp = atual->prox;

        while (temp != NULL) {
            if (temp->idade > maior->idade) {
                maior = temp;
            }
            temp = temp->prox;
        }


        if (maior != atual) {
            Funcionarios aux = *atual;


            strcpy(atual->nome, maior->nome);
            strcpy(atual->naturalidade, maior->naturalidade);
            atual->idade = maior->idade;
            atual->salario = maior->salario;


            strcpy(maior->nome, aux.nome);
            strcpy(maior->naturalidade, aux.naturalidade);
            maior->idade = aux.idade;
            maior->salario = aux.salario;
        }

        atual = atual->prox;
    }

    return l;
}

Funcionarios* ordenaSAlfabetica(Funcionarios *l) {
    if (l == NULL || l->prox == NULL) {
        return l;
    }

    Funcionarios *atual = l;

    while (atual != NULL) {

        Funcionarios *menor = atual;
        Funcionarios *temp = atual->prox;

        while (temp != NULL) {
            if (strcmp(temp->nome, menor->nome) < 0) {
                menor = temp;
                    }
            temp = temp->prox;
        }

        if (menor != atual) {
            Funcionarios aux = *atual;


            strcpy(atual->nome, menor->nome);
            strcpy(atual->naturalidade, menor->naturalidade);
            atual->idade = menor->idade;
            atual->salario = menor->salario;


            strcpy(menor->nome, aux.nome);
            strcpy(menor->naturalidade, aux.naturalidade);
            menor->idade = aux.idade;
            menor->salario = aux.salario;
        }

        atual = atual->prox;
    }

    return l;
}

void imprimeLista(Funcionarios* l) {
    if (l == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    printf("\n=== Funcionários ===\n");
    Funcionarios* aux = l;
    while (aux != NULL) {
        printf("Nome: %s| Naturalidade: %s|Idade: %d| Salário: %.2f\n", aux->nome, aux->naturalidade, aux->idade, aux->salario);
        aux = aux->prox;
    }
}

int main(){
    Funcionarios* lista = criarListaVazia();
    int opcao, contador=0;

    do {
        printf("\n------ MENU -------\n");
        printf("1. Inserir novo funcionário\n");
        printf("2. Imprimir lista atual\n");
        printf("3. Ordenar por salário (crescente) - BubbleSort\n");
        printf("4. Ordenar por salário (crescente) - SelectionSort\n");
        printf("5. Ordenar por idade (decrescente) - BubbleSort\n");
        printf("6. Ordenar por idade (decrescente) - SelectionSort\n");
        printf("7. Ordenar por nome (alfabética) - BubbleSort\n");
        printf("8. Ordenar por nome (alfabetica) - Selection Sort\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){

            case 1: {
                if (contador >= 10) {
                printf("Limite máximo de 10 funcionários atingido.\n");
                break;
            }
                Funcionarios novo;
                printf("Nome: ");
                fgets(novo.nome, 50, stdin);
                novo.nome[strcspn(novo.nome, "\n")] = '\0';

                printf("Naturalidade: ");
                fgets(novo.naturalidade, 30, stdin);
                novo.naturalidade[strcspn(novo.naturalidade, "\n")] = '\0';

                printf("Idade: ");
                scanf("%d", &novo.idade);

                printf("Salário: ");
                scanf("%f", &novo.salario);
                getchar();

                lista = insereInicio(lista, novo);
                contador++;
                printf("\n\nFuncionário inserido!\n");
                break;
            }

            case 2:
                imprimeLista(lista);
                break;

            case 3:
                printf("\nOrdenado por salario BubbleSort Crescente:\n");
                lista = ordenaBCSalario(lista);
                imprimeLista(lista);
                break;
            case 4:
                printf("\nOrdenado por salario SelectionSort Crescente:\n");
                lista = ordenaSCsalario(lista);
                imprimeLista(lista);
                break;
            case 5:
                printf("\nOrdenado por idade BubbleSort Decrescente:\n");
                lista = ordenaBDidade(lista);
                imprimeLista(lista);
                break;
            case 6:
                printf("\nOrdenado por idade SelectionSort Decrescente:\n");
                lista = ordenaSDidade(lista);
                imprimeLista(lista);
                break;
            case 7:
                printf("\nOrdenado Alfabeticamente BubbleSort:\n");
                lista = ordenaBAlfabetica(lista);
                imprimeLista(lista);
                break;
            case 8:
                printf("\nOrdenado Alfabeticamente SelectionSort:\n");
                lista = ordenaSAlfabetica(lista);
                imprimeLista(lista);
                break;
            case 0:
                printf("Encerrando....");
                break;
            default:
                printf("Opção invalida\n");
                break;
        }

    }while(opcao!=0);

    return 0;
}












