#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){

    palavra *str = criarstring();
    char caractere;
    int ocorrencia=0;
    int tamanho=0;

    printf("Digite sua string:\n");
    preencherstring(str);

    printf("Digite um caractere:\n");
    scanf("%c",&caractere);

    ocorrencia = ocorrenciastring(str,caractere);
    tamanho = tamanhostring(str);

    printf("O tamanho da string eh:%d\n",tamanho);
    printf("O caractere %c ocorre %d vezes na string!\n",caractere,ocorrencia);

    printf("A string digitada foi:");

    exibirstring(str);

    return 0;



}
