#include <stdio.h>
#define pi 3.141592

int main(){
    int altura;
    int raio;
    int qraio;
    int vol;

    printf("Digite a altura do cilindro:");
    scanf("%d",&altura);

    printf("Digite o raio do cilindro:");
    scanf("%d",&raio);

    qraio = raio*raio;
    vol = pi*qraio*altura;

    printf("O volume desse cilindro eh:%d",vol);

    return 0;



}