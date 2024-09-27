#include <stdio.h>

int main(){
    
    float custofabri,custofinal,distri,imposto;

    printf("Digite o custo de fabrica:");
    scanf("%f",&custofabri);

    if(custofabri<=12000){
        distri = 0.05*custofabri;
        custofinal = custofabri + distri;
        printf("O custo final do carro sera de: %0.2f",custofinal);

    } else {
        if(custofabri <=25000){
            distri = 0.10*custofabri;
            imposto = 0.15*custofabri;
            custofinal = custofabri + distri + imposto;
            printf("O custo final do carro sera de: %0.2f",custofinal);
        } else {
            if(custofabri>25000){
                distri = 0.15*custofabri;
                imposto = 0.20*custofabri;
                custofinal = custofabri + distri + imposto;
                printf("O custo final do carro sera de: %0.2f",custofinal);
            }
        }
    }

    return 0;




}