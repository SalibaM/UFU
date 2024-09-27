#include <stdio.h>

int main(){
    float volm3;
    float vollitro;
    printf("Digite um valor de volume em metros cubicos:");
    scanf("%f",&volm3);  

    vollitro = 1000*volm3;

    printf("O valor desse volume em litros eh:%f",vollitro);

    return 0;
}