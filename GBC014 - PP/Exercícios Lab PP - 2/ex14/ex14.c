#include <stdio.h>

int main(){

    float nota1,nota2,nota3,notaf1,notaf2,notaf3,somanotaf,mediapondf;

    printf("Digite sua nota no trabalho de laboratorio:");
    scanf("%f",&nota1);

    printf("Digite sua nota na avaliacao trimestral:");
    scanf("%f",&nota2);

    printf("Digite sua nota no exame final:");
    scanf("%f",&nota3);

    notaf1 = nota1 * 2;
    notaf2 = nota2 * 3;
    notaf3 = nota3 * 5;

    somanotaf = notaf1 + notaf2 + notaf3;

    mediapondf = somanotaf / 10;

    if((mediapondf >= 0) && (mediapondf <= 2.9)){
        printf("Voce esta reprovado!");
        
    } else {
        if((mediapondf >=3) && (mediapondf <= 4.9)){
            printf("Voce esta de recuperacao!");

        } else {
            printf("Voce foi aprovado!");
        }

    }
    return 0;
}