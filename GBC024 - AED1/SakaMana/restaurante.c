#include "restaurante.h"
#include "prato.h"
#include "cliente.h"
#include "pedidos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_r{
    Restaurante dados;
    struct no_r* prox;
}noR;

typedef struct lista_r{
    noR* inicio;
    int ultimo_codigo;
    int ultimo_prato;
}ListaR;

ListaR *criarR(){
    ListaR *lr = (ListaR *)malloc(sizeof(ListaR));
    lr->inicio=NULL;
    lr->ultimo_codigo = 1;
    lr->ultimo_prato = 1;
    return lr;
}

int inserirRestaurante(ListaR *lr, Restaurante it){
    if(lr == NULL)return -2;
    noR *noLista = (noR*)malloc(sizeof(noR));
    noLista->dados = it;
    noLista->dados.cardapio = criarP();
    noLista->dados.pedidos = criarF();
    noLista->dados.codigo = lr->ultimo_codigo;
    lr->ultimo_codigo++;

    noLista->prox = lr->inicio;
    lr->inicio = noLista;
    return 0;
}

int geraCodigo(ListaR *lr){
    int cod;
    cod = lr->ultimo_prato;
    (lr->ultimo_prato)++;
    return cod;
}

int removerRestaurante(ListaR *lr, Restaurante it){
    if(lr == NULL) return -2;
    if(listaVaziaR(lr)==0)return -1;
    noR *no = lr->inicio;
    noR *aux = NULL;
    while(no != NULL){
        if(strcmp(no->dados.cnpj, it.cnpj)!=0){
            aux = no;
            no = no->prox;
        }
        else break;
    }
    if(no==NULL) return -3;
    if(aux!=NULL) aux->prox = no->prox;
    else lr->inicio = no->prox;
    free(no);
    return 0;
}

int listaVaziaR(ListaR *lr){
    if(lr == NULL) return -2;
    if(lr->inicio == NULL) return 0;
    else return -1;
}



int buscaItemRestaurante(ListaR *lr, char *cod, Restaurante *it){
    if(lr==NULL)return -2;
    if(listaVaziaR(lr)==0) return -1;
    noR *no = lr->inicio;
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

int buscaCodigoRestaurante(ListaR *lr, int cod, Restaurante *it){
    if(lr==NULL)return -2;
    if(listaVaziaR(lr)==0) return -1;
    noR *no = lr->inicio;
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

int procuraItemRestaurante(ListaR *lr, char *cod){
    if(lr==NULL)return -2;
    if(listaVaziaR(lr)==0) return -1;
    noR *no = lr->inicio;
    while(no != NULL){
        if(strcmp(no->dados.cnpj, cod)!=0){
            no = no->prox;
        }
        else return 0;
    }
    return -3;
}

int procuraEmailRestaurante(ListaR *lr,char *cod){
    if(lr==NULL)return -2;
    if(listaVaziaR(lr)==0) return -1;
    noR *no = lr->inicio;
    while(no != NULL){
        if(strcmp(no->dados.email, cod)!=0){
            no = no->prox;
        }
        else return 0;
    }
    return -3;
}

void mostrarTodosPratos(ListaR *lr, int *i){
    if(lr!=NULL){
        int k =0;
        noR *noLista = lr->inicio;
        while(noLista!=NULL){
            mostrarPratos(noLista->dados.cardapio);
            noLista = noLista->prox;
            k++;
        }
        *i = k;
    }
}


void mostrarRestaurante (ListaR *lr, char *categoria)
{
    if (lr != NULL)
    {
        noR *nLista = lr->inicio;
        if(strcmp(categoria,"Sem categoria")==0){
            while(nLista!=NULL){
                printf ("(%d) %s\n", nLista->dados.codigo, nLista->dados.nome_restaurante);
                nLista = nLista->prox;
            }
        }
        else{
            while (nLista != NULL)
            {
                if (strcmp(nLista->dados.categoria, categoria) == 0)
                {
                    printf ("(%d) %s\n", nLista->dados.codigo, nLista->dados.nome_restaurante);
                }
                nLista = nLista->prox;
            }
        }

    }
}

int buscaPrato(ListaR *lr, int cod, Restaurante *it){
    if(lr==NULL)return -2;
    if(listaVaziaR(lr)==0)return -1;
    noR *no = lr->inicio;
    while(no!=NULL){
        if(procuraItemPrato(no->dados.cardapio,cod)!=0)no = no->prox;
        else break;
    }
    *it = no->dados;
    return 0;
}

