#include <stdio.h>

int main(){
    float valor1ap;
    float valor2ap;
    float valor3ap;
    float valorpre;
    float valortotalinvest;
    float porc1ap;
    float porc2ap;
    float porc3ap;
    float valorfinalap1;
    float valorfinalap2;
    float valorfinalap3;

    printf("Digite o valor do premio:");
    scanf("%f",&valorpre);

    printf("Digite o valor investido pelo primeiro apostador:");
    scanf("%f",&valor1ap);

    printf("Digite o valor investido pelo segundo apostador:");
    scanf("%f",&valor2ap);

    printf("Digite o valor investido pelo terceiro apostador:");
    scanf("%f",&valor3ap);

    valortotalinvest = valor1ap + valor2ap + valor3ap;
    
    porc1ap = valor1ap/valortotalinvest;
    porc2ap = valor2ap/valortotalinvest;
    porc3ap = valor3ap/valortotalinvest;

    valorfinalap1 = porc1ap * valorpre;
    valorfinalap2 = porc2ap * valorpre;
    valorfinalap3 = porc3ap * valorpre;

    printf("O valor que os apostadores ganharao,respectivamente,sao os seguintes:%f,%f,%f",valorfinalap1,valorfinalap2,valorfinalap3);

    return 0;

    

}