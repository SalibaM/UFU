#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int mat[5][5];
    int i,j,cont;

    cont=0;

    srand((unsigned)time(NULL) );

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            mat[i][j] = rand()%100;
            if(mat[i][j]==mat[i-cont][j-cont]){
                mat[i][j] = rand()%100;
            }
        }
        cont++;
    }


    
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%d ",mat[i][j]);
        }
        if(j==5){
            printf("\n");
        }
    }

    return 0;
}