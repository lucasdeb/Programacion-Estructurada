#include <stdio.h>
#include <stdlib.h>

int fun(int arr[10],int pos);

int main(void){
    int arr[10];

    printf("Valor: %d Direccion: %d\n",arr[3],&arr[3]);

    printf("%d\n",fun(arr,3));

}

int fun(int arr[10],int pos){
    return &arr[pos];
}