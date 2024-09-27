#include <stdio.h>
#include <stdlib.h>

int main(){

    float numsdig,num,soma=0,media=0;

    numsdig = 0;
    num = 0;

    while(numsdig<10){
        printf("Digite um numero:\n");
        scanf("%f",&num);
        numsdig++;
        if(num>=0){
        soma = soma + num;
    } else {
        soma = soma;
        numsdig--;
    }
    }
    media = soma/numsdig;
    printf("A media desses numeros eh:%.2f",media);

    return 0;
}