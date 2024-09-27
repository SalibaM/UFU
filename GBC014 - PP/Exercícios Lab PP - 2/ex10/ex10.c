#include <stdio.h>

int main(){
    
    char sexo;
    float h;
    float pesof;
    float pesom;

    printf("Digite o seu sexo(M ou F somente):");
    scanf("%c",&sexo);

    printf("Digite sua altura:");
    scanf("%f",&h);

    if (sexo == 'M'){
        pesom = (72.7 * h) - 58.0;
        printf("O seu peso ideal eh:%0.2f kg",pesom);

    } else{
        if(sexo == 'F'){
           pesof = (62.1 * h) - 44.7;
           printf("O seu peso ideal eh:%0.2f kg",pesof);
        } else{
            printf("Sexo invalido...");
        }

    }
    return 0;
}