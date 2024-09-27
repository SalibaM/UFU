#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x;
    float raizx;
    printf("Digite um numero positivo:");
    scanf("%f",&x);

    if(x>0){
       raizx = sqrt(x);
       printf("A raiz quadrada desse numero eh:%0.1f",raizx);
    }else{
        printf("O numero eh invalido.");

    }
    return 0;


}