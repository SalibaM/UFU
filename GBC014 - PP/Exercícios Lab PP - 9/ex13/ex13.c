#include <stdio.h>
#include <stdlib.h>

void leitura(float *nota1,float *nota2){

    *nota1=0;
    *nota2=0;

    scanf("%f",nota1);
    while(*nota1<0){
        printf("Nota inválida,digite outra:\n");
        scanf("%f",nota1);
    }

    scanf("%f",nota2);
    while(*nota2<0){
        printf("Nota inválida,digite outra:\n");
        scanf("%f",nota2);
    }

}

void media(float *media_simples,float *media_pond,float nota1,float nota2){

    *media_simples=(nota1+nota2)/2;
    *media_pond=(nota1+(nota2*2))/3;
}

int main(){

    float nota1,nota2,media_simples,media_pond;

    printf("Digite a primeira e a segunda nota,respectivamente:\n");
    leitura(&nota1,&nota2);

    printf("A media simples e ponderada entre essas notas sera:\n");
    media(&media_simples,&media_pond,nota1,nota2);
    printf("SIMPLES:%.2f\n",media_simples);
    printf("PONDERADA:%.2f\n",media_pond);


    return 0;


}