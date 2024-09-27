#include <stdio.h>

int main(){
    float vollitro;
    float volm3;
    printf("Digite um valor de volume em litros:");
    scanf("%f",&vollitro);

    volm3 = vollitro/1000;

    printf("O valor desse volume em metros cubicos eh:%f",volm3);

    return 0;


}