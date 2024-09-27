#include <stdio.h>
#include <stdlib.h>

int main(){

    float matriz[3][3];
    float *pos;
    int i,j;

    pos = &matriz[0][0];

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            pos = &matriz[i][j];
            printf("O endereco da posicao (%d,%d) da matriz sera:%p\n",i,j,pos);
        }
    }

    return 0;
}