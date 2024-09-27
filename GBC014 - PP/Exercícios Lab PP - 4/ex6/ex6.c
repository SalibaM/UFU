#include <stdio.h>
int transfsegundos (int horas,int minutos,int segundos);

int main(){
    int horas,minutos,segundos,horasseg,minseg,soma;
    printf("Digite o numero de horas,minutos e segundos, respectivamente:");
    scanf("%d%d%d",&horas,&minutos,&segundos);

    printf("Esse valor convertido em segundos eh:%d",transfsegundos(horas,minutos,segundos));

    return 0;

}
int transfsegundos (int horas,int minutos,int segundos){
    int horasseg,minseg,soma;
    horasseg = horas*3600;
    minseg = minutos*60;
    soma = horasseg + minseg + segundos;

    return soma;
    

}