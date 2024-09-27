#ifndef PRATO_H_INCLUDED

#define PRATO_H_INCLUDED
#include "restaurante.h"
#include "cliente.h"


struct lista_p;
typedef struct lista_p ListaP;

typedef struct prato{

    int codigo;
    char nome[30];
    char ingredientes[450];
    float preco;
    int quantidade;
    int cod_restaurante;

}Prato;

ListaP *criarP();

int inserirPrato(ListaP *lp, Prato it);
int inserirPratoLista(ListaP *lp, Prato it, int *cod);

int removerPrato(ListaP *lp, Prato it);
int listaVaziaP(ListaP *lp);

int buscaItemPrato(ListaP *lp,int cod, Prato *it);
int procuraItemPrato(ListaP *lp,int cod);

void mostrarPratos(ListaP *lp);
void mostrarPedidosCliente(ListaP *lp);//remover
float totalCarrinho(ListaP *lp);
void retornaPrato(ListaP *lp, Prato *p);

#endif // PRATO_H_INCLUDED
