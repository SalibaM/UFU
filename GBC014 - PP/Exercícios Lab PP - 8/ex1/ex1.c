#include <stdio.h>
#include <stdlib.h>

int main(){

    float array[10]={0,1,2,3,4,5,6,7,8,9};
    float *pos;
    int i;

    pos = &array[0];

    for(i=0;i<10;i++){
        pos = &array[i];
        printf("O endereco da posicao %d do vetor sera %p\n",i,pos);
    }

    return 0;

}