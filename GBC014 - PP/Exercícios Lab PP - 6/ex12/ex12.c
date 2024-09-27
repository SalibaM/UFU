#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Carta {
    char naipe;
    int valor;
};

int main() {
    struct Carta baralho[52] = {
        {'C', 1}, {'C', 2}, {'C', 3}, {'C', 4}, {'C', 5}, {'C', 6}, {'C', 7}, {'C', 8}, {'C', 9}, {'C', 10}, {'C', 11}, {'C', 12}, {'C', 13},
        {'O', 1}, {'O', 2}, {'O', 3}, {'O', 4}, {'O', 5}, {'O', 6}, {'O', 7}, {'O', 8}, {'O', 9}, {'O', 10}, {'O', 11}, {'O', 12}, {'O', 13},
        {'E', 1}, {'E', 2}, {'E', 3}, {'E', 4}, {'E', 5}, {'E', 6}, {'E', 7}, {'E', 8}, {'E', 9}, {'E', 10}, {'E', 11}, {'E', 12}, {'E', 13},
        {'P', 1}, {'P', 2}, {'P', 3}, {'P', 4}, {'P', 5}, {'P', 6}, {'P', 7}, {'P', 8}, {'P', 9}, {'P', 10}, {'P', 11}, {'P', 12}, {'P', 13}
    };

    struct Carta jogador1[3];
    struct Carta jogador2[3];

    int i, j;
    struct Carta temp;

    srand(time(NULL));

    for (i = 51; i > 0; i--) {
        j = rand() % (i + 1);
        temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }

    for (i = 0; i < 3; i++) {
        jogador1[i] = baralho[i];
        jogador2[i] = baralho[i + 3];
    }

    printf("Cartas do Jogador 1:\n");
    for (i = 0; i < 3; i++) {
        printf("Carta %d: %c%d\n", i + 1, jogador1[i].naipe, jogador1[i].valor);
    }

    printf("\nCartas do Jogador 2:\n");
    for (i = 0; i < 3; i++) {
        printf("Carta %d: %c%d\n", i + 1, jogador2[i].naipe, jogador2[i].valor);
    }

    return 0;
}
