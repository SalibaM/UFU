#include <stdio.h>

int main(){
    float tempc;
    float tempf;
    printf("Digite uma temperatura em graus Celsius:");
    scanf("%f",&tempc);

    tempf = tempc*(9.0/5.0) + 32;

    printf("A temperatura convertida para Fahrenheit eh:%f",tempf);

    return 0;



}