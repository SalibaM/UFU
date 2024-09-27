#include <stdio.h>

int main(){

    int mat[4][4],i,j;
    int auxi=0,auxj=0;

    printf("Digite os valores de uma matriz 4x4:");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(mat[i][j]>mat[auxi][auxj]){
                auxi = i;
                auxj = j;
            }
        }

    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d",mat[i][j]);
        }
    if(j=4){
        printf("\n");
    }
    }

    return 0;
}