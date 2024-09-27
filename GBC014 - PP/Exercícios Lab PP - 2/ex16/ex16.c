#include <stdio.h>

int main (){
    int mes;

    printf("Digite um numero de 1 a 12:");
    scanf("%d",&mes);

    switch(mes){
        case 1 :
        printf("Esse mes eh janeiro!");
        break;
        case 2 :
        printf("Esse mes eh fevereiro!");
        break;
        case 3 :
        printf("Esse mes eh março!");
        break;
        case 4 :
        printf("Esse mes eh abril!");
        break;
        case 5 :
        printf("Esse mes eh maio!");
        break;
        case 6 :
        printf("Esse mes eh junho!");
        break;
        case 7 :
        printf("Esse mes eh julho!");
        break;
        case 8 :
        printf("Esse mes eh agosto!");
        break;
        case 9 :
        printf("Esse mes eh setembro!");
        break;
        case 10 :
        printf("Esse mes eh outubro!");
        break;
        case 11 :
        printf("Esse mes eh novembro!");
        break;
        case 12 :
        printf("Esse mes eh dezembro!");
        break;
        default :
        printf("Esse numero nao esta entre 0 e 12");
        break;



    }
    return 0;
}