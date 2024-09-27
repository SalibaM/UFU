#include <stdio.h>

int main(){

    char string[200];
    int i;

    printf("Digite uma string:\n");
    fgets(string,200,stdin);

    for(i=0;string[i]!='\0';i++){
        if(string[i]==' '){
            string[i]=string[i];
        } else {
        string[i] = string[i]-29;
        }
    }

    printf("A codificacao dessa string sera:\n %s",string);


    return 0;
}