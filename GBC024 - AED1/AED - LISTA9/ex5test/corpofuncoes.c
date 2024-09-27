#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    Aluno valor;
    struct no *prox;
}No;

typedef struct lista{
    No *fim;
}ListaCircular;

ListaCircular *criar(){

    ListaCircular *l = (ListaCircular *)malloc(sizeof(ListaCircular));
    l->fim=NULL;
    return l;
}

int listaVazia(ListaCircular *l){

    if(l==NULL){
        return 2;
    }

    if(l->fim == NULL){
        return 0;
    } else {
        return 1;
    }

}

int removerInicio(ListaCircular *l){

    if(l == NULL){
        return 2;
    }

    if(l->fim->prox == l->fim){
        free(l->fim);
        l->fim = NULL;
    }

    No *noAux = l->fim->prox;

    No *no = noAux->prox;

    l->fim->prox = no;

    free(noAux);

    return 0;

}

void limpar(ListaCircular *l){
    while(listaVazia(l)!=0){
        removerInicio(l);
    }
    free(l);
    l = NULL;
}

int tamanho(ListaCircular *l){
    if(l==NULL){
        return -1;
    }

    if(listaVazia(l)==0){
        return 0;
    }

    int cont=0;
    No *noLista = l->fim;

    do{
        cont++;
        noLista = noLista->prox;
    }while(noLista->prox != l->fim);

    return cont;

}

void mostrar(ListaCircular *l){

    if(l!=NULL){

        printf("[");

        if(listaVazia(l)!= 0){
            No *noLista = l->fim;
            do{
                printf("{%d, ",noLista->valor.mat);
                printf("%s, ",noLista->valor.nome);
                printf("%.2f} ",noLista->valor.n1);
                noLista = noLista->prox;
            }while(noLista != l->fim);
        }

    printf("]\n");


    }

}

int listaCheia(ListaCircular *l){
    return 1;
}

int inserirInicio(ListaCircular *l,Aluno it){

    if(l==NULL){
        return 2;
    }

    No *no = (No *)malloc(sizeof(No));
    no->valor = it;

    if(listaVazia(l)==0){
        l->fim = no;
        no->prox = no;
    } else {
        no->prox = l->fim->prox;
        l->fim->prox = no;
    }

    return 0;
}

int inserirFim(ListaCircular *l,Aluno it){

    if(l==NULL){
        return 2;
    }

    No *no = (No *)malloc(sizeof(No));
    no->valor = it;

    if(listaVazia(l)==0){
        l->fim = no;
        no->prox = no;
    } else {

        no->prox = l->fim->prox;
        l->fim->prox = no;
        l->fim = no;

    }

    return 0;


}

int inserirPosicao(ListaCircular *l,Aluno it,int pos){

    if(l==NULL){
        return 2;
    }

    int p = 1;
    int tam = 0;

    tam = tamanho(l);

    No *no = (No*)malloc(sizeof(No));

    no->valor = it;

    No *noLista = l->fim->prox;
    No *noAux = l->fim->prox;

    if(listaVazia(l)==0){
        l->fim = no;
        no->prox=no;

        return 0;
    }

    if(pos==1){
        inserirInicio(l,it);
        return 0;
    }

    if(pos == tam){
        inserirFim(l,it);

        return 0;
    }

    while(noLista!=l->fim || p==pos){
        noAux = noLista;
        noLista = noLista->prox;
        p++;
    }

    no->prox = noLista;
    noAux->prox = no;

    return 0;
}

int removerFim(ListaCircular *l){

    if(l==NULL){
        return 2;
    }

    if(l->fim->prox == l->fim){
        free(l->fim);
        l->fim = NULL;
        return 0;
    }

    No *no = l->fim;
    No *noAux = l->fim;

    while(no->prox!=l->fim){
        no = no->prox;
    }

    no->prox = noAux->prox;
    l->fim = no;

    free(noAux);

    return 0;



}

int removerPosicao(ListaCircular *l,int pos){

    if(l==NULL){
        return 2;
    }

    if(pos == 1){
        removerInicio(l);

        return 0;
    }

    int p = 0;

    int tam;
    tam = tamanho(l);

    if(pos == tam){
        removerFim(l);
    }

    No *no = l->fim->prox;
    No *noAux = l->fim->prox;

    while(no!=l->fim || p == pos){
        noAux = no;
        no = no->prox;
        p++;
    }

    noAux->prox = no->prox;

    free(no);

    return 0;

}

int removerItem(ListaCircular *l,int it){

    if(l==NULL){
        return 2;
    }

    int p = 1;

    No *no = l->fim->prox;

    while(no!=l->fim){

        if(no->valor.mat == it){
            removerPosicao(l,p);

            return 0;
        }

        no = no->prox;
        p++;
    }

    return 0;
}

int buscarItemChave(ListaCircular *l,int chave,Aluno *retorno){

    if(l==NULL){
        return 2;
    }

    No *no = l->fim->prox;

    while(no!=l->fim){

        if(no->valor.mat == chave){

            *retorno = no->valor;

            return 0;
        }

        no = no->prox;
    }

    return 0;

}

int buscarPosicao(ListaCircular *l,int posicao,int *retorno){

    if(l==NULL){
        return 2;
    }

    int p = 1;

    No *no = l->fim->prox;

    while(no!=l->fim){

        if(p==posicao){

            *retorno = no->valor.mat;

            return 0;
        }

        no = no->prox;
        p++;
    }

    return 0;
}

int removerCentral(ListaCircular *l){

    if(l==NULL){
        return 2;
    }

    int tam;
    int tamanhomeio;
    tam = tamanho(l);

    if(tam == 1){
        removerInicio(l);
    }

    tamanhomeio = tam/2;

    removerPosicao(l,tamanhomeio);

    return 0;

}

ListaCircular *intersecaoListas(ListaCircular *l,ListaCircular *l2){

    ListaCircular *l3 = criar();

    int p=0;

    No *noLista1 = l->fim->prox;

    while(noLista1 != l->fim){

        No *noLista2 = l2->fim->prox;

        while(noLista2 != l2->fim){
            if(noLista1->valor.mat==noLista2->valor.mat){

                inserirPosicao(l3,noLista1->valor,p);
                p++;
                break;
            }

            noLista2 = noLista2->prox;
        }

        noLista1 = noLista1->prox;
    }

    return l3;

}

int contaOcorrencias(ListaCircular *l,Aluno it){

    if(l==NULL){
        return 2;
    }

    int quantidade=0;

    No *noLista = l->fim->prox;

    while(noLista!=l->fim){
        if(noLista->valor.mat==it.mat){
            quantidade++;
        }

        noLista = noLista->prox;
    }

    return quantidade;


}

int inserirFimNovo(ListaCircular *l,Aluno it){

    if(l==NULL){
        return 2;
    }

    int quantidade = 0;

    quantidade = contaOcorrencias(l,it);

    if(quantidade>=1){
        return -1;
    } else {
        inserirFim(l,it);
        return 0;
    }

}







