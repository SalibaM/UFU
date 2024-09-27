#include <stdio.h>
#include <stdlib.h>

int main(){

    int num,soma=0,contagem=0;

    while(num!=10){
        printf("Digite um numero,ou digite 10 para parar:");
        scanf("%d",&num);

        if(num>10){
            soma = soma+num;
        } else {
            if(num<10){
               contagem++;

            }
        }
    }

    printf("A soma dos numeros maiores que dez foi:%d\n",soma);
    printf("Voce digitou %d numeros menores que dez.\n",contagem);


    return 0;
}
