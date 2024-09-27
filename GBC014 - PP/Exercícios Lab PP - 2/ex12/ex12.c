#include <stdio.h>
#include <math.h>

int main(){

    int num1;
    float lognum1;

    printf("Digite um numero inteiro positivo:");
    scanf("%d",&num1);

    if(num1 < 0){
        printf("Numero invalido!");
    } else {
        lognum1 = log10(num1);
        printf("O logaritmo desse numero na base 10 eh aproximadamente:%0.2f",lognum1);
    }
    return 0;
}