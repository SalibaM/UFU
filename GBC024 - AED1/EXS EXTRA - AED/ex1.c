#include <stdio.h>

int main(){

    int x=7,y=9;
    int aux;
    int *p,*point;

    p = &x;
    point = &y;
    aux = *p;

    *p = *point;
    *point = aux;

    printf("%d %d",x,y);

    return 0;


}