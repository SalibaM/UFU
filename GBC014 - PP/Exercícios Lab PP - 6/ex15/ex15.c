#include <stdio.h>
#include <string.h>

struct livro{

    char nome[30];
    char autor[15];
    int ano;

};

int main(){

    struct livro livros[5];
    char titulo[30];
    int tamanhos[5];
    int i=0,j=0;

    for(i=0;i<5;i++){
        printf("Livro %d\n",i+1);
        printf("Nome do livro: \n");
        fflush(stdin);
        fgets(livros[i].nome,30,stdin);
        printf("Nome do autor: \n");
        fgets(livros[i].autor,15,stdin);
        printf("Ano do livro: \n");
        scanf("%d",&livros[i].ano);
        printf("\n");

    }

    for(i=0;i<5;i++){
        tamanhos[i] = strlen(livros[i].nome);
    }

    printf("Qual titulo voce quer buscar?\n");
    fflush(stdin);
    fgets(titulo,30,stdin);

    for(i=0;i<5;i++){
        if(strlen(titulo)==tamanhos[i]){
            printf("Livro encontrado!\n");
            printf("Nome: %s\n",livros[i].nome);
            printf("Autor: %s\n",livros[i].autor);
            printf("Ano: %d\n",livros[i].ano);
        }
    }

    return 0;
}