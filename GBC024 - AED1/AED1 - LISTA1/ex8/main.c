#include <stdio.h>
#include <stdlib.h>

int main(){

    char palavra[100];
    int i,j;

    printf("Digite uma palavra:\n");
    fgets(palavra,100,stdin);

    for(i=0;palavra[i]!='\0';i++){
        for(j=i+1;palavra[j]!='\0';j++){
            if(palavra[i]==palavra[j]){
                printf("A letra (%c) se repetiu!\n",palavra[i]);
            }
        }

    }

    return 0;


}
