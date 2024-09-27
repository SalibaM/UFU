#include <stdio.h>
#define pi 3.141592

int main(){
    float raio;
    float raioq;
    float area;

    printf("Digite o valor do raio de um circulo:");
    scanf("%f",&raio);

    raioq = raio*raio;
    area = pi*raioq;

    printf("A area do circulo correspondente eh:%f",area);

    return 0;


}