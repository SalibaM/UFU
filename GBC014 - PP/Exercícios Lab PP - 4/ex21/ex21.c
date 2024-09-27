#include <stdio.h>

void imprimir (int linhas,int contador,int contador2);

int main(){
    int linhas,contador,contador2;

    printf("Digite o numero de linhas:\n");
    scanf("%d",&linhas);

    imprimir(linhas,contador,contador2);

    return 0;
    
}
void imprimir (int linhas,int contador,int contador2){
    for(contador=1;contador <= linhas;contador++){
        for(contador2=1;contador2 <= contador;contador2++){
            printf("!");
            
        }
        printf("\n");
    }

}