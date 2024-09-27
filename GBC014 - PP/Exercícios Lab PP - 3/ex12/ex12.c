#include <stdio.h>

int main(){

    int divisor,num,soma;

    printf("Digite um numero inteiro:");
    scanf("%d",&num);

    divisor = 1;
    soma = 0;

    while (divisor < num){
        if (num % divisor == 0){
            soma += divisor;
        }
    divisor ++;

    }

    printf("A soma dos divisores eh %d",soma);

  return 0;
}