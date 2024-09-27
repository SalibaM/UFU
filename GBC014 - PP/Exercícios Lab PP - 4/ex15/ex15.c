#include <stdio.h>

float formacao (float a, float b, float c, float resultado, float soma1, float soma2, float soma3);
float tipot (float a, float b, float c,float tipo);

int main(){

    float a,b,c,resultado,tipo,soma1,soma2,soma3;

    printf("Digite os valores dos lados de um triangulo:\n");
    scanf("%f%f%f",&a,&b,&c);

    if((formacao(a,b,c,resultado,soma1,soma2,soma3)==1) || (formacao(a,b,c,resultado,soma1,soma2,soma3)==2) || (formacao(a,b,c,resultado,soma1,soma2,soma3)==3)){
        printf("Esses valores de lado nao formam um triangulo.\n");
    } else {
        if((tipot(a,b,c,tipo))==1){
        printf("Esses valores de lado formam um triangulo.\n");
        printf("Esse triangulo eh equilatero.");
    } else {
        if((tipot(a,b,c,tipo))==2){
            printf("Esses valores de lado formam um triangulo.\n");
            printf("Esse triangulo eh escaleno.");
        } else {
            if((tipot(a,b,c,tipo))==3){
                printf("Esses valores de lado formam um triangulo.\n");
                printf("Esse triangulo eh isosceles.");
            }
        }
    }
}

    return 0;

}

float formacao (float a, float b, float c, float resultado, float soma1, float soma2, float soma3){
    soma1 = a+b;
    soma2 = a+c;
    soma3 = b+c;
    if(c>soma1){
        return 1;
    } else{
        if(b>soma2){
        return 2;
    } else {
        if(a>soma3){
            return 3;
        }
    }
  }
} 
float tipot (float a, float b, float c,float tipo){
    if((a==b) && (a==c) && (b==c)){
        return 1;
    }else{
        if((a!=b) && (a!=c) && (b!=c)){
            return 2;
        } else {
            if((a==b) || (a==c) || (b==c)){
                return 3;
            }
        }
        

    }
}