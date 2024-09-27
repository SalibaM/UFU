#include <stdio.h>

int main(){

    int array[10];
    int i;
    int *acessar,*valormax,*valormin;

    printf("Digite os 10 valores do vetor:\n");
    for(i=0;i<10;i++){
        scanf("%d",&array[i]);
    }
    
    acessar = array;
    valormax = array;

    while(acessar < array + 10){
        if(*acessar > *valormax){
            valormax = acessar;
            *valormax = *acessar;
        }
        acessar++;
    }

    acessar = array;
    valormin = array;

    while(acessar < array + 10){
        if(*acessar < *valormin){
            valormin = acessar;
            *valormin = *acessar;
        }
        acessar++;
    }
    
    
    printf("O maior valor desse vetor sera:%d\n",*valormax);
    printf("O menor valor desse vetor sera:%d\n",*valormin);

    return 0;
        

}