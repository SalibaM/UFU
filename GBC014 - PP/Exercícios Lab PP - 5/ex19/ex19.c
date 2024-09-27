#include <stdio.h>
#include <string.h>

int main(){

    char str[100];
    int i,tamanho;

    printf("Digite uma string de ate 100 palavras:\n");
    gets(str);

    tamanho=strlen(str);
      
    printf("Ao contrario, a string sera:");
    for(i=tamanho;i>=0;i--){
          
        printf("%c",str[i]);
    }
        

     
    return 0;
}