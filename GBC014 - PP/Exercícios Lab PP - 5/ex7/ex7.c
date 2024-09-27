#include <stdio.h>

int main(){

    int vet[6],i,j,par,soma=0,impar,qntdimpar=0;
    printf("Digite 6 numeros inteiros:\n");

    for(i=0;i<6;i++){
    scanf("%d",&vet[i]);
    }

    for(i=0;i<6;i++){
        if(vet[i]<=0){
            par = 0;
        } else {
            if((vet[i]%2) != 0){
                par = 0;
            } else {
                if((vet[i]%2) == 0){
                    par = 1;
                }
            }
            
        }
        if(par){
            soma = soma+vet[i];
            printf("\nO numero %d eh par!\n\n",vet[i]);
        }

    }
    printf("A soma dos numeros pares sera %d!\n\n",soma);


    for(i=0;i<6;i++){
        if(vet[i]<=0){
            return 0;
        } else {
            if((vet[i]%2) == 0){
                impar = 0;
            } else {
                impar = 1;
                qntdimpar++;
            }
        }
        if(impar){
            printf("O numero %d eh impar!\n\n",vet[i]);
        }
    }

    printf("Foram digitados %d numeros impares!",qntdimpar);




return 0;
}