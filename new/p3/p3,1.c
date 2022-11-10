#include <stdio.h>
#include <stdlib.h>

void fun(int *v1, int *v2);

int main(void){
    int var1 = 1;
    int var2 = 2;

    printf("&var1 &var2: %d %d\n",&var1,&var2);

    fun(&var1,&var2);
}

void fun(int *v1, int *v2){
    int aux = *v1;

    *v1 = *v2;
    *v2 = aux;
    

    printf("&v1 &v2: %d %d\nv1 v2: %d %d",&v1, &v2, v1, v2);
}