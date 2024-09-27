#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Registro {
    float chave;
    char *uf;
    char *cidade;
    char *endereco;
} Registro;

typedef struct No *Apontador;

typedef struct No {
    Registro r;
    Apontador esq, dir;
} No;

typedef Apontador tipoDicionario;

void antecessor(Apontador q, Apontador *r);
void criacao(Apontador *Dicionario);
void insercao(Registro x, Apontador *p);
void remocao(Registro x, Apontador *p);
Registro pesquisa(Registro *x, Apontador *p);
void central(Apontador p);
int altura(Apontador p);
Apontador* menor(Apontador p);
Apontador* maior(Apontador p);

#endif /* ABB_H */
