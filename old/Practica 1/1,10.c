#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define C 100

void cargarMatDeArch(FILE* arch);

void main(){
    FILE* arch;
    arch = fopen("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/Practica 1/equipos.txt","r");
    cargarMatDeArch(arch);

}

void cargarMatDeArch(FILE* arch){
    
    //int c=0;
    //char arr[C]={0};
    //int i,j=0;
    char matriz[10][C], l;
    for (int i = 0; l != EOF; i++){
        l = fgetc(arch);
        for (int j = 0; l != '\r' && l != EOF; j++){
            matriz[i][j] = l;
            l = fgetc(arch);
        }
        printf("%s\n", matriz[i]);
    }
    /*
    if (arch!= NULL){
        c = fgetc(arch);
        while (c!=EOF){
            for (i = 0; i < C && c!='\n'; i++){
                arr[i] = c;
                c = fgetc(arch);
            }
            arr[i] = '\n';
            strcpy(matriz[j],arr);
            j++;
            c = fgetc(arch);
            char arr[C]={0};
        }
    */
        
        /*
        c = fgetc(arch);
        while (c!=EOF){
            while (c!='\n' && c!=EOF){
                matriz[i][j] = c;
                c = fgetc(arch);
                j++;
            }
            matriz[i][j] = '\0';
            i++;
            c = fgetc(arch);
        }
        fclose(arch);
    */

}
