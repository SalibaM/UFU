#include <stdio.h>

int main(){

    int vet[6],i,j;
    j = 5;

    printf("Digite 6 valores:");
    for (i=0;i<6;i++){
        scanf("%d",&vet[i]);
    }
    for (i=0;i<6;i++){
        printf("%d",vet[j]);
        j--;
    }





    return 0;
}