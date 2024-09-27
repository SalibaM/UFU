#include <stdio.h>

void localizarTresMaiores(int matriz[][100], int linhas, int colunas) {
    int maiores[3] = {0};
    int linha[3] = {0};
    int coluna[3] = {0};

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int numero = matriz[i][j];
            for (int k = 0; k < 3; k++) {
                if (numero > maiores[k]) {
                    for (int l = 2; l > k; l--) {
                        maiores[l] = maiores[l - 1];
                        linha[l] = linha[l - 1];
                        coluna[l] = coluna[l - 1];
                    }
                    maiores[k] = numero;
                    linha[k] = i;
                    coluna[k] = j;
                    break;
                }
            }
        }
    }

    printf("Os tres maiores numeros sao:\n");
    for (int i = 0; i < 3; i++) {
        printf("Numero: %d\n", maiores[i]);
        printf("Localizado na linha: %d\n", linha[i]);
        printf("Localizado na coluna: %d\n\n", coluna[i]);
    }
}

int main() {
    int N, M;
    int matriz[100][100];

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &N);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &M);

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    localizarTresMaiores(matriz, N, M);

    return 0;
}
