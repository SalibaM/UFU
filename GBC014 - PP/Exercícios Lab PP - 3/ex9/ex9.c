#include <stdio.h>

int main(){

    int numsimpares, num, numimparreal;

    printf("Digite o numero de numeros naturais impares que voce quer imprimir:");
    scanf("%d",&num);
    numimparreal = 1;
    numsimpares=1;


    while (numsimpares <= num){
        printf("%d\n",numimparreal);
        numimparreal +=2;
        numsimpares++;

    }

  
  return 0;
}