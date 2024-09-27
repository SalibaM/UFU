#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subs(char string[],char caractere,int tamanho,int *contador){

    int i;

    for(i=0;string[i]!='\0';i++){

        if(string[i]==caractere){
            string[i]='*';
            *contador = *contador + 1;
        }

    }

}

int main(){

    int i,n=0;
    char caractere;
    char string[100];
    int contador=0;
    int tamanho=0;


    printf("Digite a sua string:\n");
    setbuf(stdin,NULL);
    fgets(string,100,stdin);

    printf("Digite o caractere que voce quer substituir:\n");
    scanf("%c",&caractere);

    tamanho = strlen(string);

    subs(string,caractere,tamanho,&contador);

    printf("Sua string ficou:%s\n",string);
    printf("%d substituicoes foram realizadas!\n",contador);



    return 0;
}
