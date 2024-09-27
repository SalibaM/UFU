#include "utilitarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct no_lista {
  int sala;
  int peso;
  struct no_lista *prox;
} no;
typedef struct lista_grafo {
  no *comeco;
} lista;
typedef struct grafo {
  int tam;
  lista **vet;
} grafo;

typedef struct no_arvore_binaria {
  grafo *area;
  struct no_arvore_binaria *esq;
  struct no_arvore_binaria *dir;
} no_arvore;
typedef struct arvore_binaria {
  no_arvore *raiz;
} arvore;

typedef struct meu_file {
  FILE *file;
} meu_file;

typedef struct ranking rank;

void Titulo() {
  printf("*********************************************************************"
         "***\n\n");
  printf(" ###### ###### #####  #####  ###### #####  ###### ##   ## ###### "
         "###### \n");
  printf(" ##  ## ##     ##   # ##   #   ##   ##   #   ##   ###  ##   ##   ##  "
         "##\n");
  printf(" ###### ####   #####  ##   #   ##   #####    ##   ## # ##   ##   ##  "
         "##\n");
  printf(" ##     ##     ## #   ##   #   ##   ## #     ##   ##  ###   ##   ##  "
         "##\n");
  printf(" ##     ###### ##  #  #####  ###### ##  #  ###### ##   ##   ##   "
         "######\n\n");
  printf("*********************************************************************"
         "***\n");
}

int menu(rank *vet, int *tam) {
  int opcao, loop=1;

  do {
    Titulo();
    printf("\nBem-vindo ao Perdirinto, um jogo onde você ficará perdido em um "
           "labirinto :) \n");
    printf("Escolha uma opção: \n");
    printf("1) Jogar\n");
    printf("2) Ranking\n");
    printf("0) Sair\n");
    printf("Opção escolhida: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      jogo(vet, tam);
      break;
    case 2:
      ranking(vet, tam);
      loop = 1;
      break;
    case 0:
      printf("Obrigada por jogar! :)\n");
      loop = 0;
      break;
    default:
      printf("Opção inválida! Por favor, refaça-a.\n\n");
      loop = 1;
    }
  } while (loop);
  return loop;
}

void jogo(rank *vet, int *tam) {

  int esc, sala = 0, tp;
  time_t a1, b;
  rank a;
  arvore *mapa = criar_arv();
  
  setbuf(stdin, NULL);
  printf("Insira o seu nome: ");
  fgets(a.nome, 50, stdin);

  int k = 0;
  while(a.nome[k] != '\n') k++;
  a.nome[k] = '\0';


  while(1)
  {
    preencher(mapa);
    a1 = clock();
    tp = percorrer(mapa->raiz, 0, &sala, &a);
    b = clock();
    if(tp != (-2))
    {
      break;
    }
    else
    {
      printf("\n\nVoce perdeu. Deseja recomecar?\n");
      printf("1) Sim\n");
      printf("2) Nao\n");
      scanf("%d", &esc);
      if(esc == 2) break;
    }
    apagar(mapa->raiz);
    mapa->raiz = NULL;
    sala = 0;
  }


  if(tp != (-2))
  {

    printf("\n\nParabens! Voce saiu do labirinto!\n\n");
    if(*tam == 10) ordena_tempo(vet,tam);
    a.tempoTotal = (double)(b - a1) / CLOCKS_PER_SEC;
    vet[*tam] = a;
    if(*tam != 10) (*tam)++;
  }
  
  apagar(mapa->raiz);
  mapa->raiz = NULL;
  free(mapa);
}

