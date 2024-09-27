#include <stdio.h>

int main(){

    int ano;
    float alturachico,alturaze;
    
    alturachico = 1.50;
    alturaze = 1.10;
    ano = 0;

    while(alturaze<alturachico){
        alturachico += 0.02;
        alturaze += 0.03;
        ano++;
    }

    printf("A quantidade de anos necessarios para Ze ser maior que Chico (ultrapassar) sera: %d",ano);
    return 0;






}