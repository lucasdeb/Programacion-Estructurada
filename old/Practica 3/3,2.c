#include <stdio.h>
#define TAM 5

int posicion(int A[TAM], int pos);

int posicion(int A[TAM], int pos){
    return &A[pos];
}

void main(){
    int A[TAM] = {5,4,3,2,1};
    int pos = 2;
    printf("Valor: %d Direccion: %d\n",A[pos],&A[pos]);
    printf("%d\n", posicion(A,pos));
}