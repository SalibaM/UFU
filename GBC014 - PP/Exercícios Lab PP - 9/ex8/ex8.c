#include <stdio.h>

int negativos (int *array,int N){
    int i;
    int contador=0;

    for(i=0;i<N;i++){
        if(array[i]<0){
            contador++;
        }
    }
    return contador;
}

int main(){

    int array[5];
    int i;

    printf("Digite os 5 elementos da sua array:\n");
    for(i=0;i<5;i++){
        scanf("%d",&array[i]);
    }

    printf("Essa array tem %d numeros negativos :)",negativos(array,5));

    return 0;




}