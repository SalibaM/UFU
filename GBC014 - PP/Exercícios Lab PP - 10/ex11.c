#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char sobrenome[50];
    int anoNascimento;
} Aluno;

int main() {
    int numAlunos, i;
    Aluno* alunos;

    printf("Digite o numero de alunos a serem cadastrados: ");
    scanf("%d", &numAlunos);

    alunos = (Aluno*)malloc(numAlunos * sizeof(Aluno));

    if (alunos == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    for (i = 0; i < numAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &(alunos[i].matricula));

        printf("Sobrenome: ");
        scanf("%s", alunos[i].sobrenome);

        printf("Ano de Nascimento: ");
        scanf("%d", &(alunos[i].anoNascimento));
    }

    printf("\nDados dos alunos cadastrados:\n");
    for (i = 0; i < numAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Sobrenome: %s\n", alunos[i].sobrenome);
        printf("Ano de Nascimento: %d\n", alunos[i].anoNascimento);
    }

    free(alunos);

    return 0;
}
