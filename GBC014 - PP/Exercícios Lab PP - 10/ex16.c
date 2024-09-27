#include <stdio.h>

int main() {
    int N, M;

    scanf("%d", &N);
    scanf("%d", &M);

    int matriz[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int matriz_transposta[M][N];

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            matriz_transposta[j][i] = matriz[i][j];
        }
    }

    printf("Matriz original:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Matriz transposta:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz_transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
