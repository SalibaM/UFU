#include <stdio.h>

int main(){

    int numstotal,num,num2;

    printf("Digite um numero inteiro positivo:");
    scanf("%d",&num);
    numstotal = 0;
    num2 = 1;

    while(numstotal < num){
        printf("%d ",num2);
        num2++;
        numstotal++;

    }

return 0;
}