#include <stdio.h>

int main(){

    int anoinicial;
    double aumento,taxaaumento,salario;
    
    anoinicial = 1995;
    salario = 2000;
    taxaaumento = 1.5;


    while(anoinicial <= 2023){
        aumento = salario * (taxaaumento/100);
        salario += aumento;
        taxaaumento *= 2;
        anoinicial++;
        
    }
    printf("O salario atual dele eh :%.2lf",salario);
    return 0;



}