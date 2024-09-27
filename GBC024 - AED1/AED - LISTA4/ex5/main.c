
#include <stdio.h>
#include <stdlib.h>

float* vetor(int n,float valor){

    float *p;
    int i;

    p = (float *)malloc(n*sizeof(float));

    if(p==NULL){
        printf("Erro!");
        exit(1);
    }

    for(i=0;i<n;i++){
        p[i]=valor;
    }

    return p;

}





int main(){

    int i,n=0;
    float valor=0;
    float *vet;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d",&n);

    printf("Digite o valor para preencher:\n");
    scanf("%f",&valor);

    vet = vetor(n,valor);

    printf("O vetor sera:\n");

    for(i=0;i<n;i++){
        printf("%.2f  ",vet[i]);
    }

    free(vet);

    return 0;
}
