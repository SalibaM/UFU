#include <stdio.h>

int main(){
    float velkmh;
    float velms;

    printf("Digite uma velocidade em km/h:");
    scanf("%f",&velkmh);

    velms = velkmh/3.6;
    printf("Essa velocidade em m/s eh %f",velms);

    return 0;


}