#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 3
#define C 10

void cargarMat(char mat[F][C]);
void imprimirMat(char mat[F][C]);
void ordenarMat(char mat[F][C]);

void main(){
    char mat[F][C];

    cargarMat(mat);
    imprimirMat(mat);
    ordenarMat(mat);
    printf("\n");
    imprimirMat(mat);

}

void cargarMat(char mat[F][C]){
    int i,j;
    char aux;

    for (i = 0; i < F; i++){
        printf("[%d]: ",i);
        aux = getchar();
        for (j = 0; j < C && aux!='\n'; j++){
            mat[i][j] = aux;
            fflush(stdin);
            aux = getchar();
        }
        mat[i][j] = '\0';
    }
}

void imprimirMat(char mat[F][C]){
    for (int i = 0; i < F; i++){
        printf("%s",mat[i]);
        printf("\n");
    }
}

void ordenarMat(char mat[F][C]){
    int result;
    char aux[C];

    for (int i = 0; i < F; i++){
        for (int j = i+1; j < C; j++){
            result = strcmp(mat[i],mat[j]);
            if (result>0){
                strcpy(aux,mat[j]);
                strcpy(mat[j],mat[j+1]);
                strcpy(mat[j+1],aux);
            }
        }
    }
}