#include <stdio.h>

int main(){
    float tempk;
    float tempc;
    printf("Digite uma temperatura em Kelvin:");
    scanf("%f",&tempk);

    tempc = tempk - 273.15;

    printf("A temperatura digitada em Celsius eh:%f",tempc);

    return 0;


}