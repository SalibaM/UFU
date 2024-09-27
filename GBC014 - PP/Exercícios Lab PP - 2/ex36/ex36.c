#include <stdio.h>

int main(){

    float valor,valorf,comissao,porc1,porc2;

    printf("Digite o valor da venda mensal:");
    scanf("%f",&valor);

    porc1 = 0.14*valor;
    porc2 = 0.16*valor;


    if(valor >= 100000){
        comissao = 700 + porc2;
        printf("A comissao do vendedor sera de: %0.2f",comissao);
    } else {
        if((valor < 100000) && (valor>=80000)){
            comissao = 650 + porc1;
            printf("A comissao do vendedor sera de: %0.2f",comissao);
        } else {
            if((valor<80000) && (valor>=60000)) {
                comissao = 550 + porc1;
                printf("A comissao do vendedor sera de: %0.2f",comissao);
            } else {
                if((valor<60000) && (valor>=40000)) {
                    comissao = 600 + porc1;
                    printf("A comissao do vendedor sera de: %0.2f",comissao);
                } else {
                    if((valor<40000) && (valor>=20000)) {
                        comissao = 500 + porc1;
                        printf("A comissao do vendedor sera de: %0.2f",comissao);
                    } else {
                        if((valor<20000)) {
                            comissao = 400 + porc1;
                            printf("A comissao do vendedor sera de: %0.2f",comissao);
                        }
                    }
                }
            }
        }
    }
    return 0;

}