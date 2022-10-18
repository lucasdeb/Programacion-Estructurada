#include <stdio.h>
#include <stdlib.h>

void fun(int *v1, int *v2);

int main(void){
    int var1 = 1;
    int var2 = 2;

    fun(&var1,&var2);
}

void fun(int *v1, int *v2){
    int aux = *v1;

    *v1 = *v2;
    *v2 = aux;
    

    printf("%d %d",*v1, *v2);
}