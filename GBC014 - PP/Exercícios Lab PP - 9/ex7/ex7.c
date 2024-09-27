#include <stdio.h>

void verificar (int array[10],int *maiorvalor,int *qntdvezes,int n){
    int i;
    *maiorvalor=0;
    *qntdvezes=0;

    for(i=0;i<n;i++){
        if(array[i]>*maiorvalor){
            *maiorvalor=array[i];
        }
    }

    for(i=0;i<10;i++){
        if(array[i]==*maiorvalor){
            (*qntdvezes)++;
        }
    }
}

int main(){

    int array[10];
    int maiorvalor=0,qntdvezes=0,i;

    printf("Digite os valores do seu array de 10 posicoes:\n");
    for(i=0;i<10;i++){
        scanf("%d",&array[i]);
    }

    verificar(array,&maiorvalor,&qntdvezes,10);

    printf("O maior valor da sua array sera:%d\n",maiorvalor);
    printf("Ele aparece %d vez/vezes na sua array.",qntdvezes);

    return 0;


}