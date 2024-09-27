#include <stdio.h>

void imprimir (int num,int contador,int contador2,int contador3);

int main(){
    int num,contador,contador2,contador3;

    printf("Digite o numero:\n");
    scanf("%d",&num);

    imprimir(num,contador,contador2,contador3);

    return 0;
    
}
void imprimir (int num,int contador,int contador2,int contador3){
    for (contador = 1; contador <= num; contador++) {
            for (contador2 = 1; contador2 <= num-contador; contador2++) {
                printf(" ");
            }
            for (contador3 = 1; contador3 <= 2*contador-1; contador3++) {
                printf("*");
            }
        printf("\n");
        }
    }
