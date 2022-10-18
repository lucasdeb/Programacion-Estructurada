#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 10
#define C 30

void cargarMatDeArch(char nomArch[100], char mat[F][C]);
void imprimirMat(char mat[F][C]);
void ordenarMat(char mat[F][C]);
void imprimirMat(char mat[F][C]);

int main(void){
    char mat[F][C] = {0};
    char nomArch[100] = "/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/equipos.txt";
    cargarMatDeArch(nomArch, mat);
    imprimirMat(mat);
    printf("\nLa Matriz Ordenada: \n");
    ordenarMat(mat);
    imprimirMat(mat);
}

void imprimirMat(char mat[F][C]){
    for (int i = 0;(i<F) && (mat[i][0]!=0); i++){ 
        printf("%s\n", mat[i]);
    }
}

void cargarMatDeArch(char nomArch[100], char mat[F][C])
{
    int i=0, r; //inicializado en 0
    FILE *arch;

    arch = fopen(nomArch, "r");

    r = fscanf(arch, "%[^\n]\n", mat[i]); //saca todos los datos menos el \n
    for (i = 1;!feof(arch); i++){ //una vez que lei la primer linea pasa a la segunda linea (inicializar for loop en 1)
        r = fscanf(arch, "%[^\n]\n", mat[i]);
    }
    mat[i][0]='\0';
    fclose(arch);
}

void ordenarMat(char mat[F][C]){

    char temp[30]={0};
    for (int i = 0; i < F; i++){
        for (int j = i+1; (j < C) && (mat[j][0]!='\0'); j++){
            if (strcmp(mat[i],mat[j])>0){
                strcpy(temp, mat[i]);
                strcpy(mat[i],mat[j]);
                strcpy(mat[j],temp);
            }
        }
    }
}