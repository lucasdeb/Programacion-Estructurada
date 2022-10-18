#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a, b, c;
}t_tres;

void ordenar(t_tres *p);

int main(void){
    t_tres a = {10,3,5};
    ordenar(&a);
    printf("a: %d b: %d c: %d", a.a, a.b, a.c);
}

void ordenar(t_tres *p){
    int arr1[3] = {p->a, p->b, p->c};
    int aux;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            if(arr1[i]>arr1[j]){
                aux = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = aux;
            }
        }
    }
    p->a = arr1[0];
    p->b = arr1[1];
    p->c = arr1[2];
    
}