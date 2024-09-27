#include <stdio.h>
#include <string.h>
#include <math.h>

struct vetor{
    float a;
    float b;
    float c;

};

int main(){

    struct vetor a,b;

    printf("Digite os pontos do vetor 1:\n");
    scanf("%f%f%f",&a.a,&a.b,&a.c);

    printf("Digite os pontos do vetor 2:\n");
    scanf("%f%f%f",&b.a,&b.b,&b.c);

    printf("O vetor resultante sera: (%.2f,%.2f,%.2f)",a.a+b.a, a.b+b.b, a.c+b.c);

    return 0;
}