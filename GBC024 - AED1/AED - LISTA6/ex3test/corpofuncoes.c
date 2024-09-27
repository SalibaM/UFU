#include "prototipos.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct criarmatrizes{

    float **mat;


}matriz;

matriz *criarmatriz_tad(int linhas,int colunas){

    matriz *mat1 = (matriz *)malloc(sizeof(matriz));
    int i;

    mat1->mat = (float **)malloc(linhas*sizeof(float *));

    for(i=0;i<linhas;i++){
        mat1->mat[i] = (float *)malloc(colunas*sizeof(int));
    }

    return mat1;


}

void destruirmatriz_tad(matriz *mat1){

    int i;
    int linhas=0;

    linhas = sizeof(mat1->mat[0])/sizeof(mat1->mat[0][0]);

    for(i=0;i<linhas;i++){
        free(mat1->mat[i]);
    }

    free(mat1->mat);

}

void atribuirvalor(matriz *mat1,int m,int n){

    m--;
    n--;

    printf("Atribua o valor para a posicao [%d][%d]:\n",m,n);

    scanf("%f",&mat1->mat[m][n]);

}

float acessarvalor(matriz *mat1,int m,int n){

    float valor=0;
    m--;
    n--;

    valor = mat1->mat[m][n];

    return valor;

}

int retornolinhas(matriz *mat1){

    int linhas=0;


    linhas = sizeof(mat1->mat[0])/sizeof(mat1->mat[0][0]);


    return linhas;
}

int retornocoluna(matriz *mat1){

    int coluna=0;

    coluna = sizeof(mat1->mat)/sizeof(mat1->mat[0]);

    return coluna;


}

void preenchermat(matriz *mat1,int tamanhomax,int tamanhomin){

    srand(time(NULL));
    int i,j;
    int m,n;

    m = sizeof(mat1->mat[0])/sizeof(mat1->mat[0][0]);

    n = sizeof(mat1->mat)/sizeof(mat1->mat[0]);


    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            mat1->mat[i][j]=(rand() % (tamanhomax - tamanhomin + 1)) + tamanhomin;
        }
    }

}

matriz *somamatriz(matriz *mat1,matriz *mat2){

    matriz *mat_aux = (matriz *)malloc(sizeof(matriz));

    int linhas=0,colunas=0;
    int i;

    int j,k;

    linhas = sizeof(mat1->mat[0])/sizeof(mat1->mat[0][0]);
    colunas = sizeof(mat1->mat)/sizeof(mat1->mat[0]);

    mat_aux->mat = (float **)malloc(linhas*sizeof(float *));

    for(i=0;i<linhas;i++){
        mat_aux->mat[i] = (float *)malloc(colunas*sizeof(float));
    }

    for(j=0;j<linhas;j++){
        for(k=0;k<colunas;k++){
            mat_aux->mat[j][k] = mat1->mat[j][k]+mat2->mat[j][k];
        }
    }

    return mat_aux;





}

void liberarmatrizes(matriz *mat1,matriz *mat2,matriz *mat_aux){

    int i;
    int linha;

    linha = sizeof(mat1->mat[0])/sizeof(mat1->mat[0][0]);

    for(i=0;i<linha;i++){
        free(mat1->mat[i]);
    }

    free(mat1->mat);

    for(i=0;i<linha;i++){
        free(mat2->mat[i]);
    }

    free(mat2->mat);

    for(i=0;i<linha;i++){
        free(mat_aux->mat[i]);
    }

    free(mat_aux->mat);

}









