#include <stdio.h>

int main(){

    float basemaior,basemenor,altura,somabases,areatrap;

    printf("Digite o valor da base maior:");
    scanf("%f",&basemaior);

    printf("Digite o valor da base menor:");
    scanf("%f",&basemenor);

    printf("Digite o valor da altura:");
    scanf("%f",&altura);

    if(basemaior <= 0){
        printf("A base maior deve ser maior que zero.");

    } else {
        if(basemenor <= 0){
            printf("A base menor deve ser maior que zero.");
        } else{
            somabases = basemaior + basemenor;
            areatrap = (somabases * altura) / 2;
            printf("A area desse trapezio eh:%0.2f",areatrap);

            }

        }

    
        return 0;
}

