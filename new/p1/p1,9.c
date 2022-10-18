#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 3
#define C 10

void cargarMat(char mat[F][C]);
void imprimirMat(char mat[F][C]);
void ordenarMat(char mat[F][C]);

int main(void){
    char mat[F][C];

    cargarMat(mat);
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
            aux = getchar();
        }
    }
    mat[i][0]='\0';
}

void imprimirMat(char mat[F][C]){
    for (int i = 0;(i<F) && (mat[i][0]!=0); i++){ 
        printf("%s\n", mat[i]);
    }
}

void ordenarMat(char mat[F][C]){
    char temp[30]={0};
    int i;
    for (i = 0; i < F; i++){
        for (int j = i+1; (j < C) && (mat[j][0]!='\0'); j++){
            if (strcmp(mat[i],mat[j])>0){
                strcpy(temp, mat[i]);
                strcpy(mat[i],mat[j]);
                strcpy(mat[j],temp);
            }
        }
    }
    mat[i][0]='\0';
}