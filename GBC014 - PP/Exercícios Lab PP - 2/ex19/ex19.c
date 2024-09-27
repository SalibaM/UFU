#include <stdio.h>

int main(){
    
    int num,div1,div2;

    printf("Digite um numero inteiro:");
    scanf("%d",&num);

    div1 = num % 3;
    div2 = num % 5;

    if(div1==0){
        printf("Esse numero eh divisivel por 3");
    } else {
        if(div2==0){
            printf("Esse numero eh divisivel por 5");
        } else {
            printf("Esse numero nao eh divisivel nem por 3, nem por 5.");
        }
    }
    return 0;

}