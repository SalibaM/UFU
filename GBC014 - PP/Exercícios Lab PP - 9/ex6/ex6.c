#include <stdio.h>
#include <stdlib.h>

void calculoesfera (float raio,float *area,float *volume){

    *area = 4*raio*raio*3.14;
    *volume= (4/3)*raio*raio*raio*3.14;

}


int main(){

    float raio,area=0,volume=0;

    printf("Digite o valor do raio da superficie da esfera:\n");
    scanf("%f",&raio);

    calculoesfera(raio,&area,&volume);

    printf("Area:%.3f\n",area);
    printf("Volume:%.3f\n",volume);

    return 0;

}