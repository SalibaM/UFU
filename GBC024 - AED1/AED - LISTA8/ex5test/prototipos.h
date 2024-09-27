#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

typedef struct cidade{

    char sigla[5];
    char nome[30];

}Cidade;

typedef struct rotas{

    char origem[5];
    char destino[5];
    int preco;

}Rotas;


typedef struct listarotas ListaRotas;

typedef struct listacidades ListaCidades;

typedef struct nocidades NoCity;

typedef struct norotas NoRotas;

ListaRotas *criarListarotas();

ListaCidades *criarListacidades();

int criarRota(ListaRotas *l,char origem[],char destino[],int preco);

int criarCidade(ListaCidades *l,char nome[],char sigla[]);

int consultarTrecho(ListaRotas *l,char origem[],char destino[]);

int consultarBarato(ListaRotas *l,Rotas *retorno);

int consultarCaro(ListaRotas *l,Rotas *retorno);


#endif // PROTOTIPOS_H_INCLUDED
