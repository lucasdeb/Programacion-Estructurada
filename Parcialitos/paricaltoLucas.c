//Ordenar matriz cargada por un archivo que contiene palabras en orden desdendiente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 30
#define C 30

void imprimirMat(char mat[F][C]);
void cargarMat(char mat[F][C], FILE* fp);
void ordenarMat(char mat[F][C]);

void main(){
    char mat[F][C]={0};
    FILE* fp;
    fp = fopen("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/Parcialitos/parcialitoLucas.txt","r");

    cargarMat(mat,fp);
    imprimirMat(mat);
    ordenarMat(mat);
    imprimirMat(mat);
    printf("hola");
}

void cargarMat(char mat[F][C], FILE* fp){
    int f,c,l=0;

    l = fgetc(fp);
    for (f = 0;l!=EOF; f++){
        for (c = 0; l != '\n' && l != EOF; c++){
            mat[f][c] = l;
            l = fgetc(fp);

        }
        mat[f][c]='\0';
        l = fgetc(fp);
        
    }
    mat[f][0]='\0';
}

void imprimirMat(char mat[F][C]){
    int i;

    for ( i = 0; i<F-1 && mat[i][0]!='\0'; i++){
        printf("%s\n",mat[i]);
    }
    printf("\n");
}

void ordenarMat(char mat[F][C]){
    char temp[F];
    
    for (int i = 0;mat[i][0]!='\0'; i++){
        for (int j = i+1; mat[j][0]!='\0'; j++){
            if(strcmp(mat[i],mat[j])<0){
                strcpy(temp,mat[i]);
                strcpy(mat[i],mat[j]);
                strcpy(mat[j],temp);
            }
        }
    }
}