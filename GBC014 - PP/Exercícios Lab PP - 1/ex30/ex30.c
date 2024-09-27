#include <stdio.h>

int main(){
    float real;
    float cotacao;
    float dolar;

    printf("Digite o valor em real:");
    scanf("%f",&real);
    
    printf("Digite a atual cotacao do dolar:");
    scanf("%f",&cotacao);

    dolar = real/cotacao;

    printf("O valor digitado, agora em dolares, eh:%f",dolar);

    return 0;


}