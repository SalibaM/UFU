#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Palavra{

    char *string;

}palavra;

palavra *criarstring(){

    palavra *str;

    str = (palavra *)malloc(sizeof(palavra));

    if(str!=NULL){
        str->string = (char *)malloc(50*sizeof(char));
    }

    return str;

}

void preencherstring(palavra *str){

    int i;
    int contador=0;

    setbuf(stdin,NULL);
    fgets(str->string,50,stdin);

    for(i=0;str->string[i]!='\0';i++){
        contador++;
    }

    contador++;

    str->string = (char *)realloc(str->string,contador*sizeof(char));

    //deixar string com tamanho de memória certo

}

int tamanhostring(palavra *str){

    int i;
    int tamanho=0;

    for(i=0;str->string[i]!='\0';i++){
        tamanho++;
    }

    tamanho--;

    return tamanho;

}

int ocorrenciastring(palavra *str,char caractere){

    int i;
    int occur=0;

    for(i=0;str->string[i]!='\0';i++){
        if(str->string[i]==caractere){
            occur++;
        }
    }

    return occur;


}

void exibirstring(palavra *str){

    int i;

    for(i=0;str->string[i]!='\0';i++){
        printf("%c",str->string[i]);
    }


}





