#include <stdio.h>

int main(){
    float valorht;
    float numh;
    float valortratotal;
    float valoradd;
    float valorfinal;

    printf("Digite o valor da hora de trabalho em reais:");
    scanf("%f",&valorht);

    printf("Digite o numero de horas trabalhadas no mes:");
    scanf("%f",&numh);

    valortratotal = numh*valorht;
    valoradd = 0.10*valortratotal;
    valorfinal = valortratotal + valoradd;

    printf("O valor a ser pago ao funcionario adicionando 10 por cento eh:%f",valorfinal);

    return 0;


}