#include <stdio.h>

int main(){
    float lado;
    float area;

    printf("Digite o valor do lado de um quadrado:");
    scanf("%f",&lado);

    area = lado*lado;

    printf("A area desse quadrado eh:%f",area);

    return 0;


}