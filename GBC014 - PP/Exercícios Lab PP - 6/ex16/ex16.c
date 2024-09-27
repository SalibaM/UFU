#include <stdio.h>
#include <string.h>
struct data{
    int dia,mes,ano;
    };

struct comp{

    char nome[60];
    struct data datas;
};

int main(){

    struct comp compromissos[5];
    int mes,ano;
    int i;

    for(i=0;i<5;i++){
        printf("Compromisso %d\n",i+1);
        printf("Nome: \n");
        fflush(stdin);
        fgets(compromissos[i].nome,60,stdin);
        printf("Dia: \n");
        scanf("%d",&compromissos[i].datas.dia);
        printf("Mes: \n");
        scanf("%d",&compromissos[i].datas.mes);
        printf("Ano: \n");
        scanf("%d",&compromissos[i].datas.ano);
    }

    printf("Digite o mes checado: \n");
    scanf("%d",&mes);
    printf("Digite o ano checado: \n");
    scanf("%d",&ano);

    while(1){
        if(mes==0){
            break;
        } else {
            for(i=0;i<5;i++){
                if(mes==compromissos[i].datas.mes || ano==compromissos[i].datas.ano){
                    printf("Compromisso encontrado!\n");
                    printf("%s",compromissos[i].nome);
                    printf("%d/%d/%d",compromissos[i].datas.dia,compromissos[i].datas.mes,compromissos[i].datas.ano);
                    return 0;
                }

            }
        }


    }





    return 0;
}