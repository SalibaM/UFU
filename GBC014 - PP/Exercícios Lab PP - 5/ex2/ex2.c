#include <stdio.h>

int main(){

    int vet[8];
    int x,y,i,soma;

    printf("Digite oito numeros em sequencia para serem armazenados:\n");
    for(i=0;i<8;i++){
        scanf("%d",&vet[i]);
    }
    printf("Escolha duas posicoes entre 0 e 7:");
    scanf("%d%d",&x,&y);

    soma = vet[x] + vet[y];
    printf("A soma dos numeros armazenados nessas posicoes eh:%d",soma);





    return 0;
}