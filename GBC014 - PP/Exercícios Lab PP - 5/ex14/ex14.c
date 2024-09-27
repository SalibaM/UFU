#include <stdio.h>
#include <stdlib.h>

int main(){

    int mat[4][4];
    int i,j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            mat[i][j] = 1 +(2*(rand()%10));
        }
    }

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",mat[i][j]);
        }
        if(j==4){
            printf("\n");
        }
    }

    printf("\n\n");

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(j>i){
                mat[i][j]=0;
            } else {
                mat[i][j]=mat[i][j];
            }
        }
    }

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",mat[i][j]);
        }
        if(j==4){
            printf("\n");
        }
    }

    
    return 0;
}