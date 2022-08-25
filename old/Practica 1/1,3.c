#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

void leer(char txt[TAM]);
void reemplazar(char txt[TAM]);

int main() {
    char txt[TAM];

    leer(txt);
    reemplazar(txt);
    return 0;

    
}

void leer(char txt[TAM]){
    
    int i=0;
    char aux;
    printf("Ingrese contenido: ");
	char term='\n';

    if (i<TAM-1){
        aux = getchar();
    }
    while(aux!=term && i<TAM-1){
        txt[i] = aux;
        i++;
        if(i<TAM-1){
            aux = getchar();
        }
    }
    txt[i]='\0';


}

void reemplazar(char txt[TAM]){

    int i;
    char l,r;

    printf("Ingresar letra a reemplazar: ");
    fflush(stdin);
    l = getchar();
    printf("Ingresar letra de reemplazo: ");
    fflush(stdin);
    r = getchar();

    for (i=0;i<TAM-1 && txt[i]!='\0'; i++){
        if (txt[i] == l){
            txt[i] = r;
        }
    }

    printf("Resultado: %s",txt);
}
