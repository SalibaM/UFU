#include <stdio.h>

void desenha_linha(int qntsinais,int contador);

int main(){

    int qntsinais,contador;
    printf("Digite a quantidade (valor) de simbolos que voce quer na linha:");
    scanf("%d",&qntsinais);

    desenha_linha(qntsinais,contador);
    return 0;

    

}
void desenha_linha (int qntsinais,int contador){
    for (contador = 0; contador < qntsinais; contador++){
        printf("=");
    }


    
}