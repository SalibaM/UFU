#include "restaurante.h"
#include "prato.h"
#include "cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_c{
    Cliente dados;
    struct no_c* prox;
}noC;

typedef struct lista_c{
    noC* inicio;
}ListaC;

ListaC *criarC(){
    ListaC *lc = (ListaC *)malloc(sizeof(ListaC));
    lc->inicio=NULL;
    return lc;
}

int inserirCliente(ListaC *lc, Cliente it){
    if(lc == NULL)return -2;
    noC *noLista = (noC*)malloc(sizeof(noC));
    noLista->dados = it;
    noLista->dados.carrinho = criarP();
    noLista->dados.pedidos_realizados = criarP();
    noLista->dados.pedidos_entregues = criarP();

    noLista->prox = lc->inicio;
    lc->inicio = noLista;
    return 0;
}

int removerCliente(ListaC *lc, Cliente it){
    if(lc == NULL) return -2;
    if(listaVaziaC(lc)==0)return -1;
    noC *no = lc->inicio;
    noC *aux = NULL;
    while(no != NULL){
        if(strcmp(no->dados.cpf, it.cpf)!=0){
            aux = no;
            no = no->prox;
        }
        else break;
    }
    if(no==NULL) return -3;
    if(aux!=NULL)aux->prox = no->prox;
    else lc->inicio = no->prox;
    free(no);
    return 0;
}

int listaVaziaC(ListaC *lc){
    if(lc == NULL) return -2;
    if(lc->inicio == NULL) return 0;
    else return -1;
}


int buscaItemCliente(ListaC *lc,char *cod, Cliente *it){
    if(lc==NULL)return -2;
    if(listaVaziaC(lc)==0) return -1;
    noC *no = lc->inicio;
    while(no != NULL){
        if(strcmp(no->dados.email, cod)!=0){
            no = no->prox;
        }
        else break;
    }
    if(no==NULL) return -3;
    *it = no->dados;
    return 0;
}


int procuraItemCliente(ListaC *lc ,char *cod){
    if(lc==NULL)return -2;
    if(listaVaziaC(lc)==0) return -1;
    noC *no = lc->inicio;
    while(no != NULL){
        if(strcmp(no->dados.cpf, cod)!=0){
            no = no->prox;
        }
        else return 0;
    }
    return -3;
}

int procuraEmailCliente(ListaC *lc,char *cod){
    if(lc==NULL)return -2;
    if(listaVaziaC(lc)==0) return -1;
    noC *no = lc->inicio;
    while(no != NULL){
        if(strcmp(no->dados.email, cod)!=0){
            no = no->prox;
        }
        else return 0;
    }
    return -3;
}


