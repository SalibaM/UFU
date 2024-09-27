#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int mat[5][10];
    int vet[5];
    int i=0,j=0,somalinha=0;

    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            mat[i][j]= rand()%50;
        }
    }

    for(i=0;i<5;i++){
        somalinha=0;
        for(j=0;j<10;j++){
            somalinha = somalinha + mat[i][j];
            vet[i] = somalinha;

        }
    }

    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            mat[i][j]=vet[i]*mat[i][j];
        }
    }

    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            printf("%d\n",mat[i][j]);
            if(j==9){
                printf("\n");
            }
        }
    }



    return 0;

}
