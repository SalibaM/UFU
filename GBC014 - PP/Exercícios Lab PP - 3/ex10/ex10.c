#include <stdio.h>

int main(){

    int numsparestotal,numparatual,soma;
    numsparestotal = 0;
    numparatual = 0;
    soma = 0;

    while (numsparestotal <= 50){
        soma += numparatual;
        numparatual +=2;
        numsparestotal++;
    }
    printf("A soma dos primeiros 50 numeros pares sera de %d",soma);
    return 0;

}