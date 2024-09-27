#include <stdio.h>
#include <stdlib.h>
int data(int dia, int mes, int ano);

int main(){
    int dia;
    int mes;
    int ano;
    printf("Digite o dia:");
    scanf("%d",&dia);

    printf("Digite o mes:");
    scanf("%d",&mes);

    printf("Digite o ano:");
    scanf("%d",&ano);

    data(dia,mes,ano);



}
int data (int dia, int mes, int ano){
    switch(mes){
    case (1):
        printf("%d de janeiro de %d",dia,ano);
        break;
    case (2):
        printf("%d de fevereiro de %d",dia,ano);
        break;
    case (3):
        printf("%d de março de %d",dia,ano);
        break;
    case (4):
        printf("%d de abril de %d",dia,ano);
        break;
    case (5):
        printf("%d de maio de %d",dia,ano);
        break;
    case (6):
        printf("%d de junho de %d",dia,ano);
        break;
    case (7):
        printf("%d de julho de %d",dia,ano);
        break;
    case (8):
        printf("%d de agosto de %d",dia,ano);
        break;
    case (9):
        printf("%d de setembro",dia,ano);
        break;
    case (10):
        printf("%d de outubro de %d",dia,ano);
        break;
    case (11):
        printf("%d de novembro de %d",dia,ano);
        break;
    case (12):
        printf("%d de dezembro de %d",dia,ano);
        break;

    }






}