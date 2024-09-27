#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(){

    int opcao;
    Aluno it;
    Lista *l;
    int r;
    int pos;
    int pos2;
    int chavemat;

    do{

        printf("---MENU---\n");
        printf("1.Criar lista.\n");
        printf("2.Limpar lista.\n");
        printf("3.Tamanho da lista.\n");
        printf("4.Mostrar lista.\n");
        printf("5.Verificar lista vazia.\n");
        printf("6.Inserir inicio.\n");
        printf("7.Inserir fim.\n");
        printf("8.Inserir em posicao.\n");
        printf("9.Remover do inicio.\n");
        printf("10.Remover do fim.\n");
        printf("11.Remover de posicao.\n");
        printf("12.Trocar elementos.\n");
        printf("13.Retirar repeticoes.\n");
        printf("14.Sair.\n");

        printf("Digite a opcao:\n");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:

                l = criar();
                printf("Lista criada.\n");

                break;


            case 2:

                limpar(l);
                printf("Lista limpa.\n");

                break;

            case 3:

                printf("A lista tem tamanho %d.\n",tamanho(l));

                break;

            case 4:
                mostrar(l);
                printf("\n");

                break;

            case 5:
                if(listaVazia(l)==0){
                    printf("A lista esta vazia.\n");

                } else {
                    printf("A lista nao esta vazia.\n");
                }

                break;


            case 6:
                printf("Digite o numero de matricula, nome e nota do aluno, respectivamente:\n");
                scanf("%d",&it.mat);
                setbuf(stdin,NULL);
                fgets(it.nome,50,stdin);
                it.nome[strcspn(it.nome,"\n")]=0;
                scanf("%f",&it.n1);

                r=inserirInicio(l,it);

                if(r==0){
                    printf("Aluno inserido com sucesso!\n");
                } else {
                    printf("Erro!\n");
                }

                break;


            case 7:

                printf("Digite o numero de matricula, nome e nota do aluno, respectivamente:\n");
                scanf("%d",&it.mat);
                setbuf(stdin,NULL);
                fgets(it.nome,50,stdin);
                it.nome[strcspn(it.nome,"\n")]=0;
                scanf("%f",&it.n1);

                r=inserirFim(l,it);

                if(r==0){
                    printf("Aluno inserido com sucesso!\n");
                } else {
                    printf("Erro!\n");
                }

                break;


            case 8:

                printf("Qual posicao?\n");
                scanf("%d",&pos);

                printf("Digite o numero de matricula, nome e nota do aluno, respectivamente:\n");
                scanf("%d",&it.mat);
                setbuf(stdin,NULL);
                fgets(it.nome,50,stdin);
                it.nome[strcspn(it.nome,"\n")]=0;
                scanf("%f",&it.n1);

                r=inserirPosicao(l,it,pos);

                if(r==0){
                    printf("Aluno inserido com sucesso!\n");
                } else {
                    printf("Erro!\n");
                }

                break;

            case 9:

                r = removerInicio(l);
                if(r==0){
                    printf("Aluno removido com sucesso!\n");

                }

                break;
            case 10:

                r = removerFim(l);
                if(r==0){
                    printf("Aluno removido com sucesso!\n");

                }

                break;

            case 11:

                printf("Qual posicao?\n");
                scanf("%d",&pos);

                r = removerPosicao(l,pos);

                if(r==0){
                    printf("Aluno removido com sucesso!\n");

                }

                break;

            case 12:

                printf("Digite a primeira e a segunda posicao,respectivamente:\n");
                scanf("%d%d",&pos,&pos2);

                r = trocarElementos(l,pos,pos2);

                if(r==0){
                    printf("Troca feita!\n");
                }

                break;

            case 13:

                r = retiraRepete(l);

                if(r==0){
                    printf("Repeticoes retiradas!\n");
                }

                break;




            case 14:

                printf("Saindo...\n");

                exit(1);

                break;


        }




    }while(opcao!=14);

    free(l);

    return 0;
}
