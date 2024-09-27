#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED


typedef struct lista_grafo lista;
typedef struct no_lista no;

typedef struct grafo grafo;

typedef struct arvore_binaria arvore;
typedef struct no_arvore_binaria no_arvore;
typedef struct meu_file meu_file;
void Titulo();

struct ranking {
  char nome[50];
  int pontuacao;
  double tempoTotal;
  double tempoArea[7];
} typedef rank;

int menu(rank *vet, int *tam);
void jogo(rank *vet, int *tam);

int escolhePortas (int tipo);
int escolhePortasCentral (int tipo, int pontos, int custoDeVolta);
void printarMapa(int indice);

void ordena_pontuacao(rank *vet, int *tam);
void ordena_tempo(rank *vet, int *tam);
void menu_ranking(rank *vet, int *tam);
void ranking(rank *vet, int *tam); 
void removePos(rank *vet,int elem,int *tam);
int procuraRank(rank *vet, int *tam, char *nome, int tamchar);

lista *criar_lista();
int tamanho(lista *l);
void apagar_lista(lista *l);
void insere(lista *l, int sala, int peso); 
void modifica_peso(lista *l, int sala, int peso); 

grafo *criar_grafo(meu_file *f, int tam);
void apagar_grafo(grafo *g);


arvore *criar_arv(); 
void preencher(arvore *a);
void preencher2(struct no_arvore_binaria *a, meu_file *f, int h);
void apagar(struct no_arvore_binaria *a);

int percorrer(struct no_arvore_binaria *a, int h, int *sala, rank *rank);
void nivel(grafo *fase, int *sala);
int boss(grafo *fase);





#endif // UTIL_H_INCLUDED
