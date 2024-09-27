#include <stdio.h>

int main(){
    float cjar;
    float cmet;
    printf("Digite um valor de comprimento em jardas:");
    scanf("%f",&cjar);

    cmet = cjar*0.91;

    printf("Esse valor de comprimento em metros eh:%f",cmet);

    return 0;


}