#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    int *p;
    int i;

    printf("Digite o tamanho da alocacao:\n");
    scanf("%d",&n);

    p = (int*)malloc(n*sizeof(int));
    printf("Digite os %d numeros da alocacao:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",(p+i));
    }
    printf("Os numeros digitados foram:\n");
    for(i=0;i<n;i++){
        printf("%d",*(p+i));
    }

    free(p);

    return 0;


}