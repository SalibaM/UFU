#include <stdio.h>

struct eletro{

    char nome[15];
    float potencia;
    int horas;

};

int main(){

    struct eletro dom[2];
    float consumototal=0,consumoindiv=0,consumoporc=0;
    int tempodias=0;
    int i=0;

    for(i=0;i<2;i++){
        printf("Eletrodomestico %d\n",i+1);
        printf("Nome: \n");
        fflush(stdin);
        fgets(dom[i].nome,15,stdin);
        printf("Potencia: \n");
        scanf("%f",&dom[i].potencia);
        printf("Horas ligado: \n");
        scanf("%d",&dom[i].horas);
    }

    printf("Digite uma qntd de dias:\n");
    scanf("%d",&tempodias);

    for(i=0;i<2;i++){
        consumoindiv = dom[i].potencia * dom[i].horas * tempodias;
        consumototal = consumototal+consumoindiv;
    }

    for(i=0;i<2;i++){
        consumoindiv = dom[i].potencia * dom[i].horas * tempodias;
        consumoporc = (consumoindiv/consumototal)*100;
        printf("O consumo relativo do eletrodomestico %d sera de %.2f porcento.\n",i+1,consumoporc);
    }

    printf("O consumo total da casa sera de %.2f kWh.\n",consumototal);
    

    





    return 0;
}