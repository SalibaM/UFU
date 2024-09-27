#include <stdio.h>
#include <stdlib.h>

void soma (int *x,int *y){
    *x = *x + *y;
}

int main(){

    int x,y;

    printf("Digite dois valores(x e y):\n");
    scanf("%d%d",&x,&y);

    soma(&x,&y);

    printf("Soma:%d\n",x);
    printf("Valor de B:%d",y);

    return 0;

}