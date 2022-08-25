#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

void cargarText(char arr[TAM]);
void imprimir(char arr[TAM]);
void normalizar(char arr[TAM]);

void main(){
    char arr[TAM];
    cargarText(arr);
    imprimir(arr);
    normalizar(arr);
    imprimir(arr);

}

void cargarText(char arr[TAM]){
    char term='\n';
    int i=0;
    char aux;
    printf("Ingrese contenido: ");

    aux = getchar();
    
    while(aux!=term && i<TAM-1){
        arr[i] = aux;
        i++;
        if(i<TAM-1){
            aux = getchar();
        }
    }
    arr[i]='\0';
}

void normalizar(char arr[TAM]){
    int i,f,j;

    if (isupper(arr[0])==0){
        arr[0] = arr[0]-32;
    }
    for (i = 0; i < TAM-1 && arr[i]!='\0'; i++){
        if ((i!=0 && i!=sizeof(arr[TAM]-1))&&(arr[i+1]==' ' && arr[i+2]==' ')){
            f=i+1;
            while (arr[f+1]==' '){
                for (j=f;j<TAM-1 && arr[j]!='\0';j++){
                    arr[j]=arr[j+1];
                }
            }
        }
    }
    
}

void imprimir(char arr[TAM]){
    int i = 0;
    //imprime arreglo por posicion
    printf("\nEl arreglo: ");
    while (arr[i]!='\0'){
        printf("%c",arr[i]);
        i++;
    }
}

/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

void cargarText(char arr[TAM]);
void imprimir(char arr[TAM]);
void normalizar(char arr[TAM]);

void main(){
    char arr[TAM];
    cargarText(arr);
    imprimir(arr);
    normalizar(arr);
    imprimir(arr);

}

void cargarText(char arr[TAM]){
    char term='\n';
    int i=0;
    char aux;
    printf("Ingrese contenido: ");

    aux = getchar();
    
    while(aux!=term && i<TAM-1){
        arr[i] = aux;
        i++;
        if(i<TAM-1){
            aux = getchar();
        }
    }
    arr[i]='\0';
}

void normalizar(char arr[TAM]){
    int i,f;

    if (isupper(arr[0])==0){
        arr[0] = 'H';
    }
    for (i = 0; i < TAM-1 && arr[i]!='\0'; i++){
        if ((i!=0 && i!=sizeof(arr[TAM]-1))&&(arr[i+1]==' ' && arr[i+2]==' ')){
            for (f=i+1;f<TAM-1 && arr[f]!='\0';f++){
                arr[f]=arr[f+1];
            }
        }
    }
    
}

void imprimir(char arr[TAM]){
    int i = 0;
    //imprime arreglo por posicion
    printf("\nEl arreglo:");
    while (arr[i]!='\0'){
        printf("%c",arr[i]);
        i++;
    }
}
*/