#include <stdio.h>
#include <stdlib.h>

void retorno(int *x,int *y){

    int temp;
    temp = *y;
    *y=*x;
    *x=temp;


}

int main(){
    int x;
    int y;

    printf("Digite dois valores x e y:");
    scanf("%d%d",&x,&y);

    printf("Valores antes da troca - X=%d e Y=%d\n",x,y);

    retorno(&x,&y);

    printf("Valores depois da troca - X=%d e Y=%d\n",x,y);

    return 0;

}