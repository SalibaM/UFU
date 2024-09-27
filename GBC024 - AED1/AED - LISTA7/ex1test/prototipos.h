#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
#define MAX 100

struct aluno{
    int mat;
    char nome[30];
    float n1;
};

typedef struct aluno Aluno;

typedef struct lista Lista;

Lista *criar();

void limpar(Lista *l);

int inserirInicio(Lista *l,Aluno it);

int inserirFim(Lista *l,Aluno it);

int buscarItemChave(Lista *l,int chave,Aluno *retorno);

int listaVazia(Lista *l);

int removerInicio(Lista *l);

int removerFim(Lista *l);

int listaCheia(Lista *l);

void mostrar(Lista *l);

//para fazer ----

int removerPosicao(Lista *l,int pos);

int removerItem(Lista *l,Aluno it);

int buscarPosicao(Lista *l,int posicao,Aluno *it);

int inserirPosicao(Lista *l,Aluno it,int pos);

int tamanho(Lista *l);





#endif // PROTOTIPOS_H_INCLUDED
