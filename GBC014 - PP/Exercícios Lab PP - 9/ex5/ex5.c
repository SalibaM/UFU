#include <stdio.h>
#include <stdlib.h>

void valores(float *x,int *inteira,float *fracao){

    *inteira = (int)*x/1;
    *fracao = (float)*x - *inteira;
}

int main(){

    float x,fracao=0;
    int inteira=0;

    printf("Digite um numero real:\n");
    scanf("%f",&x);

    valores(&x,&inteira,&fracao);

    printf("Parte inteira:%d\n",inteira);
    printf("Parte fracionaria:%.3f\n",fracao);

    return 0;
}