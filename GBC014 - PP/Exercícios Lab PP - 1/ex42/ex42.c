#include <stdio.h>

int main(){
    float valorsal;
    float valorgrat;
    float valorimposto;
    float valorfinal;

    printf("Digite o salario-base do funcionario:");
    scanf("%f",&valorsal);

    valorgrat = 0.05*valorsal;
    valorimposto = 0.07*valorsal;
    valorfinal = valorsal + valorgrat - valorimposto;

    printf("O valor a ser pago ao funcionario com gratificacao e impostos inseridos eh:%f",valorfinal);

    return 0;

}
