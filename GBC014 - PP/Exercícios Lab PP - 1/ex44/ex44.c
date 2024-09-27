#include <stdio.h>

int main(){
    float altdegrau;
    float alttotal;
    int qntddegrau;

    printf("Digite a altura do degrau de uma escada:");
    scanf("%f",&altdegrau);

    printf("Digite a altura que voce deseja alcancar ao subir a escada:");
    scanf("%f",&alttotal);

    qntddegrau = alttotal/altdegrau;

    printf("A quantidade de degraus que voce precisara subir eh:%d",qntddegrau);

    return 0;

}