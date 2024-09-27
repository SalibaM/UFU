#include <stdio.h>

int main(){

    char produto[200];
    float valor,desconto,valorfinal;

    printf("Digite o nome do produto:\n");
    fgets(produto,200,stdin);

    printf("Digite o valor do produto:\n");
    scanf("%f",&valor);

    desconto = (valor*0.10);
    valorfinal=valor-desconto;

    printf("Os dados informados sao:\n");
    printf("Nome do produto:%s",produto);
    printf("Valor do produto:%.2f \n",valor);
    printf("Valor do desconto:%.2f \n",desconto);
    printf("Valor a ser pago a vista:%.2f",valorfinal);



    return 0;
}