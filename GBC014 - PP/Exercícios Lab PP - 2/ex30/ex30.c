#include <stdio.h>

int main(){

    float x,y,z;

    printf("Digite os tres numeros:");
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);

    if((x>y) && (x>z) && (y>z)){
        printf("Ordem crescente: %0.2f, %0.2f, %0.2f.",z,y,x);
    } else {
        if((x>y) && (x>z) && (z>y)){
            printf("Ordem crescente: %0.2f, %0.2f, %0.2f.",y,z,x);
    } else {
        if((y>x) && (y>z) && (x>z)){
            printf("Ordem crescente: %0.2f, %0.2f, %0.2f.",z,x,y);
        } else {
            if((y>x) && (y>z) && (z>x)){
                printf("Ordem crescente: %0.2f, %0.2f, %0.2f.",x,z,y);
            } else {
                if((z>x) && (z>y) && (x>y)){
                    printf("Ordem crescente: %0.2f, %0.2f, %0.2f.",y,x,z);
                } else {
                    if((z>x) && (z>y) && (y>x)){
                        printf("Ordem crescente: %0.2f, %0.2f, %0.2f.",x,y,z);
                    }
                }
            }
        }
    }

}
 return 0;
}