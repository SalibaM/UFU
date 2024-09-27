#include <stdio.h>

int main(){

    int vet[5] = {0,1,2,3,4};
    int valor,i;
    int *pont;

    printf("Digite o valor que sera preenchido dentro do vetor:\n");
    printf("!!!VALOR INTEIRO OBRIGATORIAMENTE!!!\n");
    scanf("%d",&valor);

    pont = vet;

    while(pont < vet + 5){
        *pont = valor;
        pont++;
    }

    for(i=0;i<5;i++){
        printf("O vetor na posicao %d atualizado sera:%d\n",i+1,vet[i]);
    }

    return 0;

}