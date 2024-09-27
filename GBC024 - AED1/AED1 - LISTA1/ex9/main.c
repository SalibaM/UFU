#include <stdio.h>
#include <stdlib.h>

struct livro{

    char titulo[50];
    int ano,numpaginas;
    float preco;

};

int main(){

    struct livro livros[5];
    int i;
    float media=0;
    int soma=0;

    for(i=0;i<5;i++){
        printf("Digite o nome do livro:\n");
        scanf("%s",livros[i].titulo);
        fflush(stdin);
        printf("Digite o ano,o numero de paginas e o preco do livro, respectivamente:\n");
        fflush(stdin);
        scanf("%d%d%f",&livros[i].ano,&livros[i].numpaginas,&livros[i].preco);
    }

    for(i=0;i<5;i++){
        soma = soma + livros[i].numpaginas;
    }

    media = soma/5.0;

    printf("A media de paginas dos livros digitados eh:%.2f",media);

    return 0;



}
