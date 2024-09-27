#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int **p;
    int **p2;
    int **p3;
    int i,j;

    srand(time(NULL));

    // Criação de matrizes

    p = (int **)malloc(3*sizeof(int *));
    p2 = (int **)malloc(3*sizeof(int *));
    p3 = (int **)malloc(3*sizeof(int *));

    if(p == NULL){
        printf("Erro!\n!");
        exit(1);
    }

    if(p2 == NULL){
        printf("Erro!/n");
        exit(1);
    }

    if(p3 == NULL){
        printf("Erro!\n");
        exit(1);
    }

    for(i=0;i<3;i++){
        p[i] = (int *)malloc(3*sizeof(int));
    }

    for(i=0;i<3;i++){
        p2[i]=(int *)malloc(3*sizeof(int));
    }

    for(i=0;i<3;i++){
        p3[i] = (int *)malloc(3*sizeof(int));
    }

    //Preencher matrizes

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            p[i][j] = rand() % 10;
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            p2[i][j] = rand() % 10;
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            p3[i][j] = rand() % 10;
        }
    }

    // ----------------------------------------

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            p3[i][j] = p[i][j] + p2[i][j];
        }
    }

    // Mostrar matrizes;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",p[i][j]);
        }
    }

    printf("\n\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",p2[i][j]);
        }
    }

    printf("\n\n");

    printf("MATRIZ FINAL: \n\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",p3[i][j]);
        }
    }

    // Liberar

    for(i=0;i<3;i++){
        free(p[i]);
        free(p2[i]);
        free(p3[i]);
    }

    free(p);
    free(p2);
    free(p3);

    return 0;

}
