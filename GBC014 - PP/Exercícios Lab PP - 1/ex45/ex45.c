#include <stdio.h>

int main(){
    char letramai;
    char letramin;

    printf("Digite uma letra maiuscula:");
    scanf("%c",&letramai);

    letramin = letramai + 32;
    //sempre se adiciona 32 na seção ''Dec'' da tabela ASCII, isso vira um padrão

    printf("Essa mesma letra, mas agora minuscula eh:%c",letramin);

    return 0;


}