#include <stdio.h>

int main(){

    int ano,div1,div2,div3;

    printf("Digite o ano que sera verificado:");
    scanf("%d",&ano);

    div1 = ano % 400;
    div2 = ano % 4;
    div3 = ano % 100;

    if(div1 == 0){
        printf("Esse ano eh bissexto.");
    } else {
        if ((div2 == 0) && (div3) != 0){
            printf("Esse ano eh bissexto.");

        } else {
            printf("Esse ano nao eh bissexto.");
        }

    }
    return 0;
}