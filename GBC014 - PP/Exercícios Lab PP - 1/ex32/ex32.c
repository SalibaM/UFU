#include <stdio.h>

int main(){
    int num;
    int triplonum;
    int suctriplonum;
    int dobronum;
    int antdobronum;
    int soma;

    printf("Digite um numero inteiro:");
    scanf("%d",&num);

    triplonum = num*3;
    suctriplonum = triplonum + 1;
    dobronum = num*2;
    antdobronum = dobronum - 1;
    soma = suctriplonum + antdobronum;

    printf("A soma do sucessor do triplo desse numero inteiro com o antecessor do dobro desse mesmo numero eh:%d",soma);

    return 0;


}