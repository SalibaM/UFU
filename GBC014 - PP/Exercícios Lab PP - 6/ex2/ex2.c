#include <stdio.h>
#include <string.h>

struct dados{
    char nome[200];
    int idade;
    char rua[200];
    int numerocasa;
};

int main(){

    struct dados a;
    
    printf("Digite seu nome:\n");
    setbuf(stdin, NULL);
    fgets(a.nome,200,stdin);
    a.nome[strcspn(a.nome, "\n")] = 0;

    printf("Digite sua idade:\n");
    scanf("%d",&a.idade);

    printf("Digite o nome da sua rua,e em seguida,o numero da mesma:\n");
    setbuf(stdin, NULL);
    fgets(a.rua,200,stdin);
    a.rua[strcspn(a.rua, "\n")] = 0;
    scanf("%d",&a.numerocasa);

    printf("Seu nome eh %s,voce tem %d anos e mora na rua %s,%d",a.nome,a.idade,a.rua,a.numerocasa);
    







    return 0;
}