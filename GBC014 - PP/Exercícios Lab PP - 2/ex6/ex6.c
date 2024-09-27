#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int x;
    int y;
    int dif1;
    int dif2;
    printf("Digite um numero inteiro:");
    scanf("%d",&x);
    printf("Digite outro numero inteiro:");
    scanf("%d",&y);

    if(x>y){
       dif1 = x-y;
       printf("O numero %0.1d eh maior que %0.1d, e a diferenca entre eles eh %0.1d",x,y,dif1);
    }else{
        if(y>x){
           dif2 = y-x;
           printf("O numero %0.1d eh maior que %0.1d, e a diferenca entre eles eh %0.1d",y,x,dif2);
        }else{
            printf("Os numeros sao iguais e nao possuem diferenca;.");
        }
    }
    return 0;
}