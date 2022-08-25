#include <stdio.h>
#include <stdlib.h>
#define TAM 100

void cargarArrPNR(int arr[TAM]);
int estaEnArr(int arr[TAM],int n);
int esPos(int n);
void imprimirArr(int arr[TAM]);

void main(){
    int arr[TAM];
    cargarArrPNR(arr);
} 

void cargarArrPNR(int arr[TAM]){
    int i=0,n;
    printf("Ingrese numeros y el 0 para terminar: \n");
    scanf("%d",&n);
    while (n!=0 && i<TAM-1 estaEnArr(arr,n)==0 && esPos(n)==0){
        arr[i]=n;
        i++;
        scanf("%d",&n);
    }
    arr[i]=0;
    imprimirArr(arr);
    printf("\n");
}

int estaEnArr(int arr[TAM],int n){
    for(int i=0;i<TAM-1 && arr[i]!=0;i++){
        if(arr[i]==n){
            return 1;
        }
    }
    return 0;
}

int esPos(int n){
    if(n>0){
        return 1;
    }
    return 0;
}

void imprimirArr(int arr[TAM]){
    for(int i=0;i<TAM && arr[i]!=0;i++){
        printf("%d",arr[i]);
    }
}