#include <stdio.h>
#include <stdlib.h>

int main(){

    int numsdig,num,soma=0;

    numsdig = 0;
    num = 0;

    while(numsdig<10){
        printf("Digite um numero:\n");
        scanf("%d",&num);
        soma = soma + num;
        numsdig++;
    }
    printf("A soma desses numeros eh:%d",soma);

    return 0;
}