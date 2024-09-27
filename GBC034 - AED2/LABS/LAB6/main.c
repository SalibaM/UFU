#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

#include "abb.h"
#include <stdio.h>
#include <string.h>

// NOME: AMANDA DUARTE GARCIA - 12221BCC031
// NOME: CAIKE CESAR MOTA DE ARAUJO - 12221BCC030
// NOME: MATHEUS FIOD SALIBA - 12221BCC024

struct cep {
  float cep;
  char estado[3];
  char cidade[50];
  char endereco[100];
} typedef CEP;

int busca_binaria(CEP v[], int n, int chave_busca, CEP *retorno);
void troca(CEP v[], int pivo, int i);
void qsParticaoTres(CEP a[], int l, int r);

int main() {
  FILE *arquivo = fopen("cep ponto e virgula.txt", "r");
  char estado[15], cidade[255], endereco[255];
  Registro reg, reg2;
  Apontador *apt = (Apontador *)malloc(sizeof(Apontador));
  Apontador *apt2 = (Apontador *)malloc(sizeof(Apontador));
  float cep;
  int i = 0;

  criacao(apt);
  criacao(apt2);

  while (fscanf(arquivo, "%f; %2[^;]; %[^;]; %[^\n]\n", &cep, estado, cidade,
                endereco) != EOF) {
    reg.chave = cep;
    reg.uf = estado;
    reg.cidade = cidade;
    reg.endereco = endereco;

    insercao(reg, apt);
    i++;
  }

  central(apt);

  printf("\nEscreva um CEP para buscar: ");
  scanf("%f", &cep);
  reg.chave = cep;
  reg2 = pesquisa(&reg, apt);
  if (reg2.chave == -1) {
    printf("CEP não encontrado");
  } else
    printf("\nCEP: %f\nEstado: %s\nCidade: %s", reg2.chave, reg2.uf,
           reg2.cidade);

  int h = altura(apt);

  printf("\nAltura da árvore: %d\n", h);

  while (fscanf(arquivo, "%f; %2[^;]; %[^;]; %[^\n]\n", &cep, estado, cidade,
                endereco) != EOF) {
    reg.chave = cep;
    reg.uf = estado;
    reg.cidade = cidade;
    reg.endereco = endereco;

    insercao(reg, apt2);
    i++;
    if (i == 20)
      break;
  }

  central(apt2);
  pre_fixado(apt2);
  pos_fixado(apt2);

  return 0;
}




































