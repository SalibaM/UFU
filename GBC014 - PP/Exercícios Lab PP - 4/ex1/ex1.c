#include <stdio.h>
#include <stdlib.h>
int dobro(int x);

int main(){
    int x;
    int d;
    printf("Digite um numero inteiro:");
    scanf("%d",&x);
    d = dobro(x);
    printf("O dobro desse numero eh:%d",d);


    return 0;
}
int dobro (int x){
    int d;
    d = x*x;
    return d;
}