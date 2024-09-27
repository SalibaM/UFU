#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,count=0;
    int *p;

    p = (int*)calloc(1500,sizeof(int));
    
    for(i=0;i<1500;i++){
        if(*(p+i)==0){
            count++;
        }
    }

    if(count==1500){
        printf("O vetor tem exatas 1500 posicoes!\n\n");
    }

    for(i=0;i<=1500;i++){
        *(p+i)=i;
    }

    printf("10 primeiros numeros:\n");
    for(i=0;i<10;i++){
        printf("%d\n",*(p+i));
    }

    printf("\n\n");

    printf("10 ultimos numeros:\n");
    for(i=1491;i<=1500;i++){
        printf("%d\n",*(p+i));
    }


    return 0;
}