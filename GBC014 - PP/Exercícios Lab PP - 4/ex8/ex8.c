#include <stdio.h>
#include <math.h>
float hipotenusa(float a,float b,float hip,float somacat);

int main(){
    float a,b,hip,somacat;
    printf("Digite o valor dos catetos a e b, respectivamente:\n");
    scanf("%f%f",&a,&b);

    printf("O valor da hipotenusa desse triangulo eh %.2f",hipotenusa(a,b,hip,somacat));
    return 0;
}
float hipotenusa (float a,float b,float hip,float somacat){
    somacat = (a*a)+(b*b);
    hip = sqrt(somacat);
    return hip;
}