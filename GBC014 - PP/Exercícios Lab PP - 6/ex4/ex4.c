#include <stdio.h>
#include <string.h>

struct aluno{
    char nome[200];
    int matricula;
    int nota1,nota2,nota3;
    int media;
};

int main(){

    struct aluno vet[5];
    int i=0,j=0,k=0,l=0;
    for (i = 0; i < 5; i++) {
        printf("Digite a matricula do aluno: ");
        scanf("%d", &vet[i].matricula);
        printf("Digite o nome do aluno: ");
        scanf("%s", vet[i].nome);
        printf("Digite a nota da primeira prova: ");
        scanf("%f", &vet[i].nota1);
        printf("Digite a nota da segunda prova: ");
        scanf("%f", &vet[i].nota2);
        printf("Digite a nota da terceira prova: ");
        scanf("%f", &vet[i].nota3);
    }

    for(i=0;i<5;i++){
        if(vet[i].nota1>vet[j].nota1){
            j = i;
        }
    }
    for (i=1;i<5;i++) {
        if ((vet[i].nota1 + vet[i].nota2 + vet[i].nota3) / 3 > (vet[k].nota1 + vet[k].nota2 + vet[k].nota3) / 3) {
            k = i;
        }
    }
    printf("A maior media geral foi do aluno %s\n",vet[k].nome);

    for (i=1;i<5;i++) {
        if ((vet[i].nota1 + vet[i].nota2 + vet[i].nota3) / 3 < (vet[l].nota1 + vet[l].nota2 + vet[l].nota3) / 3) {
            l = i;
        }
    }
    printf("A menor media geral foi do aluno %s\n",vet[l].nome);


    for(i=0;i<5;i++){
        if ((vet[i].nota1 + vet[i].nota2 + vet[i].nota3) / 3 >= 6) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }

    printf("A maior nota da primeira prova foi do aluno %s\n",vet[j].nome);

    return 0;
}