#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

struct aluno{
    int mat;
    char nome[30];
    float n1;
};

typedef struct aluno Aluno;

typedef struct lista Lista;

Lista *criar(int tamanhototal);

void limpar(Lista *l);

int inserirInicio(Lista *l,Aluno it,int tamanhototal);

int inserirFim(Lista *l,Aluno it,int tamanhototal);

int buscarItemChave(Lista *l,int chave,Aluno *retorno);

int listaVazia(Lista *l);

int removerInicio(Lista *l);

int removerFim(Lista *l);

int listaCheia(Lista *l,int tamanhototal);

void mostrar(Lista *l);

//para fazer ----

int removerPosicao(Lista *l,int pos);

int removerItem(Lista *l,Aluno it);

int buscarPosicao(Lista *l,int posicao,Aluno *it);

int inserirPosicao(Lista *l,Aluno it,int pos);

int tamanho(Lista *l);

int ContemItem(Lista *l,Aluno it);

Lista *Reversa(Lista *l,int tamanhototal);

int ContaItem(Lista *l,Aluno it);






#endif // PROTOTIPOS_H_INCLUDED
