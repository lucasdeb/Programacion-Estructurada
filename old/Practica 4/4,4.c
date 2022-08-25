#include <stdio.h>
#include <stdlib.h>

void imprimirArr(char* str, int* v, int t);
void invertir(int *a, int n);

int main(){
    int a[4] = {1,2,3,4};
    imprimirArr("Original",a,4);
    invertir(a,4);
    imprimirArr("Invertido",a,4);
    return 0;

}

void imprimirArr(char* str, int* v, int t){
    int i;
    printf("%s\n",str);
    for (i = 0; i < t; i++){
        printf("[%d]:%d ",i,v[i]);
    }
    printf("\n");
    
}

void invertir(int *a, int n){
    int aux;
    if (n > 1){
        aux = a[n-1];
        a[n-1] = a[0];
        a[0] = aux;
        invertir(a+1,n-2);
    }

}