#include <stdio.h>
#define anoatual 2022

int main(){

    int dia,mes,ano,divanobi1,divanobi2,divanobi3;

    printf("Digite o dia,mes e ano, respectivamente:\n");
    scanf("%d %d %d",&dia,&mes,&ano);

    divanobi1 = ano % 400;
    divanobi2 = ano % 4;
    divanobi3 = ano % 100;

    if((dia<=0)){
        printf("Data invalida.");
        } else {
            if(ano>=anoatual){
                printf("Data invalida.");
            } else {
                if((mes<0) || (mes>12)){
                    printf("Data invalida;");
                } else {
                    if((mes==4 || mes==6 || mes==9 || mes==11) && (dia>30)){
                        printf("Data invalida.");
                    } else {
                        if((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && (dia>31)){
                            printf("Data invalida.");
                        } else {
                            if((mes==2) && (divanobi1==0 ||(divanobi2==0 && divanobi3!=0) && (dia<=29))){
                                printf("Data valida.");
                            } else {
                                if((mes==2) && (divanobi1==0 ||(divanobi2==0 && divanobi3!=0) && (dia>29))){
                                    printf("Data invalida.");
                                } else {
                                    if((mes==2) && (divanobi1!=0 && divanobi2!=0) && (dia<=28)){
                                        printf("Data valida.");
                                    } else {
                                        if((mes==2) && (divanobi1!=0 && divanobi2!=0) && (dia>28)){
                                            printf("Data invalida.");
                                        } else{
                                            printf("Data valida.");
                                        }
                                    }
                                }

                            }
                        }
                    }
                }
            }
        }
        return 0;
}



                   
                            