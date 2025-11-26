#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <string.h>

int main (){
    Alunos *l=criaListaVazia();
    int opcao;
    float n1, n2;
    char nome[40];
    
    do {
        printf("\n ------------------------------------MENU------------------------------------\n");
        printf("1-Inserir Aluno - Informar: nome, nota prática (até 50) e nota teórica (até 50)\n");
        printf("2-Buscar aluno pelo nome - Informar nome completo:\n");
        printf("3-Retornar alunos com média superior à 70:\n");
        printf("4-Remover Aluno - Informar o nome completo:\n");
        printf("0-Sair do menu.\n");
        scanf("%d", &opcao);
        getchar();
        
        switch(opcao){
            case 1:
                printf("Digite o nome completo:\n");
                fgets(nome, 40,stdin);
                printf("Digite a nota prática(Max 50):\n");
                scanf("%f",&n1);
                getchar();
                    while(n1>50){
                        printf("Nota maior que 50. Digite a nota corretamente:\n");
                        scanf("%f",&n1);
                        getchar();
                    }
                printf("Digite a nota teorica(Max 50):\n");
                scanf("%f",&n2);
                getchar();
                    while(n2>50){
                        printf("Nota maior que 50. Digite a nota corretamente:\n");
                        scanf("%f",&n2);
                        getchar();
                    }
                Alunos novo;
                strcpy(novo.nome,nome);
                novo.pratica=n1;
                novo.teorica=n2;
            
            
                l=insereInicio(l, novo);
                
                break;
            
            case 2:
                printf("Digite o nome completo do aluno:\n");
                fgets(nome, 40,stdin);
                float nota;
                nota=pesquisaNota(l, nome);
                if(nota!=-1){
                printf("Nota do aluno %s:\n%f.\n",nome,nota);}
                else {
                    printf("Aluno inexistente!");
                }
                break;
            case 3:
                imprimeAprovados(l);
                break;
            case 4:
                printf("Digite o nome do aluno para remoção:\n");
                fgets(nome, 40,stdin);
                l = removeAluno(l, nome);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf ("Opção inexistente!\n");

        }
    }
    while(opcao!=0);
    
    liberaLista(l);
    
    return 0;
}