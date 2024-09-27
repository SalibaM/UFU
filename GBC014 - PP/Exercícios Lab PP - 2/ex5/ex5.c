#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
   int x;
   printf("Digite um numero inteiro:");
   scanf("%d",&x);

   if(x%2==0){
      printf("Esse numero eh par.");
   }else{
       printf("Esse numero eh impar.");
    }

   return 0;
}