#include <stdio.h>

int main(){
    float comprimento;
    float comprimento2x;
    float largura;
    float largura2x;
    float pmetrotela;
    float medidaperimetro;
    float custo;

    printf("Digite o valor do comprimento do terreno:");
    scanf("%f",&comprimento);

    printf("Digite o valor da largura do terreno:");
    scanf("%f",&largura);

    printf("Digite o valor do preco do metro de tela:");
    scanf("%f",&pmetrotela);

    comprimento2x = comprimento*2;
    largura2x = largura*2;
    medidaperimetro = comprimento2x + largura2x;
    custo = medidaperimetro * pmetrotela;

    printf("O custo para cercar esse terreno com tela eh:%f",custo);

    return 0;


}