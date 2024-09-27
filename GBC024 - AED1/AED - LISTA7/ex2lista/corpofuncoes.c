#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int total;
    Aluno valores[MAX];
}Lista;

Lista *criar(){

    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL){
        l->total = 0;
    }

    return l;
}

void limpar(Lista *l){
    if (l != NULL){
        l->total = 0;
    }
}

int inserirInicio(Lista *l, Aluno it){
    int i;
    if (l == NULL) return 2;
    if (listaCheia(l) == 0) return 1;

    for (i=l->total;i>0;i--) {
        l->valores[i] = l->valores[i-1];
    }

    l->valores[0] = it;
    l->total++;

    return 0;
}

int inserirFim(Lista *l, Aluno it){
    if (l == NULL) return 2;
    if (listaCheia(l) == 0) return 1;

    l->valores[l->total] = it;
    l->total++;

    return 0;
}

int buscarItemChave(Lista *l, int chave,Aluno *retorno){

    int i;
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    for (i=0;i<l->total;i++){
        if (l->valores[i].mat == chave){
            *retorno = l->valores[i];
            return 0;
        }
    }


    return -1;
}

int listaVazia(Lista *l) {
    if (l == NULL) return 2;

    if (l->total == 0) return 0;

    else return 1;
}

int removerInicio(Lista *l) {

    int i;

    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    for (i=0;i<l->total-1;i++){
        l->valores[i] = l->valores[i+1];
    }

    l->total--;

    return 0;
}

int removerFim(Lista *l) {

    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    l->total--;

    return 0;
}

int listaCheia(Lista *l) {

    if (l == NULL) return 2;
    if (l->total == MAX) return 0;

    else return 1;
}

void mostrar(Lista *l) {

    int i;
    if (l != NULL) {
        printf("[");
        for (i=0;i<l->total;i++) {
            printf(" {%d, ",l->valores[i].mat);
            printf("%s, ",l->valores[i].nome);
            printf("%.2f} ",l->valores[i].n1);}
            printf("]\n");
    }
}

int inserirPosicao(Lista *l,Aluno it,int pos){

    if(l==NULL){
        return 2;
    }

    if(pos>l->total){
        l->valores[l->total] = it;
        l->total++;

    } else {

        l->valores[pos] = it;
    }

    return 0;
}

int removerPosicao(Lista *l,int pos){

    int i;

    if(l==NULL){
        return 2;
    }

    if(listaVazia(l)==0){
        return 1;
    }

    if(pos>l->total){
        //não existe posição para ser retirada
        return 3;
    }

    for(i=(pos);i<(l->total-1);i++){
        l->valores[i] = l->valores[i+1];
    }

    l->total--;

    return 0;


}

int removerItem(Lista *l,Aluno it){

    int i;
    int j;

    if(l==NULL){
        return 2;
    }

    if(listaVazia(l)==0){
        return 1;
    }

    for(i=0;i<l->total;i++){
        if(l->valores[i].mat==it.mat){
            for(j=i;j<l->total-1;j++){
                l->valores[j] = l->valores[j+1];
            }
            l->total--;
            i--;

        }
    }

    return 0;

}

int buscarPosicao(Lista *l,int posicao,Aluno *it){


    if(l==NULL){
        return 2;
    }

    if(listaVazia(l)==0){
        return 1;
    }

    if(posicao>l->total){
        it = NULL;
        return 3;
    } else {
        *it = l->valores[posicao];
        return 4;
    }

    return 0;


}

int tamanho(Lista *l){

    int tamanho;

    tamanho = l->total;

    return tamanho;

}


int ContemItem(Lista *l,Aluno it){

    int i;

    if(l==NULL){
        return 2;
    }

    if(listaVazia(l)==0){
        return 4;
    }

    for(i=0;i<l->total;i++){
        if(it.mat==l->valores[i].mat){
            return 0;
        }
    }

    return 1;

}


Lista *Reversa(Lista *l){

    Lista *laux;
    int i;
    int n = l->total;

    laux = criar();

    for(i=0;i<l->total;i++){
        laux->valores[i] = l->valores[n-i-1];
    }

    laux->total=l->total;

    return laux;

}

int ContaItem(Lista *l,Aluno it){

    int contador=0;
    int i;

    if(l==NULL){
        return 2;
    }

    if(listaVazia(l)==0){
        return 1;
    }

    for(i=0;i<l->total;i++){
        if(l->valores[i].mat==it.mat){
            contador++;

        }

    }

    return contador;


}

