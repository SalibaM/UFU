#include <stdio.h>

int main(){
    float aacre;
    float am2;
    printf("Digite um valor de area em acres:");
    scanf("%f",&aacre);

    am2 = aacre*4048.58;

    printf("Esse valor de area em metros quadrados eh:%f",am2);

    return 0;


}