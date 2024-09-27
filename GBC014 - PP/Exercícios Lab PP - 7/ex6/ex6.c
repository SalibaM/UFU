#include <stdio.h>
#include <stdlib.h>

int main(){

    int A,B;
    int *C;
    int *D;

    printf("Digite A:\n");
    scanf("%d",&A);
    printf("Digite B:\n");
    scanf("%d",&B);

    C = &A;
    D = &B;

    printf("A soma entre esses numeros sera:%d\n",*C + *D);
    printf("A subtracao entre esses numeros sera:%d\n",*C - *D);
    printf("A multiplicacao entre esses numeros sera:%d\n",(*C * *D));
    printf("A divisao entre esses numeros sera:%d\n",(*C / *D));


    return 0;


}