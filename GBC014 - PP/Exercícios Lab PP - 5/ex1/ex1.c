#include <stdio.h>

int main(){

    int vet[6] = {1,0,5,-2,-5,7};
    int somavet,i;

    somavet = vet[0]+vet[1]+vet[2]+vet[3]+vet[4]+vet[5];
    printf("%d\n",somavet);

    vet[3] = 100;

    for(i=0; i<6 ;i++){
        printf("%d,",vet[i]);
    }
   

    return 0;





    
}