#include <stdio.h>
#include <stdlib.h>

#define F 20
#define C 10

void cargarMat(char mat[F][C],FILE* arch);
void imprimirMat(char mat[F][C]);
void cargarArr(char mat[F][C],char arr[F]);

int main(void){

    FILE* arch;
    char mat[F][C]={0}, arr[F]={0};
    arch = fopen("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/Parcialitos/codigo.txt","r");

    cargarMat(mat,arch);
    imprimirMat(mat);
    cargarArr(mat,arr);

    return 0;
}

void cargarMat(char mat[F][C],FILE* arch){

    int f,c,i=0;

    i = fgetc(arch);
    for ( f = 0; f < F-1 && i!=EOF; f++){
        for ( c = 0; c < C-1 && i!=EOF && i!='\n'; c++){
            mat[f][c] = i;
            i = fgetc(arch);
        }
        mat[f][c] = '\0';
        if (i!=EOF){
            i = fgetc(arch);
        }
    }
}

void imprimirMat(char mat[F][C]){
    int j;

    for (j = 0; j < mat[j][j]!='\0'; j++){
        printf("%s\n",mat[j]);
    }
}

void cargarArr(char mat[F][C],char arr[F]){
    int e;

    for ( e = 0; mat[e][e]!='\0' ; e++){
        arr[e] = mat[e][e];
    }

    printf("\n");
    printf("%s",arr);

}
