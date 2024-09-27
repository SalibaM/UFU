#include <stdio.h>

float consumo (float distancia,float litros, float kml);

int main(){

    float distancia,litros,kml;
    printf("Digite a distancia em KM e a quantidade de litros consumidos pelo carro,respectivamente:");
    scanf("%f%f",&distancia,&litros);
  
    if(consumo(distancia,litros,kml)==1){
        printf("Venda o carro!");
    } else {
        if(consumo(distancia,litros,kml)==2){
            printf("Economico!");
        } else {
            if(consumo(distancia,litros,kml)==3){
                printf("Super economico!");
            }
        }
    }
    return 0;

}
float consumo (float distancia,float litros,float kml){
    kml = (distancia/litros);
    if(kml<8){
        return 1;
    } else {
        if((kml>=8) && (kml<14)){
            return 2;
        } else {
            if(kml>=14){
                return 3;
            }
        }
    }
}

