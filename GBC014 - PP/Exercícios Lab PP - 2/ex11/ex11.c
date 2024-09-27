#include <stdio.h>

int main(){

    int num,resto1,resto2,resto3,alg1,alg2,alg3,soma;

    printf("Digite um numero inteiro de ate 4 algarismos:");
    scanf("%d",&num);

    if(num < 0){
        printf("Numero invalido.");
    } else {
        resto1 = num/10;
        alg1 = num % 10;
        
        resto2 = resto1/10;
        alg2 = resto1 % 10;
        
        resto3 = resto2/10;
        alg3 = resto2 % 10;
        //resto 3 acaba se tornando o primeiro último algarismo que coletamos

        soma = resto3+ alg3 + alg2 + alg1;
        printf("A soma de todos os algarismos desse numero eh:%d",soma);

    }
    return 0;
}