#include <stdio.h>

int main(){
    float dkm;
    float dmilhas;

    printf("Digite uma distancia em quilometros:");
    scanf("%f",&dkm);

    dmilhas = dkm/1.61;
    printf("Essa distancia em milhas eh:%f",dmilhas);

    return 0;

}