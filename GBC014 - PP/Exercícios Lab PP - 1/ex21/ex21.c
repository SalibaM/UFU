#include <stdio.h>

int main(){
    float mlb;
    float mkg;
    printf("Digite um valor de massa em libras:");
    scanf("%f",&mlb);

    mkg = mlb*0.45;

    printf("Esse valor de massa em quilogramas eh:%f",mkg);

    return 0;


}