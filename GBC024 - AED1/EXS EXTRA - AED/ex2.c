#include <stdio.h>

int main(){

    int x=10;
    float y=2.5;
    char c='M';

    int *xa;
    float *ya;
    char *ca;

    xa = &x;
    ya = &y;
    ca = &c;

    printf("ANTES:%d %.2f %c\n",x,y,c);

    *xa = 11;
    *ya = 3.5;
    *ca = 'N';

    printf("DEPOIS:%d %.2f %c",x,y,c);

    return 0;


}