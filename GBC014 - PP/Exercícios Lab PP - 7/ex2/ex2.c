#include <stdio.h>
#include <stdlib.h>

int main(){
    int x=1;
    float y=2;
    char z='$';

    int* a;
    float* b;
    char* c;

    a = &x;
    b = &y;
    c = &z;

    printf("Valores das variaveis antes: %d,%.2f,%c\n",x,y,z);

    *a = 7;
    *b = 9;
    *c = '%';

    printf("Valores das variaveis antes: %d,%.2f,%c\n",x,y,z);




    return 0;
}