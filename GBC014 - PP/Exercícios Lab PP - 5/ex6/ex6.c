#include <stdio.h>

int main(){

    int vet[10],j,i,primos;
    printf("Digite 10 numeros:\n");

    for(i=0;i<10;i++){
        scanf("%d",&vet[i]);
    }

    for(i=0;i<10;i++){
        primos = 1;
        if(vet[i]<=0){
            return 0;
        } else {
            for(j = 2; j <= vet[i]/2;j++){
                if(vet[i]%j == 0){
                    primos = 0;
                    break;
                }
            }
            if(primos){
            printf("Numero %d\n",vet[i]);
            printf("Esse numero primo esta na posicao %d\n\n",i);
        }
    }

}


    return 0;
}