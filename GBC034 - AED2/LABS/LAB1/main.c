#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// MATHEUS FIOD SALIBA(1221BCC024) E CAIKE CESAR MOTA DE ARAUJO(12221BCC030)

void BubbleSort(int vetor[], int tam, int *comp, int *troca);

void Shellsort(int vetor [], int n, int *comp, int *troca);

void mergeSort (int vetor[], int n, int *comp, int *troca);

void m_sort (int vetor[], int aux[], int esq, int dir, int *comp, int *troca);

void merge (int vetor[], int aux[], int esq, int meio, int dir, int *comp, int *troca);

void abcSort(int vetor[],int i,int j);

int main(){

    int i, j, comp, troca;
    int *v;
    int *aux;
    time_t ini;
    time_t fim;
    double tempo_total;
    srand(time(NULL));

    //Começo do código para 10.000 posições
    printf("\n- Para 10.000 posicoes de vetor: ");
    aux = (int *)malloc(10000*sizeof(int));
    v = (int *)malloc(10000*sizeof(int));

    for(i=0;i<10000;i++)
    {
        aux[i] = rand()%100;
    }

    //Bubble
    for(i=0;i<10000;i++){
        v[i]=aux[i];
    }

    ini=clock();
    BubbleSort(v,10000, &comp, &troca);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nBubble sort = %f",tempo_total);

    //Shell
    for(i=0;i<10000;i++)
    {
        v[i]=aux[i];
    }
    ini=clock();
    Shellsort(v,10000, &comp, &troca);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nShell sort = %f",tempo_total);

    //Merge
    for(i=0;i<10000;i++){
        v[i]=aux[i];
    }
    ini=clock();
    mergeSort(v,10000, &comp, &troca);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nMerge sort = %f",tempo_total);

    //ABC Sort

    for(i=0;i<10000;i++){
        v[i]=aux[i];
    }
    ini=clock();
    i=0, j=9999;
    abcSort(v,i,j);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nABC sort = %f\n",tempo_total);

    free(v);
    free(aux);

    //Começo do código para 50.000 posicoes ---------------------------------------------------------------------------------------------------------
    aux = (int *)malloc(50000*sizeof(int));
    v = (int *)malloc(50000*sizeof(int));

    printf("\n Para 50.000 posicoes de vetor: ");

    for(i=0;i<50000;i++)
    {
        aux[i] = rand()%100;
    }

    //Bubble
    for(i=0;i<50000;i++){
        v[i]=aux[i];
    }

    ini=clock();
    BubbleSort(v,50000, &comp, &troca);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nBubble sort = %f",tempo_total);

    //Shell
    for(i=0;i<50000;i++)
    {
        v[i]=aux[i];
    }
    ini=clock();
    Shellsort(v,50000, &comp, &troca);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nShell sort = %f",tempo_total);

    //Merge
    for(i=0;i<50000;i++){
        v[i]=aux[i];
    }
    ini=clock();
    mergeSort(v,50000, &comp, &troca);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nMerge sort = %f",tempo_total);

    //ABC Sort

    /*for(i=0;i<50000;i++){
        v[i]=aux[i];
    }
    i=0, j=49999;
    ini=clock();
    abcSort(v,i,j);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nABC sort = %f",tempo_total);*/

    free(v);
    free(aux);

    //Começo do código para 100.000 posicoes ---------------------------------------------------------------------------------------------------------

    printf("\n- Para 100.000 posicoes do vetor: ");
    aux = (int *)malloc(100000*sizeof(int));
    v = (int *)malloc(100000*sizeof(int));

    for(i=0;i<100000;i++)
    {
        aux[i] = rand()%100;
    }

    //Bubble
    for(i=0;i<100000;i++){
        v[i]=aux[i];
    }

    ini=clock();
    BubbleSort(v,100000, &comp, &troca);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nBubble sort = %f",tempo_total);

    //Shell
    for(i=0;i<100000;i++)
    {
        v[i]=aux[i];
    }
    ini=clock();
    Shellsort(v,100000, &comp, &troca);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nShell sort = %f",tempo_total);

    //Merge
    for(i=0;i<100000;i++){
        v[i]=aux[i];
    }
    ini=clock();
    mergeSort(v,100000, &comp, &troca);
    fim=clock();

    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

    printf("\nMerge sort = %f",tempo_total);
    printf("\nABC sort = crash"); //Nao testarei pois a professora falou que demora até 15 minutos para ordenar um vetor de 100k posicoes

    free(v);
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
