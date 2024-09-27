#include <stdio.h>
#include <math.h>

int main(){
    int catA;
    int catB;
    int hip;
    int qcatA;
    int qcatB;
    int somaqcat;

    printf("Digite o valor do primeiro cateto:");
    scanf("%d",&catA);

    printf("Digite o valor do segundo cateto:");
    scanf("%d",&catB);

    qcatA = catA*catA;
    qcatB = catB*catB;
    somaqcat = qcatA + qcatB;
    hip = sqrt(somaqcat);


    printf("A hipotenusa desse triangulo eh:%d",hip);

    return 0;
    

}