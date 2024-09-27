#include <stdio.h>

int main(){
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float soma;
    float media;

    printf("Digite a primeira nota:");
    scanf("%f",&nota1);

    printf("Digite a segunda nota:");
    scanf("%f",&nota2);

    printf("Digite a terceira nota:");
    scanf("%f",&nota3);

    printf("Digite a quarta nota:");
    scanf("%f",&nota4);

    soma = nota1 + nota2 + nota3 + nota4;

    media = soma/4;

    printf("A media aritmetica dessas quatro notas eh:%f",media);

    return 0;



}