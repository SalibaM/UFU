#include <stdio.h>

long int somaalg (int numeroprincipal,int numeroresultante,int soma);

int main(){
    
    long int numeroprincipal,resto,numeroresultante,soma;
    printf("Digite um numero inteiro maior que zero:\n");
    scanf("%d",&numeroprincipal);

    if(numeroprincipal<0){
        printf("Numero invalido");
    } else {
        printf("A soma de todos os algarismos desse numero sera:%d",somaalg(numeroprincipal,numeroresultante,soma));
    }

    return 0;

}
long int somaalg (int numeroprincipal,int numeroresultante,int soma){
    if(numeroprincipal>0){
        soma = 0;
        while(numeroprincipal>0){
            numeroresultante = numeroprincipal%10;
            soma = soma+numeroresultante;
            numeroprincipal = numeroprincipal/10;
        }
        return soma;
   
    }

}