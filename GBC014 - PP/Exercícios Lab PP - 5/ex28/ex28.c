#include <stdio.h>
#include <string.h>

int main(){
    
    char frase[200],fraselimpa[200];
    int tamanho,i,palindromo=1,tamanholimpo;

    printf("Digite a frase que sera verificada:\n");
    fgets(frase,200,stdin);

    tamanho = strlen(frase);

    for(i=0;i<tamanho;i++){
        if(frase[i]!=' '){
            fraselimpa[i]=frase[i];
        }
    }

    tamanholimpo = strlen(fraselimpa);

    for(i=0;i<tamanholimpo/2;i++){
        if(fraselimpa[i]!=fraselimpa[tamanho-i-2]){
            palindromo = 0;
            break;
        } else {
            palindromo = 1;
        }
    }

    if(palindromo==1){
        printf("Essa frase eh palindromo!");
    } else {
        printf("Essa frase nao eh palindromo.");
    }






    return 0;
}