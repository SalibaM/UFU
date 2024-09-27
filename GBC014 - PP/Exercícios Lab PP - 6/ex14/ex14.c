#include <stdio.h>

struct carro{
    char marca[15];
    int ano;
    int preco;
};

int main(){

    struct carro carros[5];
    int i,p;

    for(i=0;i<5;i++){
        printf("Carro %d\n",i+1);
        fflush(stdin);
        printf("Marca: \n");
        fflush(stdin);
        fgets(carros[i].marca,15,stdin);
        printf("Ano: \n");
        fflush(stdin);
        scanf("%d",&carros[i].ano);
        printf("Preco: \n");
        fflush(stdin);
        scanf("%d",&carros[i].preco);
        printf("\n");
    }

    printf("Digite um valor p:\n");
    scanf("%d",&p);

    while(1){

        printf("Digite um valor p: ");
        scanf("%d", &p);
        if(p == 0){
           break;
        }

    for(i=0; i<5; i++){
        if(carros[i].preco <= p){
            printf("%s", carros[i].marca);
            printf("Ano: %d\n", carros[i].ano);
            printf("Preco: %d\n", carros[i].preco);
            }
        }
    }
    return 0;
}