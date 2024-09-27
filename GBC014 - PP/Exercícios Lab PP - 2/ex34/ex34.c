#include <stdio.h>

int main(){

    int faltas;
    float nota;

    printf("Digite sua nota: ");
    scanf("%f",&nota);

    printf("Digite seu numero de faltas: ");
    scanf("%d",&faltas);

    if((nota>=0.0) && (nota<=3.91) && (faltas<=20)){
        printf("Conceito E");
    } else {
        if ((nota>=0.0) && (nota<=3.91) && (faltas>20)){
            printf("Conceito E");
        } else {
            if((nota>=4.0) && (nota<=4.91) && (faltas<=20)){
                printf("Conceito D");
            } else {
                if((nota>=4.0) && (nota<=4.91) && (faltas>20)){
                    printf("Conceito E");
                } else {
                    if((nota>=5.0) && (nota<=7.41) && (faltas<=20)){
                        printf("Conceito C");
                    } else {
                        if((nota>=5.0) && (nota<=7.41) && (faltas>20)){
                            printf("Conceito D");
                        } else {
                            if((nota>=7.5) && (nota<=8.0) && (faltas<=20)){
                                printf("Conceito B");
                            } else {
                                if((nota>=7.5) && (nota<=8.0) && (faltas>20)){
                                    printf("Conceito C");
                                } else {
                                    if((nota>=9.0) && (nota<=10.0) && (faltas<=20)){
                                        printf("Conceito A");
                                    } else {
                                        if((nota>=9.0) && (nota<=10.0) && (faltas>20)){
                                            printf("Conceito B");
                                        } else {
                                            printf("Digite uma nota valida.");
                                        }
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