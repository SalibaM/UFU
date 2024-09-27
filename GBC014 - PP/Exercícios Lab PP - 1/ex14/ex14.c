#include <stdio.h>
#define pi 3.141592

int main(){
    float angg;
    float angr;
    printf("Digite um angulo em graus:");
    scanf("%f",&angg);

    angr = angg*pi/180;
    printf("Esse angulo em radianos eh:%f",angr);

    return 0;

}