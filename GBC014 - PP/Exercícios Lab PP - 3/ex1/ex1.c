#include <stdio.h>
#include <stdlib.h>

int main(){

    int num1,mult1;

    mult1=1;
    num1=0;

    while(mult1<=5){
        num1 = 3 * mult1;
        mult1++;
        printf("%d, ",num1);

    }
    return 0;

}
