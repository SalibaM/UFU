#include <stdio.h>

int main(){

    int codigo;
    printf("Digite o codigo do produto: ");
    scanf("%d",&codigo);

    if(codigo==100){
        printf("Cachorro quente que custa 1,20");
    } else {
        if(codigo==101){
            printf("Bauru simples que custa 1,30");
        } else {
            if(codigo==102){
                printf("Bauru com ovo que custa 1,50");
            } else {
                if(codigo==103){
                    printf("Hamburguer que custa 1,20");
                } else {
                    if(codigo==104){
                        printf("Cheeseburguer que custa 1,70");
                    } else {
                        if(codigo==105){
                            printf("Suco que custa 2,20");
                        } else {
                            if(codigo==106){
                                printf("Refrigerante que custa 1,00");
                            } else {
                                printf("Esse codigo nao esta no cardapio");
                            }
                        }

                    }
                }
            }
        }
    }
    return 0;
}