int escolhePortas(int tipo) {
  int opcao;
  switch (tipo) {
  case 0:
    printf(
        "_______________________________\n|                             |\n|   "
        "                          |\n|   0                         |\n[) /|\\ "
        "                       |\n|  / \\                        |\n|         "
        "                    |\n|_____________________________|\n");
    printf("Sala vazia! Pressione qualquer tecla para reiniciar: ");
    getchar();
    return -1;
  case 1:
    do {
      printf(
          "_______________________________\n|                             |\n| "
          "                           _|\n|   0                     1 [-]\n[) "
          "/|\\                       _|\n|  / \\                    2 [-]\n|  "
          "                           |\n|_____________________________|\n");
      printf("Digite o número da porta que deseja abrir: ");
      setbuf(stdin, NULL);
      scanf("%d", &opcao);
    } while (opcao != 1 && opcao != 2);
    if (opcao == 1) {
      printf(
          "_______________________________\n|                             |\n| "
          "                         _ _|\n|   0                 ->  |_[ ]\n[) "
          "/|\\                       _|\n|  / \\                      [-]\n|  "
          "                           |\n|_____________________________|\n");
    } else {
      printf(
          "_______________________________\n|                             |\n| "
          "                           _|\n|   0                       [-]\n[) "
          "/|\\                     _ _|\n|  / \\                ->  |_[ ]\n|  "
          "                           |\n|_____________________________|\n");
    }
    printf("Pressione qualquer tecla para continuar: ");
    setbuf(stdin, NULL);
    getchar();
    return opcao;
  case 2:
    printf(
        "_______________________________\n|                             |\n|   "
        "                          |\n|  \\0/                        |\n[)  |  "
        "     S A I D A         |\n|  / \\                        |\n|         "
        "                    |\n|_____________________________|\n");
    printf("Você saiu! Pressione qualquer tecla para continuar: ");
    return 0;
  }
  return -3;
}

int escolhePortasCentral(int tipo, int pontos, int custoDeVolta) {
  int opcao;
  printf("\nPontos disponíveis: %d\n", pontos);
  switch (tipo) {
  case 0:
    printf(
        "_______________________________\n|                             |\n|   "
        "                          |\n|   0                         |\n[) /|\\ "
        "                       |\n|  / \\                        |\n|         "
        "                    |\n|_____________________________|\n");
    if (pontos >= custoDeVolta) {
      printf("Sala vazia! Pressione qualquer tecla para retornar a sala "
             "anterior (custo de %d pontos): ",
             custoDeVolta);
    } else {
      printf("Sala vazia! Você não tem pontos suficientes para voltar :( "
             "Pressione qualquer tecla para reiniciar: ");
      return -2;
    }
    getchar();
    return -1;
  case 1:
    do {
      printf(
          "_______________________________\n|                             |\n| "
          "                           _|\n|   0                     1 [-]\n[) "
          "/|\\                       _|\n|  / \\                    2 [-]\n|  "
          "                           |\n|_____________________________|\n");
      printf("Digite o número da porta que deseja abrir ou 0 para retornar à "
             "sala anterior (custo de %d pontos): ",
             custoDeVolta);
      scanf("%d", &opcao);
      if (opcao == 0 && pontos < custoDeVolta) {
        printf("Você não tem pontos suficientes para retornar à sala anterior! "
               "Escolha outra opção.");
      }
    } while (opcao != 1 && opcao != 2 && opcao != 0 ||
             (opcao == 0 && pontos < custoDeVolta));
    if (opcao == 1) {
      printf(
          "_______________________________\n|                             |\n| "
          "                         _ _|\n|   0                 ->  |_[ ]\n[) "
          "/|\\                       _|\n|  / \\                      [-]\n|  "
          "                           |\n|_____________________________|\n");
    } else if (opcao == 2) {
      printf(
          "_______________________________\n|                             |\n| "
          "                           _|\n|   0                       [-]\n[) "
          "/|\\                     _ _|\n|  / \\                ->  |_[ ]\n|  "
          "                           |\n|_____________________________|\n");
    } else {
      printf("_______________________________\n|                             "
             "|\n|                            _|\n|_  0                       "
             "[-]\n[_)/|\\ <-                    _|\n|  / \\                   "
             "   [-]\n|                             "
             "|\n|_____________________________|\n");
      opcao = -1;
    }
    printf("Pressione qualquer tecla para continuar: ");
    setbuf(stdin, NULL);
    getchar();
    return opcao;
    break;
  case 2:
    printf(
        "_______________________________\n|                             |\n|   "
        "                          |\n|  \\0/                        |\n[)  |  "
        "     S A I D A         |\n|  / \\                        |\n|         "
        "                    |\n|_____________________________|\n");
    printf("Você saiu! Pressione qualquer tecla para continuar: ");
    setbuf(stdin, NULL);
    getchar();
    return 0;
  }
  return -3;
} 

