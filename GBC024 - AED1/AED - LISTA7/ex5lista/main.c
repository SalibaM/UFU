#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char str[2000];

    printf("Digite sua string de ate 2000 caracteres:\n");
    fgets(str,2000,stdin);
    str[strcspn(str, "\n")] = '\0';

    ocorrencias(str);


    return 0;
}
