#include <stdio.h>

int main(){

    int array[3]={1,2,3};
    int *p1,*p2,*p3;

    printf("Valores antigos:%d, %d, %d.\n",array[0],array[1],array[2]);

    p1 = &array[0];
    p2 = &array[1];
    p3 = &array[2];

    (*p1)++;
    (*p2)++;
    (*p3)++;

    printf("Valores atualizados:%d, %d, %d.",*p1,*p2,*p3);

    return 0;
}