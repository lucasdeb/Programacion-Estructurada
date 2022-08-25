#include <stdio.h>

void intercambiar(int * p,int * p1);

void intercambiar(int * p,int * p1){
    int aux = *p;

    *p = *p1;
    *p1 = aux;
}

void main(){
    int a = 9,b = 8;
    printf("Valor 1: %d, Valor 2: %d\n",a,b);
    intercambiar(&a,&b);
    printf("Valor 1: %d, Valor 2: %d\n",a,b);
}

