#include <stdio.h>

int main(){

    int menu;
    float valor1,valor2,resultado;
    

    printf("Escolha uma das quatro operacoes que podem ser feitas:\n1.Multiplicacao\n2.Divisao\n3.Soma\n4.Subtracao\n");
    scanf("%d",&menu);

    switch(menu){
        case 1:
        printf("Digite o primeiro numero da multiplicacao:");
        scanf("%f",&valor1);
        printf("Digite o segundo numero da multiplicacao:");
        scanf("%f",&valor2);

        resultado = valor1 * valor2;
        printf("O resultado da multiplicacao eh:%0.2f",resultado);
        break;

        case 2:
        printf("Digite o primeiro numero da divisao:");
        scanf("%f",&valor1);
        printf("Digite o segundo numero da divisao:");
        scanf("%f",&valor2);

        resultado = valor1 / valor2;
        printf("O resultado da divisao eh:%0.2f",resultado);
        break;

        case 3:
        printf("Digite o primeiro numero da soma:");
        scanf("%f",&valor1);
        printf("Digite o segundo numero da soma:");
        scanf("%f",&valor2);

        resultado = valor1 + valor2;
        printf("O resultado da soma eh:%0.2f",resultado);
        break;

        case 4:
        printf("Digite o primeiro numero da subtracao:");
        scanf("%f",&valor1);
        printf("Digite o segundo numero da subtracao:");
        scanf("%f",&valor2);

        resultado = valor1 - valor2;
        printf("O resultado da subtracao eh:%0.2f",resultado);
        break;

        default :
        printf("Selecione uma das opcoes, por favor.");
        break;

    }
    return 0;
}