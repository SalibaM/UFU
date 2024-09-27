#include <stdio.h>

int main(){

    int opcao;
    float valor,valorfinal,impostomg,impostosp,impostorj,impostoms;

    printf("Escolha o estado destino do produto:\n1.MG\n2.SP\n3.RJ\n4.MS\n-Opcao:");
    scanf("%d",&opcao);

    printf("Digite o valor do seu produto:");
    scanf("%f",&valor);

    if(opcao==1){
        impostomg = (7.0/100.0) * valor;
        valorfinal = valor + impostomg;

        printf("O valor final do seu produto sera:%f",valorfinal);

    } else {
        if(opcao==2){
            impostosp = (12.0/100.0) * valor;
            valorfinal = valor + impostosp;

            printf("O valor final do seu produto sera:%f",valorfinal);
        } else{
            if(opcao==3){
                impostorj = (15.0/100.0) * valor;
                valorfinal = valor + impostorj;

                printf("O valor final do seu produto sera:%f",valorfinal);
            } else {
                if(opcao==4){
                    impostoms = (8.0/100.0) * valor;
                    valorfinal = valor + impostoms;

                    printf("O valor final do seu produto sera:%f",valorfinal);
                } else {
                    printf("Selecione uma opcao valida.");
                }
            }
        }

    }
    return 0;
}