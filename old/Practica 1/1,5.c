#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define term 0

void cargarArrPNR(int arr[TAM]);
int estaEnArr(int arr[TAM], int aux);
int esPos(int aux);
void imprimir(int arr[TAM]);

void main(){
    int arr[TAM];

    cargarArrPNR(arr);
}

void cargarArrPNR(int arr[TAM]){
    int aux;
    int i = 0;

    printf("Ingresar numeros y el 0 para terminar:");
    scanf("%d",&aux);

    while(aux!=term && i<TAM-1){
        arr[i] = aux;
        i++;
        if (i<TAM-1){
            scanf("%d",&aux);
            while (esPos(aux) == 0 || estaEnArr(arr,aux) == 0){
                printf("Error:");
                scanf("%d",&aux);
            }
        }
    }
    arr[i]= 0;
    imprimir(arr);
}

int estaEnArr(int arr[TAM], int aux){
    int i;
    for (i = 0; i < sizeof(arr[TAM]); i++){
        if (arr[i] == aux){
            return 0;
        } 
    }

    return 1;
}

int esPos(aux){
    if (aux<0){
        return 0;
    }
    return 1;
}
void imprimir(int arr[TAM]){
    int i = 0;
    //imprime arreglo por posicion
    printf("El arreglo:");
    while (arr[i]!= 0){
        printf("%d",arr[i]);
        i++;
    }
}
