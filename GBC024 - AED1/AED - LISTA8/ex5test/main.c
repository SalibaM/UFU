#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){

    int opcao;
    ListaRotas *l = criarListarotas();
    ListaCidades *l2 = criarListacidades();
    Rotas *retorno = (Rotas *)malloc(sizeof(Rotas));
    char nome[30];
    char sigla[5];
    char origem[5];
    char destino[5];
    int preco;


    do{

        printf("----MENU----\n");
        printf("1.Cadastrar novas cidades.\n");
        printf("2.Cadastrar rotas.\n");
        printf("3.Mostrar rota mais barata.\n");
        printf("4.Mostrar rota mais cara.\n");
        printf("5.Consultar trecho.\n");
        printf("6.Sair.\n");

        printf("Digite sua opcao:");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:

                printf("Digite o nome da cidade(ate 30 caracteres):");
                setbuf(stdin,NULL);
                scanf("%s",nome);

                printf("Digite a sigla da cidade(ate 5 caracteres):");
                setbuf(stdin,NULL);
                scanf("%s",sigla);

                if(criarCidade(l2,nome,sigla)==0){
                    printf("Cidade criada com sucesso!\n");
                }

            break;

            case 2:

                printf("Digite a sigla da cidade de origem(ate 5 caracteres):");
                setbuf(stdin,NULL);
                scanf("%s",origem);

                setbuf(stdin,NULL);

                printf("Digite a sigla da cidade de destino(ate 5 caracteres):");
                setbuf(stdin,NULL);
                scanf("%s",destino);

                setbuf(stdin,NULL);

                printf("Digite o preco da viagem:");
                scanf("%d",&preco);

                if(criarRota(l,origem,destino,preco)==0){
                    printf("Rota criada com sucesso!\n");
                }

            break;

            case 3:

                if(consultarBarato(l,retorno)==0){
                    printf("Viagem mais barata:\n");
                    printf("%s -> %s\n",retorno->origem,retorno->destino);
                    printf("Preco:%d\n",retorno->preco);
                }

            break;

            case 4:

                if(consultarCaro(l,retorno)==0){
                    printf("Viagem mais cara:\n");
                    printf("%s -> %s\n",retorno->origem,retorno->destino);
                    printf("Preco:%d\n",retorno->preco);
                }

            break;

            case 5:

                printf("Digite a sigla da cidade de origem(ate 5 caracteres):");
                setbuf(stdin,NULL);
                scanf("%s",origem);

                printf("Digite a sigla da cidade de destino(ate 5 caracteres):");
                setbuf(stdin,NULL);
                scanf("%s",destino);

                if(consultarTrecho(l,origem,destino)==0){
                    printf("Trecho nao encontrado ou não existente.\n");
                } else {
                    printf("Preco do trecho:%d\n",consultarTrecho(l,origem,destino));
                }

            break;

            case 6:

                printf("Saindo...\n");
                exit(1);

            break;

        }



    }while(opcao!=6);

    free(l);
    free(l2);



    return 0;
}
