#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define F 10
#define C 10

void cargarMatDeArch(arch);

void main(){
    FILE* arch;
    arch = fopen("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/equipos.txt","r");
    cargarMatDeArch(arch);
    fclose(arch);
}

void cargarMatDeArch(arch){
    char mat[F][C],a;
    int i=0;

    if (arch!=NULL){
        a = (char)fgets(mat,C,arch);
        while(a!=EOF){
            printf("%s",mat);
            strcpy(mat[i],a);
            i++;
            a = (char)fgets(mat,C,arch);
        }
        mat[i][C]='\0';
    }
}