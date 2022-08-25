#include <stdio.h>
#include <stdlib.h>
#define TAM 100

void cargarText(char txt[TAM]);
void imprimirText(char txt[TAM]);
void normalizar(char txt[TAM]);

void main(){
    char txt[TAM];
    
    cargarText(txt);
    normalizar(txt);
    imprimirText(txt);
}

void cargarText(char txt[TAM]){
    
}