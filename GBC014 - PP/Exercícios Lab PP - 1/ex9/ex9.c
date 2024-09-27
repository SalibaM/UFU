#include <stdio.h>

int main(){
    float tempc;
    float tempk;

    printf("Digite uma temperatura em Celsius:");
    scanf("%f",&tempc);

    tempk = tempc + 273.15;
    printf("A temperatura em Kelvin eh:%f",tempk);

    return 0;



}