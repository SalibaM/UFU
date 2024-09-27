#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    int opcao;
    ListaCircular *l;
    ListaCircular *l2;
    Aluno it;
    int pos;
    int chave;
    int it4;
    int it5;
    int i;

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
        printf("14.Remover central.\n");
        printf("15.Intersecao listas.\n");
        printf("16.Inserir fim novo.\n");
        printf("17.Sair.\n");

        printf("Digite sua opcao:\n");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:

                l = criar();
                printf("Lista criada com sucesso.\n");

                break;

            case 2:

                if(listaVazia(l)==0){
                    printf("A lista esta vazia.\n");
                } else {
                    printf("A lista nao esta vazia ou nao foi criada.\n");
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

                inserirInicio(l,it);

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

                inserirFim(l,it);

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

                inserirPosicao(l,it,pos);

                printf("Aluno inserido na posicao %d com sucesso.\n",pos);

                pos=0;

                break;

            case 6:

                if(removerInicio(l)==0){
                    printf("Aluno removido do inicio com sucesso.\n");
                }

                break;


            case 7:

                if(removerFim(l)==0){
                    printf("Aluno removido do fim com sucesso.\n");
                }

                break;

            case 8:

                printf("Digite a posicao:");
                scanf("%d",&pos);

                if(removerPosicao(l,pos)==0){
                    printf("Posicao %d removida com sucesso.\n",pos);
                }

                pos = 0;

                break;

            case 9:


                printf("Digite a chave que sera buscada:");
                scanf("%d",&chave);

                if(buscarItemChave(l,chave,it2)==0){
                    printf("Aluno encontrado. Dados:\n");
                    printf("Matricula:%d\n",it.mat);
                    printf("Nome:%s\n",it.nome);
                    printf("N1:%f\n",it.n1);
                } else {

                    printf("Aluno nao encontrado.\n");

                }

                break;


            case 10:

                limpar(l);
                printf("Lista limpa com sucesso.\n");

                break;

            case 11:

                mostrar(l);

                break;

            case 12:


                printf("Digite a matricula do aluno:\n");
                scanf("%d",&it4);

                if(removerItem(l,it4)==0){
                    printf("Item removido com sucesso.\n");
                }

                break;

            case 13:

                printf("Digite a posicao:");
                scanf("%d",&pos);

                if(buscarPosicao(l,pos,&it5)==0){
                    printf("Posicao encontrada. Dados:\n");
                    printf("Matricula:%d\n",it5);

                }

                break;

            case 14:

                removerCentral(l);
                printf("Removido!\n");

                break;

            case 15:

                l2 = criar();

                for(i=0;i<3;i++){

                    printf("Digite os dados:\n");
                    printf("Matricula:");
                    scanf("%d",&it.mat);
                    printf("Nome:");
                    setbuf(stdin,NULL);
                    fgets(it.nome,30,stdin);
                    it.nome[strcspn(it.nome, "\n")] = 0;
                    printf("N1:");
                    scanf("%f",&it.n1);

                    inserirInicio(l2,it);
                }

                ListaCircular *l3 = intersecaoListas(l,l2);

                mostrar(l3);

                break;

            case 16:

                    printf("Digite os dados:\n");
                    printf("Matricula:");
                    scanf("%d",&it.mat);
                    printf("Nome:");
                    setbuf(stdin,NULL);
                    fgets(it.nome,30,stdin);
                    it.nome[strcspn(it.nome, "\n")] = 0;
                    printf("N1:");
                    scanf("%f",&it.n1);

                    if(inserirFimNovo(l,it)==-1){
                        printf("Aluno ja na lista...\n");
                    }else {
                        printf("Aluno inserido.\n");

                    }

                    break;




            case 17:

                printf("Saindo...\n");
                exit(0);

                break;

        }




    }while(opcao!=17);

    free(l);

    return 0;
}