void printarMapa(int indice) {

  switch (indice) {

  case 0:

    printf("Localizacao do jogador:\n");

    printf("                \n");
    printf("        XXX      \n");
    printf("    XX   |      \n");
    printf("   X 1   |      \n");
    printf("  X      |      \n");
    printf("  X ---- T      \n");
    printf("                \n");

    break;

  case 1:

    printf("Localizacao do jogador:\n");

    printf("                \n");
    printf("        XXX       \n");
    printf("    XX   |   XX     \n");
    printf("   X 1   | 2   X    \n");
    printf("  X      |      X   \n");
    printf("  X ---- T ---- X   \n");
    printf("                    \n");

    break;

  case 2:

    printf("Localizacao do jogador:\n");

    printf("                \n");
    printf("        XXX       \n");
    printf("    XX   |   XX     \n");
    printf("   X 1   | 2   X    \n");
    printf("  X      |      X   \n");
    printf("  X ---- T ---- X   \n");
    printf("           |      X  \n");
    printf("           \\  3   X  \n");
    printf("           |      X  \n");
    printf("           ---- X   \n");
    printf("                    \n");

    break;

  case 3:

    printf("Localizacao do jogador:\n");

    printf("                \n");
    printf("        XXX       \n");
    printf("    XX   |   XX     \n");
    printf("   X 1   | 2   X    \n");
    printf("  X ---- T ---- X   \n");
    printf("           |      X  \n");
    printf("           \\  3   X  \n");
    printf("           |      X  \n");
    printf("         T ---- X   \n");
    printf("         | 4   X    \n");
    printf("         |   XX     \n");
    printf("        XXX       \n");
    printf("                \n");

    break;

  case 4:

    printf("Localizacao do jogador:\n");

    printf("                \n");
    printf("        XXX       \n");
    printf("    XX   |   XX     \n");
    printf("   X 1   | 2   X    \n");
    printf("  X ---- T ---- X   \n");
    printf("           |      X  \n");
    printf("           \\ 3    X  \n");
    printf("           |      X  \n");
    printf("  X ---- T ---- X   \n");
    printf("   X 5   | 4   X    \n");
    printf("    XX   |   XX     \n");
    printf("        XXX       \n");
    printf("                \n");

    break;

  case 5:

    printf("Localizacao do jogador:\n");

    printf("                \n");
    printf("        XXX       \n");
    printf("    XX   |   XX     \n");
    printf("   X   1 | 2   X    \n");
    printf("  X ---- T ---- X   \n");
    printf(" X     |   |      X  \n");
    printf("X   6  /   \\ 3    X  \n");
    printf(" X     |   |      X  \n");
    printf("  X ---- T ---- X   \n");
    printf("   X 5   | 4   X    \n");
    printf("    XX   |   XX     \n");
    printf("        XXX       \n");
    printf("                \n");

    break;

  case 6:

    printf("Localizacao do jogador:\n");

    printf("                \n");
    printf("         XXX       \n");
    printf("    XX    |   XX     \n");
    printf("   X   1  | 2    X    \n");
    printf("  X ----  T ----  X   \n");
    printf(" X     |     |     X  \n");
    printf("X  6   /  7  \\ 3   X  \n");
    printf(" X     |     |     X  \n");
    printf("  X ----  T ----  X   \n");
    printf("   X 5    | 4    X    \n");
    printf("    XX    |    XX     \n");
    printf("         XXX       \n");
    printf("                \n");
    printf("                \n");

    break;
  }
  return;
}

void ordena_pontuacao(rank *vet, int *tam) {
  int i, j;
  rank menor;
  for (int i = 1; i < (*tam); i++) {
    menor = vet[i];
    for (int j = i - 1; i >= 0 && vet[j].pontuacao > menor.pontuacao; i--) {
      vet[j + 1] = vet[j];
    }
    vet[j + 1] = menor;
  }
}

void ordena_tempo(rank *vet, int *tam) {
  int i, j;
  rank menor;
  for (int i = 1; i < (*tam); i++) {
    menor = vet[i];
    for (int j = i - 1; i >= 0 && vet[j].tempoTotal > menor.tempoTotal; i--) {
      vet[j + 1] = vet[j];
    }
    vet[j + 1] = menor;
  }
}

