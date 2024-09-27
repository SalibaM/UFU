#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int i,n,n2;
    int op;
    int *p;
    
    printf("Digite quantos bytes do tipo inteiro voce quer:\n");
    scanf("%d",&n);
    
    if(n%4==0){
        n2 = n/4;
        p = (int*)malloc(n2*sizeof(int));
    } else {
        printf("O tamanho de byte nao se adapta ao inteiro.\n");
        exit(1);
    }
    
    printf("O que voce deseja?\n(1)Inserir valor em especifica posicao.\n(2)Consultar o valor de certa posicao.\n");
    scanf("%d",&op);
    
    
    
    
    

   
    return 0;
}