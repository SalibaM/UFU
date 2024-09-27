#include <stdio.h>
#include <stdlib.h>

void multiplica(float p[],int n,int val){

    int i=0;

    for(i=0;i<n;i++){
        p[i]=p[i]*val;
    }
}

int main(){

    int i,n=0;
    float *p;
    float val;

    printf("Digite o tamanho do seu vetor:\n");
    scanf("%d",&n);

    p = (float *)malloc(n*sizeof(float));

    if(p==NULL){
        printf("Erro!");
        exit(1);
    }

    printf("Preencha seu vetor:\n");

    for(i=0;i<n;i++){
        scanf("%f",&p[i]);
    }

    printf("Digite o valor de multiplicacao:\n");
    scanf("%f",&val);

    printf("Vetor antes da multiplicacao:\n");

    for(i=0;i<n;i++){
        printf("%.2f ",p[i]);
    }

    printf("\n");

    multiplica(p,n,val);

    printf("Vetor depois da multiplicacao:\n");
    for(i=0;i<n;i++){
        printf("%.2f ",p[i]);
    }

    printf("\n");

    free(p);



    return 0;
}
