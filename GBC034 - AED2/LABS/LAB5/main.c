#include <stdio.h>
#include <string.h>

// NOME: AMANDA DUARTE GARCIA - 12221BCC031
// NOME: CAIKE CESAR MOTA DE ARAUJO - 12221BCC030
// NOME: MATHEUS FIOD SALIBA - 12221BCC024

struct cep {
  int cep;
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
  int cep;
  int cepP;
  int i = 0;

  CEP vetor[58];
  int tam;

  while (fscanf(arquivo, "%d; %2[^;]; %[^;]; %[^\n]\n", &cep, estado, cidade,
                endereco) != EOF) {
    vetor[i].cep = cep;
    strcpy(vetor[i].estado, estado);
    strcpy(vetor[i].cidade, cidade);
    strcpy(vetor[i].endereco, endereco);
    i++;
  }

  tam = sizeof(vetor) / sizeof(vetor[0]);

  qsParticaoTres(vetor, 0, tam - 1);

  printf("Digite o CEP desejado\n");
  scanf("%d", &cepP);

  CEP *retorno;
  int encontrado = busca_binaria(vetor, tam, cepP, &retorno);

  if (encontrado == 0) {
    printf("CEP encontrado!\n");
    printf("Estado: %s\n", retorno->estado);
    printf("Cidade: %s\n", retorno->cidade);
    printf("Endereco: %s\n", retorno->endereco);
  } else {
    printf("CEP nao encontrado!\n");
  }
}

int busca_binaria(CEP v[], int n, int chave_busca, CEP *retorno) {
  int inf = 0, sup = n - 1, meio;

  while (inf <= sup) {
    meio = (inf + sup) / 2;
    if (v[meio].cep == chave_busca) {
      *retorno = v[meio];
      return 0;
    } else if (v[meio].cep > chave_busca)
      sup = meio - 1;
    else
      inf = meio + 1;
  }
  return -1;
}

void troca(CEP v[], int pivo, int i) {
  CEP temp = v[pivo];
  v[pivo] = v[i];
  v[i] = temp;
}

void qsParticaoTres(CEP a[], int l, int r) {
  int k, i = l - 1, j = r, p = l - 1, q = r;
  int v = a[r].cep;
  if (r <= l)
    return;
  for (;;) {
    while (a[++i].cep < v)
      ;
    while (v < a[--j].cep)
      if (j == l)
        break;
    if (i >= j)
      break;
    troca(a, i, j);
    if (a[i].cep == v) {
      p++;
      troca(a, p, i);
    }
    if (v == a[j].cep) {
      q--;
      troca(a, j, q);
    }
  }
  troca(a, i, r);
  j = i - 1;
  i = i + 1;
  for (k = l; k <= p; k++, j--)
    troca(a, k, j);
  for (k = r - 1; k >= q; k--, i++)
    troca(a, i, k);
  qsParticaoTres(a, l, j);
  qsParticaoTres(a, i, r);
}
