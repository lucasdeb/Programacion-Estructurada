#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 10
#define C 30

void cargarMatDeArch(char nomArch[100], char mat[F][C]);
void imprimirMat(char mat[F][C]);

int main(void)
{
    char mat[F][C] = {0};
    char nomArch[100] = "/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/equipos.txt";
    cargarMatDeArch(nomArch, mat);
    imprimirMat(mat);
}

void imprimirMat(char mat[F][C]){
    for (int i = 0;(i<F) && (mat[i][0]!='\0'); i++){ 
        printf("%s", mat[i]);
    }
}

void cargarMatDeArch(char nomArch[100], char mat[F][C])
{
    int i=0;
    FILE *arch = fopen(nomArch, "r");
    
    while(!feof(arch)){
        if(fgets(mat[i],C,arch)!= NULL){
            i++;
        }
    }
    fclose(arch);
}