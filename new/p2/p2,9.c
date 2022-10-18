#include <stdio.h>

unsigned char shift(unsigned char var, int s);

int main(void){
    unsigned char var;
    int s;

    printf("Ingresar char a ser shifteado: ");
    scanf("%c",&var);
    printf("Ingresar cantidad de shifteos: ");
    scanf("%d",&s);

    printf("%d",shift(var,s));
}

unsigned char shift(unsigned char var, int s){

    for (int i = 0; i < s; i++){
        var = var>>1;
    }
    
    return var;
}