#include <stdio.h>
#include <stdlib.h>

int main(){

    int vet[5];
    int vet2[5];
    int acertos=0,i,j;
    int *p=NULL;
    float pAcertos=0.0;

    printf("Digite os numeros da lotomania:\n");
    for(i=0;i<5;i++){
        scanf("%d",&vet[i]);
    }

    printf("Digite os numeros que voce apostou:\n");
    for(i=0;i<5;i++){
        scanf("%d",&vet2[i]);
    }

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(vet2[i]==vet[j]){
                acertos = acertos + 1;
                continue;
            }
        }
    }


    p = (int *)malloc(acertos*sizeof(int));

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(vet2[i]==vet[j]){
                p[i]=vet2[i];
                continue;
            }
        }
    }

    pAcertos = (acertos/100.0)*50.0;

    printf("Numeros da lotomania:\n");

    for(i=0;i<5;i++){
        printf("%d ",vet[i]);
    }

    printf("\n");

    printf("Numeros que voce acertou:\n");

    for(i=0;i<acertos;i++){
        printf("%d ",p[i]);
    }

    printf("\n");

    printf("Porcentagem de acerto:\n");
    printf("%.2f%",pAcertos*100);




    return 0;
}
