#include <stdio.h>
#include <string.h>

struct dados{

    char nome[50];
    char rua[50];
    int dia,mes,ano;
    char cidade[50];
    char cep[50];
    char email[50];


};

int main(){

    struct dados a;


    printf("Digite seu nome:\n");
    setbuf(stdin, NULL);
    fgets(a.nome,50,stdin);
    printf("Digite sua rua:\n");
    setbuf(stdin, NULL);
    fgets(a.rua,50,stdin);
    printf("Digite o dia do seu nascimento:\n");
    scanf("%d",&a.dia);
    printf("Digite o mes do seu nascimento:\n");
    scanf("%d",&a.mes);
    printf("Digite o ano do seu nascimento:\n");
    scanf("%d",&a.ano);
    printf("Digite o nome da sua cidade:\n");
    setbuf(stdin, NULL);
    fgets(a.cidade,50,stdin);
    printf("Digite seu CEP(sem o hifen):\n");
    setbuf(stdin, NULL);
    fgets(a.cep,50,stdin);
    setbuf(stdin, NULL);
    printf("Digite seu email:\n");
    setbuf(stdin, NULL);
    fgets(a.email,50,stdin);

    if(a.dia<1 || a.dia>30){
        printf("O dia inserido nao esta de acordo.\n");
        return 0;
    } else {
        if(a.mes>12 || a.dia<1){
            printf("O mes inserido nao esta de acordo.\n");
            return 0;
        } else {
            if(a.ano<1924 || a.ano>2023){
                printf("O ano inserido nao esta de acordo.\n");
                return 0;
            } else {
                if(strlen(a.cep)>9){
                    printf("O CEP tem mais digitos do que o esperado.\n");
                    return 0;
                } else {
                    printf("Todos os dados estao de acordo com o esperado!\n");
                }
            }
        }
    }







    return 0;
}