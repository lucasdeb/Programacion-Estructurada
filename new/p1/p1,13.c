#include <stdio.h>
#include <stdlib.h>

#define F 50
#define C 50
#define TERM_STR '\0'
#define TERM_INT -99

void cargarMatEquipos(char nomArch[100], matEquipos[F][C]);
void cargarMatDatos(char nomArch[100], int matDatos[F][C]);
void cargarMatTitulos(char nomArch[100], matTitulos[F][C]);
void imprimirTabla(char matTitulos[F][C]);

int main(void){
    char matEquipos[F][C], matTitulos[F][C];
    int matDatos[F][C], ord, col;

    cargarMatDatos("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/puntos.txt", matDatos);
    cargarMatEquipos("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/equipos.txt", matEquipos);
    cargarMatTitulos("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/titulo.txt", matTitulos);

    imprimirTabla(matTitulos);
}

void cargarMatDatos(char nomArch[100], int matDatos[F][C]){
    int i=0, r;
    
    FILE* arch = fopen(nomArch, "r");

    r = fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d, %d\n", &matDatos[i][0], &matDatos[i][1],&matDatos[i][2],&matDatos[i][3],&matDatos[i][4],&matDatos[i][5],&matDatos[i][6],&matDatos[i][7]);
    matDatos[i][8] = TERM_INT;

    for (i = 1; (!feof(arch)) && (i<F-1); i++){
        r = fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d, %d\n", &matDatos[i][0], &matDatos[i][1],&matDatos[i][2],&matDatos[i][3],&matDatos[i][4],&matDatos[i][5],&matDatos[i][6],&matDatos[i][7]);
        matDatos[i][8] = TERM_INT;
    }
    matDatos[i][0]=TERM_INT;
    
    fclose(arch);
}

void cargarMatEquipos(char nomArch[100], matEquipos[F][C]){
    int i=0, r; //inicializado en 0
    FILE *arch;

    arch = fopen(nomArch, "r");

    r = fscanf(arch, "%[^\n]\n", &matEquipos[i]); //saca todos los datos menos el \n
    for (i = 1;(!feof(arch)) && (i<F-1); i++){ //una vez que lei la primer linea pasa a la segunda linea (inicializar for loop en 1)
        r = fscanf(arch, "%[^\n]\n", &matEquipos[i]);
    }
    matEquipos[i][0]=TERM_STR;
    fclose(arch);
}

void cargarMatTitulos(char nomArch[100], matTitulos[F][C]){
    int i=0, r; //inicializado en 0
    FILE *arch;

    arch = fopen(nomArch, "r");

    r = fscanf(arch, "%[^\n]\n", &matTitulos[i]); //saca todos los datos menos el \n
    for (i = 1;(!feof(arch)) && (i<F-1); i++){ //una vez que lei la primer linea pasa a la segunda linea (inicializar for loop en 1)
        r = fscanf(arch, "%[^\n]\n", &matTitulos[i]);
    }
    matTitulos[i][0]=TERM_STR;
    fclose(arch);
    for (int j = 0; (j < F-1) && (matTitulos[j][0]!=TERM_STR); j++){
        printf("%6s",matTitulos[j]);
    }
}

void imprimirTabla(char matTitulos[F][C]){
    for (int j = 0;matTitulos[j][0]!='\0'; j++){
        printf("%6s",matTitulos[j]);
    }
    printf("\n---------------------------------------------------------------------\n");
}