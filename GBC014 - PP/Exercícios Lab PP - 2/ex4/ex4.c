#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x;
    float raizx;
    float squarex;
    printf("Digite um numero positivo:");
    scanf("%f",&x);

    if(x>0){
       raizx = sqrt(x);
       squarex = x*x;
       printf("Esse numero ao quadrado eh %0.1f e sua raiz quadrada eh %0.1f.",squarex,raizx);
    }else{
        printf("Esse numero nao e positivo.");
    }
    return 0;
}