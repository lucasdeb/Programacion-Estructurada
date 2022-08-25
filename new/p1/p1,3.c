#include <stdio.h>
#include <stdlib.h>
#define TAM 100 

void leer(char arreglo[TAM]);
void reemplazar(char arreglo[TAM]);

void main(){
    char arreglo[TAM];
    leer(arreglo);
    reemplazar(arreglo);
}

void leer(char arreglo[TAM]){
    char aux;
    int i;
    printf("Ingrese contenido: ");
    aux = getchar();
    while(aux!='\n' && i<100){
        arreglo[i] = aux;
        i++;
        aux = getchar();
    }
    arreglo[i]='\0';
}

void reemplazar(char arreglo[TAM]){
    char are, re;
    printf("Ingrese un caracter a reemplazar: ");
    fflush(stdin);
    re = getchar();
    printf("Ingrese un caracter a reemplazar por: ");
    fflush(stdin);
    are = getchar();
    for (int i=0; i<100 && arreglo[i]!='\n'; i++){
        if (arreglo[i] == re){
            arreglo[i] = are;
        } 
    }
    printf("%s", arreglo);
}