#include <stdio.h>

int main(){

    int resp1,resp2,resp3,resp4,resp5;

    printf("Qual eh a soma de 55+45? ");
    scanf("%d",&resp1);
    if(resp1==100){
        printf("Certo!\n");
    } else{
        printf("Errado! O valor correto era 100 :(\n");
    }
    printf("Qual eh a soma de 1+2? ");
    scanf("%d",&resp2);
    if(resp2==3){
        printf("Certo!\n");
    } else{
        printf("Errado! O valor correto era 3 :(\n");
    }
    printf("Qual eh a soma de 10+20? ");
    scanf("%d",&resp3);
    if(resp3==30){
        printf("Certo!\n");
    } else {
        printf("Errado! O valor correto era 30 :(\n");
    }
    printf("Qual eh a soma de 44+7? ");
    scanf("%d",&resp4);
    if(resp4==51){
        printf("Certo!\n");
    } else {
        printf("Errado! O valor correto era 51 :(\n");
    }
    printf("Qual eh a soma de 70+7? ");
    scanf("%d",&resp5);
    if(resp5==77){
        printf("Certo!\n");
    } else{
        printf("Errado! O valor correto era 77 :(\n");
    }
    return 0;
    //fiz o código imaginando uma prova fixa com valores aleatórios escolhidos por mim,
    //não soube qual interpretação do exercício era a certa, perdão se estiver errado :(
}   