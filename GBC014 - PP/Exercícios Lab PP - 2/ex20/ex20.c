#include <stdio.h>

int main(){

    float lado1,lado2,lado3,somalados1,somalados2,somalados3;

    printf("Digite o valor do primeiro lado do triangulo:");
    scanf("%f",&lado1);

    printf("Digite o valor do segundo lado do triangulo:");
    scanf("%f",&lado2);

    printf("Digite o valor do terceiro lado do triangulo:");
    scanf("%f",&lado3);

    somalados1 = lado1 + lado2;
    somalados2 = lado1 + lado3;
    somalados3 = lado2 + lado3;

    if((lado1==lado2) && (lado2==lado3)){
        printf("Esse triangulo eh equilatero.");
    } else{
        if((lado1==lado2) || (lado1==lado3) || (lado2==lado3)){
            printf("Esse triangulo eh isosceles.");
        } else {
            if((somalados1 < lado3) || (somalados2 < lado2) || (somalados3 < lado1)){
                printf("Esse triangulo nao eh possivel de ser construido");
            } else{
                printf("Esse triangulo eh escaleno.");
            }

        }
    }
    return 0;


}