#include <stdio.h>

int fatorial (int num1,int resultado);

int main(){

    int num1,contador,resultado,fator;
    printf("Digite um numero inteiro positivo:");
    scanf(" %d",&num1);

   printf("O fatorial desse numero sera: %d",fatorial(num1,resultado));

   return 0;


}
int fatorial (int num1,int resultado){
    resultado = 1;
    while(num1>=1){
        resultado = resultado*num1;
        num1 = num1-1;
    }
    return resultado;
}