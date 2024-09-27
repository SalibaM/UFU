#include <stdio.h>

int main(){

    int x;
    float num1,num2,soma,sub,mult,div;

    x = 1;

    while(x<5 && x>0){
        printf("Escolha uma opcao: \n1.Adicao\n2.Subtracao\n3.Multiplicacao\n4.Divisao\n5.Sair\n");
        scanf("%d",&x);
        switch(x){
            case 1:
            printf("Escolha um numero:");
            scanf("%f",&num1);
            printf("Escolha o segundo numero:");
            scanf("%f",&num2);

            soma = num1 + num2;
            printf("A soma sera: %.2f\n\n",soma);
            break;

            case 2:
            printf("Escolha um numero:");
            scanf("%f",&num1);
            printf("Escolha o segundo numero:");
            scanf("%f",&num2);

            sub = num1 - num2;

            printf("A subtracao sera: %.2f\n\n",sub);
            break;

            case 3:
            printf("Escolha um numero:");
            scanf("%f",&num1);
            printf("Escolha o segundo numero:");
            scanf("%f",&num2);

            mult = num1 * num2;
            
            printf("A multiplicacao sera: %.2f\n\n",mult);
            break;

            case 4:
            printf("Escolha um numero:");
            scanf("%f",&num1);
            printf("Escolha o segundo numero:");
            scanf("%f",&num2);

            div = num1/num2;

            printf("A divisao sera: %.2f\n\n",div);
            break;

            case 5:
            printf("Programa finalizado!");
            break;

        }
    }
    return 0;

}