#include <stdio.h>

int main(){

    int vet[10],i,j,k,numerodig;
    
    for(i=0;i<10;i++){
        printf("Digite um numero:");
        scanf("%d",&numerodig);
        for(j=0;j<10;j++){
            if(vet[j] == numerodig){
                printf("Esse numero ja foi digitado.\n");
                i--;
                break;
                //isso aqui é genial, sério.
            }
        }
        vet[i] = numerodig;
    }
    for(k=0;k<10;k++){
        printf("A posicao %d desse vetor ocupa o valor %d\n",k,vet[k]);
    }



    return 0;


}