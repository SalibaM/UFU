#include <stdio.h>
#include <stdlib.h>

int main(){

    float num1,num2,resultado;
    char operador;

    printf("Digite o primeiro valor:\n");
    scanf("%f",&num1);

    printf("Digite o segundo valor:\n");
    scanf("%f",&num2);

    printf("Digite a operacao que voce quer (+,-,* ou /):\n");
    scanf(" %c",&operador);

    switch(operador){

    case '+':
        resultado = num1+num2;
        printf("%.2f",resultado);
        break;

    case '-':
        resultado = num1-num2;
        printf("%.2f",resultado);
        break;

    case '*':
        resultado = num1*num2;
        printf("%.2f",resultado);
        break;

    case '/':
        if(num2==0){
            printf("Nao pode dividir por zero!\n");
            break;
        }
        resultado = num1/num2;
        printf("%.2f",resultado);
        break;
    default:
        printf("Opcao invalida!\n");

    }
    return 0;
}
