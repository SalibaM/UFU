#include <stdio.h>
#include <math.h>

int main(){

    int valor,quadrado,cubo,raiz;
    valor = 1;

    while(1){
        printf("Digite um valor positivo se quiser determinar seu quadrado, cubo e raiz.\nSe quiser finalizar, digite zero ou qualquer numero negativo :");
        scanf("%d",&valor);

        if(valor<=0){
            printf("Programa finalizado!");
            break;
        } else{
        quadrado = valor*valor;
        cubo = valor*valor*valor;
        raiz = sqrt(valor);

        printf("O quadrado, cubo e raiz desse numero sao, respectivamente: %d ,%d ,%d\n\n",quadrado,cubo,raiz);
        
        }
    }


    return 0;
}