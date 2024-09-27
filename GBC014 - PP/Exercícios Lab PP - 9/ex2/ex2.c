#include <stdio.h>
#include <stdlib.h>

void maiormenor (int *x,int *y,int *maior,int *menor){

    if(*x>*y){
        *maior = *x;
        *menor = *y;
    }else {
        *maior = *y;
        *menor = *x;
     }
}

int main(){

    int x,y,maior=0,menor=0;

    printf("Digite dois valores(x e y):\n");
    scanf("%d%d",&x,&y);

    maiormenor(&x,&y,&maior,&menor);

    printf("Maior valor:%d\n",maior);
    printf("Menor valor:%d\n",menor);

    return 0;

}