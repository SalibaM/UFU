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

    *C = (*C*2);
    *D = (*D*2);

    printf("A soma do dobro digitado sera:%d",A+B);

    return 0;

}