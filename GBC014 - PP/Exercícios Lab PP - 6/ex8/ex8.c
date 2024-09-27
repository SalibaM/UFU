#include <stdio.h>

struct dados{

    char nome[50];
    int idade;
    char sexo;
    int cpf;
    int dia,mes,ano;
    int codsetor;
    char cargo[30];
    int salario;
};

int main(){

    struct dados a;

    printf("Digite o primeiro nome:\n");
    fgets(a.nome,50,stdin);
    setbuf(stdin, NULL);

    printf("Digite a idade:\n");
    setbuf(stdin, NULL);
    scanf("%d",&a.idade);

    printf("Digite o sexo ( M ou F ):\n");
    setbuf(stdin, NULL);
    scanf("%c",&a.sexo);

    printf("Digite o CPF:\n");
    setbuf(stdin, NULL);
    scanf("%d",&a.cpf);

    printf("Digite o dia,mes e ano do nascimento, respectivamente e separadamente:\n");
    setbuf(stdin, NULL);
    scanf("%d%d%d",&a.dia,&a.mes,&a.ano);

    printf("Digite o codigo de setor (0-99):\n");
    setbuf(stdin, NULL);
    scanf("%d",&a.codsetor);

    printf("Digite o cargo que ocupa:\n");
    setbuf(stdin, NULL);
    fgets(a.cargo,30,stdin);

    printf("Digite o salario:\n");
    setbuf(stdin, NULL);
    scanf("%d",&a.salario);

    printf("Dados:\nNome:%s\nIdade:%d\nSexo:%c\nCPF:%d\nNascimento:%d/%d/%d\nCodigo do setor:%d\nCargo:%s\nSalario:%d\n.",a.nome,a.idade,a.sexo,a.cpf,a.dia,a.mes,a.ano,a.codsetor,a.cargo,a.salario);

   return 0;
}