void menu_ranking(rank *vet, int *tam) {
  int opcao;
  int elem;

  do {

    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    printf("RANKING\n");
    printf("   Nome     Pontos     Tempo Total     Tempo A1     Tempo A2     Tempo A3     Tempo A4     Tempo A5     Tempo A6     Tempo Area Final\n");
    for (int i = 0; i < (*tam); i++) {
      printf("%i- ", i + 1);
      printf("%s     %d     %lf     ", vet[i].nome, vet[i].pontuacao, vet[i].tempoTotal);
      for (int j = 0; j < 7; j++) {
        printf("%lf     ", vet[i].tempoArea[j]);
      }
      printf("\n");
      setbuf(stdin, NULL);
    }

    printf("Selecione uma opcao:\n");

    printf("1) Apagar Ranking\n");
    printf("2) Apagar item especifico do Ranking\n");
    printf("3) Voltar\n");
    setbuf(stdin, NULL);
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:

      *tam = 0;

      break;

    case 2:



      printf("Qual o elemento do ranking voce deseja apagar(1-10)\n");
       scanf("%d", &elem);

       if (elem < 0 || elem > (*tam)) {
        printf("Posição inválida!\n");
        break;
      } else {
        removePos(vet, elem - 1, tam);
      }


      break;

    case 3:
      printf("Voltando...\n");
      break;
    }
  } while (opcao != 3);
}

void ranking(rank *vet, int *tam) {
  int esc;
  do {
    printf("\nVoce deseja ordenar o vetor de acordo com:\n1 - Pontuacao\n2 - "
           "Tempo\n");

    scanf("%i", &esc);
    if ((esc != 1) && (esc != 2))
      printf("Escolha inválida! Por favor, refaça-a.\n\n");
  } while ((esc != 1) && (esc != 2));
  switch (esc) {
  case 1:
    ordena_pontuacao(vet, tam);
    menu_ranking(vet, tam);
    break;
  case 2:
    ordena_tempo(vet, tam);
    menu_ranking(vet, tam);
    break;
  }
}

void removePos(rank *vet, int elem, int *tam) {
  int i;
  for (i = elem; i < (*tam) - 1; i++) {

    vet[i] = vet[i + 1];
  }
  (*tam)--;
}

int procuraRank(rank *vet, int *tam, char *nome, int tamchar) {
  int i;

  for (i = 0; i < (*tam); i++) {

    if (strcmp(vet[i].nome, nome) == 0) {
      return i;
    }
  }
  return -1;
}

lista *criar_lista() {
  lista *l = (lista *)malloc(sizeof(lista));
  l->comeco = NULL;
  return l;
}

void apagar_lista(lista *l) {
  no *aux = l->comeco;
  no *ant = l->comeco;

  while (aux != NULL) {
    aux = aux->prox;
    free(ant);
    ant = aux;
  }
  free(l);
}

void insere(lista *l, int sala, int peso) { 
  no *novo = (no *)malloc(sizeof(no));
  novo->sala = sala;
  novo->peso = peso;
  novo->prox = NULL;

  no *aux = l->comeco;
  if (l->comeco == NULL) {
    l->comeco = novo;
    return;
  }

  while (aux->prox != NULL) {
    aux = aux->prox;
  }

  aux->prox = novo;
}

void modifica_peso(lista *l, int sala, int peso) { 
  no *aux = l->comeco;
  while (aux != NULL) {
    if (aux->sala == sala) {
      aux->sala = peso;
      return;
    }
    aux = aux->prox;
  }
}

grafo *criar_grafo(meu_file *f, int tam) {
  grafo *g = (grafo *)malloc(sizeof(grafo));
  g->tam = tam;
  g->vet = (lista **)malloc(tam * sizeof(lista *));
  int sala1, sala2, peso1, peso2;
  for (int i = 0; i < tam; i++) {
    fscanf(f->file, "%d; %d; %d; %d\n", &sala1, &peso1, &sala2, &peso2);

    g->vet[i] = criar_lista();
    if (sala1 != 99) {
      insere(g->vet[i], sala1, peso1);
      insere(g->vet[i], sala2, peso2);
    }
  }
  return g;
}

void apagar_grafo(grafo *g) {
  for (int i = 0; i < g->tam; i++) {
    apagar_lista(g->vet[i]);
  }
  free(g->vet);
  free(g);
}

arvore *criar_arv() {
  arvore *a = (arvore *)malloc(sizeof(arvore));
  a->raiz = NULL;
  return a;
}

