#include <stdio.h>

int main(){
    int numero;
    int sucessor;
    int antecessor;

    printf("Digite o numero inteiro:");
    scanf("%d",&numero);

    sucessor = numero + 1;
    antecessor = numero - 1;

    printf("O sucessor e o antecessor desse numero sao respectivamente:%d e %d",sucessor,antecessor);

    return 0;
}
