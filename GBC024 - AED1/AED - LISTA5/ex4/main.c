#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void repeticao(char string[],int tamanho){

    int i;
    int j;
    int k;
    int contador=0;
    int *p;

    p = (int *)calloc(26,sizeof(int));

    if(p==NULL){
        printf("Erro!");
        exit(1);
    }


    for(i=0;string[i]!='\0';i++){
        if(string[i]==' '){
            for(k=i;string[k]!='\0';k++){
                string[k] = string[k+1];
            }
        }
    }

    for(i=0;string[i]!='\0';i++){

        contador = 0;

        for(j=(i+1);string[j]!='\0';j++){

            if(string[i]==string[j]){

                contador++;

                for(k=j;string[k]!='\0';k++){

                    string[k] = string[k+1];

                }
              j--;//voltar e checar se existem mais repetições.
            }
        }

        p[i]=contador;//i armazena a própria letra, já que ela não vai mais se repetir na string,
                    //além do seu número de repetições(contador).

    }

    tamanho = strlen(string);

    p = (int *)realloc(p,tamanho*sizeof(int));

    printf("STRING ATUALIZADA COM REPETICOES POR LETRA:\n");

    printf("\n");

    printf("REPETICOES:\n");

    for(i=0;i<tamanho;i++){
        printf("[ %d ] ",p[i]);
    }

    printf("\n");


    for(i=0;string[i]!='\0';i++){
        printf("[ %c ] ",string[i]);
    }

    free(p);


}

int main(){


    char string[400];
    int tamanho=0;


    printf("Digite sua string:\n");
    fgets(string,400,stdin);

    string[strcspn(string, "\n")] = '\0';

    tamanho = strlen(string);

    repeticao(string,tamanho);










    return 0;
}
