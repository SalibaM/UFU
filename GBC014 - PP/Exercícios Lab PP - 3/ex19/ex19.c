#include <stdio.h>

int main(){

    int saque, nota100,nota50,nota20,nota2,nota1;

    printf("Digite o valor do saque:");
    scanf("%d",&saque);
    nota100 = 0;
    nota50 = 0;
    nota20 = 0;
    nota2 = 0;
    nota1 = 0;

    while(saque>0){

    nota100 = saque/100;
    saque = saque % 100;

    nota50 = saque/50;
    saque = saque % 50;

    nota20 = saque/20;
    saque = saque % 20;

    nota2 = saque/2;
    saque = saque % 2;

    nota1 = saque/1;
    saque = saque % 1;
    
    }
    printf("A quantidade de notas utilizadas, em ordem, será: %d de 100, %d de 50, %d de 20, %d de 2 e %d de 1.\n",nota100,nota50,nota20,nota2,nota1);
    return 0;
}