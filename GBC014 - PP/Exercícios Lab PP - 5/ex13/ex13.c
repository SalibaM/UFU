#include <stdio.h>

int main(){

    int mat[10][10];
    int i,j,quadradoi,quadradoj,cuboi;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(i<j){
                mat[i][j] = (2*i)+(7*j);
            } else {
                if(i==j){
                    quadradoi=i*i;
                    mat[i][j]=(3*quadradoi) - 1;
                } else {
                    if(i>j){
                        quadradoj=j*j;
                        cuboi=i*i*i;
                        mat[i][j]= (4*cuboi) - (5*quadradoj);
                    }
                }
            }
        }
    }

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ",mat[i][j]);
        }
        if(j==10){
            printf("\n");
        }
    }



    
    return 0;
}