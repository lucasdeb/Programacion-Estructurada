#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

void cargarText(char txt[TAM]);
void imprimirText(char txt[TAM]);
void normalizar(char txt[TAM]);
int espacios(char txt[TAM]);

void main(){
    char txt[TAM];
    
    cargarText(txt);
    printf("\nVolvi al main");
    imprimirText(txt);
    normalizar(txt);
    imprimirText(txt);
}

void cargarText(char txt[TAM]){
    char term='\n';
    int i=0;
    char aux;
    printf("Ingrese contenido: ");

    aux = getchar();
    
    while (aux!=term && i<TAM-1){
        txt[i] = aux;
        i++;
        if(i<TAM-1){
            aux = getchar();
        }
    }
    txt[i]='\0';
}

void normalizar(char txt[TAM]){
    printf("%d",espacios(txt));
    if (txt[0]!=isupper(txt[0])){
        txt[0] = toupper(txt[0]);
    }
    if (espacios(txt) == 1){
        printf("Hasta aca tamos");
        for (int i = 0; i < TAM-1 && txt[i]!='\0'; i++){
            if (txt[i]== ' '){
                while (txt[i+1]== ' '){
                    for (int j=i+1; j<sizeof(txt[TAM]-1) && txt[j]!='\0'; j++){
                        txt[j] = txt[j+1];
                    }
                }
            }
        }
    }
}

int espacios(char txt[TAM]){
    printf("Estoy en espacios");
    for (int i = 0; i < TAM-1 && txt[i]!='\0'; i++){
        if ((txt[i]== ' ' && txt[i+1] == ' ')){
            return 1;
        }
    }
    return 0;
}

void imprimirText(char txt[TAM]){
    printf("\nEl arreglo: ");
    printf("%s",txt);
}