void preencher2(struct no_arvore_binaria *a, meu_file *f, int h) {
  if (h > 2)
    return;
  if (h != 2) {
    no_arvore *esq = (no_arvore *)malloc(sizeof(no_arvore));
    no_arvore *dir = (no_arvore *)malloc(sizeof(no_arvore));
    a->esq = esq;
    a->dir = dir;
    preencher2(esq, f, h + 1);
    preencher2(dir, f, h + 1);
  }
  int n;
  fscanf(f->file, "%d\n", &n);
  a->area = criar_grafo(f, n);
  return;
}

void preencher(arvore *a) {
  meu_file *aux = (meu_file *)malloc(sizeof(meu_file));
  aux->file = fopen("grafos.txt", "r");

  no_arvore *raiz = (no_arvore *)malloc(sizeof(no_arvore));
  no_arvore *esq = (no_arvore *)malloc(sizeof(no_arvore));
  no_arvore *dir = (no_arvore *)malloc(sizeof(no_arvore));

  a->raiz = raiz;
  raiz->esq = esq;
  raiz->dir = dir;
  preencher2(esq, aux, 1);
  preencher2(dir, aux, 1);
  int n;
  fscanf(aux->file, "%d\n", &n);
  raiz->area = criar_grafo(aux, n);
  return;
}

void apagar(struct no_arvore_binaria *a){
  if(a == NULL) return;
  apagar(a->esq);
  apagar(a->dir);
  apagar_grafo(a->area);
  free(a);
  return;
}

int percorrer(struct no_arvore_binaria *a, int h, int *sala, rank *rank) {
  int retorno = 0;
  time_t comeco, fim;
  rank->tempoTotal = 0;
  if (h > 2)
    return retorno;
  if (h != 2) {
    percorrer(a->esq, h + 1, sala, rank);
    percorrer(a->dir, h + 1, sala, rank);
  }
  printf("\n\n");
  printf("\n\n");
  if (h) {
    comeco = clock();
    nivel(a->area, sala);
    fim = clock();
    rank->tempoArea[(*sala)-1] = (double)(fim - comeco) / CLOCKS_PER_SEC;
  } else {
    comeco = clock();
    retorno = boss(a->area);
    fim = clock();

    if (retorno != (-2)) {
      rank->tempoArea[6] = (double)(fim - comeco) / CLOCKS_PER_SEC;
      rank->pontuacao = retorno;
    }
  }
  for(int i=0; i<7; i++){
    rank->tempoTotal += rank->tempoArea[i];
  }
  return retorno;
}

void nivel(grafo *fase, int *sala) {
  int i = 0, retorno = 0;
  (*sala)++;
  printf("Nível %d\n", *sala);
  printarMapa((*sala)-1);
  do {
    if (i == fase->tam - 1) { 
      retorno = escolhePortas(2);
      break;
    } else if (fase->vet[i]->comeco == NULL) {
      retorno = escolhePortas(0);
      i = 0;
    } 
    else {
      retorno = escolhePortas(1);
      if (retorno == 1)
        i = fase->vet[i]->comeco->sala;
      else
        i = fase->vet[i]->comeco->prox->sala;
    }
  } while (1);
}

int boss(grafo *fase) {
  int i = 0, retorno = 0, pontos = 0;
  int *vet;
  int pos = -1;
  vet = (int *)malloc(fase->tam * sizeof(int));

  printf("Nível Final\n");
  printarMapa(6);
  do {
    if (i == fase->tam - 1) { 
      retorno = escolhePortasCentral(2, pontos, 1);
      break;
      
    } else if (fase->vet[i]->comeco == NULL) {
      retorno = escolhePortasCentral(0, pontos, 1);
      if (retorno == (-2))
        return (-2);
      i = vet[pos];
      pos--;
      pontos -= 1;
      
    } 
    else {
      retorno = escolhePortasCentral(1, pontos,1);
      pos++;
      vet[pos] = i;
      
      if (retorno == 1) {
        pontos += fase->vet[i]->comeco->peso;
        fase->vet[i]->comeco->peso = 0;
        i = fase->vet[i]->comeco->sala;
        
      } else if(retorno == 2){
        pontos += fase->vet[i]->comeco->prox->peso;
        fase->vet[i]->comeco->prox->peso = 0;
        i = fase->vet[i]->comeco->prox->sala;
      }
      else{
        i = vet[pos];
        pos--;
        pontos -= 1;
        
        if(pontos < 0) return (-2);
      }
    }
  } while (1);
  return pontos;
}
