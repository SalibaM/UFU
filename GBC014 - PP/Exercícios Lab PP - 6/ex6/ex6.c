#include <stdio.h>

struct aluno{

    int mat,codis;
    float nota1,nota2,media;
    char nome[50];
    

};

int main(){

    struct aluno aluno[2];
    int i;

    for(i=0;i<10;i++){
        printf("Digite o numero de matricula do %d aluno:\n",i+1);
        scanf("%d",&aluno[i].mat);
        printf("Digite o nome do %d aluno:\n",i+1);
        scanf("%s",&aluno[i].nome);
        printf("Digite o codigo da disciplina:\n");
        scanf("%d",&aluno[i].codis);
        printf("Digite a primeira e a segunda nota do aluno %d:\n",i+1);
        scanf("%f%f",&aluno[i].nota1,&aluno[i].nota2);
    }

    for(i=0;i<10;i++){
        aluno[i].media = (aluno[i].nota1 + (2*aluno[i].nota2)) / 3;
        printf("A media final do aluno %s sera %.2f.\n",aluno[i].nome,aluno[i].media);
    }

    return 0;
}