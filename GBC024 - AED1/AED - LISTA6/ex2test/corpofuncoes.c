#include "prototipos.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct conj{

    int *vetconj;

}Conjunto;

Conjunto *criarconjunto(){

    Conjunto *c1;

    c1 = (Conjunto *)malloc(sizeof(Conjunto));

    if(c1!=NULL){
        c1->vetconj = (int *)malloc(50*sizeof(int));
    }

    return c1;

}

void inserir_membros_conjunto(Conjunto *c1){

    int i=0;
    int num=1;

    do{

        printf("Digite um numero para inserir no conjunto(0 para cancelar):\n");
        scanf("%d",&num);

        if(num==0){
            printf("Terminou.\n");
            break;
        }

        c1->vetconj[i]=num;

        i++;

        c1->vetconj=(int *)realloc(c1->vetconj,(i+1)*sizeof(int));


    }while(num!=0);
}

void remove_membros_conjunto(Conjunto *c1,int numero){

    int i,k;
    int tamanho_conjunto=0;
    int aux=0;


    tamanho_conjunto = sizeof(c1->vetconj)/sizeof(c1->vetconj[0]);

    aux = tamanho_conjunto;



    for(i=0;i<tamanho_conjunto;i++){
        if(c1->vetconj[i]==numero){
            aux--;
            for(k=i;k<tamanho_conjunto;k++){
                c1->vetconj[k]=c1->vetconj[k+1];
            }
            c1->vetconj=(int *)realloc(c1->vetconj,aux*sizeof(int));
        }
    }


}

int membro_presente(Conjunto *c1,int membro){

    int tamanho_conjunto=0;
    int i;

    tamanho_conjunto = sizeof(c1->vetconj)/sizeof(c1->vetconj[0]);

    for(i=0;i<tamanho_conjunto;i++){
        if(c1->vetconj[i]==membro){
            return 1;
        }
    }

    return 0;

}

Conjunto *uniao_entre_conjuntos(Conjunto *c1,Conjunto *c2){

    Conjunto *c_aux;

    int i,k;
    int j=0;
    int aux=0;

    int tamanho_c1=0;
    int tamanho_c2=0;
    int tamanho_ambos=0;

    tamanho_c1 = sizeof(c1->vetconj)/sizeof(c1->vetconj[0]);

    tamanho_c2= sizeof(c2->vetconj)/sizeof(c2->vetconj[0]);

    tamanho_ambos = tamanho_c1+tamanho_c2;

    aux = tamanho_ambos;

    c_aux = (Conjunto *)malloc(sizeof(Conjunto));

    if(c_aux!=NULL){
        c_aux->vetconj = (int *)malloc(tamanho_ambos*sizeof(int));
    }

    for(i=0;i<tamanho_c1;i++){
        c_aux->vetconj[i]=c1->vetconj[i];
    }

    for(k=i;k<tamanho_c2;k++){
        c_aux->vetconj[k]=c2->vetconj[j];
        j++;
    }

    for(i=0;i<tamanho_ambos;i++){
        for(j=i;j<tamanho_ambos;j++){
            if(c_aux->vetconj[i]==c_aux->vetconj[j]){
                aux--;
                for(k=i;k<tamanho_ambos;k++){
                    c_aux->vetconj[k]=c_aux->vetconj[k+1];
                }
                c_aux->vetconj = (int *)realloc(c_aux->vetconj,aux*sizeof(int));
            }
        }
        i--;
    }

    return c_aux;

}

Conjunto *interseccao_entre_conjuntos(Conjunto *c1,Conjunto *c2){

    Conjunto *c_aux;
    int i;
    int k;
    int aux=0;
    int tamanho_c1=0;
    int tamanho_c2=0;
    int tamanho_maior=0;

    tamanho_c1 = sizeof(c1->vetconj)/sizeof(c1->vetconj[0]);

    tamanho_c2= sizeof(c2->vetconj)/sizeof(c2->vetconj[0]);

    c_aux = (Conjunto *)malloc(sizeof(Conjunto));

    if(c_aux!=NULL){
        c_aux->vetconj = (int *)malloc(50*sizeof(int));
    }

    if(tamanho_c1>tamanho_c2){
        c2->vetconj = (int *)realloc(c2->vetconj,tamanho_c1*sizeof(int));
        tamanho_maior=tamanho_c1;
    }

    if(tamanho_c2>tamanho_c1){
        c1->vetconj = (int *)realloc(c1->vetconj,tamanho_c2*sizeof(int));
        tamanho_maior=tamanho_c2;
    }

    for(i=0;i<tamanho_maior;i++){
        for(k=i;k<tamanho_maior;k++){
            if(c1->vetconj[i]==c2->vetconj[k]){
                c_aux->vetconj[aux]=c1->vetconj[i];
                c_aux->vetconj = (int *)realloc(c_aux->vetconj,(aux+1)*sizeof(int));
                aux++;
            }


        }
    }

    return c_aux;

}

Conjunto *diferenca_entre_conjuntos(Conjunto *c1,Conjunto *c2){

    Conjunto *c_aux;

    int i,j;
    int aux=0;
    int tamanho_c1=0;
    int tamanho_c2=0;

    int presente=0;

    tamanho_c1 = sizeof(c1->vetconj)/sizeof(c1->vetconj[0]);

    tamanho_c2= sizeof(c2->vetconj)/sizeof(c2->vetconj[0]);

    c_aux = (Conjunto *)malloc(sizeof(Conjunto));

    if(c_aux!=NULL){
        c_aux->vetconj = (int *)malloc(50*sizeof(int));
    }

    for(i=0;i<tamanho_c1;i++){
       for(j=0;j<tamanho_c2;j++){
        if(c1->vetconj[i]==c2->vetconj[j]){
            presente=1;
            break;

        }

        if(!presente){
            c_aux->vetconj[aux]=c1->vetconj[i];
            aux++;
        }

       }
    }

    c_aux->vetconj = (int *)realloc(c_aux->vetconj,aux*sizeof(int));

    return c_aux;


}













