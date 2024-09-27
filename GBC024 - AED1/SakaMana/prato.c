#include "restaurante.h"
#include "prato.h"
#include "cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nop{
    Prato dados;
    struct nop* prox;
};

typedef struct nop noP;

struct lista_p{
    noP* inicio;
};

typedef struct lista_p ListaP;

ListaP *criarP(){
    ListaP *lp = (ListaP *)malloc(sizeof(ListaP));
    lp->inicio=NULL;
    return lp;
}

int inserirPrato(ListaP *lp, Prato it){
    if(lp == NULL)return -2;
    noP *noLista = (noP*)malloc(sizeof(noP));
    noLista->dados = it;

    noLista->prox = lp->inicio;
    lp->inicio = noLista;
    return 0;
}

int removerPrato(ListaP *lp, Prato it){
    if(lp == NULL) return -2;
    if(listaVaziaP(lp)==0)return -1;
    noP *no = lp->inicio;
    noP *aux = NULL;
    while(no != NULL){
        if(no->dados.codigo!=it.codigo){
            aux = no;
            no = no->prox;
        }
        else break;
    }
    if(no==NULL) return -3;
    if(aux!=NULL) aux->prox = no->prox;
    else lp->inicio = no->prox;
    free(no);
    return 0;
}

int listaVaziaP(ListaP *lp){
    if(lp == NULL) return -2;
    if(lp->inicio == NULL) return 0;
    else return -1;
}

int buscaItemPrato(ListaP *lp,int cod, Prato *it){
    if(lp==NULL)return -2;
    if(listaVaziaP(lp)==0) return -1;
    noP *no = lp->inicio;
    while(no != NULL){
        if(no->dados.codigo!=cod){
            no = no->prox;
        }
        else break;
    }
    if(no==NULL) return -3;
    *it = no->dados;
    return 0;
}

int procuraItemPrato(ListaP *lp,int cod){
    if(lp==NULL)return -2;
    if(listaVaziaP(lp)==0) return -1;
    noP *no = lp->inicio;
    while(no != NULL){
        if(no->dados.codigo!=cod){
            no = no->prox;
        }
        else return 0;
    }
    return -3;
}

void mostrarPratos(ListaP *lp){
    if(lp != NULL)
    {
        noP *nolista = lp->inicio;

        while(nolista != NULL)
        {
            printf("\n");
            printf("\n==== Prato (%d) ====", nolista->dados.codigo);
            printf("\nNome: %s", nolista->dados.nome);
            printf("\nIngredientes: %s", nolista->dados.ingredientes);
            printf("\nPreço: R$%.2f", nolista->dados.preco);

            nolista = nolista->prox;
        }
    }
}

void mostrarPedidosCliente(ListaP *lp){
    if(lp != NULL)
    {
        noP *nolista = lp->inicio;
        while(nolista != NULL)
        {
            printf("\n");
            printf("\n==== Prato (%d) ====", nolista->dados.codigo);
            printf("\nNome: %s", nolista->dados.nome);
            printf("\nIngredientes: %s", nolista->dados.ingredientes);
            printf("\nPreço: R$%.2f", nolista->dados.preco);
            printf("\nQuantidade: %d", nolista->dados.quantidade);

            nolista = nolista->prox;
        }
    }
}

float totalCarrinho(ListaP *lp){
    if(lp==NULL)return -2;
    if(listaVaziaP(lp)==0)return 0;
    float soma = 0;
    noP *no = lp->inicio;
    while(no!=NULL){
        soma += (no->dados.preco * no->dados.quantidade);
        no = no->prox;
    }
    return soma;
}

void retornaPrato(ListaP *lp, Prato *p){
    *p = lp->inicio->dados;
}
