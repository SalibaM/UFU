#include <stdio.h>

int main(){

    float num,menornum,maiornum;
    int numsdig;

    num=0;
    numsdig=0;
    menornum=0;
    maiornum=0;

    while(numsdig<10){
        printf("Digite um numero:");
        scanf("%f",&num);
        numsdig++;

        if(num < menornum){
            menornum = num;

        }

        if(num > maiornum){
            maiornum = num;
        }

    }
    printf("O maior numero digitado foi:%.2f\n",maiornum);
    printf("O menor numero digitado foi:%.2f",menornum);


   return 0;

}