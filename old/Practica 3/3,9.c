#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* leerArch(const char * nomArch);
char * subcadena(char * p, int i, int n);

char* leerArch(const char * nomArch){
    FILE *f = fopen(nomArch, "r");
    char *cad = NULL;
    cad = (char*)malloc(sizeof(char));
    while (!feof(f)){
        char aux = fgetc(f);
        cad = (char*)realloc(cad, sizeof(char)*(strlen(cad)+1));
        cad[strlen(cad)] = aux;
    }
    cad[strlen(cad)] = '\0';
    fclose(f);
    return cad;
}

char * subcadena(char * p, int i, int n){
    char *cad = NULL;
    cad = (char*)malloc(sizeof(char));
    int j = 0;
    while (j < n){
        cad = (char*)realloc(cad, sizeof(char)*(strlen(cad)+1));
        cad[strlen(cad)] = p[i];
        i++;
        j++;
    }
    cad[strlen(cad)] = '\0';
    return cad;
}

int main(){
    char* str = NULL;
    char* subStr = NULL;
    int i = 8, n = 5;
    str = leerArch("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/Practica 3/frase.txt");
    subStr = subcadena(str, i, n);
    printf("Para i = %d y n = %d, Se encontro el substring: ",i,n);
    printf("%s", subStr);
    return 0;
}