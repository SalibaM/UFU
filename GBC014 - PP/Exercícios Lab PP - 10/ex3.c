#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    int *p;
    int i;
    int qntdpares=0,qntdimpar=0;

    printf("Digite o tamanho da alocacao:\n");
    scanf("%d",&n);

    p = (int*)malloc(n*sizeof(int));
    printf("Digite os %d numeros da alocacao:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",(p+i));
    }

    for(i=0;i<n;i++){
        if(*(p+i)%2==0){
            qntdpares++;
        } else {
            qntdimpar++;
        }
    }

    printf("Voce digitou %d numeros pares.\n",qntdpares);
    printf("Voce digitou %d numeros impares.\n",qntdimpar);

    free(p);

    return 0;


}