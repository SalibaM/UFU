#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// MATHEUS FIOD SALIBA 12221BCC024
// CAIKE CESAR MOTA DE ARAUJO 12221BCC030

void BubbleSort(int vetor[], int tam, int *comp, int *troca);

void Shellsort(int vetor [], int n, int *comp, int *troca);

void mergeSort (int vetor[], int n, int *comp, int *troca);

void m_sort (int vetor[], int aux[], int esq, int dir, int *comp, int *troca);

void merge (int vetor[], int aux[], int esq, int meio, int dir, int *comp, int *troca);

void abcSort(int vetor[],int i,int j);

int main()
{

    int i,comp, troca;
    int trocaB, trocaS, trocaM;
    int comparacaoB, comparacaoS, comparacaoM;
    int *v1;
    int *aux;

    //Começo do código para 10.000 posições
    v1 = (int *)malloc(10000*sizeof(int));
    aux = (int *)malloc(10000*sizeof(int));

    for(i=0;i<10000;i++)
    {
        aux[i] = rand()%100;
    }

    //Bubble
    for(i=0;i<10000;i++)
    {
        v1[i]=aux[i];
    }

    BubbleSort(v1,10000, &comp, &troca);
    trocaB = troca;
    comparacaoB = comp;

    //Shell
    for(i=0;i<10000;i++)
    {
        v1[i]=aux[i];
    }
    Shellsort(v1,10000, &comp, &troca);
    trocaS = troca;
    comparacaoS = comp;

    //Merge
    for(i=0;i<10000;i++){
        v1[i]=aux[i];
    }
    mergeSort(v1,10000, &comp, &troca);
    trocaM = troca;
    comparacaoM = comp;

    printf("\n- Bubble sort: ");
    printf("\n*Comparacoes: %d", comparacaoB);
    printf("\n*Trocas: %d", trocaB);

    printf("\n- Shell sort: ");
    printf("\n*Comparacoes: %d", comparacaoS);
    printf("\n*Trocas: %d", trocaS);

    printf("\n- Merge sort: ");
    printf("\n*Comparacoes: %d", comparacaoM);
    printf("\n*Trocas: %d", trocaM);

    free(v1);
    free(aux);

  return 0;

}

void BubbleSort(int vetor[], int tam, int *comp, int *troca)
{
    int temp, i, j;
    *comp = 0, *troca = 0;

    for(i=0; i<tam ; i++)
    {
        for(j=0; j<tam-1-i; j++)
        {
            (*comp)++;
            if(vetor[j+1] < vetor[j])
            {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                (*troca)++;
            }
        }
    }

}

void Shellsort(int vetor [], int n, int *comp, int *troca)
{
    int i, j, h = 1;
    int aux;
    *comp = 0, *troca = 0;
    do
    {
        h = h * 3 + 1;
    }
    while (h < n);
    do
    {
        h /= 3;
        for(i = h ; i < n ; i++)
        {
            aux = vetor[i];
            j = i;
            while (vetor[j - h] > aux)
            {
                (*comp)++;
                vetor[j] = vetor[j - h];
                j -= h;
                if (j < h)
                    break;
            }
            (*troca)++;
            vetor[j] = aux;
        }
    }
    while (h != 1);
}

void mergeSort (int vetor[], int n, int *comp, int *troca) 
{
    *comp = 0, *troca = 0;
    int aux[n];
    m_sort(vetor, aux, 0, n-1, comp, troca);
}

void m_sort (int vetor[], int aux[], int esq, int dir, int *comp, int *troca) 
{
    int meio;
    if (dir > esq) {
        meio = (dir + esq) / 2;
        m_sort(vetor, aux, esq, meio, comp, troca);
        m_sort(vetor, aux, meio+1, dir, comp, troca);
        merge(vetor, aux, esq, meio+1, dir, comp, troca);
    }
}

void merge (int vetor[], int aux[], int esq, int meio, int dir, int *comp, int *troca) 
{
    int i, esq_fim, n;
    esq_fim = meio-1;
    i = esq;
    n = dir - esq + 1;
    while (esq <= esq_fim && meio <= dir) 
    {
        (*comp)++;
        if (vetor[esq] <= vetor[meio])
            aux[i++] = vetor[esq++];
        else
            aux[i++] = vetor[meio++];
    }
    while (esq <= esq_fim) aux[i++] = vetor[esq++];
    while (meio <= dir) aux[i++] = vetor[meio++];
    for (i = 0; i < n; i++) 
    {
        (*troca)++;
        vetor[dir] = aux[dir];
        dir--;
    }
}

void abcSort(int vetor[],int i,int j)
{

    int temp;
    int k;

    if(vetor[i]>vetor[j]){

        temp = vetor[j];

        vetor[j] = vetor[i];

        vetor[i] = temp;

    }

    if(i+1 >= j){
        return;
    }

    k = (j-i+1)/3;

    abcSort(vetor,i,j-k);
    abcSort(vetor,i+k,j);
    abcSort(vetor,i,j-k);

}
