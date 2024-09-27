#include <stdio.h>
#define pi 3.141592
float volume1(float altura,float raio,float volumecil);


int main(){
    float altura,raio,volumecil;

    printf("Digite o valor da altura e do raio do cilindro circular,respectivamente:\n");
    scanf("%f%f",&altura,&raio);

    printf("O valor do volume desse cilindro sera:%.2f",volume1(altura,raio,volumecil));
    return 0;
}
float volume1 (float altura,float raio,float volumecil){
    volumecil = pi*(raio*raio)*altura;
    return volumecil;
}