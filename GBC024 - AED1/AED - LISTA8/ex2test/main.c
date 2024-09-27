#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"


int main(){

    int opcao;
    Lista *l;
    Lista *l2;
    Aluno it;
    int pos;
    int chave;
    int opcaolista;

    Aluno *it2 = (Aluno *)malloc(sizeof(Aluno));


    do{

        printf("----- MENU -----\n");
        printf("1.Criar lista.\n");
        printf("2.Verificar lista vazia.\n");
        printf("3.Inserir no inicio.\n");
        printf("4.Inserir no fim.\n");
        printf("5.Inserir na posicao.\n");
        printf("6.Remover do inicio.\n");
        printf("7.Remover do fim.\n");
        printf("8.Remover posicao.\n");
        printf("9.Buscar item por chave.\n");
        printf("10.Limpar lista.\n");
        printf("11.Mostrar lista.\n");
        printf("12.Remover item.\n");
        printf("13.Buscar posicao.\n");
        printf("14.Contem item.\n");
        printf("15.Concatenar as duas listas.\n");
        printf("16.Sair.\n");

        printf("Digite sua opcao:\n");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:

                printf("Qual lista voce deseja criar? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    l = criar();
                } else {
                    if(opcaolista==2){
                        l2 = criar();
                    }
                }

                printf("Lista criada com sucesso.\n");

                break;

            case 2:

                printf("Qual lista voce deseja verificar? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    if(listaVazia(l)==0){
                    printf("A lista esta vazia.\n");
                    } else {
                        printf("A lista nao esta vazia ou nao foi criada.\n");
                    }
                } else {
                    if(opcaolista==2){
                        if(listaVazia(l2)==0){
                            printf("A lista esta vazia.\n");
                        } else {
                            printf("A lista nao esta vazia ou nao foi criada.\n");
                        }
                    }
                }

                break;

            case 3:

                printf("Digite os dados:\n");
                printf("Matricula:");
                scanf("%d",&it.mat);
                printf("Nome:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);
                it.nome[strcspn(it.nome, "\n")] = 0;
                printf("N1:");
                scanf("%f",&it.n1);

                printf("Em qual lista voce deseja inserir? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    inserirInicio(l,it);
                } else {
                    if(opcaolista==2){
                        inserirInicio(l2,it);
                    }
                }

                printf("Aluno inserido no inicio com sucesso.\n");

                break;


            case 4:

                printf("Digite os dados:\n");
                printf("Matricula:");
                scanf("%d",&it.mat);
                printf("Nome:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);
                it.nome[strcspn(it.nome, "\n")] = 0;
                printf("N1:");
                scanf("%f",&it.n1);

                printf("Em qual lista voce deseja inserir? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    inserirFim(l,it);
                } else {
                    if(opcaolista==2){
                        inserirFim(l2,it);
                    }
                }
                printf("Aluno inserido no fim com sucesso.\n");

                break;

            case 5:
                printf("Digite os dados:\n");
                printf("Matricula:");
                scanf("%d",&it.mat);
                printf("Nome:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);
                it.nome[strcspn(it.nome, "\n")] = 0;
                printf("N1:");
                scanf("%f",&it.n1);

                printf("Digite a posicao:");
                scanf("%d",&pos);

                printf("Em qual lista voce deseja inserir? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    inserirPosicao(l,it,pos);
                } else {
                    if(opcaolista==2){
                        inserirPosicao(l2,it,pos);
                    }
                }

                printf("Aluno inserido na posicao %d com sucesso.\n",pos);

                pos=0;

                break;

            case 6:

                printf("Qual lista voce deseja remover do inicio? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    if(removerInicio(l)==0){
                        printf("Aluno removido do inicio com sucesso.\n");
                    }
                } else {
                   if(removerInicio(l2)==0){
                        printf("Aluno removido do inicio com sucesso.\n");
                    }
                }

                break;

            case 7:

               printf("Qual lista voce deseja remover do inicio? (1 ou 2):");
               scanf("%d",&opcaolista);

               if(opcaolista==1){
                    if(removerFim(l)==0){
                        printf("Aluno removido do fim com sucesso.\n");
                    }
                } else {
                   if(removerFim(l2)==0){
                        printf("Aluno removido do fim com sucesso.\n");
                    }
                }

                break;

            case 8:

                printf("Digite a posicao:");
                scanf("%d",&pos);

                printf("Qual lista voce deseja remover a posicao? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    if(removerPosicao(l,pos)==0){
                        printf("Posicao %d removida com sucesso.\n",pos);
                    }
                } else {
                    if(removerPosicao(l,pos)==0){
                        printf("Posicao %d removida com sucesso.\n",pos);
                    }
                    }

                pos = 0;

                break;

            case 9:


                printf("Digite a chave que sera buscada:");
                scanf("%d",&chave);

                printf("Em qual lista voce deseja buscar? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    if(buscarItemChave(l,chave,it2)==0){
                        printf("Aluno encontrado. Dados:\n");
                        printf("Matricula:%d\n",it2->mat);
                        printf("Nome:%s\n",it2->nome);
                        printf("N1:%f\n",it2->n1);
                    } else {

                        printf("Aluno nao encontrado.\n");

                    }
                } else {
                    if(buscarItemChave(l2,chave,it2)==0){
                        printf("Aluno encontrado. Dados:\n");
                        printf("Matricula:%d\n",it.mat);
                        printf("Nome:%s\n",it.nome);
                        printf("N1:%f\n",it.n1);
                    } else {

                        printf("Aluno nao encontrado.\n");

                    }
                }

                break;


            case 10:

                printf("Qual lista voce deseja limpar? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                     limpar(l);
                } else {
                    if(opcaolista==2){
                         limpar(l2);
                    }
                }
                printf("Lista limpa com sucesso.\n");

                break;

            case 11:

                printf("Qual lista voce deseja mostrar? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                     mostrar(l);
                } else {
                    if(opcaolista==2){
                         mostrar(l2);
                    }
                }

                break;

            case 12:

                printf("Digite os dados:\n");
                printf("Matricula:");
                scanf("%d",&it.mat);
                printf("Nome:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);
                it.nome[strcspn(it.nome, "\n")] = 0;
                printf("N1:");
                scanf("%f",&it.n1);

                printf("Em qual lista voce deseja remover? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    if(removerItem(l,it)==0){
                        printf("Item removido com sucesso.\n");
                    }
                } else {
                    if(opcaolista==2){
                        if(removerItem(l2,it)==0){
                            printf("Item removido com sucesso.\n");
                        }
                    }
                }

                break;

            case 13:

                printf("Digite a posicao:");
                scanf("%d",&pos);

                printf("Em qual lista voce deseja buscar? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                     if(buscarPosicao(l,pos,it2)==0){
                        printf("Posicao encontrada. Dados:\n");
                        printf("Matricula:%d\n",it2->mat);
                        printf("Nome:%s\n",it2->nome);
                        printf("N1:%f\n",it2->n1);
                    }
                } else {
                    if(opcaolista==2){
                         if(buscarPosicao(l2,pos,it2)==0){
                            printf("Posicao encontrada. Dados:\n");
                            printf("Matricula:%d\n",it2->mat);
                            printf("Nome:%s\n",it2->nome);
                            printf("N1:%f\n",it2->n1);
                        }
                    }
                }

                break;

            case 14:

                printf("Digite os dados:\n");
                printf("Matricula:");
                scanf("%d",&it.mat);
                printf("Nome:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);
                it.nome[strcspn(it.nome, "\n")] = 0;
                printf("N1:");
                scanf("%f",&it.n1);

                printf("Qual lista voce deseja verificar? (1 ou 2):");
                scanf("%d",&opcaolista);

                if(opcaolista==1){
                    if(ContemItem(l,it)==0){
                        printf("A lista 1 contem o item.\n");
                    } else {
                        printf("O item nao esta na lista.\n");
                    }
                } else {
                    if(opcaolista==2){
                        if(ContemItem(l2,it)==0){
                            printf("A lista 2 contem o item.\n");
                        } else {
                            printf("O item nao esta na lista.\n");
                        }
                    }
                }

                break;

            case 15:

                Concatena(l,l2);
                mostrar(l);

                break;

            case 16:

                printf("Saindo...\n");
                exit(0);

                break;

        }




    }while(opcao!=16);

    free(l);
    free(l2);

    return 0;
}
