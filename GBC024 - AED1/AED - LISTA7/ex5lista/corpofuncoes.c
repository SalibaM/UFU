#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct occur{

    int contagem;
    char caracter;


};

struct Lista{

    int total;

    struct occur *vetoroccur;

};

void ocorrencias(char str[]){

    int i;
    int j;

    struct Lista *laux;

    laux = (struct Lista *)malloc(sizeof(struct Lista));

    laux->vetoroccur = (struct occur *)malloc(128*sizeof(struct occur));

    for(i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            for(j=i;str[j]!='\0';j++){
                str[j]=str[j+1];
            }
        }

    }

    for(i=0;i<128;i++){
        laux->vetoroccur[i].caracter=i;
        laux->vetoroccur[i].contagem=0;
    }


    for(i=0;str[i]!='\0';i++){
        laux->vetoroccur[(int)str[i]].contagem++; //usamos ascii
    }

    for(i=0;i<128;i++){
        if(laux->vetoroccur[i].contagem > 0){
            printf("O caracter %c aparece %d vezes na string!\n",laux->vetoroccur[i].caracter,laux->vetoroccur[i].contagem);

        }
    }

}

