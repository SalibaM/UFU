#include <stdio.h>

int expoentetotal (int x,int z,int contador,int result);

int main(){

    int x,z,contador,result;

    printf("Digite o valor da base e do expoente,respectivamente:");
    scanf("%d%d",&x,&z);

    printf("O valor dessa exponenciacao sera %d",expoentetotal(x,z,contador,result));



}
int expoentetotal (int x,int z,int contador,int result){
    result = 1;
    for(contador=0;contador<z;contador++){
        result = result*x;
    }
    return result;
}