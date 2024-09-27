#include <stdio.h>

int main(){

    int x,y;
    int *xa,*ya;

    printf("Digite as variaveis:\n");
    scanf("%d%d",&x,&y);

    printf("\n");

    xa = &x;
    ya = &y;

    if(xa>ya){
        printf("%d",x);
    } else {
        printf("%d",y);
    }


    return 0;
}