#include <stdio.h>

void maxmin (int *array,int *valmax,int *valmin,int n){
    int i;

    *valmax=array[0];

    for(i=0;i<n;i++){
        if(array[i]>*valmax){
            *valmax=array[i];
        }
    }

    *valmin=array[0];

    for(i=0;i<n;i++){
        if(array[i]<*valmin){
            *valmin=array[i];
        }
    }
}

int main(){

    int n;
    printf("Digite o tamanho da sua array:\n");
    scanf("%d",&n);

    int array[n];
    int i,valmax=0,valmin;

    printf("Digite os %d elementos da sua array:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    valmin=array[0];

    maxmin(array,&valmax,&valmin,n);

    printf("O valor maximo sera:%d\n",valmax);
    printf("O valor minimo sera:%d\n",valmin);

    return 0;




}