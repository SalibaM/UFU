#include <stdio.h>
#define pi 3.14

int volesfera (int raio,float volumeesfera,float cuboraio);

int main(){
    float raio,volumeesf,cuboraio;

    printf("Digite o valor do raio da esfera:");
    scanf("%f",&raio);

    volesfera(raio,volumeesf,cuboraio);

    return 0;

}
int volesfera (int raio,float volumeesfera,float cuboraio){

    cuboraio = raio*raio*raio;
    volumeesfera = (4*pi*cuboraio)/3;

    if(volumeesfera > 0){
        printf("Esse raio eh valido e o volume da esfera criado por ele sera %.2f m3",volumeesfera);
    } else {
        printf("Esse raio nao forma uma esfera valida. Portanto, seu volume nao existe.");

    }

    
    

}
