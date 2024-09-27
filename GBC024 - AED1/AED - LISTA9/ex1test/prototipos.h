#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
#define MAX 100

typedef struct aluno{

    int mat;
    char nome[30];
    float n1;

}Aluno;

typedef struct lista ListaCircular;

ListaCircular *criar();

void limpar(ListaCircular *l);

int tamanho(ListaCircular *l);

void mostrar(ListaCircular *l);

int listaVazia(ListaCircular *l);

int listaCheia(ListaCircular *l);

int inserirInicio(ListaCircular *l,Aluno it);

int inserirFim(ListaCircular *l,Aluno it);

int inserirPosicao(ListaCircular *l,Aluno it,int pos);

int removerInicio(ListaCircular *l);

int removerFim(ListaCircular *l);

int removerPosicao(ListaCircular *l,int pos);

int removerItem(ListaCircular *l,int it);

int buscarItemChave(ListaCircular *l,int chave,Aluno *retorno);

int buscarPosicao(ListaCircular *l,int posicao,int *retorno);

void mostrar(ListaCircular *l);




#endif // PROTOTIPOS_H_INCLUDED
