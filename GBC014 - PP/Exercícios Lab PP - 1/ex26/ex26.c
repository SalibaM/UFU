#include <stdio.h>

int main(){
    float am2;
    float ahec;
    printf("Digite um valor de area em metros quadrados:");
    scanf("%f",&am2);

    ahec = am2*0.0001;

    printf("O valor de area em hectares eh:%f",ahec);

    return 0;

}