#include <stdio.h>

int primo(int num);
int quantidadeprimos(int num,int contador,int contadorqnt);

int main(){
    int num,contador,contadorqnt;

    printf("Digite um numero:\n");
    scanf("%d",&num);

    printf("A quantidade de numeros primos antes desse numero sera: %d",quantidadeprimos(num,contador,contadorqnt));

    

    return 0;
    
}
int primo(int num) {
    int contador;
    if (num <= 1) {
        return 0;
    }
    for (contador = 2; contador <= num/2; contador++) {
        if (num % contador == 0) {
            return 0;
        }
    }

    return 1;
}
int quantidadeprimos(int num,int contador,int contadorqnt){
    contadorqnt = 0;
    for (contador = 2; contador < num; contador++) {
        if (primo(contador)) {
            contadorqnt++;
        }
    }

    return contadorqnt;
}
