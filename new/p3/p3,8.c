#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cargarStrDin1();
void cargarStrDin2(char** pCadena);
void escribirArch(const char * nomArch, char* cadena);
void imprimirArch(const char * nomArch);

int main(void){
    char* str = NULL;
    // str = cargarStrDin1();
    cargarStrDin2(&str);
    printf("Arreglo dinamico: %s",str);
    escribirArch("frase.txt", str);
    imprimirArch("frase.txt");
}

char* cargarStrDin1(){
    char letra;
    char *arr = NULL;
    arr = (char*)malloc(sizeof(char));

    if (arr == NULL){
        letra = getchar();
    }
    while (letra!='\n'){
        arr = (char*)realloc(arr,sizeof(char)*strlen(arr)+1);
        arr[strlen(arr)] = letra;
        letra = getchar();
    }
    arr[strlen(arr)] = '\0';

    return arr;
}

void cargarStrDin2(char **str){
    char letra;
    int i = 0;
    *str = (char*)malloc(sizeof(char));

    if(*str != NULL){
        letra = getchar();

        while (letra!='\n'){
            *((*str) + i) = letra;
            i++;
            *str = (char*)realloc((*str),sizeof(char)*(i+1));
            letra = getchar();
        }
    }
    *((*str) + i) = '\0';
}

void escribirArch(const char* nomArch, char* cadena){
    FILE* arch = fopen(nomArch,"w");
    fprintf(arch,"%s",cadena);
    fclose(arch);
}

void imprimirArch(const char * nomArch){
    FILE* arch = fopen(nomArch,"r");
    int r;
    char *aux;
    r = fscanf(arch,"%c",aux);
    printf("\nContenido del archivo: %s",aux);
}