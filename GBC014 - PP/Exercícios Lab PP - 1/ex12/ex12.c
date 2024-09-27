#include <stdio.h>

int main(){
    float dmilhas;
    float dkm;
    
    printf("Digite uma distancia em milhas:");
    scanf("%f",&dmilhas);

    dkm = dmilhas*1.61;
    printf("Essa distancia em quilometros eh:%f",dkm);

    return 0;



}