#include <stdio.h>

float mediaarit (float nota1,float nota2,float nota3,float media);
float mediapond (float nota1,float nota2,float nota3,float media);

int main(){

    float nota1,nota2,nota3,media;
    char letraescolhida;
    printf("Digite as tres notas:\n");
    scanf("%f%f%f",&nota1,&nota2,&nota3);

    printf("Selecione uma letra(A ou P):\n");
    scanf(" %c",&letraescolhida);

    switch(letraescolhida){
        case 'A':
        printf("A media aritmetica entre essas tres notas sera %.2f",mediaarit(nota1,nota2,nota3,media));
        break;

        case 'P':
        printf("A media ponderada dessas notas, com peso 5,3 e 2, sera %.2f",mediapond(nota1,nota2,nota3,media));
        break;

        default:
        printf("A letra escolhida nao eh valida.");

    }
    return 0;

}
float mediaarit (float nota1,float nota2,float nota3,float media){
    media = ((nota1+nota2+nota3))/3;
    return media;
}
float mediapond (float nota1,float nota2,float nota3,float media){
    media = ((5*nota1)+(3*nota2)+(2*nota3))/10;
    return media;
}