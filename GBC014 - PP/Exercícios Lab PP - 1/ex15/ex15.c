#include <stdio.h>
#define pi 3.141592
int main(){
    float angr;
    float angg;

    printf("Digite um angulo em radianos:");
    scanf("%f",&angr);

    angg = angr*180/pi;

    printf("Esse angulo em graus eh:%f",angg);

    return 0;


}