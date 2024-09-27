#include <stdio.h>
#include <string.h>

struct aluno{
    char nome[200];
    int matricula;
    char curso[200];

};

int main(){

    struct aluno vet[5];
    int i;
    printf("Digite o nome,o numero de matricula,e o curso de 5 alunos,em ordem:\n");
    for(i=0;i<5;i++){
        setbuf(stdin, NULL);
        fgets(vet[i].nome,200,stdin);
        scanf("%d",&vet[i].matricula);
        setbuf(stdin, NULL);
        fgets(vet[i].curso,200,stdin);
        
    }

    printf("Os dados dos alunos sao:\n");
    for(i=0;i<5;i++){
        printf("Nome:%sNumero de matricula:%d\nCurso:%s\n",vet[i].nome,vet[i].matricula,vet[i].curso);
    }

    return 0;
}