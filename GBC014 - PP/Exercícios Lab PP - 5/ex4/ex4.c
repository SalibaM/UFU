#include <stdio.h>

int main(){

    int vet[5],i;

    printf("Digite 5 valores:\n");
    for (i=0;i<5;i++){
        scanf("%d",&vet[i]);
    }
    if(vet[0]>(vet[1]&&vet[2]&&vet[3]&&vet[4])){
        printf("O maior valor esta na posicao 0\n");
    } else {
        if(vet[1]>(vet[0]&&vet[2]&&vet[3]&&vet[4])){
        printf("O maior valor esta na posicao 1\n");  
        } else {
            if(vet[2]>(vet[0]&&vet[1]&&vet[3]&&vet[4])){
            printf("O maior valor esta na posicao 2 \n");    
            } else {
                if(vet[3]>(vet[0]&&vet[1]&&vet[2]&&vet[4])){
                printf("O maior valor esta na posicao 3\n");   
                } else {
                    if(vet[4]>(vet[0]&&vet[1]&&vet[2]&&vet[3])){
                    printf("O maior valor esta na posicao 4\n");
                        
                    }
                }
            }
        }
    }

    if(vet[0]<(vet[1]&&vet[2]&&vet[3]&&vet[4])){
        printf("O menor valor esta na posicao 0\n");
    } else {
        if(vet[1]<(vet[0]&&vet[2]&&vet[3]&&vet[4])){
        printf("O menor valor esta na posicao 1\n");  
        } else {
            if(vet[2]<(vet[0]&&vet[1]&&vet[3]&&vet[4])){
            printf("O menor valor esta na posicao 2\n ");    
            } else {
                if(vet[3]<(vet[0]&&vet[1]&&vet[2]&&vet[4])){
                printf("O menor valor esta na posicao 3\n");   
                } else {
                    if(vet[4]<(vet[0]&&vet[1]&&vet[2]&&vet[3])){
                    printf("O menor valor esta na posicao 4\n");
                        
                    }
                }
            }
        }
    }







    return 0;
}

