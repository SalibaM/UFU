#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

#include "prato.h"
#include "cliente.h"
#include "restaurante.h"

typedef struct filaPedidos FilaPedidos;

FilaPedidos* criarF();

int inserirPedido (FilaPedidos *f, Cliente c, Prato p);

int removerPedido (FilaPedidos *f, Cliente *c, Prato *p);

int tamanho(FilaPedidos *f);

void mostrarPedidos(FilaPedidos *f);

#endif // PEDIDOS_H_INCLUDED
