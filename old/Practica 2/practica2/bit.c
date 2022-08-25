#include <stdlib.h>
#include <stdio.h>
#define MASK1 2
void fun();
int main(){
    fun();
    return 0;
}
void fun(){
    int x = 34;
    if (x & MASK1){
        printf("La variable x contiene un 1 en el 2 bit\n");
    }
}

