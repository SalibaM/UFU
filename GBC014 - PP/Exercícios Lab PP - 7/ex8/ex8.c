#include <stdio.h>

int main(){

    int vet[6];
    int i,*a,*b,*c,*d,*e,*f;

    for(i=0;i<6;i++){
        printf("Digite o numero da posicao do vetor:\n");
        scanf("%d",&vet[i]);
    }

    a = &vet[0];
    b = &vet[1];
    c = &vet[2];
    d = &vet[3];
    e = &vet[4];
    f = &vet[5];

    printf("Esse vetor possui os numeros: (%d,%d,%d,%d,%d,%d)\n",*a,*b,*c,*d,*e,*f);
    printf("Os enderecos de memoria de cada numero, respectivamente, serao: %p, %p, %p, %p, %p, %p.",a,b,c,d,e,f);







}