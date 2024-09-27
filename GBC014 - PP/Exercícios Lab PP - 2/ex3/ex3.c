#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x;
    float raizx;
    float squarex;
    printf("Digite um numero real:");
    scanf("%f",&x);

    if(x>0){
       raizx = sqrt(x);
       printf("A raiz quadrada desse numero eh:%0.1f",raizx);
    }else{
        squarex = x*x;
        printf("O quadrado desse numero eh:%0.1f",squarex);
    }

    return 0;

}
