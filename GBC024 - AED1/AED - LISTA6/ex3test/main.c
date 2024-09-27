#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipos.h"

int main(){

    matriz *mat1;
    matriz *mat2;
    matriz *mat_soma = NULL;


    int opcao;
    int linha,coluna;
    int opcaomat;
    float valor=0;
    int valormax=0,valormin=0;

    do{
        printf("---- MENU ----\n");
        printf("1. Criar matriz.\n");
        printf("2. Destruir matriz.\n");
        printf("3. Atribuir valor para o elemento especifico.\n");
        printf("4. Acessar valor de posicao especifica.\n");
        printf("5. Retornar numero de linhas.\n");
        printf("6. Retornar numero de colunas.\n");
        printf("7. Preencher com numeros aleatorios.\n");
        printf("8. Somar uma matriz com outra.\n");
        printf("9. Sair.\n");

        scanf("%d",&opcao);

        switch(opcao){

        case 1:

            printf("Qual matriz voce deseja criar? (1 ou 2):\n");
            scanf("%d",&opcaomat);

            printf("Digite as dimensoes da matriz:\n");
            scanf("%d%d",&linha,&coluna);

            linha++;
            coluna++;

            if(opcaomat==1){
                mat1 = criarmatriz_tad(linha,coluna);
            } else {
                mat2 = criarmatriz_tad(linha,coluna);
            }

            break;

        case 2:

            printf("Qual matriz voce deseja destruir?(1 ou 2)\n");
            scanf("%d",&opcaomat);

            if(opcaomat==1){
                destruirmatriz_tad(mat1);
            } else {
                destruirmatriz_tad(mat2);
            }

            printf("Matriz destruida!\n");

            break;

        case 3:

            printf("Qual matriz voce deseja atribuir?(1 ou 2)\n");
            scanf("%d",&opcaomat);

            printf("Qual a posicao desejada?\n");
            scanf("%d%d",&linha,&coluna);

            linha++;
            coluna++;

            if(opcaomat==1){
                atribuirvalor(mat1,linha,coluna);
            } else {
                atribuirvalor(mat2,linha,coluna);
            }

            break;

        case 4:

            printf("Qual matriz voce deseja acessar?(1 ou 2)\n");
            scanf("%d",&opcaomat);

            printf("Qual posicao voce deseja acessar?\n");
            scanf("%d%d",&linha,&coluna);

            linha++;
            coluna++;

           if(opcaomat==1){
                valor = acessarvalor(mat1,linha,coluna);
                printf("Valor:%f\n",valor);
            } else {
                valor = acessarvalor(mat2,linha,coluna);
                printf("Valor:%f\n",valor);
            }

            break;

        case 5:

            printf("Qual matriz voce deseja acessar?(1 ou 2)\n");
            scanf("%d",&opcaomat);

            if(opcaomat==1){
                linha = retornolinhas(mat1);
                linha++;
                printf("Quantidade de linhas:%d\n",linha);
            } else {
                linha = retornolinhas(mat2);
                linha++;
                printf("Quantidade de linhas:%d\n",linha);
            }

            break;

        case 6:

            printf("Qual matriz voce deseja acessar?(1 ou 2)\n");
            scanf("%d",&opcaomat);

            if(opcaomat==1){
                coluna = retornocoluna(mat1);
                coluna++;
                printf("Quantidade de colunas:%d\n",coluna);
            } else {
                coluna = retornocoluna(mat2);
                coluna++;
                printf("Quantidade de colunas:%d\n",coluna);
            }

            break;

        case 7:

            printf("Qual matriz voce deseja acessar?(1 ou 2)\n");
            scanf("%d",&opcaomat);

            printf("Digite os valores maximos e minimos:\n");
            scanf("%d%d",&valormax,&valormin);

            if(opcaomat==1){
                preenchermat(mat1,valormax,valormin);
                printf("Matriz preenchida!\n");
            } else {
                preenchermat(mat2,valormax,valormin);
                printf("Matriz preenchida!\n");
            }

            break;

        case 8:

            mat_soma = somamatriz(mat1,mat2);

            printf("Soma feita!\n");

            break;

        case 9:

            printf("Saindo...");
            exit(1);

        default:
            printf("Opcao invalida.\n");
        }

    }while(opcao!=9);

    liberarmatrizes(mat1,mat2,mat_soma);


    return 0;
}
