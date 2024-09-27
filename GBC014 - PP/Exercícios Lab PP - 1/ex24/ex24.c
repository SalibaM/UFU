#include <stdio.h>

int main(){
    float am2;
    float aacre;
    printf("Digite um valor de area em metros quadrados:");
    scanf("%f",&am2);

    aacre = am2*0.000247;

    printf("O valor de area em acres eh:%f",aacre);

    return 0;


}