#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

typedef struct conj Conjunto;

Conjunto *criarconjunto();

void inserir_membros_conjunto(Conjunto *c1);

void remove_membros_conjunto(Conjunto *c1,int numero);

int membro_presente(Conjunto *c1,int membro);

Conjunto *uniao_entre_conjuntos(Conjunto *c1,Conjunto *c2);

Conjunto *interseccao_entre_conjuntos(Conjunto *c1,Conjunto *c2);

Conjunto *diferenca_entre_conjuntos(Conjunto *c1,Conjunto *c2);

#endif // PROTOTIPOS_H_INCLUDED
