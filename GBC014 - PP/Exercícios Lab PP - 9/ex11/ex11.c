#include <stdio.h>

int encontrarMaior(int array[], int tamanho) {
    int maior = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

int main() {
    int N, k;
    printf("Digite o tamanho do array (N): ");
    scanf("%d", &N);

    int array[N];
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    printf("Digite o número de elementos por linha (k): ");
    scanf("%d", &k);

    printf("Array com %d elementos por linha:\n", k);
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % k == 0) {
            printf("\n");
        }
    }

    int maior = encontrarMaior(array, N);
    printf("\nMaior elemento: %d\n", maior);

    return 0;
}
