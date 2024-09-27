#include <stdio.h>

int main(){
    int numlido;
    int restod1;
    int valord1;
    int restod2;
    int valord2;
    int restod3;
    int valord3;

    printf("Digite um numero inteiro positivo de 4 digitos(de 1000 a 9999):");
    scanf("%d",&numlido);

    restod1 = numlido % 10;
    valord1 = numlido / 10;
    restod2 = valord1 % 10;
    valord2 = valord1 / 10;
    restod3 = valord2 % 10;
    valord3 = valord2 / 10;

    printf("Os digitos singulares desse numero inteiro sao:%d e %d e %d e %d",valord3,restod3,restod2,restod1);

    return 0;

}