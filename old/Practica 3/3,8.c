#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cad();
void cad1(char** p);
void escribirArch(const char* nom, char* cad);
void imprimirArch(const char* nom);

void escribirArch(const char* nom, char* cad){
    FILE* arch = fopen(nom, "w");
    fprintf(arch, "%s", cad);
    fclose(arch);
}

void imprimirArch(const char* nom){
    FILE *f = fopen(nom, "r");
    printf("Contenido del archivo: ");
    while (!feof(f))
    {
        char aux = fgetc(f);
        printf("%c", aux);
    }
    fclose(f);
}

char* cad(){
    char letra;
    char* arr = NULL;
    arr = (char*)malloc(sizeof(char));

    printf("Ingrese una cadena: ");
    if (arr == NULL){
        letra = getchar();
    }
    while (letra != '\n'){
        arr = (char*)realloc(arr, sizeof(char)*(strlen(arr)+1));
        letra = getchar();
        arr[strlen(arr)] = letra;
    }
    arr[strlen(arr)] = '\0';
    return arr;
}

void cad1(char** p){
    char letra;
    char* arr = NULL;
    arr = (char*)malloc(sizeof(char));

    printf("Ingrese una cadena: ");
    if (arr == NULL){
        letra = getchar();
    }
    while (letra != '\n'){
        arr = (char*)realloc(arr, sizeof(char)*(strlen(arr)+1));
        letra = getchar();
        arr[strlen(arr)] = letra;
    }
    arr[strlen(arr)] = '\0';
    *p = arr;
}

int main(){
    char* str = NULL;
    str = cad();
    //cad1(&str);
    printf("Arreglo dinamico: %s",str);
    escribirArch("frase.txt", str);
    imprimirArch("frase.txt");
    return 0;
}