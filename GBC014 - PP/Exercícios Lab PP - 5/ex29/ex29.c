#include <stdio.h>
#include <string.h>

int main(){

    char str1[200];
    char str2[200];
    int i,N,tamanhovelho,tamanhonovo;

    printf("Digite a primeira string:\n");
    fgets(str1,200,stdin);

    printf("Digite a segunda string:\n");
    fgets(str2,200,stdin);

    printf("Digite um valor inteiro positivo:\n");
    scanf("%d",&N);

    tamanhovelho=strlen(str1);

    for(i=0;i<N;i++){
        str1[tamanhovelho+i]=str2[i];
    }

    tamanhonovo=tamanhovelho+N;

    str1[tamanhonovo]='\0';

    printf("O resultado da concatenacao sera:\n%s",str1);




    return 0;
}