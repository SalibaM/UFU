#include <stdio.h>

int main(){

    int idade,tserv;

    printf("Digite sua idade:");
    scanf("%d",&idade);

    printf("Digite o seu tempo de servico:");
    scanf("%d",&tserv);

    if(idade >= 65){
        printf("Voce pode se aposentar.");
    } else {
        if(tserv >= 30){
            printf("Voce pode se aposentar");
        } else {
            if((idade >= 60) && (tserv >= 25)){
                printf("Voce pode se aposentar.");
            } else {
                printf("Voce nao pode se aposentar");
            }

             
        }
    }
      return 0;
}