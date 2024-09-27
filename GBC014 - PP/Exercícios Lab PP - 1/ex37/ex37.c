#include <stdio.h>

int main(){
    float valor;
    float desconto12;
    float valorfinal;

    printf("Digite o valor do produto:");
    scanf("%f",&valor);

    desconto12 = 0.12*valor;
    valorfinal = valor - desconto12;
    
    printf("O valor do produto com desconto de 12 por cento eh:%f",valorfinal);

    return 0;

}