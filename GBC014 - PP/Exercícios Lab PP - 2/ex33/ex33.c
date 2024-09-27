#include <stdio.h>

int main(){

    float precoant,preconovo,aumento1,aumento2,aumento3;

    printf("Digite o preco antigo do produto: ");
    scanf("%f",&precoant);

    if(precoant<50){
        aumento1 = (5.0/100) * precoant;
        preconovo = precoant + aumento1;
    } else {
        if((precoant>=50) && (precoant<=100)){
            aumento2 = (10.0/100) * precoant;
            preconovo = precoant + aumento2;
            printf("O preco novo do produto sera: %f \n", preconovo);
        } else {
            if(precoant>100){
                aumento3 = (15.0/100) * precoant;
                preconovo = precoant + aumento3;
                printf("O preco novo do produto sera: %f \n", preconovo);
            } 
            }
        }

    if(preconovo<80){
        printf("Barato.");
    } else {
        if((preconovo >=80) && (preconovo<=120)){
            printf("Normal.");
        } else {
            if((preconovo>120) && (preconovo<=200)){
                printf("Caro.");
            } else {
                if(preconovo>200){
                    printf("Muito caro.");
                }
            }
        }
    }
    return 0;
    }


