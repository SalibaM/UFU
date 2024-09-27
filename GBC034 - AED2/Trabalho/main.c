#include <stdio.h>
#include "utilitarios.h"


int main() {
  rank score[10];
  int tam = 0, retorno;

 do{
    ordena_pontuacao(score, &tam);
    retorno = menu(score, &tam);
    ordena_pontuacao(score, &tam);
  }while(retorno);
  return 0;
}
