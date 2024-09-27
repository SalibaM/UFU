#include <stdio.h>

int main(){
    float vpol;
    float vcm;
    printf("Digite um valor de comprimento em polegadas:");
    scanf("%f",&vpol);

    vcm = vpol*2.54;

    printf("Esse valor de comprimento em centimetros eh:%f",vcm);

    return 0;

}