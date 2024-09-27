#include <stdio.h>

int main(){

    char string[200],stringaux[200] = {0};
    int i,j = 0;

    printf("Digite uma frase:");
    gets(string);

    for(i=0;string[i]!='\0';i++){
        if(string[i]==' '){
            string[i]=string[i];
        } else {
            stringaux[j]=string[i];
            j++;
        }
    }

    printf("Essa frase sem espacos em branco sera:");
    for(j=0;stringaux[j]!='\0';j++){
        printf("%c",stringaux[j]);
    }

    return 0;
}