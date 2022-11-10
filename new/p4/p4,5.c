#include <stdio.h>
#include <stdlib.h>

int* cargarArr();
int maximo(int *p);

int main(void){
    int* p = cargarArr();
    for (int j = 0; p[j]!=0; j++){
        printf(" %d",p[j]);
    }
    maximo(p);
}

int maximo(int *p){
    
}