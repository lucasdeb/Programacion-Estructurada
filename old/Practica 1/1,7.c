#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define F 3
#define C 3

void cargarMat(int mat[F][C]);
void imprimirMat(int mat[F][C]);
float promMat(int mat[F][C]);

void main(){
    int mat[F][C];

    cargarMat(mat);
    imprimirMat(mat);
    printf("%f",promMat(mat));
    
}

void cargarMat(int mat[F][C]){
    int i = 0,j = 0,e;
    for (i=0;i<F;i++){
        for (j=0;j<C;j++){
            printf("[%d][%d]: ",i,j);
            scanf("%d",&e);
            mat[i][j]=e;
        }
        
    }
    
    
}

void imprimirMat(int mat[F][C]){
    int i = 0,j = 0;
    for (i=0;i<F;i++){
        for (j=0;j<C;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

float promMat(int mat[F][C]){
    int i = 0,j = 0;
    int prom = 0;
    for (i=0;i<F;i++){
        for (j=0;j<C;j++){
            prom += mat[i][j];
        }
    }
    return prom/(F*C);
}