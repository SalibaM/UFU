#include <stdio.h>
#include <stdlib.h>

int main(){

    float base=0,altura=0,area=0;

    printf("Digite a medida da base do triangulo:\n");
    scanf("%f",&base);

    if(base<0){
        printf("Digite uma medida valida para a base.\n");
        exit(1);
    }

    printf("Digite a medida da altura do triangulo:\n");
    scanf("%f",&altura);

    if(altura<0){
        printf("Digite uma medida valida para a altura.\n");
        exit(1);
    }

    area = (base*altura)/2;

    printf("A area do triangulo fornecido sera aproximadamente:%.2f metros quadrados.",area);

    return 0;


}
