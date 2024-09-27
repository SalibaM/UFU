#include <stdio.h>

int main()
{
    int vet[4][4],i,j,qntd=0;
    printf("Digite os dados de uma matriz 4x4:\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%d",&vet[i][j]);
            if(vet[i][j]>10){
                qntd++;
            }
        }

    }
    printf("A matriz digitada tem %d numeros maiores que 10.",qntd);

    return 0;
}