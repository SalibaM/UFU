#include <stdio.h>
float conversao(float tempcelsius, float tempfahren);

int main(){
    float tempcelsius,tempfahren;
    printf("Digite a temperatura em Celsius:");
    scanf("%f",&tempcelsius);

    printf("Essa temperatura em Fahrenheit sera:%.2f",conversao(tempcelsius,tempfahren));
    
    return 0;


}
float conversao (float tempcelsius, float tempfahren){
    tempfahren = tempcelsius * (9.0/5.0) + 32.0;
    return tempfahren;
}