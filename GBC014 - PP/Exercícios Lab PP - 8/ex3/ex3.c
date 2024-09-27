#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[5];
    int *pos;
    int i,valordobro;

    pos = &array[0];

    printf("Digite os valores do seu vetor de 5 posicoes:\n");
    for(i=0;i<5;i++){
        pos = &array[i];
        scanf("%d",pos);
    }

    for(i=0;i<5;i++){
        pos = &array[i];
        valordobro = 2*(*pos);
        printf("O dobro do valor na posicao %d sera:%d\n",i+1,valordobro);
    }
    return 0;
}