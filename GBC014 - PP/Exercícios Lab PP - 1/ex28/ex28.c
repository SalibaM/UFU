#include <stdio.h>

int main(){
    float n1;
    float n2;
    float n3;
    float q1;
    float q2;
    float q3;
    float soma;
    printf("Digite o primeiro numero:");
    scanf("%f",&n1);

    printf("Digite o segundo numero:");
    scanf("%f",&n2);

    printf("Digite o terceiro numero:");
    scanf("%f",&n3);

    q1 = n1*n1;
    q2 = n2*n2;
    q3 = n3*n3;

    soma = q1 + q2 + q3;

    printf("A soma dos quadrados dos tres numeros inseridos eh:%f",soma);

    return 0;


}