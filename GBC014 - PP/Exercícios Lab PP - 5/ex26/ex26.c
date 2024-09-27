#include <stdio.h>
#include <string.h>

int main(){

    char string[200];
    int x,y,i,j,posinicial,posfinal,tamanho;

    printf("Digite uma string:\n");
    fgets(string,200,stdin);

    printf("Digite os dois numeros inteiros:\n");
    scanf("%d",&x);
    scanf("%d",&y);

    posinicial=x-1;
    posfinal=y;
    tamanho=strlen(string);

    if(posinicial<0 ||posfinal>tamanho){
        printf("Esse valor nao pode ser colocado...");
        return 0;
    }

    printf("O intervalo sera:\n");
    for(i=posinicial;i<=posfinal;i++){
        printf("%c",string[i]);
        if(i==posfinal){
            break;
        }
       
    }









    return 0;
}