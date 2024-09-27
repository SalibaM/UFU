#include <stdio.h>

void imprimir (int num,int contador,int contador2);

int main(){
    int num,contador,contador2;

    printf("Digite o numero:\n");
    scanf("%d",&num);

    imprimir(num,contador,contador2);

    return 0;
    
}
void imprimir (int num,int contador,int contador2){
    for (contador = 1; contador <= 2*num-1; contador++) {
        if (contador <= num) {
            for (contador2 = 1; contador2 <= contador; contador2++) {
                printf("*");
            }
        } else {
            for (contador2 = 1; contador2 <= 2*num-contador; contador2++) {
                printf("*");
            }
        }
        printf("\n");
    }
}