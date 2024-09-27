#include <stdio.h>

int main(){

    int dia;
    printf("Digite um numero de 1 a 7:");
    scanf("%d",&dia);

    switch(dia){
        case 1 :
    printf("O dia eh domingo!");
    break;
        case 2 :
    printf("O dia eh segunda-feira!");
    break;
        case 3 :
    printf("O dia eh terca-feira!");
    break;
        case 4 :
    printf("O dia eh quarta-feira!");
    break;
       case 5 :
    printf("O dia eh quinta-feira!");
    break;
       case 6 :
    printf("O dia eh sexta-feira!");
    break;
       case 7 :
    printf("O dia eh sabado!");
    break;
        default :
    printf("O numero nao esta entre 0 e 7.");
    }

    return 0;
}