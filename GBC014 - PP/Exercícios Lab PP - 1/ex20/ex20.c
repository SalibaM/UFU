#include <stdio.h>

int main(){
    float mkg;
    float mlb;
    printf("Digite um valor de massa em quilogramas:");
    scanf("%f",&mkg);

    mlb = mkg/0.45;

    printf("O valor de massa em libras eh:%f",mlb);

    return 0;


}