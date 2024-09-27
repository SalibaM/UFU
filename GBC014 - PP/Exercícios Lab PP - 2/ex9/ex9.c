#include <stdio.h>

int main(){
    float salario;
    float pemprestimo;

    printf("Digite o valor do seu salario:");
    scanf("%f",&salario);

    printf("Digite o valor da prestacao que voce quer como emprestimo:");
    scanf("%f",&pemprestimo);

    if(pemprestimo > 0.2 * salario){
       printf("Emprestimo nao concedido.");
    } else{
        printf("Emprestimo concedido");
        

    }

    return 0;
}