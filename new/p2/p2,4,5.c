#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct datos{
    int dni;
    char nombre[15];
    char pais[10];
};
typedef struct datos d;

void cargarArch(d arr[N],char nomArch[10]);
void imprimir(char nomArch[10]);

int main(void){
    d arr[N];
    char nomArch[10] = {"p2,4.txt"};
    cargarArch(arr,nomArch);
    imprimir("p2,4.txt");
}

void cargarArch(d arr[N],char nomArch[10]){
    int i=0;
    FILE* arch = fopen(nomArch, "w");

    printf("Ingresar Documento: ");
    scanf("%d",&arr[i].dni);

    while(arr[i].dni!=0 && i<N){
        printf("Ingresar Nombre: ");
        scanf("%s\0",&arr[i].nombre);
        printf("Ingresar Pais: ");
        scanf("%s\0",&arr[i].pais);

        fprintf(arch,"%d,%s,%s\n", arr[i].dni, arr[i].nombre, arr[i].pais);

        i++;

        if(i<N){
            printf("Ingresar Documento: ");
            scanf("%d",&arr[i].dni);
        }
    }
    fclose(arch);
}

void imprimir(char nomArch[10]){
    int i=0,r;
    d arrT[N];
    FILE* arch = fopen(nomArch,"r");

    printf("\n%-15s %-15s %-5s", "Documento", "Nombre", "Pais\n");
    printf("==========================================\n");

    while(!feof(arch)){
        r = fscanf(arch,"%d,%[^,],%[^\n]",&arrT[i].dni, arrT[i].nombre, arrT[i].pais);
        if (!feof(arch)){
            printf("%-15d %-15s %-5s\n",arrT[i].dni, arrT[i].nombre, arrT[i].pais);
        }
        i++;

    }
    fclose(arch);


}
