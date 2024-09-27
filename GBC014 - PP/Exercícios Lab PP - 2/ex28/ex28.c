#include <stdio.h>
#include <math.h>

int main(){

    int opcao;
    float x,y,z,mult,mult1,mult2,mult3,somamult,div1,div2,div3,somadiv,somapadrao,geo,pond,harm,arit;

    printf("Escolha uma das opcoes de media:\n(1) Geometrica\n(2) Ponderada\n(3) Harmonica\n(4) Aritmetica\n-Opcao:");
    scanf("%d",&opcao);

    printf("Digite os tres numeros inteiros positivos para calcular a media selecionada:");
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);

    if(opcao==1){
        mult = x*y*z;
        geo = cbrt(mult);
        printf("A media geometrica desses tres numeros eh: %0.2f",geo);
    } else {
        if(opcao==2){
            mult1 = 1*x;
            mult2 = 2*y;
            mult3 = 3*z;
            somamult = mult1 + mult2 + mult3;
            pond = somamult / 3;
            printf("A media ponderada desses tres numeros eh: %0.2f",pond);

        } else {
            if(opcao==3){
                div1 = 1.0/x;
                div2 = 1.0/y;
                div3 = 1.0/z;
                somadiv = div1 + div2 + div3;
                harm = 1 / somadiv;
                printf("A media harmonica desses tres numeros eh: %0.2f", harm);
            } else {
                if(opcao==4){
                    somapadrao = x+y+z;
                    arit = somapadrao / 3;
                    printf("A media aritmetica desses tres numeros eh: %0.2f",arit);
                } else {
                    printf("Digite uma opcao valida.");
                }
            }
        }
    }
    return 0;

}