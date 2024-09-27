#include <stdio.h>
#include <stdlib.h>

int sinal (int num);


int main(){
    int num;
    printf("Digite um numero:");
    scanf("%d",&num);

    sinal(num);
    printf("%d",sinal(num));
    return 0;

}
int sinal (int num){
    if(num>0){
        return 1;

    } else {
        if(num<0){
            return -1;
        } else{
            return 0;

        }

    }


}