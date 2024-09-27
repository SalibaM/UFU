#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
#define MAX 100
typedef struct aluno
{
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct lista Lista;
Lista *criar();
void limpar(Lista *l);
int inserirInicio(Lista *l,Aluno it);
int inserirFim(Lista *l,Aluno it);
int inserirPosicao(Lista *l,Aluno it,int pos);
int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l,int pos);
int removerItem(Lista *l,int it);
int buscarItemChave(Lista *l,int chave,Aluno* retorno);
int buscarPosicao(Lista *l,int posicao,int *retorno);
int listaVazia(Lista *l);
int listaCheia(Lista *l);
int tamanho(Lista *l);
void mostrar(Lista *l);
int trocarElementos(Lista *l,int pos1,int pos2);
int ordenarLista(Lista *l);
void mostrarMaior(Lista *l);


#endif // PROTOTIPOS_H_INCLUDED
