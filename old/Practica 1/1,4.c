#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define term 0

void cargarArr(int arr[TAM]);
void imprimir(int arr[TAM]);
void invertir(int arr[TAM]);


void main(){

    int arr1[TAM];
    int arr2[TAM];

    cargarArr(arr1);
    cargarArr(arr2);
    invertir(arr1);

}

void cargarArr(int arr[TAM]) {
    int aux;
    int i = 0;

    if (i<TAM-1){
        printf("Ingresar numeros y el 0 para terminar: \n");
        scanf("%d",&aux);
    }
    while(aux!=term && i<TAM-1){
        arr[i] = aux;
        i++;
        if(i<TAM-1){
            scanf("%d",&aux);
        }
    }
    arr[i]= 0;
}

void imprimir(int arr[TAM]){
    int i = 0;
    //imprime arreglo por posicion
    while (arr[i]!= 0){
        printf("%d",arr[i]);
        i++;
    }
}

void invertir(int arr[TAM]){
    int i = 0;
    int size;
    size = sizeof(arr[TAM]);
    int aux;
    //cambia posiciones de los elementos
    while(i<size-1){
        aux = arr[i];
        arr[i] = arr[size-1];
        arr[size-1] = aux;
        size--;
        i++;
    }
    printf("El arreglo invertido: ");
    imprimir(arr);
    
}