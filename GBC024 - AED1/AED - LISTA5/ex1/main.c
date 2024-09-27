#include <stdio.h>
#include <stdlib.h>

struct data{

    int dia;
    int mes;
    int ano;


};

void mostrarData(int dia,int mes,int ano){

    printf("%d/%d/%d",dia,mes,ano);

}

int main(){

    struct data d1;

    printf("Digite a data em ordem(dia,mes,ano):\n");
    scanf("%d%d%d",&d1.dia,&d1.mes,&d1.ano);

    mostrarData(d1.dia,d1.mes,d1.ano);

    return 0;
}
