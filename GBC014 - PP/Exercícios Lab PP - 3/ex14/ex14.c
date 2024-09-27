#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    int dado1,dado2,numjogadas,i;

    printf("Digite o numero de jogadas que voce quer:");
    scanf("%d",&numjogadas);

    dado1 = 0;
    dado2 = 0;
    i = 0;

    srand(time(NULL));//procurei sobre como fazer isso e me surpreendi, ele usa a hora do computador para deixar o código mais aleatório ainda, doideiiira!

    while(i<numjogadas){
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
        printf("Lancamento numero %d: Dado 1 tem valor de %d e dado 2 tem valor de %d.\n",i+1,dado1,dado2);

        i++;
        }
    
    if(dado1>dado2){
        printf("O valor do dado 1 eh maior que o valor do dado 2.");
    } else{
        if(dado2>dado1){
            printf("O valor do dado 2 eh maior que o valor do dado 1.");
        } else{
            printf("Os valores dos dados são iguais.");
        }
    }


      return 0;
    }








    