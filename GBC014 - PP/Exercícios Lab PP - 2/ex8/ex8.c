#include <stdio.h>

int main(){

    float nota1;
    float nota2;
    float media;
    float soma;

    printf("Digite a primeira nota valida:");
    scanf("%f",&nota1);

    printf("Digite a segunda nota valida:");
    scanf("%f",&nota2);

    if((nota1 < 0.0) || (nota1 > 10.0)){
        printf("Numeros invalidos...");

    }
        else{
            if((nota2 < 0.0) || (nota2 > 10.0)){
                printf("Numeros invalidos...");
            } else{
                soma = nota1 + nota2;
                media = soma/2;
                printf("A media dessas duas notas eh:%0.2f",media);

            }

        }
        return 0;
}