#include <stdio.h>
#include <stdlib.h>

int main()
{

    int anonasc,anoatual,idade,idade30,dif;

    printf("Digite o ano de seu nascimento:\n");
    scanf("%d",&anonasc);
    printf("Digite o ano atual:\n");
    scanf("%d",&anoatual);

    idade = anoatual - anonasc;
    dif = 2030 - anoatual;
    idade30 = idade + dif;

    printf("Voce tem %d anos, e tera %d anos em 2030.\n",idade,idade30);
    return 0;
}
