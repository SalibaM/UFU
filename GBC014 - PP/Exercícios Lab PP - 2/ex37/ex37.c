#include <stdio.h>
#include <math.h>

int main() {

    int chegadah, chegadam, partidah, partidam,chegadamin,partidamin,estacionado; 
    float preco;

    printf("Digite a hora e os minutos de chegada, respectivamente: ");
    scanf("%d %d", &chegadah, &chegadam);
    printf("Digite a hora e os minutos da partida, respectivamente: ");
    scanf("%d %d", &partidah, &partidam);

    chegadamin = chegadah * 60 + chegadam;
    partidamin = partidah * 60 + partidam;

    if (partidamin <= chegadamin) {
        partidamin += 24 * 60;
    }

    estacionado = ceil((partidamin - chegadamin) / 60.0);

    if (estacionado <= 2) {
        preco = estacionado * 100;
    } else if (estacionado <= 4) {
        preco = 200 + (estacionado - 2) * 140;
    } else {
        preco = 480 + (estacionado - 4) * 200;
    }

    printf("O preco a pagar eh: %0.2f", preco / 100.0);

    return 0;
}