#include <stdio.h>
#include <stdlib.h>

#define F 5
#define C 5

void cargarMat(int mat[F][C]);
void imprimirMat(int mat[F][C]);
void transponer(int mat[F][C]);

void main(){
    int mat[F][C];

    cargarMat(mat);
    imprimirMat(mat);
    transponer(mat);
    printf("\n");
    imprimirMat(mat);

}

void cargarMat(int mat[F][C]){
    int aux;

    for (int i = 0; i < F; i++){
        for (int j = 0; j < C; j++){
            printf("[%d][%d]: ",i,j);
            scanf("%d",&aux);
            mat[i][j] = aux;
        }
    }
}

void imprimirMat(int mat[F][C]){
    for (int i = 0; i < F; i++){
        for (int j = 0; j < C; j++){
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}

void transponer(int mat[F][C]){
    int aux;

    for (int i = 0; i < F; i++){
        for (int j = 0; j < C; j++){
            if (i!=j&&j>i){
                aux = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = aux;
            }
        }
        
    }
    
}