#include <stdio.h>

int main(){

    int num,soma;
    num = 1;
    soma = 0;

    while(num<1000){
        if(((num % 3 ==0) || (num % 5 ==0))){
            soma+=num;
        }
    num++;
    }
    printf("A soma final eh:%d",soma);
    return 0;

}