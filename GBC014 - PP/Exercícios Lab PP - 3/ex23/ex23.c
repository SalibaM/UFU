#include <stdio.h>

int main(){

    int numlinhas,iwhile,jwhile,numero;

    iwhile = 1;
    jwhile = 1;
    numero = 1;

    printf("Digite um numero inteiro positivo:");
    scanf("%d",&numlinhas);

    while(iwhile <= numlinhas){
        jwhile = 1;
        while(jwhile <=iwhile){
            printf("%d ",numero);
            numero++;
            jwhile++;

        }
        printf("\n");
        iwhile++;
    }

    return 0;
}