#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F 3
#define C 3

void transponer(int mat[F][C]);
void cargarMat(int mat[F][C]);
void imprimirMat(int mat[F][C]);




void main(){
    int mat[F][C];

    cargarMat(mat);
    imprimirMat(mat);
    transponer(mat);
    imprimirMat(mat);

    
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

void transponer(int mat[F][C]){
    int aux,f,c;
    for (f=0;f<F;f++){
        for (c=0;c<C;c++){
            if(f!=c&&c>f){
                aux = mat[f][c];
                mat[f][c] = mat[c][f];
                mat[c][f] = aux;
            }
        }
    }
}