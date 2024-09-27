#include <stdio.h>

int soman2maiorn1 (int num1,int num2,int soma);
int soman1maiorn2 (int num1, int num2, int soma);

int main(){

    int num1,num2,soma;

    printf("Digite os dois numeros inteiros:");
    scanf("%d%d",&num1,&num2);

    if(num2==num1){
        printf("Nao existem numeros entre esses dois.Eles sao iguais.");
    } else {
        if(num2>num1){
            soma = soman2maiorn1(num1,num2,soma);
            printf("A soma dos numeros entre esses dois numeros sera %d",soma);
        } else {
            if(num1>num2){
                soma = soman1maiorn2(num1,num2,soma);
                printf("A soma dos numeros entre esses dois numeros sera %d",soma);
            }
        }
    }


    return 0;
}
int soman2maiorn1 (int num1,int num2,int soma){
    soma=0;
    while(num2 != (num1 + 1)){
        num2=num2-1;
        soma=soma+num2;
    }
    return soma;   
}
int soman1maiorn2 (int num1, int num2, int soma){
    soma=0;
    while(num1 != (num2+1)){
        num1=num1-1;
        soma=soma+num1;
    }
    return soma;
}

 