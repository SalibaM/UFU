#include <stdio.h>

struct aluno{
    char nome[50];
    int matricula;
    float mediafinal;
};

int main() {
    struct aluno alunos[10];
    struct aluno aprovados[10];
    struct aluno reprovados[10];
    int numAprovados = 0;
    int numReprovados = 0;
    int i;

    for (i = 0; i<10; i++) {
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Media Final: ");
        scanf("%f", &alunos[i].mediafinal);
        printf("\n");
    }

    for (i=0;i<10;i++) {
        if (alunos[i].mediafinal >= 5.0) {
            aprovados[numAprovados] = alunos[i];
            numAprovados++;
        } else {
            reprovados[numReprovados] = alunos[i];
            numReprovados++;
        }
    }

    printf("Alunos aprovados:\n");
    for (i=0;i<numAprovados;i++) {
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s\n", aprovados[i].nome);
        printf("Matricula: %d\n", aprovados[i].matricula);
        printf("Media Final: %.2f\n", aprovados[i].mediafinal);
        printf("\n");
    }

    printf("Alunos reprovados:\n");
    for (i = 0; i < numReprovados; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s\n", reprovados[i].nome);
        printf("Matricula: %d\n", reprovados[i].matricula);
        printf("Media Final: %.2f\n", reprovados[i].mediafinal);
        printf("\n");
    }

    return 0;
}
