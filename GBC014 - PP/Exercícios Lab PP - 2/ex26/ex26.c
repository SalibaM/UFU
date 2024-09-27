#include <stdio.h>

int main(){

    float distancia,litros,kml;

    printf("Digite a distancia em km:");
    scanf("%f",&distancia);

    printf("Digite a quantidade de litros de gasolina consumidas pelo carro:");
    scanf("%f",&litros);

    kml = distancia/litros;

    if(kml < 8){
        printf("Venda o carro!");
    } else {
        if((kml >= 8) && (kml <= 14)){
            printf("Economico!");
        } else {
            if (kml > 14){
                printf("Super economico!");
            }
        }
      }
      return 0;

}