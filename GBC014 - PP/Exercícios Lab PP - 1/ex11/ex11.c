#include <stdio.h>

int main(){
    float velms;
    float velkmh;

    printf("Digite uma velocidade em m/s:");
    scanf("%f",&velms);

    velkmh = velms*3.6;

    printf("Essa velocidade em km/h eh:%f",velkmh);

    return 0;



}