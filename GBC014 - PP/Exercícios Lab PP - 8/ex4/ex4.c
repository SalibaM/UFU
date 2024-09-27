#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[5];
    int *pos;
    int i,valordobro;

    pos = &array[0];

    printf("Digite os valores do vetor de 5 posicoes:\n");
    for(i=0;i<5;i++){
        pos = &array[i];
        scanf("%d",pos);
    }

    for(i=0;i<5;i++){
        pos = &array[i];
        if(*pos%2==0){
            printf("O valor %d na posicao %d eh par e tem endereco %p.\n",*pos,i+1,pos);
        }
    }
    return 0;
}