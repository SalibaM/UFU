#include "restaurante.h"
#include "prato.h"
#include "cliente.h"
#include "pedidos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noPedidos{
    struct noPedidos *prox;
    Cliente dados;
    Prato pedido;
}NoPedidos;

typedef struct filaPedidos{
    NoPedidos* inicio;
    NoPedidos* fim;
    int quant;
}FilaPedidos;

FilaPedidos *criarF(){
    FilaPedidos *f = (FilaPedidos *)malloc(sizeof(FilaPedidos));
    f->inicio = NULL;
    f->fim = NULL;
    f->quant = 0;
    return f;
}

int inserirPedido (FilaPedidos *f, Cliente c, Prato p){
    if(f==NULL) return -2;
    NoPedidos *no = (NoPedidos*)malloc(sizeof(NoPedidos));
    no->dados = c;
    no->pedido = p;
    no->prox = NULL;
    if(f->quant == 0){
        f->inicio = no;
        f->fim = no;
    }
    else{
        f->fim->prox = no;
        f->fim = no;
    }

    f->quant++;
    return 0;
}

int removerPedido (FilaPedidos *f, Cliente *c, Prato *p){
    if(f==NULL)return -2;
    if(f->quant==0) return -1;

    *c = f->inicio->dados;
    *p = f->inicio->pedido;

    FilaPedidos *fila = f;
    if(fila->inicio == fila->fim){
        fila->fim = NULL;
    }
    fila->inicio = fila->inicio->prox;
    fila->quant--;
    free(fila);
    return 0;
}


int tamanho(FilaPedidos *f)
{
    if(f == NULL) return -2;

    return f->quant;
}

void mostrarPedidos(FilaPedidos *f)
{
    if (f != NULL)
    {
        int i = 1, q;

        FilaPedidos *itens_pedidos = f;

        Cliente cliente_pedido;
        Prato prato_pedido;

        q = tamanho(itens_pedidos);

        printf("\nLista de pedidos: ");

        while (q > 0)
        {
            if (removerPedido(itens_pedidos, &cliente_pedido, &prato_pedido) == 0)
            {
                printf("\n");
                printf("\n      Pedido(%d)", i);
                printf("\nNome: %s", prato_pedido.nome);
                printf("\nIngredientes: %s", prato_pedido.ingredientes);
                printf("\nNome do cliente: %s", cliente_pedido.nome);
                printf("\nQuantidade: %d", prato_pedido.quantidade);
                i++;
                q--;
                inserirPedido(itens_pedidos, cliente_pedido, prato_pedido);
            }
        }
    }
}
