#include <stdio.h>
#include <stdlib.h>

void fun(unsigned char var);

int main(void){
    unsigned char var;
    printf("Ingresar char a ser respresentado: ");
    scanf("%c",&var);
    fun(var);
}

void fun(unsigned char var){
    unsigned char mask = 128;
    for (int i = 7; i >= 0; i--){
        printf("%d",((mask & var) >> i));
        mask = mask >> 1;
    }
}