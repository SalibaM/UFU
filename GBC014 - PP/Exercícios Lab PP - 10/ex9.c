#include <stdio.h>
#include <stdlib.h>

int main() {
    int* numeros = NULL;
    int capacidade = 0;
    int tamanho = 0;

    int num;
    printf("Digite os numeros (digite um numero negativo para parar): \n");

    while (1) {
        scanf("%d", &num);

        if (num < 0) {
            break;
        }

        if (tamanho == capacidade) {
            capacidade = (capacidade == 0) ? 1 : capacidade * 2;
            numeros = (int*)realloc(numeros, capacidade * sizeof(int));
        }

        numeros[tamanho] = num;
        tamanho++;
    }

    printf("\nNumeros lidos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }

    free(numeros);

    return 0;
}
