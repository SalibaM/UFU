#include <stdio.h>

int main(){

    int vet[50],i;
    for(i=0;i<50;i++){
        vet[i] = (i+5*i)%(i+1);
        printf("%d   ",vet[i]);
    }


    return 0;
}