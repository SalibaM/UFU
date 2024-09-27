#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "prato.h"

typedef struct lista_c ListaC;

typedef struct cliente{

    char nome[30];
    char email[50];
    char cpf[15];
    char senha[15];

    struct lista_p *carrinho;
    struct lista_p *pedidos_realizados;
    struct lista_p *pedidos_entregues;

}Cliente;

ListaC *criarC();

int inserirCliente(ListaC *lc, Cliente it);
int removerCliente(ListaC *lc, Cliente it);
int listaVaziaC(ListaC *lc);

int buscaItemCliente(ListaC *lc,char *cod, Cliente *it);
int procuraItemCliente(ListaC *lc,char *cod);
int procuraEmailCliente(ListaC *lc,char *cod);


#endif // CLIENTE_H_INCLUDED
