#include "prototipos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no{
    Aluno valor;
    struct no *prox;
    struct no *ant;
}No;

typedef struct lista{
    No *inicio;
}Lista;

Lista *criar(){

    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void limpar(Lista *l)
{
    while (listaVazia(l)!=0)removerInicio(l);
    free(l);
    l = NULL;
}

int tamanho(Lista *l){
    if (l == NULL) return-1;
    No *no = l->inicio;
    int cont = 0;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

void mostrar(Lista *l){
    if (l != NULL)
    {
        printf("[");
        No *noLista = l->inicio;
        while (noLista != NULL)
        {
            printf(" {%d, ",noLista->valor.mat);
            printf("%s, ",noLista->valor.nome);
            printf("%.2f} ",noLista->valor.n1);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

int listaVazia(Lista *l){
    if (l == NULL) return 2;
    if (l->inicio == NULL)return 0;
    else
        return 1;
}

int listaCheia(Lista *l){
    return 1;
}

int inserirInicio(Lista*l,Aluno it){
    if (l == NULL) return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->prox = l->inicio;
    no->ant = NULL;
    if (l->inicio != NULL)l->inicio->ant =no;
    l->inicio = no;
    return 0;
}

int inserirFim(Lista *l,Aluno it){
    if (l == NULL) return 2;
    if (listaVazia(l) ==0)return inserirInicio(l,it);
    No *noLista = l->inicio;
    while (noLista->prox!=NULL)noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = NULL;
    no->ant = noLista;
    noLista->prox = no;
    return 0;
}

int inserirPosicao(Lista *l,Aluno it,int pos){
    if (l == NULL) return 1;
    if ((listaVazia(l) == 0)||(pos==0))return inserirInicio(l,it);
    No *nl = l->inicio;
    while ((nl->prox != NULL)&&(pos>1))
    {
        nl = nl->prox;
        pos--;
    }
    No *n = (No*)malloc(sizeof(No));
    n->valor = it;
    n->ant = nl;
    n->prox = nl->prox;
    nl->prox = n;
    if (n->prox != NULL) n->prox->ant=n;
    return 0;
}

int removerInicio(Lista*l){
    if (l == NULL) return 2;
    if (listaVazia(l) ==0)return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    if (l->inicio != NULL)l->inicio->ant =NULL;
    free(noLista);
    return 0;
}

int removerFim(Lista *l){
    if (l == NULL) return 2;
    if (listaVazia(l) ==0)return 1;
    No *noLista = l->inicio;
    while (noLista->prox!=NULL)noLista = noLista->prox;
    if (noLista->ant ==NULL)l->inicio = NULL;
    else
        noLista->ant->prox=NULL;
    free(noLista);
    return 0;
}

int removerPosicao(Lista*l,int pos){
    if (l == NULL) return 1;
    if (listaVazia(l) == 0)return 2;
    No *n = l->inicio;
    while ((n->prox != NULL)&&(pos>0))
    {
        n = n->prox;
        pos--;
    }
    if (n->ant == NULL) return removerInicio(l);
    if (n->prox == NULL) return removerFim(l);
    n->ant->prox = n->prox;
    n->prox->ant = n->ant;
    free(n);
    return 0;
}

int trocarElementos(Lista *l,int pos1,int pos2){

    if(l==NULL){
        return 2;
    }

    if(listaVazia(l)==0){
        return 1;
    }

    int pos11=0;
    int pos22=0;

    No *noLista1 = l->inicio;
    No *noLista2 = l->inicio;
    No *noAux = (No*)malloc(sizeof(No));

    while(noLista1->prox!=NULL && pos11!=pos1){
        noLista1 = noLista1->prox;
        pos11++;
    }

    while(noLista2->prox!=NULL && pos22!=pos2){
        noLista2 = noLista2->prox;
        pos22++;
    }

    noAux->valor = noLista1->valor;
    noLista1->valor=noLista2->valor;
    noLista2->valor=noAux->valor;

    return 0;



}

int verificarIgualdade(Lista *l,Lista *l2){

    if(l==NULL || l2==NULL){
        return 2;
    }

    if(listaVazia(l)==0 || listaVazia(l2)==0){
        return -1;
    }

    int *vetorRepeticoes = (int *)calloc(5000,sizeof(int));

    int i;

    No *noLista = l->inicio;
    No *noLista2 = l2->inicio;

    while(noLista!=NULL){
        vetorRepeticoes[noLista->valor.mat]++;
        noLista = noLista->prox;
    }

    while(noLista2!=NULL){
        vetorRepeticoes[noLista2->valor.mat]--;
        noLista2 = noLista2->prox;
    }

    for(i=0;i<5000;i++){
        if(vetorRepeticoes[i]!=0){
            return 1; //apareceram números de vezes diferentes...
        }

    }

    free(vetorRepeticoes);
    return 0;

}



























