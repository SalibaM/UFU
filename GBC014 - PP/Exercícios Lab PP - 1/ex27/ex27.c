#include <stdio.h>

int main(){
    float ahec;
    float am2;
    printf("Digite um valor de area em hectares:");
    scanf("%f",&ahec);

    am2 = ahec*10000;

    printf("O valor da area em metros quadrados eh:%f",am2);

    return 0;


}