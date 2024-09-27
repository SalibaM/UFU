#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    float y;
    printf("Digite um numero:");
    scanf("%f",&x);

    printf("Digite outro numero:");
    scanf("%f",&y);

    if(x>y){
        printf("O maior dos numeros digitados eh:%f",x);
    }
    else{
        if(y>x){
            printf("O maior dos numeros digitados eh:%f",y);
        }
        else{
            printf("Os numeros possuem o mesmo valor.");
        }
    }

    return 0;
}