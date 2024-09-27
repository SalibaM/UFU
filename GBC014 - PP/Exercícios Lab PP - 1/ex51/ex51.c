#include <stdio.h>
#include <math.h>

int main(){
    float coordx;
    float quadx;
    float coordy;
    float quady;
    float somaquad;
    float distori;

    printf("Digite o valor da coordenada x:");
    scanf("%f",&coordx);

    printf("Digite o valor da coordenada y:");
    scanf("%f",&coordy);

    quadx = coordx * coordx;
    quady = coordy * coordy;
    somaquad = quadx + quady;
    distori = sqrt(somaquad);

    printf("O valor da distancia desse ponto ate a origem eh:%f", distori);

    return 0;

}