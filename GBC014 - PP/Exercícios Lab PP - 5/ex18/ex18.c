#include <stdio.h>
#include <string.h>

int main(){

    char strg[100];
    int i,qntd;
    qntd = 0;

    printf("Digite uma sequencia de 0's e 1's aleatoria:\n");
    fgets(strg, 100,stdin);

    for(i=0;strg[i]!='\0';i++){
        if(strg[i]=='1'){
            qntd++;
        } 
    }

    printf("Existem %d numeros 1's nessa sequencia.",qntd);

    return 0;

}