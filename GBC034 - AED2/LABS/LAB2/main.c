#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int vetor[], int tam)
{
    int temp, i, j;

    for(i=0; i<tam ; i++)
    {
        for(j=0; j<tam-1-i; j++)
        {
            if(vetor[j+1] < vetor[j])
            {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }

}

void selectionSort(int vetor [], int n)
{
    int temp;
    int menor, i, j;
    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < n; j++)
        {
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }
        temp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = temp;
    }
}

void insertionSort (int vet[], int n)
{
    int i,j, tmp;
    for (i=1 ; i < n ; i++)
    {
        tmp = vet[i];
        for (j = i-1 ; j >= 0 && vet[j] > tmp ; j--)
            vet[j+1] = vet[j];
        vet[j+1] = tmp;
    }
}

void Shellsort(int vetor [], int n)
{
    int i, j, h = 1;
    int aux;
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
                vetor[j] = vetor[j - h];
                j -= h;
                if (j < h)
                    break;
            }
            vetor[j] = aux;
        }
    }
    while (h != 1);
}


int main(){

    int i;
    int *v;
    int *aux;
    time_t ini;
    time_t fim;
    double tempo_total;
    srand(time(NULL));

    aux = (int *)malloc(10000*sizeof(int));
    v = (int *)malloc(10000*sizeof(int));

    for(i=0;i<10000;i++){
        aux[i] = rand()%10001;
    }

    //Bubble
    for(i=0;i<10000;i++){
        v[i]=aux[i];
    }

    ini=clock();
    BubbleSort(v,10000);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nTempo total = %f\n",tempo_total);

    //Insertion
    for(i=0;i<10000;i++){
        v[i]=aux[i];
    }

    ini=clock();
    insertionSort(v,10000);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nTempo total = %f\n",tempo_total);

    //Selection
    for(i=0;i<10000;i++){
        v[i]=aux[i];
    }
    ini=clock();
    selectionSort(v,10000);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nTempo total = %f\n",tempo_total);

    //Shell
    for(i=0;i<10000;i++){
        v[i]=aux[i];
    }
    ini=clock();
    Shellsort(v,10000);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nTempo total = %f\n",tempo_total);

    free(v);

    free(aux);




  return 0;

}

