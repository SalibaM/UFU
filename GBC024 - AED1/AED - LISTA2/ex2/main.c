#include <stdio.h>
#include <stdlib.h>

int main(){

    int i;
    int *p;

    p = (int *)malloc(5*sizeof(int));

    if(p == NULL){
        printf("Erro!\n");
        exit(1);
    }

    for(i=0;i<5;i++){
        printf("Digite o %d numero:",i+1);
        scanf(" %d",p+i);
    }

    printf("Os numeros digitados foram:\n");

    for(i=0;i<5;i++){
        printf("%d ",*(p+i));
    }

    free(p);

    return 0;

}
