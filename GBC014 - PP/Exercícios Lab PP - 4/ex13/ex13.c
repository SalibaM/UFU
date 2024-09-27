#include <stdio.h>

float operacao(int num1, int num2, int resultado, char simbolo);

int main(){

    float num1,num2,resultado;
    char simbolo;

    printf("Digite dois valores numericos:\n");
    scanf("%f%f",&num1,&num2);

    printf("Digite um simbolo (+,-,* ou /):\n");
    scanf(" %c",&simbolo);

    printf("O resultado dessa operacao sera %.2f",operacao(num1,num2,resultado,simbolo));

    return 0;

}
float operacao (int num1,int num2,int resultado,char simbolo){
    switch(simbolo){
        case ('+'):
        resultado = num1 + num2;
        return resultado;
        break;

        case('-'):
        resultado = num1 - num2;
        return resultado;
        break;

        case('*'):
        resultado = num1 * num2;
        return resultado;
        break;

        case('/'):
        resultado = num1/num2;
        return resultado;
        break;

        default:
        printf("Simbolo invalido :(");
        break;
    }
}
