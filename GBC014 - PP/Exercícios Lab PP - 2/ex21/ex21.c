#include <stdio.h>

int main(){

    int opcao;
    float num1,num2,soma,mult,sub,div;

    printf("Escolha a opcao:\n1- Soma de 2 numeros.\n2- Diferenca entre 2 numeros (maior pelo menor).\n3- Produto entre 2 numeros.\n4- Divisao entre 2 numeros (o denominador nao pode ser zero).\nOpcao:");
    scanf("%d",&opcao);

    if(opcao==1){
        printf("Digite o primeiro numero:");
        scanf("%f",&num1);

        printf("Digite o segundo numero:");
        scanf("%f",&num2);

        soma = num1 + num2;

        printf("A soma desses dois numeros eh:%0.2f",soma);
    } else {
        if(opcao==2){
            printf("Digite o primeiro numero(Deve ser o maior dos dois):");
            scanf("%f",&num1);

            printf("Digite o segundo numero(Deve ser o menor dos dois):");
            scanf("%f",&num2);

            sub = num1 - num2;

            printf("A diferenca entre esses dois numeros eh:%0.2f",sub);

        } else {
            if(opcao==3){
                printf("Digite o primeiro numero:");
                scanf("%f",&num1);

                printf("Digite o segundo numero:");
                scanf("%f",&num2);

                mult = num1 * num2;

                printf("A multiplicacao entre esses numeros eh:%0.2f",mult);

            } else {
                if(opcao==4){
                    printf("Digite o primeiro numero:");
                    scanf("%f",&num1);

                    printf("Digite o segundo numero(Nao pode ser zero):");
                    scanf("%f",&num2);

                    div = num1 / num2;

                    printf("A divisao entre esses numeros eh:%0.2f",div);
                }
            }
        }

        }
        return 0;
    }
    