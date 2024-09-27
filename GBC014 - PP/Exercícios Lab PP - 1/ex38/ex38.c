#include <stdio.h>

int main(){
    float sal;
    float aumento;
    float salfinal;

    printf("Digite o salario de um funcionario:");
    scanf("%f",&sal);

    aumento = 0.25*sal;
    salfinal = sal + aumento;

    printf("O novo salario do funcionario com aumento de 25 por cento eh:%f",salfinal);

    return 0;


}