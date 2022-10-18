#include <stdio.h>
#include <stdlib.h>

#define F 3
#define C 3

void cargarMat(int mat[F][C]);
void prom(int mat[F][C]);
void imprimirMat(int mat[F][C]);

void main(){
    int mat[F][C];

    cargarMat(mat);
    imprimirMat(mat);
    prom(mat);
}

void cargarMat(int mat[F][C]){
    int num;
    for (int f = 0; f<F; f++){
        for (int c = 0; c<C; c++){
            printf("[%d][%d]: ",f,c);
            scanf("%d",&num);
            mat[f][c] = num;
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

void prom(int mat[F][C]){
    int prom=0;
    int c=0;
    for (int i = 0; i < F; i++){
        for (int j = 0; j < C; j++){
            prom+=mat[i][j];
            c++;
        }
    }
    prom = prom/c;
    printf("%d",prom);
}