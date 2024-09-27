#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b);

void heapify(int arr[], int N, int i);

void heapSort(int arr[], int N);

void Shellsort(int vetor [], int n);

int main()
{
    int i;
    time_t ini;
    time_t fim;
    double tempo_total;
    srand(time(NULL));

    int tipoVet;
    int opcaoTam;

    int *vet;
    int *aux;

    do
    {
        printf("Digite o tipo de vetor que voce quer:\n (1)Aleatoria\n(2)Descendente\n(3)Ascendente\n(4)Sair");
        printf("\n");
        scanf("%d",&tipoVet);

        switch (tipoVet)
        {

        case 1 :
            printf("Digite o tamanho do vetor: \n(1)10.000\n(2)50.000\n(3)100.000\n(4)Sair");
            printf("\n");
            scanf("%d",&opcaoTam);

            if(opcaoTam==1)
            {
                aux = (int *)malloc(10000*sizeof(int));
                vet = (int *)malloc(10000*sizeof(int));

                for(i=0; i<10000; i++)
                {
                    vet[i] = rand()%100;
                }

                for(i=0; i<10000; i++)
                {
                    aux[i]=vet[i];
                }

                ini=clock();
                heapSort(vet,10000);
                fim=clock();

                tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                printf("Tempo total HEAP SORT:%lf",tempo_total);
                printf("\n");

                for(i=0; i<10000; i++)
                {
                    vet[i]=aux[i];
                }

                ini=clock();
                Shellsort(vet,10000);
                fim=clock();

                tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                printf("Tempo total SHELL SORT:%lf",tempo_total);
                printf("\n");

                free(vet);
                free(aux);

            }
            else
            {
                if(opcaoTam==2)
                {
                    aux = (int *)malloc(50000*sizeof(int));
                    vet = (int *)malloc(50000*sizeof(int));


                    for(i=0; i<50000; i++)
                    {
                        vet[i] = rand()%100;
                    }

                    for(i=0; i<50000; i++)
                    {
                        aux[i]=vet[i];
                    }

                    ini=clock();
                    heapSort(vet,50000);
                    fim=clock();

                    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                    printf("Tempo total HEAP SORT:%lf",tempo_total);
                    printf("\n");

                    for(i=0; i<50000; i++)
                    {
                        vet[i]=aux[i];
                    }

                    ini=clock();
                    Shellsort(vet,50000);
                    fim=clock();

                    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                    printf("Tempo total SHELL SORT:%lf",tempo_total);
                    printf("\n");

                    free(vet);
                    free(aux);


                }
                else
                {
                    if(opcaoTam==3)
                    {

                        aux = (int *)malloc(100000*sizeof(int));
                        vet = (int *)malloc(100000*sizeof(int));


                        for(i=0; i<100000; i++)
                        {
                            vet[i] = rand()%100;
                        }

                        for(i=0; i<100000; i++)
                        {
                            aux[i]=vet[i];
                        }

                        ini=clock();
                        heapSort(vet,100000);
                        fim=clock();

                        tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                        printf("Tempo total HEAP SORT:%lf",tempo_total);
                        printf("\n");

                        for(i=0; i<100000; i++)
                        {
                            vet[i]=aux[i];
                        }

                        ini=clock();
                        Shellsort(vet,100000);
                        fim=clock();

                        tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                        printf("Tempo total SHELL SORT:%lf",tempo_total);
                        printf("\n");

                        free(vet);
                        free(aux);


                    }

                }
            }

            break;

        case 2:

            printf("Digite o tamanho do vetor: \n(1)10.000\n(2)50.000\n(3)100.000\n(4)Sair");
            printf("\n");
            scanf("%d",&opcaoTam);

            if(opcaoTam==1)
            {
                aux = (int *)malloc(10000*sizeof(int));
                vet = (int *)malloc(10000*sizeof(int));

                for(i=10000; i<0; i--)
                {
                    vet[i] = i;
                }

                for(i=0; i<10000; i++)
                {
                    aux[i]=vet[i];
                }

                ini=clock();
                heapSort(vet,10000);
                fim=clock();

                tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                printf("Tempo total HEAP SORT:%lf",tempo_total);
                printf("\n");

                for(i=0; i<10000; i++)
                {
                    vet[i]=aux[i];
                }

                ini=clock();
                Shellsort(vet,10000);
                fim=clock();

                tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                printf("Tempo total SHELL SORT:%lf",tempo_total);
                printf("\n");

                free(vet);
                free(aux);

            }
            else
            {
                if(opcaoTam==2)
                {
                    aux = (int *)malloc(50000*sizeof(int));
                    vet = (int *)malloc(50000*sizeof(int));

                    for(i=50000; i<0; i--)
                    {
                        vet[i] = i;
                    }


                    for(i=0; i<50000; i++)
                    {
                        aux[i]=vet[i];
                    }

                    ini=clock();
                    heapSort(vet,50000);
                    fim=clock();

                    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                    printf("Tempo total HEAP SORT:%lf",tempo_total);
                    printf("\n");

                    for(i=0; i<50000; i++)
                    {
                        vet[i]=aux[i];
                    }

                    ini=clock();
                    Shellsort(vet,50000);
                    fim=clock();

                    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                    printf("Tempo total SHELL SORT:%lf",tempo_total);
                    printf("\n");

                    free(vet);
                    free(aux);


                }
                else
                {
                    if(opcaoTam==3)
                    {
                        aux = (int *)malloc(100000*sizeof(int));
                        vet = (int *)malloc(100000*sizeof(int));

                        for(i=100000; i<0; i--)
                        {
                            vet[i] = rand()%100;
                        }

                        for(i=0; i<100000; i++)
                        {
                            aux[i]=vet[i];
                        }

                        ini=clock();
                        heapSort(vet,100000);
                        fim=clock();

                        tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                        printf("Tempo total HEAP SORT:%lf",tempo_total);
                        printf("\n");

                        for(i=0; i<100000; i++)
                        {
                            vet[i]=aux[i];
                        }

                        ini=clock();
                        Shellsort(vet,100000);
                        fim=clock();

                        tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                        printf("Tempo total SHELL SORT:%lf",tempo_total);
                        printf("\n");

                        free(vet);
                        free(aux);


                    }

                }
            }

            break;

        case 3:


            printf("Digite o tamanho do vetor: \n(1)10.000\n(2)50.000\n(3)100.000\n(4)Sair");
            printf("\n");
            scanf("%d",&opcaoTam);

            if(opcaoTam==1)
            {
                aux = (int *)malloc(10000*sizeof(int));
                vet = (int *)malloc(10000*sizeof(int));

                for(i=0; i<10000; i++)
                {
                    vet[i] = i;
                }

                for(i=0; i<10000; i++)
                {
                    aux[i]=vet[i];
                }

                ini=clock();
                heapSort(vet,10000);
                fim=clock();

                tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                printf("Tempo total HEAP SORT:%lf",tempo_total);
                printf("\n");

                for(i=0; i<10000; i++)
                {
                    vet[i]=aux[i];
                }

                ini=clock();
                Shellsort(vet,10000);
                fim=clock();

                tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                printf("Tempo total SHELL SORT:%lf",tempo_total);
                printf("\n");

                free(vet);
                free(aux);

            }
            else
            {
                if(opcaoTam==2)
                {
                    aux = (int *)malloc(50000*sizeof(int));
                    vet = (int *)malloc(50000*sizeof(int));

                    for(i=0; i<50000; i++)
                    {
                        vet[i] = i;
                    }


                    for(i=0; i<50000; i++)
                    {
                        aux[i]=vet[i];
                    }

                    ini=clock();
                    heapSort(vet,50000);
                    fim=clock();

                    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                    printf("Tempo total HEAP SORT:%lf",tempo_total);
                    printf("\n");

                    for(i=0; i<50000; i++)
                    {
                        vet[i]=aux[i];
                    }

                    ini=clock();
                    Shellsort(vet,50000);
                    fim=clock();

                    tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                    printf("Tempo total SHELL SORT:%lf",tempo_total);
                    printf("\n");

                    free(vet);
                    free(aux);


                }
                else
                {
                    if(opcaoTam==3)
                    {
                        aux = (int *)malloc(100000*sizeof(int));
                        vet = (int *)malloc(100000*sizeof(int));

                        for(i=0; i<10000; i++)
                        {
                            vet[i] = rand()%100;
                        }

                        for(i=0; i<100000; i++)
                        {
                            aux[i]=vet[i];
                        }

                        ini=clock();
                        heapSort(vet,100000);
                        fim=clock();

                        tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                        printf("Tempo total HEAP SORT:%lf",tempo_total);
                        printf("\n");

                        for(i=0; i<100000; i++)
                        {
                            vet[i]=aux[i];
                        }

                        ini=clock();
                        Shellsort(vet,100000);
                        fim=clock();

                        tempo_total=(double)(fim-ini)/CLOCKS_PER_SEC;

                        printf("Tempo total SHELL SORT:%lf",tempo_total);
                        printf("\n");

                        free(vet);
                        free(aux);

                    }

                }

            }

            break;

        default:
            exit(1);

        }

    }while(tipoVet!=3 || opcaoTam!=3);

    return 0;

}

void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i)
{

    int largest = i;


    int left = 2 * i + 1;


    int right = 2 * i + 2;


    if (left < N && arr[left] > arr[largest])

        largest = left;

    if (right < N && arr[right] > arr[largest])

        largest = right;

    if (largest != i)
    {

        swap(&arr[i], &arr[largest]);

        heapify(arr, N, largest);
    }
}


void heapSort(int arr[], int N)
{


    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);


    for (int i = N - 1; i >= 0; i--)
    {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
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

