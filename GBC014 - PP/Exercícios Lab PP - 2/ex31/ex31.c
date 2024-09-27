#include <stdio.h>

int main(){

    float altura,peso;

    printf("Digite sua altura: ");
    scanf("%f",&altura);
    printf("Digite seu peso: ");
    scanf("%f",&peso);

    if((altura<1.20) && (peso<60)){
        printf("Classe A");
    } else{
        if((altura<1.20) && (peso>=60 && peso<=90)){
            printf("Classe D");
        } else {
            if((altura<1.20) && (peso>90)){
                printf("Classe G");
            } else {
                if((altura>=1.20 && altura<=1.70) && (peso<60)){
                    printf("Classe B");
                } else {
                    if((altura>=1.20 && altura<=1.70) && (peso>=60 && peso<=90)){
                        printf("Classe E");
                    } else {
                        if((altura>=1.20 && altura<=1.70) && (peso>90)){
                            printf("Classe H");
                        } else {
                            if((altura>1.70) && (peso<60)){
                                printf("Classe C");
                            } else {
                                if((altura>1.70) && (peso>=60 && peso<=90)){
                                    printf("Classe F");
                                } else {
                                    if((altura>1.70) && (peso>90)){
                                        printf("Classe I");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }

    return 0;

}