#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

typedef struct criarmatrizes matriz;

matriz *criarmatriz_tad(int linhas,int colunas);

void destruirmatriz_tad(matriz *mat1);

void atribuirvalor(matriz *mat1,int m,int n);

float acessarvalor(matriz *mat1,int m,int n);

int retornolinhas(matriz *mat1);

int retornocoluna(matriz *mat1);

void preenchermat(matriz *mat1,int tamanhomax,int tamanhomin);

matriz *somamatriz(matriz *mat1,matriz *mat2);

void liberarmatrizes(matriz *mat1,matriz *mat2,matriz *mat_aux);


#endif // PROTOTIPOS_H_INCLUDED
