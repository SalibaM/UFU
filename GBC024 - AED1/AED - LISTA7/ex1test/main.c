#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){

    Lista *l;
    Aluno it;
    int posicao;
    int opcao;
    int matchave;
    int tamanholista;

    do{
        printf("----MENU----\n");
        printf("\n");
        printf("1.Criar lista.\n");
        printf("2.Limpar lista.\n");
        printf("3.Inserir item no inicio da lista.\n");
        printf("4.Inserir item no fim da lista.\n");
        printf("5.Remover item no inicio da lista.\n");
        printf("6.Remover item no fim da lista.\n");
        printf("7.Remover posicao da lista.\n");
        printf("8.Remover item especifico da lista.\n");
        printf("9.Buscar item na lista.\n");
        printf("10.Buscar posicao na lista.\n");
        printf("11.Inserir item em posicao espeficica.\n");
        printf("12.Verificar se lista esta vazia.\n");
        printf("13.Verificar se lista esta cheia.\n");
        printf("14.Tamanho da lista atual.\n");
        printf("15.Mostrar lista.\n");
        printf("16.Sair do programa.\n");

        printf("\n");

        printf("Selecione sua opcao:\n");
        scanf("%d",&opcao);

        switch(opcao){


            case 1:

                l = criar();

                printf("Lista criada com sucesso!\n");
                printf("\n\n");

            break;

            case 2:

                limpar(l);
                printf("Lista limpa com sucesso!\n");

            break;

            case 3:

                printf("Digite os dados do aluno:\n");

                printf("MATRICULA:");
                scanf("%d",&it.mat);

                printf("NOME:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);

                printf("N1:");
                scanf("%f",&it.n1);

                if(inserirInicio(l,it)==2){
                    printf("Problema de memoria na lista :(...\n");
                    printf("Saindo...");
                    exit(1);
                } else {
                    if(inserirInicio(l,it)==1){
                        printf("Lista cheia!\n");
                        printf("\n\n");
                    }
                }

                inserirInicio(l,it);

                printf("Aluno inserido com sucesso!\n");

                printf("\n\n");

                break;

            case 4:

                printf("Digite os dados do aluno:\n");

                printf("MATRICULA:");
                scanf("%d",&it.mat);

                printf("NOME:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);

                printf("N1:");
                scanf("%f",&it.n1);

                if(inserirFim(l,it)==2){
                    printf("Problema de memoria na lista :(...\n");
                    printf("Saindo...");
                    exit(1);
                } else {
                    if(inserirFim(l,it)==1){
                        printf("Lista cheia!\n");
                        printf("\n\n");
                    }
                }

                inserirFim(l,it);

                printf("Aluno inserido com sucesso!\n");

                printf("\n\n");

            break;

            case 5:

                if(removerInicio(l)==2){
                    printf("Problema de memoria na lista :(...\n");
                    printf("Saindo...");
                    exit(1);
                } else {
                    if(removerInicio(l)==1){
                        printf("Lista cheia!\n");
                        printf("\n\n");
                    }
                }

                removerInicio(l);

                printf("Aluno removido com sucesso!\n");

                printf("\n\n");

            break;

            case 6:

                if(removerFim(l)==2){
                    printf("Problema de memoria na lista :(...\n");
                    printf("Saindo...");
                    exit(1);
                } else {
                    if(removerFim(l)==1){
                        printf("Lista cheia!\n");
                        printf("\n\n");
                    }
                }

                removerFim(l);

                printf("Aluno removido com sucesso!\n");

                printf("\n\n");

            break;

            case 7:

                printf("Digite a posicao que sera removida:\n");
                scanf("%d",&posicao);

                if(removerPosicao(l,posicao)==2){
                    printf("Problema de memoria na lista :(...\n");
                    printf("Saindo...");
                    exit(1);
                } else {
                    if(removerPosicao(l,posicao)==1){
                        printf("Lista cheia!\n");
                        printf("\n\n");
                    }
                }

                removerPosicao(l,posicao);

                printf("Aluno/posicao removido(a) com sucesso!\n");

                printf("\n\n");



            break;

            case 8:

                printf("Digite a matricula do aluno:\n");

                printf("MATRICULA:");
                scanf("%d",&it.mat);

                if(removerItem(l,it)==2){
                    printf("Problema de memoria na lista :(...\n");
                    printf("Saindo...");
                    exit(1);
                } else {
                    if(removerItem(l,it)==1){
                        printf("Lista cheia!\n");
                        printf("\n\n");
                    }
                }

                removerItem(l,it);

                printf("Aluno removido com sucesso!\n");

                printf("\n\n");


            break;

            case 9:

                printf("Digite a matricula do aluno:\n");
                scanf("%d",&matchave);

                if(buscarItemChave(l,matchave,&it)==2){
                    printf("Problema de memoria na lista :(...\n");
                    printf("Saindo...");
                    exit(1);
                } else {
                    if(buscarItemChave(l,matchave,&it)==1){
                        printf("Lista cheia!\n");
                        printf("\n\n");
                    }
                }

                if(buscarItemChave(l,matchave,&it)==-1){
                    printf("Aluno/item encontrado!\n");
                    printf("\n\n");
                }

            break;

            case 10:

                printf("Digite a posicao que sera buscada:\n");
                scanf("%d",&posicao);

                if(buscarPosicao(l,posicao,&it)==2){
                    printf("Problema de memoria na lista :(...\n");
                    printf("Saindo...");
                    exit(1);
                } else {
                    if(buscarPosicao(l,posicao,&it)==1){
                        printf("Lista cheia!\n");
                        printf("\n\n");
                    }
                }

                if(buscarPosicao(l,posicao,&it)==3){
                    printf("Aluno nao encontrado...");
                    printf("\n\n");
                }

                if(buscarPosicao(l,posicao,&it)==4){

                    printf("Aluno encontrado nessa posicao!\n");
                    printf("DADOS DO ALUNO:\n");

                    printf("MATRICULA: %d",it.mat);

                    printf("NOME: %s",it.nome);

                    printf("N1: %f",it.n1);

                    printf("\n\n");

                }

            break;

            case 11:

                printf("Digite a posicao que o item sera inserido:\n");
                scanf("%d",&posicao);

                printf("Digite os dados do aluno:\n");

                printf("MATRICULA:");
                scanf("%d",&it.mat);

                printf("NOME:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);

                printf("N1:");
                scanf("%f",&it.n1);

                if(inserirPosicao(l,it,posicao)==2){
                    printf("Problema de memoria na lista :(...\n");
                    printf("Saindo...");
                    exit(1);
                } else {
                    if(inserirPosicao(l,it,posicao)==1){
                        printf("Lista cheia!\n");
                        printf("\n\n");
                    }
                }

                inserirPosicao(l,it,posicao);

                printf("Aluno inserido com sucesso!\n");

                printf("\n\n");

            break;

            case 12:

                if(listaVazia(l)==0){
                    printf("A lista esta vazia!\n");
                    printf("\n\n");
                } else {
                    if(listaVazia(l)==2){
                        printf("Erro de memoria na lista :(...\n");
                        printf("\n\n");
                    } else {
                        if(listaVazia(l)==-1){
                            printf("A lista nao esta vazia!\n");
                            printf("\n\n");
                        }


                    }
                }


            break;

            case 13:

                if(listaCheia(l)==0){
                printf("A lista esta cheia!\n");
                printf("\n\n");
                    } else {
                        if(listaVazia(l)==2){
                            printf("Erro de memoria na lista :(...\n");
                            printf("\n\n");
                        } else {
                            if(listaVazia(l)==1){
                                printf("A lista nao esta cheia!\n");
                                printf("\n\n");
                            }


                        }
                    }

            break;

            case 14:

                tamanholista=tamanho(l);

                printf("A lista atual tem %d elementos!\n",tamanholista);
                printf("\n\n");

            break;

            case 15:

                mostrar(l);

            break;

            case 16:

                printf("Saindo...\n");
                exit(0);

            break;

            default:

                printf("Opcao invalida!\n");

            break;
        }

    }while(opcao!=16);

    free(l);

    return 0;
}
