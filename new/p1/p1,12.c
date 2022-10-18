#include <stdio.h>
#include <stdlib.h>

#define F 20
#define C 20
#define TERM_INT -99

void cargarMatDeNumArch(char nomArch[100], int mat[F][C]);
void imprimirMat(int mat[F][C]);

int main(void){
    int mat[F][C]={0};
    char nomArch[100] = "/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/puntos.txt";

    cargarMatDeNumArch(nomArch,mat);
    imprimirMat(mat);

}

void cargarMatDeNumArch(char nomArch[100], int mat[F][C]){
    int i=0,r;
    FILE* arch = fopen(nomArch,"r");

    r = fscanf(arch,"%d, %d, %d, %d, %d, %d, %d, %d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
    mat[i][8]=TERM_INT;

    for (i = 1; !feof(arch) && i<F-1; i++){
        r = fscanf(arch,"%d, %d, %d, %d, %d, %d, %d, %d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
        mat[i][8]=TERM_INT;
    }
    mat[i][0]=TERM_INT;
}

void imprimirMat(int mat[F][C]){
    for (int i = 0;i<F && mat[i][0]!=TERM_INT; i++){
        for (int j = 0; j<C && mat[i][j]!=TERM_INT; j++){
            if (j == 7 && mat[i][7]>0){
                printf("%+5d", mat[i][j]);
            }
            else{
                printf("%5d", mat[i][j]);
            }
        }
        printf("\n");
    }
}