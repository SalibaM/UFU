#include <stdio.h>

int main(){
    float tempf;
    float tempc;
    printf("Digite uma temperatura em Fahrenheit:");
    scanf("%f",&tempf);

    tempc = 5.0*(tempf - 32.0)/9.0;
    printf("A temperatura em Celsius eh:%f",tempc);
    
    return 0;



}