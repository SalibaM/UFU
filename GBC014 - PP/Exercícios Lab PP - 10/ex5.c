#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int i,n=0,x=0,num=0;;
    int *p;

    printf("Digite o tamanho:\n");
    scanf("%d",&n);

    p = (int*)malloc(n*sizeof(int));

    printf("Digite seu vetor:\n");
    for(i=0;i<n;i++){
        scanf("%d",(p+i));
    }

    printf("Digite um numero:\n");
    scanf("%d",&x);

    for(i=0;i<n;i++){
        if(*(p+i)%x==0){
            num=*(p+i);
            printf("Multiplo:%d.\n",num);
        }
    }

    free(p);

    return 0;
}