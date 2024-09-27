#include <stdio.h>

int main(){
    int idade;
    int anoatual;
    int anonasc;

    printf("Digite sua idade:");
    scanf("%d",&idade);

    printf("Digite o ano atual:");
    scanf("%d",&anoatual);

    anonasc = anoatual - idade;

    printf("O ano do seu nascimento e:%d",anonasc);
    /* Nesse caso, o resultado só dá certo se você já tiver feito aniversário no ano
    atual inserido, caso contrário, penso eu que teria de se usar funções como if e else,
    e perguntar ao usuário sobre essa informação. Não sei utilizar ambas ainda, então pre-
    firo deixar desta maneira.
    */

    return 0;

}