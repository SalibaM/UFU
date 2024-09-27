#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int v[], int esq, int dir);
int particao(int v[],int esq,int dir);
void troca(int v[], int pivo, int i);
void quicksort_aleatorizado(int *v, int esq, int dir);
int pivo_aleatorio(int esq, int dir);
void quicksort_mediana_tres(int v[], int esq, int dir);
void quicksort_tres_partes(int a[], int l, int r);

//Caike Cesar Mota de Araújo, matrícula: 12221BCC030
//Matheus Fiod Saliba, matrícula: 12221BCC024
//Marcos Gabriel Moreira Fonseca, matrícula: 12221BCC043
int main () 
{
    int opcao, tipo, tamanho1 = 5000, tamanho2 = 50000, num, i, j;
    double inicio, fim, tempo;

    srand(time(NULL));


        int *v = (int *) malloc (tamanho1 * sizeof(int));

        int *v2 = (int *) malloc (tamanho2 * sizeof(int));

        printf("\n-- Metodo de ordenacao Quick Sort básico --\n");

        printf("\n");

        // Vetor aleatório
        printf ("\nVetor dinamico aleatorio: ");

         // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

         // ordenando com quicksort
        inicio = clock();
        quicksort (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 500 + 1;
        }

        inicio = clock();
        quicksort (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");

        // Vetor crescente
        printf ("\nVetor dinamico em ordem crescente: ");

        // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

        for (int i = 0; i < tamanho1; i++) 
        {
          for (int j = i + 1; j < tamanho1; j++) 
          {
            if (v[i] > v[j]) 
            {
              num = v[i];
              v[i] = v[j];
              v[j] = num;
            }
          }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        for (i = 0; i < tamanho2; i++) 
          {
            v2[i] = rand() % 500 + 1;
          }

        // ordenando em ordem crescente
        for (int i = 0; i < tamanho2; i++) 
        {
          for (int j = i + 1; j < tamanho2; j++) 
          {
            if (v2[i] > v2[j]) 
            {
              num = v2[i];
              v2[i] = v2[j];
              v2[j] = num;
            }
          }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");


        // Vetor decrescente
        printf ("\nVetor dinamico em ordem decrescente:" );

        // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

        // ordenando em ordem decrescente
        for (int i = 0; i < tamanho1; i++) 
        {
          for (int j = i + 1; j < tamanho1; j++) 
            {
              if (v[i] < v[j]) 
              {
                num = v[i];
                v[i] = v[j];
                v[j] = num;
              }
            }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        // gerando Vetor aleatório
        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 500 + 1;
        }

        // ordenando em ordem decrescente
        for (int i = 0; i < tamanho2; i++) 
        {
          for (int j = i + 1; j < tamanho2; j++) 
            {
              if (v2[i] < v2[j]) 
              {
                num = v2[i];
                v2[i] = v2[j];
                v2[j] = num;
              }
            }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");


        printf ("\nVetor dinamico aleatorio com muitas repeticoes: ");

        // gerando Vetor com muitas repeticoes
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 5 + 1;
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        // gerando Vetor com muitas repeticoes
        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 5 + 1;
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort (v2, 0, tamanho2-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");


        printf("\n-- Metodo de ordenacao quicksort aleatorizado --\n");

        printf("\n");

        // Vetor aleatório
        printf ("\nVetor dinamico aleatorio: ");

         // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

         // ordenando com quicksort
        inicio = clock();
        quicksort_aleatorizado (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 500 + 1;
        }

        inicio = clock();
        quicksort_aleatorizado (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");

        // Vetor crescente
        printf ("\nVetor dinamico em ordem crescente: ");

        // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

        for (int i = 0; i < tamanho1; i++) 
        {
          for (int j = i + 1; j < tamanho1; j++) 
          {
            if (v[i] > v[j]) 
            {
              num = v[i];
              v[i] = v[j];
              v[j] = num;
            }
          }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_aleatorizado (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        for (i = 0; i < tamanho2; i++) 
          {
            v2[i] = rand() % 500 + 1;
          }

        // ordenando em ordem crescente
        for (int i = 0; i < tamanho2; i++) 
        {
          for (int j = i + 1; j < tamanho2; j++) 
          {
            if (v2[i] > v2[j]) 
            {
              num = v2[i];
              v2[i] = v2[j];
              v2[j] = num;
            }
          }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_aleatorizado (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");


        // Vetor decrescente
        printf ("\nVetor dinamico em ordem decrescente:" );

        // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

        // ordenando em ordem decrescente
        for (int i = 0; i < tamanho1; i++) 
        {
          for (int j = i + 1; j < tamanho1; j++) 
            {
              if (v[i] < v[j]) 
              {
                num = v[i];
                v[i] = v[j];
                v[j] = num;
              }
            }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_aleatorizado (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        // gerando Vetor aleatório
        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 500 + 1;
        }

        // ordenando em ordem decrescente
        for (int i = 0; i < tamanho2; i++) 
        {
          for (int j = i + 1; j < tamanho2; j++) 
            {
              if (v2[i] < v2[j]) 
              {
                num = v2[i];
                v2[i] = v2[j];
                v2[j] = num;
              }
            }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_aleatorizado (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");


        printf ("\nVetor dinamico aleatorio com muitas repeticoes: ");

        // gerando Vetor com muitas repeticoes
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 5 + 1;
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_aleatorizado (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        // gerando Vetor com muitas repeticoes
        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 5 + 1;
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_aleatorizado (v2, 0, tamanho2-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");

        printf("\n-- Metodo de ordenacao quicksort com mediana de tres: --\n");

        printf("\n");

        // Vetor aleatório
        printf ("\nVetor dinamico aleatorio: ");

         // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

         // ordenando com quicksort
        inicio = clock();
        quicksort_mediana_tres (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 500 + 1;
        }

        inicio = clock(); 
        quicksort_mediana_tres (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");

        // Vetor crescente
        printf ("\nVetor dinamico em ordem crescente: ");

        // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

        for (int i = 0; i < tamanho1; i++) 
        {
          for (int j = i + 1; j < tamanho1; j++) 
          {
            if (v[i] > v[j]) 
            {
              num = v[i];
              v[i] = v[j];
              v[j] = num;
            }
          }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_mediana_tres (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        for (i = 0; i < tamanho2; i++) 
          {
            v2[i] = rand() % 500 + 1;
          }

        // ordenando em ordem crescente
        for (int i = 0; i < tamanho2; i++) 
        {
          for (int j = i + 1; j < tamanho2; j++) 
          {
            if (v2[i] > v2[j]) 
            {
              num = v2[i];
              v2[i] = v2[j];
              v2[j] = num;
            }
          }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_mediana_tres (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");


        // Vetor decrescente
        printf ("\nVetor dinamico em ordem decrescente:" );

        // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

        // ordenando em ordem decrescente
        for (int i = 0; i < tamanho1; i++) 
        {
          for (int j = i + 1; j < tamanho1; j++) 
            {
              if (v[i] < v[j]) 
              {
                num = v[i];
                v[i] = v[j];
                v[j] = num;
              }
            }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_mediana_tres (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        // gerando Vetor aleatório
        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 500 + 1;
        }

        // ordenando em ordem decrescente
        for (int i = 0; i < tamanho2; i++) 
        {
          for (int j = i + 1; j < tamanho2; j++) 
            {
              if (v2[i] < v2[j]) 
              {
                num = v2[i];
                v2[i] = v2[j];
                v2[j] = num;
              }
            }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_mediana_tres (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");


        printf ("\nVetor dinamico aleatorio com muitas repeticoes: ");

        // gerando Vetor com muitas repeticoes
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 5 + 1;
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_mediana_tres (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        // gerando Vetor com muitas repeticoes
        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 5 + 1;
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_mediana_tres (v2, 0, tamanho2-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");

        printf("\n-- Metodo de ordenacao quicksort com tres vias: --\n");

        printf("\n");

        // Vetor aleatório
        printf ("\nVetor dinamico aleatorio: ");

         // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

         // ordenando com quicksort
        inicio = clock();
        quicksort_tres_partes (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 500 + 1;
        }

        inicio = clock();
        quicksort_tres_partes (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");

        // Vetor crescente
        printf ("\nVetor dinamico em ordem crescente: ");

        // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

        for (int i = 0; i < tamanho1; i++) 
        {
          for (int j = i + 1; j < tamanho1; j++) 
          {
            if (v[i] > v[j]) 
            {
              num = v[i];
              v[i] = v[j];
              v[j] = num;
            }
          }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_tres_partes (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        for (i = 0; i < tamanho2; i++) 
          {
            v2[i] = rand() % 500 + 1;
          }

        // ordenando em ordem crescente
        for (int i = 0; i < tamanho2; i++) 
        {
          for (int j = i + 1; j < tamanho2; j++) 
          {
            if (v2[i] > v2[j]) 
            {
              num = v2[i];
              v2[i] = v2[j];
              v2[j] = num;
            }
          }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_tres_partes (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");

        // Vetor decrescente
        printf ("\nVetor dinamico em ordem decrescente:" );

        // gerando Vetor aleatório
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 500 + 1;
        }

        // ordenando em ordem decrescente
        for (int i = 0; i < tamanho1; i++) 
        {
          for (int j = i + 1; j < tamanho1; j++) 
            {
              if (v[i] < v[j]) 
              {
                num = v[i];
                v[i] = v[j];
                v[j] = num;
              }
            }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_tres_partes (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        // gerando Vetor aleatório
        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 500 + 1;
        }

        // ordenando em ordem decrescente
        for (int i = 0; i < tamanho2; i++) 
        {
          for (int j = i + 1; j < tamanho2; j++) 
            {
              if (v2[i] < v2[j]) 
              {
                num = v2[i];
                v2[i] = v2[j];
                v2[j] = num;
              }
            }
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_tres_partes (v2, 0, v2[tamanho2-1]);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");

        printf ("\nVetor dinamico aleatorio com muitas repeticoes: ");

        // gerando Vetor com muitas repeticoes
        for (i = 0; i < tamanho1; i++) 
        {
          v[i] = rand() % 5 + 1;
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_tres_partes (v, 0, tamanho1-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n5.000 posicoes: %lf", tempo);

        // gerando Vetor com muitas repeticoes
        for (i = 0; i < tamanho2; i++) 
        {
          v2[i] = rand() % 5 + 1;
        }

        // ordenando com quicksort
        inicio = clock();
        quicksort_tres_partes (v2, 0, tamanho2-1);
        fim = clock();
        tempo = (fim - inicio) / CLOCKS_PER_SEC;
        printf ("\n50.000 posicoes: %lf", tempo);

        printf("\n");
        printf("\n");

    return 0;
}

void troca(int v[], int pivo, int i) 
{
    int temp = v[pivo];
    v[pivo] = v[i];
    v[i] = temp;
}

int particao(int v[],int esq,int dir)
{
  int i, pivo;
  pivo = esq;
  for(i=esq+1; i<=dir; i++)
    {
      if(v[i] < v[esq]) 
      {
        pivo = pivo + 1;
        troca(v,pivo,i);
      }
    }

  troca(v,esq,pivo);
  return pivo;
}

void quicksort(int v[], int esq, int dir)
{
  int i;
  if(esq>=dir) return;
  i = particao(v,esq,dir);
  quicksort(v,esq,i-1);
  quicksort(v,i+1,dir);
}

int pivo_aleatorio(int esq, int dir) 
{
  double r;
  r = (double) rand()/RAND_MAX; // valor entre 0.01 e 0.99
  return (int)(esq + r*(dir-esq));
}

void quicksort_aleatorizado(int *v, int esq, int dir) 
{
  int i;
  if (dir <= esq) return;
  troca(v, pivo_aleatorio(esq,dir), esq);
  i = particao(v, esq, dir);
  quicksort_aleatorizado(v, esq, i-1);
  quicksort_aleatorizado(v, i+1, dir);
}

void quicksort_mediana_tres(int v[], int esq, int dir)
{
    int i;
    if (dir <= esq) return;

    troca(v, (esq + dir) / 2, esq + 1);

    if (v[esq] > v[esq + 1]) troca(v, esq, esq + 1);

    if (v[esq] > v[dir]) troca(v, esq, dir);

    if (v[esq + 1] > v[dir]) troca(v, esq + 1, dir);

    i = particao(v, esq + 1, dir - 1);

    quicksort_mediana_tres(v, esq, i - 1);
    quicksort_mediana_tres(v, i + 1, dir);
}

void quicksort_tres_partes(int a[], int l, int r)
{
    int k, i = l - 1, j = r, p = l - 1, q = r;
    int v = a[r];
    if (r <= l)
        return;
    for (;;)
    {
        while (a[++i] < v)
            while (v < a[--j])
                if (j == 1)
                    break;
        if (i >= j)
            break;
        troca(a, i, j);
        if (a[i] == v)
        {
            p++;
            troca(a, p, i);
        }
        if (v == a[j])
        {
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

    quicksort_tres_partes(a, l, j);
    quicksort_tres_partes(a, i, r);
}
