#include <stdio.h>
#include <string.h>

int main(){

    char string[200];
    int i;

    printf("Digite sua string em letra minusculas:\n");
    gets(string);

    for(i=0;string[i]!='\0';i++){
        if(string[i]==' '){
            string[i]=string[i];
        } else {
             string[i]=string[i]-32;
        }
    }

    printf("Essa string em letras maiusculas sera:\n");
    for(i=0;string[i]!='\0';i++){
        printf("%c",string[i]);
    }


    
}