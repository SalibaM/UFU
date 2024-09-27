#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x;
    float y;
    printf("Digite o primeiro numero:");
    scanf ("%f",&x);
    printf("Digite o segundo numero:");
    scanf("%f",&y);

    if(x>y){
       printf("O maior numero eh %0.1f.",x);
    }else{
        if(y>x){
            printf("O maior numero eh %0.1f.",y);
        }else{
            printf("Numeros iguais.");

        }
    }
    return 0;
}