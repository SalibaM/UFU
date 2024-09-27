#include <stdio.h>
#include <stdlib.h>

int main(){

    char nome[] = "Carla Faria";
    double vet[10] = {1,2,3,4,5,6,7,8,9,10};
    char *p;
    int i;

    p = &nome;

    for(i=0;*(p+i)!='\0';i++){
        printf("%c",*(p+i));
    }

    printf("\n\n");

    for(i=0;i<10;i++){
        printf("%.0lf ",*(vet+i));
    }

    return 0;


}
