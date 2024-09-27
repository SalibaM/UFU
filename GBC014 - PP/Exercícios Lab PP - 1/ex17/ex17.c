#include <stdio.h>

int main(){
    float vcm;
    float vpol;
    printf("Digite um valor de comprimento em centimetros:");
    scanf("%f",&vcm);

    vpol = vcm/2.54;

    printf("O valor desse comprimento em polegadas eh:%f",vpol);

    return 0;


}