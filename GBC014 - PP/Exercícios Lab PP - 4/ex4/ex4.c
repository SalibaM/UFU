#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void verificacao (int num);


int main(){
    int num;
    printf("Digite um numero:");
    scanf("%d",&num);

    verificacao(num);
    return 0;



}
void verificacao (int num){
    float num2;
    int num3;
    num2 = sqrt(num);
    num3 = sqrt(num);
    if(num2==num3){
        printf("Esse numero eh um quadrado perfeito!");
    } else {
        printf("Esse numero nao eh um quadrado perfeito!");
    }



}