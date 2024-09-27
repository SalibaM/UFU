#include <stdio.h>
#include <stdlib.h>

int soma(int n){

    int i=0;
    int soma=0;

    for(i=0;i<=n;i++){
        soma = soma + i;
    }

    return soma;


}

int main(){

    printf("%d",soma(5));

    return 0;
}
