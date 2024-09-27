#include <stdio.h>

int main(){
    float valort;
    float q1col;
    float q2col;
    float q3col;

    printf("Digite a quantidade de 780 mil do premio do concurso:");
    scanf("%f",&valort);

    q1col = 0.46*valort;
    q2col = 0.32*valort;
    q3col = 0.22*valort;

    printf("As quantias ganhas pelo primeiro, segundo e terceiro colocado, respectivamente, sao %f, %f e %f",q1col,q2col,q3col);

    return 0;


}
