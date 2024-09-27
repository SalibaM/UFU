#include <stdio.h>
#include <stdlib.h>

int main(){
    int x,y;
    int *z = NULL,*w = NULL;

    printf("Digite x:\n");
    scanf("%d",&x);
    printf("Digite y:\n");
    scanf("%d",&y);

    z = &x;
    w = &y;

    if(z>w){
        printf("O maior endereco de memoria sera %p.",z);
    } else {
        printf("O maior endereco de memoria sera %p.",w);

    }
    return 0;







}