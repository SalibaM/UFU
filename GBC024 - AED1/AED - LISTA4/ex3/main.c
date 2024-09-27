#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){

    int temp;
    temp=*b;
    *b = *a;
    *a = temp;

}


void troca(int p[],int n){

    int i,j;

    for(i=0;i<n;i++){
        for(j=(i+1);j<n;j++){
            swap(&p[j],&p[i]);
        }
    }
}

int main(){

    int i,n=0;
    int *p;

    printf("Digite o tamanho do seu vetor:\n");
    scanf("%d",&n);

    p = (int *)malloc(n*sizeof(int));

    if(p==NULL){
        printf("Erro!");
        exit(1);
    }


    printf("Preencha seu vetor:\n");

    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    troca(p,n);

    printf("Seu novo vetor sera:\n");

    for(i=0;i<n;i++){
        printf("%d ",p[i]);
    }



    return 0;

}



