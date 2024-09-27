#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(){

    int opcao;
    Aluno it;
    Lista *l;
    int r,j;

    do{

        printf("---MENU---\n");
        printf("1.Criar lista.\n");
        printf("2.Cadastrar aluno.\n");
        printf("3.Listar alunos cadastrados.\n");
        printf("4.Mostrar aluno com maior nota.\n");
        printf("5.Remover todos os alunos.\n");
        printf("6.Sair.\n");

        printf("Digite a opcao:\n");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:

                l = criar();
                printf("Lista criada.\n");

                break;

            case 2:

                printf("Digite o numero de matricula, nome e nota do aluno, respectivamente:\n");
                scanf("%d",&it.mat);
                setbuf(stdin,NULL);
                fgets(it.nome,50,stdin);
                it.nome[strcspn(it.nome,"\n")]=0;
                scanf("%f",&it.n1);

                r=inserirInicio(l,it);
                j=ordenarLista(l);

                if(r==0 && j==0){
                    printf("Aluno inserido com sucesso!\n");
                } else {
                    printf("Erro!\n");
                }

                break;

            case 3:

                mostrar(l);
                printf("\n");

                break;


            case 4:

                mostrarMaior(l);

                printf("\n");

                break;


            case 5:

                limpar(l);
                printf("Lista limpa.\n");

                break;


            case 6:

                printf("Saindo...\n");

                exit(1);

                break;


        }




    }while(opcao!=6);

    free(l);

    return 0;
}
