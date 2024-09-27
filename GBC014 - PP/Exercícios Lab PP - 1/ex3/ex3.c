#include <stdio.h>

int main(){
    int x;
    int y;
    int z;
    int soma;
    printf("Digite o primeiro numero inteiro:");
    scanf("%d",&x);

    printf("Digite o segundo numero inteiro:");
    scanf("%d",&y);

    printf("Digite o terceiro numero inteiro:");
    scanf("%d",&z);

    soma = x + y + z;
    printf("A soma dos tres numeros inteiros digitados eh:%d",soma);

    return 0;


}