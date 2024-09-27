#include <stdio.h>
#include <stdlib.h>

int main(){

    int num,num2;

    num=0;
    num2=0;

    while(num2<100000){
        num2 = num + 1000;
        printf("%d ",num2);
        num = num2;
    }
    return 0;
}