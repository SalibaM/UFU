#include <stdio.h>
#include <stdlib.h>

int main(){

    float nota1=0,nota2=0,nota3=0,media=0,notaexame=0;

    printf("Digite suas tres notas em ordem:\n");
    scanf("%f%f%f",&nota1,&nota2,&nota3);

    media = (nota1+nota2+nota3)/3;

    printf("Sua media com as tres notas sera:%.2f\n",media);

    if(media>=0 && media<=3){
        printf("Voce esta reprovado, infelizmente...\n");
    } else {
        if(media>=7 && media<=10){
            printf("Voce foi aprovado!!!\n");

        } else {
            if(media>=3 && media<=7){
                notaexame = 12 - media;
                printf("Voce ficou de exame final, e precisa tirar %.2f para ser aprovado.\n",notaexame);
            }
          }


      }

    return 0;

}
