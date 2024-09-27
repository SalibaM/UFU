#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculos(int p[],float *media,int *maiorval,int n){

    int i;
    float soma=0;

    for(i=0;i<n;i++){

        soma = soma + p[i];
    }

    *media = soma/n;

    *maiorval=p[0];

    for(i=0;i<n;i++){

        if(p[i]>*maiorval){
            *maiorval = p[i];
        }

    }

}


int main(){

    int maiorval=0,i=0,n=0;
    int *p;
    float media=0;

    printf("Digite o tamanho do seu vetor:\n");
    scanf("%d",&n);

    p = (int *)malloc(n*sizeof(int));

    if(p==NULL){
        printf("Erro!\n");
        exit(1);
    }

    printf("Preencha o seu vetor:\n");

    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    calculos(p,&media,&maiorval,n);

    printf("O valor da sua media sera:%.2f\n",media);

    printf("O valor mais alto digitado foi:%d\n",maiorval);

    free(p);

    return 0;
}
