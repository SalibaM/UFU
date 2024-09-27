#include <stdio.h>
int verificacao(float num1,float num2);

int main(){
    float num1,num2;
    printf("Digite o valor do primeiro e do segundo numero,respectivamente:\n");
    scanf("%f%f",&num1,&num2);

    if(verificacao(num1,num2)==1){
        printf("O maior numero sera %.2f",num1);
    } else {
        printf("O maior numero sera %.2f",num2);
    }

    return 0;

}
int verificacao (float num1,float num2){
    if(num1>num2){
        return 1;
    } else {
        return 0;
    }
}