#include <stdio.h>

int main(){

    int mat[5][5];
    int i,j,valor,igual,auxi,auxj;

    printf("Digite os valores de uma matriz 5x5:\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("Digite um valor para ser buscado na matriz:\n");
    scanf("%d",&valor);

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(mat[i][j]==valor){
                igual=1;
                auxi=i;
                auxj=j;
            }
        }
    }
    if(igual==1){
        printf("Esse valor esta armazenado na posicao (%d,%d)",auxi,auxj);
    } else {
        printf("Valor nao encontrado :(");
    }



    return 0;
}