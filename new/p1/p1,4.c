#include <stdio.h>
#include <stdlib.h>
#define TAM 100

void cargarArr(int arr[TAM]);
void imprimirArr(int arr[TAM]);
void invertirArr(int arr[TAM]);

void main(){
    int arr[TAM];
    cargarArr(arr);
    invertirArr(arr);
}

void cargarArr(int arr[TAM]){
    int i=0,n;
    printf("Ingrese numeros y el 0 para terminar: \n");
    scanf("%d",&n);
    while (n!=0 && i<TAM-1){
        arr[i]=n;
        i++;
        scanf("%d",&n);
    }
    arr[i]=0;
    imprimirArr(arr);
    printf("\n");
}

void imprimirArr(int arr[TAM]){
    for(int i=0;i<TAM && arr[i]!=0;i++){
        printf("%d",arr[i]);
    }
}

void invertirArr(int arr[TAM]){
    int i=0,n;
    int size;
    while (arr[size]!=0){
        size++;
    }
    int aux;
    //cambia posiciones de los elementos
    while(i<size-1){
        aux = arr[i];
        arr[i] = arr[size-1];
        arr[size-1] = aux;
        size--;
        i++;
    }
    imprimirArr(arr);
}

