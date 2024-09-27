#include <stdio.h>

int main (){
    int vsegundos;
    int vhoras;
    int vminutos;

    printf("Digite um valor inteiro em segundos:");
    scanf("%d",&vsegundos);

    vminutos = vsegundos / 60;
    vhoras = vminutos / 60;

    printf("Esse valor de segundos corresponde a:%d hora(s), %d minutos e %d segundos",vhoras,vminutos,vsegundos);

    return 0;


}