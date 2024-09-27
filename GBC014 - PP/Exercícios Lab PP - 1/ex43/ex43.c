#include <stdio.h>

int main(){
    float valort;
    float valordes;
    float valortdes;
    float valorpar;
    float valorcomv;
    float valorcomp;

    printf("Digite o valor total do produto:");
    scanf("%f",&valort);

    valordes = 0.10*valort;
    valortdes = valort - valordes;
    valorpar = valort/3;
    valorcomv = 0.05*valortdes;
    valorcomp = 0.05*valort;

    printf("O total a pagar com desconto de 10 por cento eh:%f\n",valortdes);
    printf("O valor de cada parcela, sendo o parcelamento de 3x sem juros eh:%f\n",valorpar);
    printf("O valor da comissao do vendedor com a venda a vista eh:%f\n",valorcomv);
    printf("O valor de comissao do vendedor com a venda sendo parcelada eh:%f\n",valorcomp);

    return 0;

}