#include <stdio.h>

int main(){
    float diaria;
    float diast;
    float valorl;
    float imposto;
    float valorfinal;

    printf("Digite o numero de dias trabalhados pelo encanador:");
    scanf("%f",&diast);

    diaria = 30;
    valorl = diaria*diast;
    imposto = 0.08*valorl;
    valorfinal = valorl-imposto;
    
    printf("O valor final que deve ser pago eh:%f",valorfinal);

    return 0;


}