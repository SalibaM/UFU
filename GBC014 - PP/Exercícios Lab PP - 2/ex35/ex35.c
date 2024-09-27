#include <stdio.h>

int main(){

    int dia,mes,ano,divanobi1,divanobi2,divanobi3;

    printf("Digite o dia: ");
    scanf("%d",&dia);

    printf("Digite o mes: ");
    scanf("%d",&mes);

    printf("Digite o ano: ");
    scanf("%d",&ano);

    divanobi1 = ano % 400;
    divanobi2 = ano % 4;
    divanobi3 = ano % 100;

    if(mes<1 || mes>12){
        printf("Data invalida!");
    } else {
        if((mes==2) && (divanobi1==0 ||(divanobi2==0 && divanobi3!=0) && (dia<=29))){
            printf("Data valida!");
        } else {
            if((mes==2) && (divanobi1==0 ||(divanobi2==0 && divanobi3!=0) && (dia>29))){
                printf("Data invalida!");
            } else {
            if((mes==2) && (divanobi1!=0 && divanobi2!=0) && (dia<=28)){
                printf("Data valida!");
            } else {
                if((mes==2) && (divanobi1!=0 && divanobi2!=0) && (dia>28)){
                    printf("Data invalida!");
                } else{
                if((dia>30) || (dia<=0)){
                    printf("Data invalida!");
                } else {
                    if((dia<=30)){
                        printf("Data valida!");
                    } 
                }
            }

        }
        
    }

}
}
return 0;
}