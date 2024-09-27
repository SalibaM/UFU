#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nocidades{

    Cidade valor;
    struct nocidades *prox;

}NoCity;

typedef struct norotas{

    Rotas valor;
    struct norotas *prox;

}NoRotas;

typedef struct listacidades {

    NoCity *inicio;

}ListaCidades;

typedef struct listarotas {

    NoRotas *inicio;

}ListaRotas;

ListaRotas *criarListarotas(){

    ListaRotas *l = (ListaRotas *)malloc(sizeof(ListaRotas));
    l->inicio = NULL;
    return l;

}

ListaCidades *criarListacidades(){

    ListaCidades *l = (ListaCidades *)malloc(sizeof(ListaCidades));
    l->inicio = NULL;
    return l;

}

int criarRota(ListaRotas *l,char origem[],char destino[],int preco){

    if(l==NULL){
        return 2;
    }

    NoRotas *noRot = (NoRotas *)malloc(sizeof(NoRotas));

    strcpy(noRot->valor.origem,origem);
    strcpy(noRot->valor.destino,destino); //inserção de valores...
    noRot->valor.preco = preco;

    noRot->prox = l->inicio; //mesma coisa que NULL;
    l->inicio = noRot;

    return 0;

}

int criarCidade(ListaCidades *l,char nome[],char sigla[]){

    if(l==NULL){
        return 2;
    }

    NoCity *noCit = (NoCity *)malloc(sizeof(NoCity));

    strcpy(noCit->valor.nome,nome);
    strcpy(noCit->valor.sigla,sigla);

    noCit->prox = l->inicio;

    l->inicio = noCit;

    return 0;

}

int consultarTrecho(ListaRotas *l,char origem[],char destino[]){

    if(l==NULL){
        return 2;
    }

    NoRotas *noRot = l->inicio;

    int preco=0;

    while(noRot!=NULL){
        if((strcmp(noRot->valor.destino,destino)==0) && (strcmp(noRot->valor.origem,origem)==0)){

           preco = noRot->valor.preco;

           return preco;
        } else {
            noRot = noRot->prox;
        }
    }

    return 0;
}

int consultarBarato(ListaRotas *l,Rotas *retorno){

    int maisBarato=10000;

    NoRotas *noRot = l->inicio;

    while(noRot!=NULL){

        if(noRot->valor.preco<maisBarato){
            maisBarato = noRot->valor.preco;
            *retorno = noRot->valor;
        }

        noRot = noRot->prox;
    }

    return 0;

}

int consultarCaro(ListaRotas *l,Rotas *retorno){

    int maisCaro=0;

    NoRotas *noRot = l->inicio;

    while(noRot!=NULL){

        if(noRot->valor.preco>maisCaro){
            maisCaro = noRot->valor.preco;
            *retorno = noRot->valor;
        }

        noRot = noRot->prox;
    }

    return 0;

}






