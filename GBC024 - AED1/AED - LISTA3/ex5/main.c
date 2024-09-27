#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculaHexagono(float lado,float *perimetro,float *area){

    *perimetro = 6*lado;
    *area = 6 * ((lado*lado*sqrt(3))/4);

}

int main(){

    float lado=0,perimetro,area;

    printf("Digite o valor do lado do seu hexagono regular:\n");
    scanf("%f",&lado);

    calculaHexagono(lado,&perimetro,&area);
    printf("\n");

    printf("O valor do perimetro sera de: %.2f metros.\n",perimetro);
    printf("A area sera igual a aproxidamente: %.2f metros quadrados.\n",area);


    return 0;
}
