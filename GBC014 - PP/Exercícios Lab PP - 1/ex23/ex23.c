#include <stdio.h>

int main(){
    float cmet;
    float cjar;
    printf("Digite um valor de comprimento em metros:");
    scanf("%f",&cmet);

    cjar = cmet/0.91;

    printf("O valor desse comprimento em jardas eh:%f",cjar);

    return 0;

}