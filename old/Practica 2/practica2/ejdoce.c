#include <stdio.h>
#include <stdlib.h>
#define mask 32
int funcion(unsigned char letra);
int main(){
    unsigned char letra='B';
    int num;
    num=funcion(letra);
    printf("%c\n",(char)num);
    return 0;
}
/////para cambiarlo a mayuscula hay q ponerle el bit 1 en 32
int funcion(unsigned char letra){
    return letra|mask;
}