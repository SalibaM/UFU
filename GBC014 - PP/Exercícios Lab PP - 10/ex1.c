#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p;
    int i;

    p=(int*)malloc(5*sizeof(int));

    if(p==NULL){
        printf("Memoria nao alocada!");
        exit(1);
    }

    printf("Digite 5 numeros para o espaco alocado:\n");
    for(i=0;i<5;i++){
        scanf("%d",(p+i));
    }

    printf("Os numeros digitados foram:\n");
    for(i=0;i<5;i++){
        printf("%d",*(p+i));
    }

    free(p);

    return 0;


}