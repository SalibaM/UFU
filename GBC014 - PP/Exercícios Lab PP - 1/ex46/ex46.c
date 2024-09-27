#include <stdio.h>

int main(){
    int numlido;
    int restod1;
    int valord1;
    int restod2;
    int valord2;

    printf("Digite um numero inteiro positivo de tres digitos(de 100 a 999):");
    scanf("%d",&numlido);

    restod1 = numlido % 10;
    valord1 = numlido / 10;
    restod2 = valord1 % 10;
    valord2 = valord1 / 10;
    //só consegui por vc ter falado na sala, Claudiney kkk
    printf("Esse numero inteiro positivo escrito com os digitos invertidos eh:%d%d%d",restod1,restod2,valord2);

    return 0;

    

}