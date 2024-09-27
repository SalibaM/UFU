#include <stdio.h>
#include <string.h>

int main(){

    char string[200];
    int i,j;
    int tamanho;

    printf("Digite uma frase:\n");
    setbuf(stdin, NULL);
    fgets(string,200,stdin);

    tamanho = strlen(string);

    for(i=0;string[i]!='\0';i++){
        if((string[i]=='r')&&(string[i+1]=='r')){
            string[i]='l';
            for(j=i+1;j<tamanho-1;j++){
                string[j]=string[j+1];
            }
        }
        if(string[i]=='r'){
            string[i]='l';
            if(string[i+1]==' '){
                string[i]='r';
            }
            if(string[i+1]=='\n'){
                string[i]='r';
            }
        }
    }



    printf("A frase trocada como o Cebolinha falaria sera:\n%s\n",string);





    return 0;
}