#ifndef RESTAURANTE_H_INCLUDED
#define RESTAURANTE_H_INCLUDED

#include "prato.h"
#include "cliente.h"
#include "pedidos.h"

typedef struct lista_r ListaR;

struct restaurante{

    char nome_restaurante[30];
    char nome_proprietario[30];
    char categoria[30];
    char cnpj[19];
    char email[30];
    char senha[15];
    int codigo;

    ListaP *cardapio;
    FilaPedidos *pedidos;


};

typedef struct restaurante Restaurante;

ListaR *criarR();

int inserirRestaurante(ListaR *lr, Restaurante it);
int geraCodigo(ListaR *lr);
int removerRestaurante(ListaR *lr, Restaurante it);
int listaVaziaR(ListaR *lr);

int buscaItemRestaurante(ListaR *lr, char *cod, Restaurante *it);
int buscaCodigoRestaurante(ListaR *lr, int cod, Restaurante *it);
int procuraItemRestaurante(ListaR *lr, char *cod);
int procuraEmailRestaurante(ListaR *lr,char *cod);

void mostrarTodosPratos(ListaR *lr, int *i);
void mostrarRestaurante (ListaR *lr, char *categoria);
int buscaPrato(ListaR *lr, int cod, Restaurante *it);

#endif // RESTAURANTE_H_INCLUDED
