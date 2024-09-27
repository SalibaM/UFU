#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p;
    int i=0,j=0;
    int opcao=1;
    int num=0;
    int tamanho=0;

    p = (int *)malloc(1*sizeof(int));

    if(p==NULL){
        printf("Erro!");
        exit(1);
    }


    while(opcao==1){
        do{

        printf("Digite qualquer numero para armazenar no vetor(ou -1 para parar):\n");
        scanf("%d",&num);

        if(num==-1){
            break;
        } else {

            p = (int *)realloc(p,(i+1)*sizeof(int));

            p[i]=num;

            tamanho = i;

            i++;

         }if(tamanho>0 && (p[tamanho]==p[tamanho-1])){

             p = (int *)realloc(p,(i-1)*sizeof(int));

             i--;
             tamanho--;


          }

        }while(num!=-1);

        printf("O vetor atualizado, sem repeticoes, sera:\n");

        for(j=0;j<i;j++){
            printf("[%d] ",p[j]);
        }

        printf("\n");


        printf("Quer preencher outro vetor? Digite 1 se sim, ou qualquer numero se nao :)\n");
        scanf("%d",&opcao);

        if(opcao!=1){
            break;
        } else {

            p = (int *)realloc(p,1*sizeof(int));
            i=0;
            j=0;
            tamanho = 0;
        }

    }

    free(p);

    return 0;
}
