#include <stdio.h>
#include <stdlib.h>

#define N 50

struct s_info
{
    char texto[N];
    unsigned int fecha;
};
typedef struct s_info t_info;

void cargar(t_info arr[N]);
int decodificarA(unsigned int x);
void imprimir(t_info arr[N]);
int decodificarM(unsigned int m);

int main(void){
    t_info arr[N] = {0};
    cargar(arr);
    imprimir(arr);
}

void cargar(t_info arr[N]){
    FILE* arch = fopen("parcial.txt", "r");
    int r,i=0;

    r = fscanf(arch,"%[^,], %d",arr[i].texto, &arr[i].fecha);

    for (i = 1;!feof(arch); i++){
        r = fscanf(arch,"%[^,], %d",arr[i].texto, &arr[i].fecha);
    }
    arr[i].texto[0] = '\0';
}

int decodificarA(unsigned int x){
    return x>>20;
}

void imprimir(t_info arr[N]){
    printf("\n%15s %15s %15s\n","TEXTO", "ANIO", "MES");
    printf("------------------------------------\n");
    for (int i = 0; i < N && arr[i].texto[0]!='\0'; i++){
        printf("%15s %15d %15d",arr[i].texto, decodificarA(arr[i].fecha), decodificarM(arr[i].fecha));
    }
}

int decodificarM(unsigned int m){
    unsigned char mask = 15;
    return (m >> 16) & mask;
}