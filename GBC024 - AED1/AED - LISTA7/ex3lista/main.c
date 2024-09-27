#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"
#include <string.h>

int main(){

    Lista *laux;
    Lista *l;
    Aluno it;
    int posicao;
    int opcao;
    int matchave;
    int tamanholista;
    int tamanhototal;
    int contador;

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
        printf("16.Verificar se determinado item esta na lista.\n");
        printf("17.Mostrar lista reversa.\n");
        printf("18.Contar quantas ocorrencias certo elemento tem na lista.\n");
        printf("19.Sair do programa.\n");

        printf("\n");

        printf("Selecione sua opcao:\n");
        scanf("%d",&opcao);

        switch(opcao){


            case 1:

                printf("Qual o tamanho maximo da lista?\n");
                scanf("%d",&tamanhototal);

                l = criar(tamanhototal);
                laux = criar(tamanhototal);

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

                it.nome[strcspn(it.nome, "\n")] = '\0';

                printf("N1:");
                scanf("%f",&it.n1);

                inserirInicio(l,it,tamanhototal);

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

                it.nome[strcspn(it.nome, "\n")] = '\0';

                printf("N1:");
                scanf("%f",&it.n1);

                inserirFim(l,it,tamanhototal);

                printf("Aluno inserido com sucesso!\n");

                printf("\n\n");

            break;

            case 5:

                removerInicio(l);

                printf("Aluno removido com sucesso!\n");

                printf("\n\n");

            break;

            case 6:

                removerFim(l);

                printf("Aluno removido com sucesso!\n");

                printf("\n\n");

            break;

            case 7:

                printf("Digite a posicao que sera removida:\n");
                scanf("%d",&posicao);

                removerPosicao(l,posicao);

                printf("Aluno/posicao removido(a) com sucesso!\n");

                printf("\n\n");



            break;

            case 8:

                printf("Digite os dados do aluno:\n");

                printf("MATRICULA:");
                scanf("%d",&it.mat);

                printf("NOME:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);

                it.nome[strcspn(it.nome, "\n")] = '\0';

                printf("N1:");
                scanf("%f",&it.n1);

                removerItem(l,it);

                printf("Aluno removido com sucesso!\n");

                printf("\n\n");


            break;

            case 9:

                printf("Digite os dados do aluno:\n");

                printf("MATRICULA:");
                scanf("%d",&it.mat);

                printf("NOME:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);

                it.nome[strcspn(it.nome, "\n")] = '\0';

                printf("N1:");
                scanf("%f",&it.n1);

                matchave = it.mat;

                if(buscarItemChave(l,matchave,&it)==-1){
                    printf("Aluno/item encontrado!\n");
                    printf("\n\n");
                }

            break;

            case 10:

                printf("Digite a posicao que sera buscada:\n");
                scanf("%d",&posicao);

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

                it.nome[strcspn(it.nome, "\n")] = '\0';

                printf("N1:");
                scanf("%f",&it.n1);

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

                if(listaCheia(l,tamanhototal)==0){
                printf("A lista esta cheia!\n");
                printf("\n\n");
                    } else {
                        if(listaCheia(l,tamanhototal)==2){
                            printf("Erro de memoria na lista :(...\n");
                            printf("\n\n");
                        } else {
                            if(listaCheia(l,tamanhototal)==1){
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

                printf("Digite os dados do aluno:\n");

                printf("MATRICULA:");
                scanf("%d",&it.mat);

                printf("NOME:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);

                it.nome[strcspn(it.nome, "\n")] = '\0';

                printf("N1:");
                scanf("%f",&it.n1);

                if(ContemItem(l,it)==0){
                    printf("O item esta na lista!\n");
                    printf("\n\n");
                } else {
                    if(ContemItem(l,it)==1){
                        printf("O item nao esta na lista...\n");
                        printf("\n\n");
                    }


                }

            break;

            case 17: ;

                laux = Reversa(l,tamanhototal);

                printf("LISTA REVERSA:\n");

                mostrar(laux);


            break;

            case 18: ;

                printf("Digite os dados do aluno:\n");

                printf("MATRICULA:");
                scanf("%d",&it.mat);

                printf("NOME:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);

                it.nome[strcspn(it.nome, "\n")] = '\0';

                printf("N1:");
                scanf("%f",&it.n1);

                contador = ContaItem(l,it);

                printf("Esse item apareceu %d vezes na lista!\n",contador);
                printf("\n\n");

            break;

            case 19:

                printf("Saindo...\n");
                exit(0);

            break;

            default:

                printf("Opcao invalida!\n");

            break;
        }

    }while(opcao!=19);

    free(l);

    return 0;
}
