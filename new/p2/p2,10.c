#include <stdio.h>

void contar(unsigned int a);

int main(void){
    unsigned int var;
    printf("Ingresar numero: ");
    scanf("%ld",&var);

    contar(var);

}

void contar(unsigned int a){
    unsigned char mask = 1;
    int cant;

    for (int i = 1; i < 32; i++){
        if(((a>>i) & mask) == mask){
            cant++;
        }
    }

    printf("%d",cant);
     


}