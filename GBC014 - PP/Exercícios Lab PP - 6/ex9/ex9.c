#include <stdio.h>
#include <math.h>

struct complexos {

    int real,imaginaria;
    int realb,imaginariab;
    int somareal,somaimaginaria,subreal,subimaginaria,produto;
    float mod1,mod2;
    int produtoreal,produtoimag;

};

int main(){

    struct complexos a;

    printf("Digite a parte real e imaginaria do primeiro numero complexo:\n");
    scanf("%d%d",&a.real,&a.imaginaria);

    printf("Digite a parte real e imaginaria do segundo numero complexo:\n");
    scanf("%d%d",&a.realb,&a.imaginariab);

    a.somareal = a.real+a.realb;
    a.somaimaginaria = a.imaginaria+a.imaginariab;

    printf("O resultado da soma desses dois numeros imaginarios sera:%d + (%d)i\n",a.somareal,a.somaimaginaria);
    
    a.mod1 = sqrt(((a.real)*(a.real))+((a.imaginaria)*(a.imaginaria))); 
    a.mod2 = sqrt(((a.realb)*(a.realb))+((a.imaginariab)*(a.imaginariab))); 

    printf("O modulo do primeiro numero complexo sera: %.2f\n",a.mod1);
    printf("O modulo do segundo numero complexo sera: %.2f\n",a.mod2);

    a.produtoreal = (a.real*a.realb) + (((a.imaginaria*a.imaginariab)*-1));
    a.produtoimag = (a.real*a.imaginariab) + (a.imaginaria*a.realb);

    printf("O resultado do produto sera:%d + (%d)i\n",a.produtoreal,a.produtoimag);

    

    return 0;
}