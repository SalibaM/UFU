#include <stdio.h>

int main(){

    float nota1,nota2,nota3,notaf1,notaf2,notaf3,somanota,mediapondf;

    printf("Digite a nota da primeira prova:");
    scanf("%f",&nota1);

    printf("Digite a nota da segunda prova:");
    scanf("%f",&nota2);
    
    printf("Digite a nota da terceira prova:");
    scanf("%f",&nota3);

    notaf1 = 1 * nota1;
    notaf2 = 1 * nota2;
    notaf3 = 2 * nota3;

    somanota = notaf1 + notaf2 + notaf3;
    mediapondf = somanota / 4;

    if(mediapondf < 60.0){
        printf("Voce foi reprovado :( ");

    } else {
        printf("Voce foi aprovado! :)");

    }

    //Código está considerando prova com valor de 0-100!
    return 0;
}