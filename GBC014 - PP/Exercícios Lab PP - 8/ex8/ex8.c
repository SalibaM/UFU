#include <stdio.h>

int main(){

    int A, *B, **C, ***D;

    printf("Digite o valor de A:\n");
    scanf("%d",&A);

    B = &A;
    C = &B;
    D = &C;

    printf("O dobro de A sera:%d\n",*B * 2);
    printf("O triplo de A sera:%d\n",**C * 3);
    printf("O quadruplo de A sera:%d\n",***D * 4);

    return 0;
    

}